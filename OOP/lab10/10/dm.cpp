#include"dm.h"

/// member functions of circle class

void circle::get_information()
{

     cout<<"NAME: "<<setw(8)<<name<<", "<<"PERIMETER: "<<setw(8)<<perimeter<<", "<<"TYPE: circle"<<endl;
}
circle::circle(double r,string s1)
{
    r1=r;
    name=s1;
}
void circle::set_perimeter()
{
    if(r1<0)
    {
        perimeter=-1;
    }else{
        perimeter=2*3.14*r1;
    }

}

///member functions of triangle class
void triangle::get_information()
{
     cout<<"NAME: "<<setw(8)<<name<<", "<<"PERIMETER: "<<setw(8)<<perimeter<<", "<<"TYPE: triangle"<<endl;
}
triangle::triangle(double side0,double side1,double side2,string s1)
{
    sides=new double[3];
    sides[0]=side0;
    sides[1]=side1;
    sides[2]=side2;
    name=s1;

}
void triangle::set_perimeter()
{
    if(sides[0]+sides[1]<=sides[2]||sides[0]+sides[2]<=sides[1]||sides[2]+sides[1]<=sides[0])
   {
        perimeter=-1;
    }
    else{
        perimeter=sides[0]+sides[1]+sides[2];
    }
}


///member functions of rectangle class
void rectangle::get_information()
{

     cout<<"NAME: "<<setw(8)<<name<<", "<<"PERIMETER: "<<setw(8)<<perimeter<<", "<<"TYPE: rectangle"<<endl;
}
rectangle::rectangle(double side0,double side1,double side2,double side3,string s1)
{
    sides=new double[4];
    sides[0]=side0;
    sides[1]=side1;
    sides[2]=side2;
    sides[3]=side3;
    name=s1;

}
void rectangle::set_perimeter()
{
    if(sides[0]==sides[2]&&sides[1]==sides[3])
   {
        perimeter=sides[0]+sides[1]+sides[2]+sides[3];
    }
    else{
        perimeter=-1;
    }
}

/// member functions of square class
void square::get_information()
{
     cout<<"NAME: "<<setw(8)<<name<<", "<<"PERIMETER: "<<setw(8)<<perimeter<<", "<<"TYPE: square"<<endl;
}

square::square(double side0,double side1,double side2,double side3,string s1)
{
    sides=new double[4];
    sides[0]=side0;
    sides[1]=side1;
    sides[2]=side2;
    sides[3]=side3;
    name=s1;
}
void square::set_perimeter()
{
    if(sides[0]==sides[1]&&sides[1]==sides[2]&&sides[2]==sides[3])
   {
        perimeter=sides[0]+sides[1]+sides[2]+sides[3];
    }
    else{
        perimeter=-1;
    }
}





