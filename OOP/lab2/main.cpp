#include"fun.h"
#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

int main()
{
	double a1,a2,b1,b2,c1,c2,x,y,z,s,area,max,min;
	cout<<"Point 1's coordinate: "<<endl;
	cin>>a1>>a2;
	cout<<"Point 2's coordinate: "<<endl;
	cin>>b1>>b2;
	cout<<"Point 3's coordinate: "<<endl;
	cin>>c1>>c2;
	cout<<"-----RESULTS------"<<endl;
	x=func1(a1,a2,b1,b2);
	y=func1(a1,a2,c1,c2);
	z=func1(c1,c2,b1,b2);
	cout<<"side length: "<<x<<"  "<<y<<"   "<<z<<endl;
	area=func2(x,y,z);
	cout<<"area: "<<area<<endl;
	cout<<"max difference: "<<func3(x,y,z);


}
