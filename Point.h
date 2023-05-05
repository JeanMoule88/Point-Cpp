#ifndef POINT_H
#define POINT_H

#include<cmath>
#include <iostream>

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

    /**
     * @brief 
     * 
     * @param p 
     * @return double - the distance between the 2 points
     */
    double distance(const Point& p) const;

    /**
     * @brief 
     * @param p1 
     * @param p2 
     * @return int 1, -1 or 0 if the point is left right or on (p1p2)
     */
    int isLeft(const Point& p1, const Point& p2) const;

    bool isInside(const Point& p1, const Point& p2, const Point& p3) const;
    bool isInsideCircle(const Point& p1, const Point& p2, const Point& p3) const;
    bool isInside(const Point& p1, const Point& p2, const Point& p3, const Point& p4) const;

    bool isEqual(const Point& p) const;

    Point middle(const Point& p) const;
    double area(const Point& p1, const Point& p2, const Point& p3) const;

    bool operator==(const Point& p) const;
    bool operator!=(const Point& p) const;

    Point& operator+=(const int val);
    Point operator+(const int val);
    Point& operator-=(const int val);
    Point operator-(const int val);

    void print(std::ostream& ost) const;
    void read(std::istream& ist);
private:
    int m_x;
    int m_y;

};

inline std::ostream& operator<<(std::ostream& ost, const Point& p)
{
    p.print(ost);
    return ost;
}

inline std::istream& operator>>(std::istream& ist, Point& p)
{
    p.read(ist);
    return ist;
}


/*IMPLEMENTATIONS*/

inline double Point::distance(const Point& p) const
{
    double dx = p.m_x-m_x, dy = p.m_y-m_y;
    return std::sqrt(dx*dx + dy*dy);
}

inline int Point::isLeft(const Point &p1, const Point &p2) const
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

inline bool Point::isEqual(const Point &p) const
{
    return m_x==p.m_x && m_y==p.m_y;
}

inline Point Point::middle(const Point &p) const
{
    int x=m_x+p.m_x;
    x/=2;
    int y=m_y+p.m_y;
    y/=2;

    return Point(x,y); 
}

inline bool Point::isInside(const Point& p1, const Point& p2, const Point& p3) const
{
    /* Calculate area of triangle ABC */
   float A = area (p1, p2, p3);
  
   /* Calculate area of triangle PBC */ 
   float A1 = area (*this, p2, p3);
  
   /* Calculate area of triangle PAC */ 
   float A2 = area (p1, *this, p3);
  
   /* Calculate area of triangle PAB */  
   float A3 = area (p1, p2, *this);
    
   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}

inline bool Point::isInsideCircle(const Point &p1, const Point &p2, const Point &p3) const
{
    const int p1x = p1.x() - m_x;
    const int p1y = p1.y() - m_y;
    const int p2x = p2.x() - m_x;
    const int p2y = p2.y() - m_y;
    const int p3x = p3.x() - m_x;
    const int p3y = p3.y() - m_y;

    /*
    * if det positive then the point is in the circle, if det is equal to 0 the point is on the circle
    * else the point is outside
    */
    const int det = (
        (p1x * p1x + p1y * p1y) * (p2x * p3y - p3x * p2y) -
        (p2x * p2x + p2y * p2y) * (p1x * p3y - p3x * p1y) +
        (p3x * p3x + p3y * p3y) * (p1x * p2y - p2x * p1y)
        );

    return det >= 0;
}

inline bool Point::isInside(const Point &p1, const Point &p2, const Point &p3, const Point &p4) const
{
    int b1=this->isLeft(p1,p2);
    int b2=this->isLeft(p2,p3);
    int b3=this->isLeft(p3,p4);
    int b4=this->isLeft(p4,p1);

    return (b1==b2)&&(b1==b3)&&(b1==b4);
}

inline double Point::area(const Point& p1, const Point& p2, const Point& p3) const
{
    return abs((p1.m_x*(p2.m_y-p3.m_y)+ p2.m_x*(p3.m_y-p1.m_y)+p3.m_x*(p1.m_y-p2.m_y))/2.0);
}

inline bool Point::operator==(const Point &p) const
{
    return this->isEqual(p);
}

inline bool Point::operator!=(const Point &p) const
{
    return !this->isEqual(p);
}

inline Point& Point::operator+=(const int val)
{
    m_x+=val;
    m_y+=val;
    return *this;
}

inline Point Point::operator+(const int val)
{
    Point res{*this};
    res+=val;
    return res;
}

inline Point& Point::operator-=(const int val)
{
    *this+=-val;
    return *this;
}

inline Point Point::operator-(const int val)
{
    Point res{*this};
    res-=val;
    return res;
}

inline void Point::print(std::ostream &ost) const
{
    ost<<m_x<<";"<<m_y;
}

inline void Point::read(std::istream &ist)
{
    char c;
    int x,y;
    ist>>x>>c>>y;

    m_x=x;
    m_y=y;
}

#endif
