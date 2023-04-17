#include<iostream>
#include<vector>
#include "point.hpp"
enum MOVE{UP,DOWN,RIGHT,LEFT};
#define OPPOSITE_MOVE(move) \
    ((move == UP) ? DOWN : \
     (move == DOWN) ? UP : \
     (move == RIGHT) ? LEFT : \
     RIGHT)
class Puzzle{
    private:
        std::vector<std::vector<int>> board;
        struct point blank;
        int g,h;
        Puzzle *parent;
        int fix(MOVE);
        static point directional_vector[4];
    public:
        Puzzle(std::vector<std::vector<int>> grid,point b,int a1,int a2,Puzzle *P);
        bool operator <(const Puzzle & other)const;
        bool is_goal(void)const;
        void print_path(void)const;
        bool is_valid(MOVE)const;
        Puzzle(Puzzle * const,MOVE);

};