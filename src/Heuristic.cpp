#include"../include/Heuristic.hpp"
int heuristic(std::vector<std::vector<int>> grid){
    int h=0,value,correct_i,correct_j,n=grid.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            value = grid[i][j];
            if(value==-1)continue;
            correct_i=(value-1)/n;
            correct_j=(value-1)%n;
            h+=ABS(correct_i,i)+ABS(correct_j,j);
        }
    }
    return h;
}