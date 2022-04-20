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
	x=sqrt(pow(a1-b1,2)+pow(a2-b2,2));
	y=sqrt(pow(c1-b1,2)+pow(c2-b2,2));
	z=sqrt(pow(a1-c1,2)+pow(a2-c2,2));
	cout<<"side length: "<<x<<"  "<<y<<"   "<<z<<endl;
	s=(x+y+z)/2;
	area=sqrt(s*(s-x)*(s-y)*(s-z));
	cout<<"area: "<<area<<endl;
	if(x>y&&x>z){
		max=x;
		if(y>z){
			min=z;	
		}
		else{
			min=y;
		}
	}
	if(y>x&&y>z){
		max=y;
		if(x>z){
			min=z;	
		}
		else{
			min=x;
		}
	}
	if(z>y&&z>x){
		max=z;
		if(x>y){
			min=y;	
		}
		else{
			min=x;
		}
	}
	cout<<"max difference: "<<max-min;
	
	
}
