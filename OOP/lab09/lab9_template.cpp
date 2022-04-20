#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Employee {
public:
    Employee (string name_, double years_of_service_) : name(name_), years_of_service(years_of_service_) {}
    friend ostream & operator<< (ostream &ofs, Employee &rhs);
    int get_salary () { return salary; }
protected:
    string name;
    double years_of_service;
    int salary;
};

ostream & operator<< (ostream &ofs, Employee &rhs) {
    ofs << left << setw(30) <<rhs.name << setw(13) << rhs.years_of_service << setw(15) << rhs.salary;
    return ofs;
}

class Parttimer : public Employee {
// Finish the class
public:
	Parttimer(string name_, double years_of_service_);
};
Parttimer::Parttimer(string name_, double years_of_service_):Employee(name_,years_of_service_) 
{salary=20000+1000*years_of_service_;}

class Manager : public Employee {
// Finish the class
public: 
	Manager(string name_, double years_of_service_);
	
};
Manager::Manager(string name_, double years_of_service_):Employee(name_,years_of_service_) 
{salary=20000+15000+5000*years_of_service_;}

class Chairman : public Manager {
// Finish the class
public:
	Chairman(string name_, double years_of_service_);
};
Chairman::Chairman(string name_, double years_of_service_):Manager(name_,years_of_service_) 
{salary=(20000+15000+5000*years_of_service_)+50000;}
 

void print_out (Employee **employee_list, int num_employee) {
    // selection sort
    for (int i=0; i<num_employee; ++i) {
        for (int j=i+1; j<num_employee; ++j)
            if ( (*employee_list[i]).get_salary() < (*employee_list[j]).get_salary() ) {
                Employee *tmp;
                tmp = employee_list[i];
                employee_list[i] = employee_list[j];
                employee_list[j] = tmp;
            }
        cout << *employee_list[i] << endl;
    }
}

int main()
{
    ifstream ifs("input3.txt");
    Employee **employee_list;
    int num_employee;
    ifs >> num_employee;
    employee_list = new Employee *[num_employee];
    // Finish the reading of input file
    // --------------------------------
    for(int i=0 ; i<num_employee ; ++i){
    	string namee;
    	ifs>>namee;
    	char cmp;
    	ifs>>cmp;
    	double year;
    	ifs>>year;
    	switch(cmp)
    	{
    		case 'C':
    			employee_list[i]=new Chairman(namee,year);
    			break;
    		case 'M':
    			employee_list[i]=new Manager(namee,year);
    			break;
    		case 'P':
    			employee_list[i]=new Parttimer(namee,year);
    			break;
		}
    	
	}
    
    // --------------------------------
    print_out(employee_list, num_employee);
    for (int i=0; i<num_employee; ++i)
        delete employee_list[i];
    delete[] employee_list;
    ifs.close();
    return 0;
}
