#ifndef POINT_H
#define POINT_H

#include<cmath>

class Point
{
public :
    Point():Point(0,0){};
    Point(int x, int y):m_x(x), m_y(y){};

    int x() const {return m_x;};
    int y() const {return m_y;};

    void setX(int x) {m_x=x;};
    void setY(int y) {m_y=y;};

    /**
     * @brief Set the point to the coordinates x and y
     * 
     * @param x 
     * @param y 
     */
    void moveTo(int x, int y){
        setX(x);
        setY(y);
    };

    double distance(const Point& p) const;

    /**
     * @brief 
     * @param p1 
     * @param p2 
     * @return int 1, -1 or 0 if the point is left right or on (ab)
     */
    int isLeft(const Point& p1, const Point& p2) const;
    int isRight(const Point& p1, const Point& p2) const;

    bool isInside(const Point& p1, const Point& p2, const Point& p3) const;
    bool isInside(const Point& p1, const Point& p2, const Point& p3, const Point& p4) const;

    Point middle() const;
private:
    int m_x;
    int m_y;
};

double Point::distance(const Point& p) const
{
    double dx = p.m_x-m_x, dy = p.m_y-m_y;
    return std::sqrt(dx*dx + dy*dy);
}

int Point::isLeft(const Point &p1, const Point &p2) const
{
    int det = (p2.x()-p1.x())*(m_y-p1.y())-(m_x-p1.x())*(p2.y()-p1.y());

	if (det==0)
    {
        return 0;
    }
    else if (det>0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int Point::isRight(const Point &p1, const Point &p2) const
{
    return 2;
}

#endif