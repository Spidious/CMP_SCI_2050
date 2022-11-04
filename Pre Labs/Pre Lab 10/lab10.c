#include "lab10.h"

// Create Searchable Employee DB
EmpDatabase createSearchableEmployeeDB(Employee ** arr, int n){
    EmpDatabase array;
    array.database = arr;

    array.size = n;
    array.error = 0;
    return array;
}

// sort by id
void sortByID(EmpDatabase * database){
    int n = database->size;
    Employee * hold;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(database->database[j+1]->id < database->database[j]->id){
                hold = database->database[j];
                database->database[j] = database->database[j+1];
                database->database[j+1] = hold;
            }
        }
    }
}

// sort by ssn
void sortBySSN(EmpDatabase * database){
    int n = database->size;
    Employee * hold;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(database->database[j+1]->ssn < database->database[j]->ssn){
                hold = database->database[j];
                database->database[j] = database->database[j+1];
                database->database[j+1] = hold;
            }
        }
    }
}



Employee * findEmpByID(int id, EmpDatabase arr){
    Employee * emp = recursiveIDsearch(id, 0, arr.size-1, arr.database);
    if(!emp) arr.error = 1;
    return emp;
}

Employee * findEmpBySSN(int ssn, EmpDatabase arr){
    Employee * emp = recursiveSSNsearch(ssn, 0, arr.size-1, arr.database);
    if(!emp) arr.error = 1;
    return emp;
}


Employee * recursiveIDsearch(int id, int startIndex, int endIndex, Employee ** arr){
    int middleIndex = startIndex+(endIndex-startIndex)/2;


    if(id < arr[middleIndex]->id){
        return recursiveIDsearch(id, startIndex, middleIndex, arr);
    }
    else if(id > arr[middleIndex]->id){
        if(startIndex == middleIndex) middleIndex+=1;
        return recursiveIDsearch(id, middleIndex, endIndex, arr);
    }
    else if(id == arr[middleIndex]->id){
        return arr[middleIndex];
    }
    else{
        return NULL;
    }
}


Employee * recursiveSSNsearch(int ssn, int startIndex, int endIndex, Employee ** arr){
    int middleIndex = startIndex+(endIndex-startIndex)/2;


    if(ssn < arr[middleIndex]->ssn){
        return recursiveSSNsearch(ssn, startIndex, middleIndex, arr);
    }
    else if(ssn > arr[middleIndex]->ssn){
        if(startIndex == middleIndex) middleIndex+=1;
        return recursiveSSNsearch(ssn, middleIndex, endIndex, arr);
    }
    else if(ssn == arr[middleIndex]->ssn){
        return arr[middleIndex];
    }
    else{
        return NULL;
    }
}