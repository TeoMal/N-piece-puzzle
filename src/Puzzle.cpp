#include"../include/Puzzle.hpp"
Puzzle::Puzzle(std::vector<std::vector<int>> grid,point b,int cost,int heur,Puzzle *P):board(grid),blank(b),g(cost),h(heur),parent(P){}
bool Puzzle::operator<(const Puzzle & other)const{
    return h+g>other.h+other.g;
}

bool Puzzle::is_goal(void)const{
    int n=(int)board.size(),value;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            value=board[i][j];
            if(value==-1)continue;
            if(i!=((value-1)/n)){
                return false;
            }
            if(j!=((value-1)%n)){
                return false;
            }
        }
    }
    return true;
}

void Puzzle::print_path(void)const{
    if (this->parent!=NULL)
    {
        this->parent->print_path();
    }
    printf("\n");
    int n=(int)this->board.size();
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            printf("----");
        }
        printf("\n|");
        for (int j = 0; j < n; j++)
        {
            if(this->board[i][j]==-1){
                printf("   |");
                continue;
            }
            printf("%-3d|", this->board[i][j]);
        }
        printf("\n");
    }
    for(int j=0;j<n;j++){
            printf("----");
    }
    printf("\n");
}

int Puzzle::fix(MOVE w){
    //TODO fix heuristic from father board to current board
}
bool Puzzle::is_valid(MOVE w)const{
    switch (w)
    {
    case UP:
        if(this->blank.x==0){
            return false;
        }
        else{
            return true;
        }
        break;
    case DOWN:
        if(this->blank.x==this->board.size()){
            return false;
        }
        else{
            return true;
        }
        break;
    case LEFT:
        if(this->blank.y==0){
            return false;
        }
        else{
            return true;
        }
        break;
    case RIGHT:
        if(this->blank.y==this->board.size()){
            return false;
        }
        else{
            return true;
        }
    default:
        return false;
        break;
    }
}
Puzzle::Puzzle(Puzzle &father,MOVE w){
    board=father.board;
    g=father.g+1;
    blank=father.blank;
    switch (w)
    {
    case UP:
        board[blank.x][blank.y]=board[blank.x-1][blank.y];
        board[blank.x-1][blank.y]=-1;
        blank.x--;
        break;
    case DOWN:
        board[blank.x][blank.y]=board[blank.x+1][blank.y];
        board[blank.x+1][blank.y]=-1;
        blank.x++;
        break;
    case LEFT:
        board[blank.x][blank.y]=board[blank.x][blank.y-1];
        board[blank.x][blank.y-1]=-1;
        blank.y--;
        break;
    case RIGHT:
        board[blank.x][blank.y]=board[blank.x][blank.y+1];
        board[blank.x][blank.y+1]=-1;
        blank.y++;
        break;
    default:
        exit(40);
        break;
 
    }
    parent=&father;
    h=father.fix(w);
}