#include <stdio.h>
#include <stdlib.h>


typedef struct employee{
    int ssn;
    int id;
}Employee;

typedef struct empdatabase{
    Employee ** data;
    int error;
    int size;
}EmpDatabase;

Employee * createEmployee(int id; int ssn);
EmpDatabase createSearchableEmployeeDB();
EmpDatabase insertEmp(Employee * emp, EmpDatabase database);
void insertEmp_R(Employee * insertEmp, Employee * emp);