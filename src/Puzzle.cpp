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