#include <bits/stdc++.h>
using namespace std;

//create employee structure
struct Employee{
    int id;
    string firstName;
    string lastName;
    string role;
    double salary;
};

//create EmployeeManagementSystem class (add,view,update,delete,list of employee)
class EmployeeManagementSystem{
    public:

        void addEmployee(int id, const string& firstName, const string& lastName, const string& role, double salary);
        void viewEmployee(int id) const;
        void updateEmployee(int id, const string& firstName, const string& lastName, const string& role, double salary);
        void deleteEmployee(int id);
        void listAllEmployees() const;

    private:
        //create map for with thier basis on id and correspoding information
        unordered_map<int,Employee> employees;

};

//create addEmployee function for adding information of employee and strore in map employees
void EmployeeManagementSystem::addEmployee(int id,const string& firstName,const string& lastName,const string& role,double salary){
    if(employees.find(id)!=employees.end()){
        cout<<"Error: Employee with ID " << id << " already exists.\n";
        return;
    }

    employees[id] = {id, firstName, lastName, role, salary};
    cout<<"Employee added successfully.\n";
} 

//create viewEmployee function for view information of employee on the basis of their id
void EmployeeManagementSystem::viewEmployee(int id) const {
    auto it = employees.find(id); //it point to the value(id) in map
    if(it == employees.end()){
        cout<<"Error: Employee with ID " << id << " not found.\n";
    }

    const Employee& emp=it->second; //here create emp that point to information of employee of id
    cout<<"ID: " << emp.id << ", Name: " << emp.firstName << " " << emp.lastName 
         << ", Role: " << emp.role << ", Salary: $" << emp.salary << "\n";

}

//create updateEmployee function for update the information of employee on the basis on id
void EmployeeManagementSystem::updateEmployee(int id, const string& firstName, const string& lastName="", const string& role="", double salary=-1){
    auto it = employees.find(id); //it point to the value(id) in map
    if(it == employees.end()){
        cout<<"Error: Employee with ID " << id << " not found.\n";
    }

    // Update fields selectively
    Employee& emp = it->second;
    if (!firstName.empty()) {
        emp.firstName = firstName;
    }
    if (!lastName.empty()) {
        emp.lastName = lastName;
    }
    if (!role.empty()) {
        emp.role = role;
    }
    if (salary >= 0) {
        emp.salary = salary;
    }

    cout<<"Employee updated successfully.\n";
}

//create deleteEmployee function for delete the information of employee on the basis on id
void EmployeeManagementSystem::deleteEmployee(int id) {
    if (employees.erase(id) == 0) {
        cout << "Error: Employee with ID " << id << " not found.\n";
    } else {
        cout << "Employee deleted successfully.\n";
    }
}

//create listAllEmployees function for show information of all employees
 void EmployeeManagementSystem::listAllEmployees() const {
    if (employees.empty()) {
        cout << "No employees found.\n";
        return;
    }
    for (const auto& [id, emp] : employees) {
        cout << "ID: " << emp.id << ", Name: " << emp.firstName << " " << emp.lastName 
             << ", Role: " << emp.role << ", Salary: $" << emp.salary << "\n";
    }
}


int main(){
    EmployeeManagementSystem ems; //ems is a object of EmployeeManagementSystem
    int choice, id;
    string firstName, lastName, role;
    double salary;

    while (true) {
        cout << "\nEmployee Management System\n";
        cout << "1. Add Employee\n2. View Employee\n3. Update Employee\n4. Delete Employee\n5. List All Employees\n6. Exit\n"; //choose a operation we have to do
        cout << "Enter your choice: ";
        cin >> choice;

        //use switch cases for perform above operations on the basis of choice number
        switch (choice) {
            case 1:  // Add Employee
                cout << "Enter ID: "; cin >> id;
                cin.ignore();
                cout << "Enter First Name: "; getline(cin, firstName);
                cout << "Enter Last Name: "; getline(cin, lastName);
                cout << "Enter Role: "; getline(cin, role);
                cout << "Enter Salary: "; cin >> salary;
                ems.addEmployee(id, firstName, lastName, role, salary);
                break;
            case 2:  // View Employee
                cout << "Enter Employee ID: "; cin >> id;
                ems.viewEmployee(id);
                break;
            case 3:  // Update Employee
                cout << "Enter ID: "; cin >> id;
                cin.ignore();
                cout << "Enter New First Name: "; getline(cin, firstName);
                cout << "Enter New Last Name: "; getline(cin, lastName);
                cout << "Enter New Role: "; getline(cin, role);
                cout << "Enter New Salary: "; cin >> salary;
                ems.updateEmployee(id, firstName, lastName, role, salary);
                break;
            case 4:  // Delete Employee
                cout << "Enter Employee ID: "; cin >> id;
                ems.deleteEmployee(id);
                break;
            case 5:  // List All Employees
                ems.listAllEmployees();
                break;
            case 6:  // Exit
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    }

}
