#ifndef DM_H
#define DM_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#define pi 3.14
using namespace std;



///shape class
class shape
{
      public:
            virtual ~shape(){};
			virtual void get_information()=0;
			virtual void set_perimeter()=0;
            double get_perimeter(){return perimeter;}
      protected:
			double perimeter;
			string name;

};

///polygon class
class polygon:public shape
{
      public:
             ~polygon(){delete[] sides;}
      protected:
            double* sides;

};

///circle class
class circle:public shape
{
    public:
        void get_information();
        void set_perimeter();
        circle(double ,string );
    private:
        double r1;

};


///triangle class
class triangle:public polygon
{
    public:
        void get_information();
        void set_perimeter();
        triangle(double,double,double,string);
};

///rectangle class
class rectangle:public polygon
{
    public:
        void get_information();
        void set_perimeter();
        rectangle(double,double,double,double,string);
        
       

};

///square class
class square:public polygon
{
    public:
        void get_information();
        void set_perimeter();
        square(double,double,double,double,string);
        
	//square():rectangle(){}
    //square(double s_0,double s_1,double s_2,double s_3,string n):rectangle(s_0, s_1, s_2, s_3, n){};
	//void get_information();
	//void set_perimeter();

};



#endif


