#ifndef DM_H
#define DM_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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


    





///triangle class






///rectangle class






///square class






#endif


