#include"fun.h"
#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

double func1(double a1,double a2,double b1,double b2){
    return sqrt(pow(a1-b1,2)+pow(a2-b2,2));
}
double func2(double x,double y,double z){
    double s;
    s=(x+y+z)/2;
	return sqrt(s*(s-x)*(s-y)*(s-z));

}
double func3(double x,double y,double z){
    double max,min;
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
	return max-min;
}




