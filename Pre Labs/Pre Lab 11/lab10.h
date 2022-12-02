#include<stdio.h>
#include<stdlib.h>

typedef struct employee{
    int ssn;
    int id;
}Employee;

typedef struct empdatabase{
    Employee ** database;
    int error;
    int size;
}EmpDatabase;

EmpDatabase createSearchableEmployeeDB(Employee ** arr, int n);  
Employee * findEmpBySSN(int ssn, EmpDatabase arr);  
Employee * findEmpByID(int id, EmpDatabase arr);  
void freeEmpDatabase(EmpDatabase arr);  
int getErrorCode(EmpDatabase arr);

void sortByID(EmpDatabase * database);
void sortBySSN(EmpDatabase * database);

Employee * recursiveIDsearch(int id, int startIndex, int n, Employee ** arr);
Employee * recursiveSSNsearch(int ssn, int startIndex, int n, Employee ** arr);


// ############################ Pre Lab 11 Begin ##################################
EmpDatabase insertEmp(Employee * emp, EmpDatabase empData);