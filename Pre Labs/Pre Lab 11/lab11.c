#include "lab11.h"

Employee * CreateEmployee(int id, int ssn){
    Employee * emp; 
    emp->id = id;
    emp->ssn =ssn;
    return emp;
}

EmpDatabase createSearchableEmployeeDB(){
    EmpDatabase database;
    database.data = NULL;
    
}
