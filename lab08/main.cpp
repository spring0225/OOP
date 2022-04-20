#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
class Student{
public:
	//add your function
	Student():numClass(0),name(""){};
    void addc(string c);
    bool checkc(string c);
    void getname(string n){name = n;};
    void getnumclass(int nc){numClass = nc;};
    void newc(){classList = new string[numClass];};
    string oname();
private:
	string name;
	int numClass;
	string *classList;
	int i=0;
};
void Student::addc(string c){
    classList[i] = c;
    ++i;
}
string Student::oname(){
    return name;
}
bool Student::checkc(string c){
    for(int j=0 ; j<numClass ; ++j){
        if(c == classList[j]){
            j = 0;
            return true;
        }
    }
    return false;
}
int main()
{
	//Student *studentList;
	//string *classList;
	int nums=0, numc=0;
	ifstream ifs;
	ofstream ofs;
	ifs.open("input1.txt");
	ofs.open("output1.txt");
	if(ifs.fail()){
        cout<<"Can not open input file";
        exit(1);
	}
	if(ofs.fail()){
        cout<<"Can not open ouput file";
        exit(1);
	}
    ifs>>nums;
    Student *studentList = new Student[nums];
    ifs>>numc;
    string *cclassList = new string[numc];
    for(int i=0 ; i<numc ; ++i){
        string c;
        ifs>>c;
        cclassList[i] = c;
    }
    for(int i=0 ; i<nums ; ++i){
        string namee;
        ifs>>namee;
        int numsc=0;
        ifs>>numsc;
        studentList[i].getname(namee);
        studentList[i].getnumclass(numsc);
        studentList[i].newc();
        for(int j=0 ; j<numsc ; ++j){
            string cn;
            ifs>>cn;
            studentList[i].addc(cn);
        }
    }
    for(int i=0 ; i<numc ; ++i){
        ofs<<"Class : "<<cclassList[i]<<endl;
        ofs<<"    ";
        for(int k=0 ; k<nums ; ++k){
            if(studentList[k].checkc(cclassList[i])){
                string nn = studentList[k].oname();
                ofs<<nn<<" ";
            }
        }
        ofs<<endl;
    }
	ifs.close();
	ofs.close();
    cout<<"Success";
	return 0;
}
