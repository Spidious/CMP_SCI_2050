#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"


typedef struct{
    char lastName[20], firstName[20];
    int id, position;
    float salary;
}empStruct;

void setEmployeeSalary(empStruct *emp, float salary){
    emp->salary = salary; // Equivalent to (*emp).salary = salary;
}




int main(void){
    empStruct employee;

    employee.position = 3;
    employee.id = 837412938;
    employee.salary = 85000.00;

    setEmployeeSalary(&employee, 55000);

}

