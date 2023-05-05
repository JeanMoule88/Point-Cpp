#include "Point.h"
#include<iostream>

int main()
{
    /*Point p(2,3);
    Point p1(1,1);
    Point p2(2,7);
    Point p3(4,2);

    bool b=p.isInside(p1,p2,p3);
    std::cout<<"Est dans triangle: "<<b<<std::endl;

    Point pEgal(2,3);

    std::cout<<"vrai operator==: "<<(p==pEgal)<<std::endl;
    std::cout<<"faux operator==: "<<(p==p2)<<std::endl;

    std::cout<<"faux operator!=: "<<(p!=pEgal)<<std::endl;
    std::cout<<"vrai operator!=: "<<(p!=p2)<<std::endl;*/

    Point p1(1, 1);
    Point p2(2, 10);
    Point p3(10, 11);
    Point p4(10, 2);
    Point pIn(5, 5);
    Point pOut(12, 12);


    std::cout<<"Dans rect: "<<pIn.isInside(p1, p2, p3, p4)<<std::endl;
    std::cout<<"Dans rect: "<<pOut.isInside(p1, p2, p3, p4)<<std::endl;

    std::cout<<"Test lecture"<<std::endl;

    Point p(12,28);

    std::cout<<"Point: "<<p<<std::endl;

    std::cin>>p;

    std::cout<<"P rentre: "<<p<<std::endl;
}