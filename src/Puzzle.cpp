#include"../include/Puzzle.hpp"
Puzzle::Puzzle(std::vector<std::vector<int>> grid,point b,int cost,int heur,Puzzle *P):board(grid),blank(b),g(cost),h(heur),parent(P){}
bool Puzzle::operator<(const Puzzle & other)const{
    return h+g>other.h+other.g;
}