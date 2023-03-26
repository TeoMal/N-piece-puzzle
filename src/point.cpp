#include<iostream>
struct point{
    int x,y;
    point operator +(const point& other)const{
        point temp;
        temp.x=x+other.x;
        temp.y=y+other.y;
        return temp;
    }
    point operator -(const point& other)const{
        point temp;
        temp.x=x-other.x;
        temp.y=y-other.y;
        return temp;
    }
};