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
public:
    Parttimer (string name_, double years_of_service_) : Employee(name_, years_of_service_) { salary = 20000 + 1000 * years_of_service; }
};

class Manager : public Employee {
public:
    Manager (string name_, double years_of_service_) : Employee(name_, years_of_service_) { salary = 35000 + 5000 * years_of_service; }
};

class Chairman : public Manager {
public:
    Chairman (string name_, double years_of_service_) : Manager(name_, years_of_service_) { salary = salary + 50000; }
};

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
    ifstream ifs("input1.txt");
    Employee **employee_list;
    int num_employee;
    ifs >> num_employee;
    employee_list = new Employee *[num_employee];
    for (int i=0; i<num_employee; ++i) {
        string name, title;
        double years_of_service;
        ifs >> name >> title >> years_of_service;
        if (title == "P")
            employee_list[i] = new Parttimer(name, years_of_service);
        else if (title == "M")
            employee_list[i] = new Manager(name, years_of_service);
        else
            employee_list[i] = new Chairman(name, years_of_service);
    }
    print_out(employee_list, num_employee);
    for (int i=0; i<num_employee; ++i)
        delete employee_list[i];
    delete[] employee_list;
    ifs.close();
    return 0;
}
