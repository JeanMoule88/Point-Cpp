#include "Point.h"
#include<iostream>

int main()
{
    Point p(2,3);
    Point p1(1,1);
    Point p2(2,7);
    Point p3(4,2);

    bool b=p.isInside(p1,p2,p3);
    std::cout<<"Est dans triangle: "<<b<<std::endl;

    Point pEgal(2,3);

    std::cout<<"vrai operator==: "<<(p==pEgal)<<std::endl;
    std::cout<<"faux operator==: "<<(p==p2)<<std::endl;

    std::cout<<"faux operator!=: "<<(p!=pEgal)<<std::endl;
    std::cout<<"vrai operator!=: "<<(p!=p2)<<std::endl;
}