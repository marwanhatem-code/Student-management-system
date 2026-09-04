#include "SDB.h"
#include "stdio.h"

student dataBase[10];
uint8   counter = 0;

uint8 SDB_GetUsedSize(){
    return counter;
}

bool SDB_IsFull(){
    if(counter == 10)
     return true;

    else
     return false;
}

bool SDB_AddEntry(){

    if(SDB_IsFull()){
    printf("Faild To Add Student (Data Base Is Full!)");
    return false;
    }
    else{
        printf("Please enter student ID:\n");
        scanf("%d",&dataBase[counter].Student_ID);

        if (SDB_IsIdExist(dataBase[counter].Student_ID)){
             printf("Faild To Add Student (Duplicate ID!)");
             return false;
        }
        
        do {
        printf("Please enter student year:\n");
        scanf("%d",&dataBase[counter].Student_year);
        if (dataBase[counter].Student_year <= 0)
        {
            printf("Please enter a valid year!");
        }
        } while(dataBase[counter].Student_year <= 0);
           

do {
        printf("Please enter student Course 1 ID:\n");
        scanf("%d",&dataBase[counter].Course1_ID);
        if (dataBase[counter].Course1_ID<=0)
        {
            printf("please enter a valid course ID!");
        }
        
} while(dataBase[counter].Course1_ID <= 0);


do {
        printf("Please enter student Course 1 Grade:\n");
        scanf("%d",&dataBase[counter].Course1_grade);
} while (dataBase[counter].Course1_grade < 0);  

do {
        printf("Please enter student Course 2 ID:\n");
        scanf("%d",&dataBase[counter].Course2_ID);
        if (dataBase[counter].Course2_ID<=0)
        {
            printf("please enter a valid course ID!");
        }
} while(dataBase[counter].Course2_ID <= 0);

do {
        printf("Please enter student Course 2 Grade:\n");
        scanf("%d",&dataBase[counter].Course2_grade);
} while (dataBase[counter].Course2_grade < 0);

do {
        printf("Please enter student Course 3 ID:\n");
        scanf("%d",&dataBase[counter].Course3_ID);
        if (dataBase[counter].Course3_ID<=0)
        {
            printf("please enter a valid course ID!");
        }
} while(dataBase[counter].Course3_ID <= 0);

do {
        printf("Please enter student Course 3 Grade:\n");
        scanf("%d",&dataBase[counter].Course3_grade);
} while (dataBase[counter].Course3_grade < 0);

        printf("student sucessfully added!");
        return true;
    }


}
