#include "SDB.h"
#include "SDBAPP.h"
#include <stdio.h>


bool exitProgram = false;



void SDB_APP(){
    uint8 choice;
    do{
        printf("\n            Student Management System           \n"
            "1. Add Entry:\n"
            "2. Get used size:\n"
            "3. Read student data:\n"
            "4. Get list:\n"
            "5. Check id ID exists:\n"
            "6. Delete Entry:\n"
            "7. Check if Database is full:\n"
            "0. Exit:\n"
        );
        scanf("%d",&choice);
        SDB_action(choice);

    }while(exitProgram == false);
}

void SDB_action(uint8 choice){


switch(choice){
    uint32 id;

    case 1: 
    SDB_AddEntry();
        break;
    case 2:
    printf("Number of students in database: %d",SDB_GetUsedSize());
        break;
    case 3: 
    printf("Please Enter Student ID: ");
    scanf("%d",&id);
    SDB_ReadEntry(id);
        break;
    case 4:
    {
    uint8 count;
    uint32 list[10];
    SDB_GetList(&count, list);
    for(uint32 i = 0 ; i < count ; i++){
        printf("        Student %d | ID: %d     \n", i+1, list[i]);
    }
    printf("--------------------------------------\n"
        "Total Students: %d\n", count);
        break;
    }
    case 5:
    printf("Please Enter Student ID: ");
    scanf("%d",&id);
    if(SDB_IsIdExist(id)) printf("ID exists in the database!\n");
    else printf("ID doesn't exist in the database!\n");
    break;
    case 6:
    printf("Please Enter Student ID: ");
    scanf("%d",&id);
    SDB_DeleteEntry(id);
    break;
    case 7:
    if(SDB_IsFull()) printf("Database is full !\n");
    else printf("Databse is not full !\n");
    break;
    case 0:
    exitProgram = true ;
    break;
    default:
    printf("Please enter a valid choice!\n");
    break;
}
}