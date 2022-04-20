#include <iostream>
#include <cmath>
using namespace std;

void area(float r1,float &carea,float pi=3)
{
    carea=r1*pi*r1;
}
void area(float x1,float x2,float x3,float y1,float y2,float y3,float &tarea)
{
    float s,a,b,c;
    a=sqrt(fabs(x1-x2)*fabs(x1-x2)+fabs(y1-y2)*fabs(y1-y2));
    b=sqrt(fabs(x1-x3)*fabs(x1-x3)+fabs(y1-y3)*fabs(y1-y3));
    c=sqrt(fabs(x3-x2)*fabs(x3-x2)+fabs(y3-y2)*fabs(y3-y2));
    s=(a+b+c)/2;
    tarea=sqrt(s*(s-a)*(s-b)*(s-c));

}
int main()
{
    float r1,r2,pi=3,carea1,carea2,tarea1,tarea2,x1,x2,x3,y1,y2,y3;
    cout<<"Please enter the radius of circle 1: ";
    cin>>r1;
    area(r1,carea1);
    cout<<"Area of the circle: "<<carea1<<endl;
    cout<<"Please enter the radius of circle 2: ";
    cin>>r2;
    cout<<"Please enter the number of pi: ";
    cin>>pi;
    area(r2,carea2,pi);
    cout<<"Area of the circle: "<<carea2<<endl;
    cout<<"Please enter three coordinates of the triangle"<<endl;
    cout<<"Coordinate of point 1: ";
    cin>>x1>>y1;
    cout<<"Coordinate of point 2: ";
    cin>>x2>>y2;
    cout<<"Coordinate of point 3: ";
    cin>>x3>>y3;
    area(x1,x2,x3,y1,y2,y3,tarea1);
    cout<<"Area of the triangle: "<<tarea1<<endl<<endl;
    cout<<"New triangle-\n";
    cout<<"Coordinate of point 1: "<<carea1<<" "<<y1<<endl;
    cout<<"Coordinate of point 2: "<<carea2<<" "<<y2<<endl;
    cout<<"Coordinate of point 3: "<<tarea1<<" "<<y3<<endl;
    area(carea1,carea2,tarea1,y1,y2,y3,tarea2);
    cout<<"Area of the triangle: "<<tarea2<<endl;


    return 0;
}
