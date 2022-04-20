#include<iostream>
#include<fstream>
using namespace std;


class Student{
public:	
	Student(void){}
	~Student();//dtor
	void initial(string name_,int numClass_);
	void add_class(int i,string className);		//store data to member varible
	bool is_in(string className);
	string get_name();
	
private:
	string name;
	int numClass;
	string *classList;
};


int main()
{
	ifstream inFile;
	ofstream outFile;
	Student *studentList;
	string *classList;
	string in_string;
	int numStudent,numClass;
	
	//global data
	inFile.open("input3.txt");
	outFile.open("output3.txt");
	
	inFile>>numStudent;
	studentList=new Student[numStudent];
	inFile>>numClass;
	classList=new string[numClass];
	
	//import class name
	for(int i=0;i<numClass;i++){
		inFile>>in_string;
		classList[i]=in_string;
	}
	
	//import student data
	for(int i=0;i<numStudent;i++){
		string name;
		int num;
		inFile>>name>>num;
		studentList[i].initial(name,num);
		
		for(int j=0;j<num;j++){
			inFile>>name;
			studentList[i].add_class(j,name);
		}
	}
	
	for(int i=0;i<numClass;i++){
		outFile<<"Class: "<<classList[i]<<endl;
		outFile<<"\t";
		for(int j=0;j<numStudent;j++){
			if(studentList[j].is_in(classList[i]))
				outFile<<studentList[j].get_name()<<" ";
		}
		outFile<<endl;
	}
	
	
	
	return 0;
}

Student::~Student()
{
	delete[] classList;
}


void Student::initial(string name_,int numClass_)
{
	name=name_;
	numClass=numClass_;
	classList=new string[numClass];
}


void Student::add_class(int i,string className)
{
	classList[i]=className;
}

bool Student::is_in(string className)
{
	for(int i=0;i<numClass;i++){
		if(classList[i]==className)
			return true;
	}
	return false;
}

string Student::get_name()
{
	return name;
}