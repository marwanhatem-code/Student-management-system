#ifndef  SDB_H
#define  SDB_H

#include"STD.h"

/*
 - Defines the structure used to store a student's information,
 - including their ID, academic year, course IDs, and grades.
 */
typedef struct SimpleDb{
uint32 Student_ID;
uint32 Student_year;
uint32 Course1_ID;
uint32 Course1_grade;
uint32 Course2_ID;
uint32 Course2_grade;
uint32 Course3_ID;
uint32 Course3_grade;
} student;

// Returns the number of students currently stored in the database.
uint8 SDB_GetUsedSize();

// Checks whether the database has reached its maximum capacity.
bool  SDB_IsFull();

//Adds a new student to the database.
bool  SDB_AddEntry();

// Displays the information of a student identified by their ID.
bool  SDB_ReadEntry(uint32 id);

//Checks whether a student ID exists in the database.
bool  SDB_IsIdExist(uint32 id);

// Removes a student from the database using their ID.
void  SDB_DeleteEntry(uint32 id);

//Retrieves the IDs of all students currently stored in the database.
void  SDB_GetList(uint8 *count, uint32 *list);

#endif
