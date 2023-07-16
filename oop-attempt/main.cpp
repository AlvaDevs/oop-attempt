//
//  main.cpp
//  oop-attempt
//
//  Created by Alvaro Alvarez on 15/07/23.
//

#include <iostream>
#include <iomanip>
#include <locale>
#include <string>

using namespace std;

// Base Class
class People {
protected:
    string name;
    int age;
    char gender;
    
public:
    People(const string& _name, int _age, char _gender)
        : name(_name), age(_age), gender(_gender) {}
    
    // Getters
    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    char getGender() const {
        return gender;
    }
   
    // Setters
    void setName(const string& _name) {
        name = _name;
    }
    void setAge(int _age) {
        age = _age;
    }
    void setGender(char _gender) {
        gender = _gender;
    }
    
    // Pure virtual function to read data
    virtual void readData() = 0;
    
    // Virtual destructor
    virtual ~People() {}
};

// Derived class - Customer
class Customer : public People {
public:
    Customer(const string& _name, int _age, char _gender)
        : People(_name, _age, _gender) {}
    
    void readData() override {
        cout << "What is your name, dear customer?: ";
        cin >> name;
        cout << "How old are you?: ";
        cin >> age;
        cout << "And finally, what is your gender?: ";
        cin >> gender;
    }
};

// Derived class - Employee
class Employee : public People {
private:
    double salary;
    
public:
    Employee(const string& _name, int _age, char _gender, double _salary)
        : People(_name, _age, _gender), salary(_salary) {}
    
    // Getters
    double getSalary() const {
        return salary;
    }
    
    // Setter
    void setSalary (double _salary) {
        salary = _salary;
    }
    
    void readData() override {
        cout << "What is your name, dear employee?: ";
        cin >> name;
        cout << "How old are you?: ";
        cin >> age;
        cout << "What is your gender?: ";
        cin >> gender;
        cout << "And finally, how much salary do you receive from our company?: ";
        cin >> salary;
    }
};



int main() {
    char employee_customer;
    People* person = nullptr;

    cout << "Hello and welcome to the Alva^2, Inc. platform. Before proceeding, I would like to know if you are an employee or a customer of our company. \nEmployee (E) or Customer (C)?: ";
    
    while (true) {
        cin >> employee_customer;
        
        if (employee_customer == 'E' || employee_customer == 'e') {
            person = new Employee("", 0, '\0', 0.0);
            break;
        } else if (employee_customer == 'C' || employee_customer == 'c') {
            person = new Customer("", 0, '\0');
            break;
        } else {
            cout << "Invalid option. Try again: ";
        }
    }
    
    cout << endl;
    cout << "Perfect, now to continue, I will require some details about you..." << endl;
    person -> readData();
    
    cout << endl;
    cout << "Perfect, dear " << person -> getName() << "! all your information has been verified, here is a brief summary." << endl;
    
    // Display user's summary based on their role
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "User Summary:" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Name: " << person -> getName() << endl;
    cout << "Age: " << person -> getAge() << endl;
    cout << "Gender: " << person -> getGender() << endl;
    if (employee_customer == 'E' || employee_customer == 'e') {
        Employee* employee = dynamic_cast<Employee*>(person);
        cout.imbue(locale("en_US.UTF-8"));
        cout << "Salary: $" << fixed << setprecision(2) << showpoint << put_money(static_cast<long>(employee -> getSalary() * 100), true) << endl;
    }
    cout << "----------------------------------------------" << endl;
    
    cout << endl;
    cout << "The rest of our platform is under construction, we hope to see you soon." << endl;
    
    delete person;
    return 0;
}
