#include "lab11.h"

int main(void){
    EmpDatabase database = createSearchableEmployeeDB();

    for(int i = 0; i < 10; i++){
        Employee * emp = malloc(sizeof(Employee));
        emp->id = i;
        emp->ssn = i+99999999+1;
        insertEmp(emp, database);
    }
}