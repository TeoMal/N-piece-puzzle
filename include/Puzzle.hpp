#include<iostream>
#include<vector>
#include "point.hpp"
class Puzzle{
    private:
        std::vector<std::vector<int>> board;
        struct point blank;
        int g,h;
        Puzzle *parent;

    public:
        Puzzle(std::vector<std::vector<int>> grid,point b,int a1,int a2,Puzzle *P);
        bool operator <(const Puzzle & other)const;
};