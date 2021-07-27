/******************************************************************************

Welcome to Employee Management System coded by Adarsh in c++ language.
There is no UI setup build here.Everything happens on command line output.I tried what i can.
Don't know PostgreSQL.I worked on msql only.Used array to store data here.

*******************************************************************************/
#include <iostream>
#include <string>
#include <conio.h>
#include <string.h>

#define max 20
using namespace std;

struct employee 
{
    string name;
    long int code;
    string department;
    int exp;
    int age;
};

int num;
void menu();

employee emp[max], tempemp[max];

//Building The Employee Table function
void details()
{
    cout << "Build Employee Table\n";
    cout << "Maximum Entries can be "
         << max << "\n";
    cout << "Enter the number of "
         << "Entries required";
    cin >> num;
    if (num > 20) 
    {
        cout << "Maximum number of "
             << "Entries are 20\n";
        num = 20;
    }
    cout << "Enter the following data:\n";
    for (int i = 0; i < num; i++) {
        cout << "Name ";
        cin >> emp[i].name;
        cout << "Employee ID ";
        cin >> emp[i].code;
        cout << "Department ";
        cin >> emp[i].department;
        cout << "Experience ";
        cin >> emp[i].exp;
        cout << "Age ";
        cin >> emp[i].age;
    }
    menu();
}

//Inserting an employee function
void insert()
{
    if (num < max) 
    {
        int i = num;
        num++;

        cout << "Enter the Employee information\n ";
        cout << "Name ";
        cin >> emp[i].name;
        cout << "Employee ID ";
        cin >> emp[i].code;
        cout << "Department ";
        cin >> emp[i].department;
        cout << "Experience ";
        cin >> emp[i].exp;
        cout << "Age ";
        cin >> emp[i].age;
    }
    else 
    {
        cout << "Employee Table Full\n";
    }
    menu();
}

void deleteIndex(int i)
{
    for (int j = i; j < num - 1; j++) {
        emp[j].name = emp[j + 1].name;
        emp[j].code = emp[j + 1].code;
        emp[j].department = emp[j + 1].department;
        emp[j].exp = emp[j + 1].exp;
        emp[j].age = emp[j + 1].age;
    }
    return;
}
// Delete an employee or department function
void deleteRecord()
{
    cout << "Enter the Employee ID "
         << "to Delete Record";
    int code;
    cin >> code;
    for (int i = 0; i < num; i++) 
    {
        if (emp[i].code == code) 
        {
            deleteIndex(i);
            num--;
            break;
        }
    }
    menu();
}

//Search a data based on field function
void searchRecord()
{
    cout << "Enter the Employee"
         << " ID to Search Record";
    int code;
    cin >> code;
    for (int i = 0; i < num; i++) 
    {
        if (emp[i].code == code) 
        {
            cout << "Name "
                 << emp[i].name << "\n";
            cout << "Employee ID "
                 << emp[i].code << "\n";
            cout << "Department "
                 << emp[i].department << "\n";
            cout << "Experience "
                 << emp[i].exp << "\n";
            cout << "Age "
                 << emp[i].age << "\n";
            break;
        }
    } 
    menu();
}

//Sort an employee and department list function
void sort()
{
for(int i = 1; i < num; i++)
for(int j = 0; j < num - i; j++)
if(emp[j].code < emp[j+1].code)
    {
    employee temp = emp[j];
    emp[j] = emp[j+1];
    emp[j+1] = temp;
    }
    cout<< "Sorted Successfully!!\n";
    menu();
}

void menu()
{
 
    cout << "-------------------------"
         << "ADARSH Employee "
         << "Management System"
         << "-------------------------\n\n";
 
    cout << "Availiable Options:\n\n";
    cout << "Build Employee Table                    (1)\n";
    cout << "Create new employees and departments    (2)\n";
    cout << "Delete an employee or department        (3)\n";
    cout << "Search a data based on field            (4)\n";
    cout << "Sort based on employee                  (5)\n";
    cout << "Exit                                    (6)\n";
 
    int option;
    cin >> option;
    if (option == 1)
    {
        details();
    }
    else if (option == 2) {
        insert();
    }
    else if (option == 3) {
        deleteRecord();
    }
    else if (option == 4) {
        searchRecord();
    }
    else if (option == 5) {
        sort();
    }
    else if (option == 6) {
        return;
    }
    else {
        cout << "Available Options"
             << " are 1/2/3/4/5/6 Only";
        menu();
    }
}
 
int main()
{
    menu();
    return 0;
}

