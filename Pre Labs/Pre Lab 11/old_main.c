#include "lab10.h"

#define SIZE 10

int main(void){
    Employee ** array = malloc(SIZE * sizeof(Employee *));


    for(int i = 0; i < SIZE; i++){
        Employee * emp = malloc(sizeof(Employee));
        emp->id = i;
        emp->ssn = i+99999999+1;
        array[i] = emp;
    }

    // Call createsearchableEmployeeDB
    EmpDatabase database = createSearchableEmployeeDB(array, SIZE);

    // find ID
    sortByID(&database);
    puts("Testing ID Search");
    for(int i = 0; i < SIZE; i++) if(findEmpByID(i, database)->id != i) puts("findbyID failed");
    puts("Passed!");

    // find SSN
    sortBySSN(&database);
    puts("testing SSN Search");
    for(int i = 0; i < SIZE; i++) if(findEmpBySSN(i+99999999+1, database)->ssn != i+99999999+1) puts("findbySSN failed");
    puts("Passed!");
}