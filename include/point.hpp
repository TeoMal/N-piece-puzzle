struct point{
    int x,y;
    point operator +(const point& other)const;
    point operator -(const point& other)const;
    friend std::ostream& operator<<(std::ostream& os, const point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};