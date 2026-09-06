#include "SDB.h"
#include "stdio.h"

// Maximum number of students supported by the database.
student dataBase[10];

//Tracks the number of currently stored students.
uint8   counter = 0;


// Returns the number of students currently stored in the database. 
uint8 SDB_GetUsedSize(){
    return counter;
}

/*
 - Checks whether the database has reached its maximum capacity.
 - Returns true if all available entries are occupied; otherwise returns false.
 */
bool SDB_IsFull(){
    if(counter == 10)
     return true;

    else
     return false;
}

/*
 - Checks whether a student with the specified ID exists in the database.
  Returns true if the ID is found and false otherwise.
 */
bool SDB_IsIdExist(uint32 id){

    for(uint32 i = 0 ; i < counter ; i++){
        if(dataBase[i].Student_ID == id){
            return true;
    }
} 
return false;
}


/*
 - Adds a new student to the database.
 - The function checks that the database is not full and that the student ID
   is unique before collecting and storing the student's information.
 - Returns true when the student is successfully added, otherwise false.
 */
bool SDB_AddEntry(){

    int32 input = 0 ;

/* Prevent adding a student when the database has reached its capacity. */
    if(SDB_IsFull()){
    printf("Faild To Add Student (Data Base Is Full!)\n");
    return false;
    }
    else{

        /* do-while validation loop for invalid inputs. */
        do{
        printf("Please enter student ID:\n");
        scanf("%d",&input);

        if(input <= 0){
        printf("please enter a valid ID!\n\n");
        }

        }while(input <= 0);
        dataBase[counter].Student_ID = input ;

        /* Student IDs must be unique within the database. */
        if (SDB_IsIdExist(dataBase[counter].Student_ID)){
             printf("Faild To Add Student (Duplicate ID!)\n");
             return false;
        }
        
        do {
        printf("Please enter student year:\n");
        scanf("%d",&input);
        if (input <= 0)
        {
            printf("Please enter a valid year!\n\n");
        }
        } while(input <= 0);
        dataBase[counter].Student_year = input ;
           
/* do-while validation loop for invalid inputs. */
do {
        printf("Please enter student Course 1 ID:\n");
        scanf("%d",&input);
        if (input<=0)
        {
            printf("please enter a valid course ID!\n\n");
        }
        
} while(input <= 0);
dataBase[counter].Course1_ID = input;


do {
        printf("Please enter student Course 1 Grade:\n");
        scanf("%d",&input);
        if(input < 0 || input > 100){
            printf("please enter a valid course grade!\n\n");
        }
} while (input < 0 || input > 100);  
dataBase[counter].Course1_grade = input ; 

/* Repeat the same validation process for Course 2. */
do {
        printf("Please enter student Course 2 ID:\n");
        scanf("%d",&input);
        if (input<=0)
        {
            printf("please enter a valid course ID!\n\n");
        }
} while(input <= 0);
dataBase[counter].Course2_ID = input ;

do {
        printf("Please enter student Course 2 Grade:\n");
        scanf("%d",&input);
        if(input < 0 || input > 100){
            printf("please enter a valid course grade!\n\n");
        }
} while (input < 0 || input > 100);
dataBase[counter].Course2_grade = input ; 

/* Repeat the same validation process for Course 3. */
do {
        printf("Please enter student Course 3 ID:\n");
        scanf("%d",&input);
        if (input<=0)
        {
            printf("please enter a valid course ID!\n\n");
        }
} while(input <= 0);
dataBase[counter].Course3_ID = input ;

do {
        printf("Please enter student Course 3 Grade:\n");
        scanf("%d",&input);
        if(input < 0 || input > 100){
            printf("please enter a valid course grade!\n\n");
        }
} while (input < 0 || input > 100);
dataBase[counter].Course3_grade = input ;

        printf("student sucessfully added!\n");

        /* Increase the number of stored students after a successful addition. */
        counter++ ;
        return true;
    }
}

/*
 - Removes a student from the database using their student ID.
 - When the student is found, subsequent entries are shifted left to fill
   the empty position and the database size is decreased.
 */
void SDB_DeleteEntry(uint32 id){
    bool found = false;

    /* for loop to find the ID to be delted from database. */
    for(uint32 i = 0 ; i < counter ; i++){
        if(dataBase[i].Student_ID == id){
            found = true;

            /* for loop to shift left all entries to fill the deleted position. */
            for (uint32 j = i ; j < counter - 1 ; j++){
            dataBase[j] = dataBase[j+1];
            }
            break;
    }
}   
   if(found){
    printf("Student deleted sucessfully!\n");

    /* Update the number of valid entries after deletion. */
    counter--;
    return;
   }

   else{
     printf("Student not found!\n");
    return ;
   }
}

/*
 - Searches for a student using their ID and displays their stored information.
 - Returns true if the student exists and false if the ID cannot be found.
 */
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
        printf("Student ID: %u\n",dataBase[index].Student_ID);
        printf("Student Year: %u\n",dataBase[index].Student_year);
        printf("Student Course 1 ID: %u\n",dataBase[index].Course1_ID);
        printf("Student Course 1 grade: %u\n",dataBase[index].Course1_grade);
        printf("Student Course 2 ID: %u\n",dataBase[index].Course2_ID);
        printf("Student Course 2 grade: %u\n",dataBase[index].Course2_grade);
        printf("Student Course 3 ID: %u\n",dataBase[index].Course3_ID);
        printf("Student Course 3 grade: %u\n",dataBase[index].Course3_grade);
        return found;
    }
    else{
        printf("Student ID not found!");
        return found;
    }
}

/*
 - Retrieves the number of stored students and copies their IDs into the
 - array provided by the caller.
 */
void  SDB_GetList(uint8 *count, uint32 *list){
    *count = counter;
    for(uint32 i = 0 ; i < counter ; i++){
        *list = dataBase[i].Student_ID;
        list++;
    }
}



