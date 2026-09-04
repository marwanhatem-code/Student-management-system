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

bool SDB_IsIdExist(uint32 id){

    for(uint32 i = 0 ; i < counter ; i++){
        if(dataBase[i].Student_ID == id){
            return true;
    }
} 
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
} while (dataBase[counter].Course1_grade < 0 || dataBase[counter].Course1_grade > 100);  

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
} while (dataBase[counter].Course2_grade < 0 || dataBase[counter].Course2_grade > 100);

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
} while (dataBase[counter].Course3_grade < 0 || dataBase[counter].Course3_grade > 100);

        printf("student sucessfully added!");
        counter++ ;
        return true;
    }
}

void SDB_DeleteEntry(uint32 id){
    bool found = false;
    for(uint32 i = 0 ; i < counter ; i++){
        if(dataBase[i].Student_ID == id){
            found = true;
            for (uint32 j = i ; j < counter - 1 ; j++){
            dataBase[j] = dataBase[j+1];
            }
            break;
    }
}   
   if(found){
    printf("Student deleted sucessfully!");
    counter--;
    return;
   }

   else{
     printf("Student not found!");
    return ;
   }
}

bool SDB_ReadEntry(uint32 id){
    bool found = false;
    uint32 index;
    for(uint32 i = 0 ; i < counter ; i++){
        if(dataBase[i].Student_ID == id){
            found = true;
            index = i ;
            break;
    }
}   
    if(found){
        printf("Student data:\n");
        printf("Student ID: %d\n",dataBase[index].Student_ID);
        printf("Student Year: %d\n",dataBase[index].Student_year);
        printf("Student Course 1 ID: %d\n",dataBase[index].Course1_ID);
        printf("Student Course 1 grade: %d\n",dataBase[index].Course1_grade);
        printf("Student Course 2 ID: %d\n",dataBase[index].Course2_ID);
        printf("Student Course 2 grade: %d\n",dataBase[index].Course2_grade);
        printf("Student Course 3 ID: %d\n",dataBase[index].Course3_ID);
        printf("Student Course 3 grade: %d\n",dataBase[index].Course3_grade);
        return found;
    }
    else{
        printf("Student ID not found!");
        return found;
    }
}

void  SDB_GetList(uint8 *count, uint32 *list){
    *count = counter;
    for(uint32 i = 0 ; i < counter ; i++){
        *list = dataBase[i].Student_ID;
        list++;
    }
}



