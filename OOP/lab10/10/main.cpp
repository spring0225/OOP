#include"dm.h"

int main()
{

	///----- parse file
    ifstream file_in("pattern3.txt");
    int nShape; ///# of total shapes
    int nTri=0,nRec=0,nSqu=0,nCir=0;

    file_in>>nShape;

    shape** shape_list = new shape*[nShape];

	string s1,s2;
    for(int i=0;i<nShape;++i)
    {

        ///get name
        file_in>>s1;
        ///get type
        file_in>>s2;


        if(s2=="triangle")
        {
          double side_0,side_1,side_2;
          file_in>>side_0>>side_1>>side_2;
          triangle *pTri=new triangle(side_0,side_1,side_2,s1);
          shape_list[i] = pTri;
          ++nTri;
        }
        else if(s2=="rectangle")
        {
          double side_0,side_1,side_2,side_3;
          file_in>>side_0>>side_1>>side_2>>side_3;
          rectangle *pRec=new rectangle(side_0,side_1,side_2,side_3,s1);
          shape_list[i] = pRec;
          ++nRec;
        }

        else if(s2=="square")
        {
          double side_0,side_1,side_2,side_3;
          file_in>>side_0>>side_1>>side_2>>side_3;
          square *pSqu=new square(side_0,side_1,side_2,side_3,s1);
         shape_list[i] = pSqu;
         //cout<<pSqu->sides[0];
          ++nSqu;
        }

        else if(s2=="circle")
        {
          double r;
          file_in>>r;
          circle *pCir=new circle(r,s1);
          shape_list[i] = pCir;
          ++nCir;
        }


    }

	for(int i=0;i<nShape;++i)
    {
      shape_list[i]->set_perimeter();
    }

	///----- print results

	cout<<"[# of each shape]"<<endl;
    cout<<"Triangle: "<<nTri<<endl;
	cout<<"Rectangle: "<<nRec<<endl;
	cout<<"Square: "<<nSqu<<endl;
	cout<<"Circle: "<<nCir<<endl;
	cout<<endl;

    cout<<"[Legal]"<<endl;
    for(int i=0;i<nShape;++i)
    {
	  if(shape_list[i]->get_perimeter() != -1){
        shape_list[i]->get_information();
	  }
    }
	cout<<endl;
	cout<<"[Illegal]"<<endl;
	for(int i=0;i<nShape;++i)
    {
	  if(shape_list[i]->get_perimeter() == -1){
        shape_list[i]->get_information();
	  }
    }


    return 0;
}
