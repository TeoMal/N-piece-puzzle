#include"../include/Puzzle.hpp"
#include"../include/Heuristic.hpp"
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
    int new_h=this->parent->h;
    int value,correct_x,correct_y,n=this->board.size();
    point old_b = this->parent->blank;
    value = this->board[old_b.x][old_b.y];
    correct_x=(value-1)/n;
    correct_y=(value-1)%n;
    new_h+=ABS(correct_x,old_b.x)+ABS(correct_y,old_b.y);
    new_h-=(ABS(correct_x,blank.x)+ABS(correct_y,blank.y));
    return new_h;
}
bool Puzzle::is_valid(MOVE w)const{
    int n =this->board.size();
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
        if(this->blank.x==n){
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
        if(this->blank.y==n){
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
Puzzle::Puzzle(Puzzle *const father,MOVE w){
    this->board=father->board;
    g=father->g+1;
    blank=father->blank;
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
    this->parent=father;
    h=this->fix(w);
}