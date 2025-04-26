////////////////////////////////////////////////////////////////////////
//
// File           : p2-support.h
// Description    : Header file for project2
// Author         : Aaron Tuck
// Date           : April 4, 2025
// Notes          : ***Type bug fixes/other with dates for your records

#ifndef P2Header  // To prevent double inclusion of header
#define P2Header  // To prevent double inclusion of header

#include <stdio.h>
#define byID 1
#define byNAME 2
#define dbSIZE 100
#define idSIZE 6
#define nameSIZE 10
#define emailSIZE 20

typedef struct date  // do not modify
{
  int day;
  int month;
  int year;
} date;

typedef struct Employee {
  char ID[idSIZE];
  char first_name[nameSIZE];
  char last_name[nameSIZE];
  char email[emailSIZE];
  double salary;
  struct date hire_date;
  // declare other members
} employee, *employee_ptr;

typedef struct DataBase {
  employee_ptr emp;  // a pointer to first element of empoloyee array
  int total;         // number of employees in database
}* dataBase_ptr;

// Functional Prototypes

// Function     : initialize
// Description  : This function creates an array in the database
//                then initalializes each array elemet with the data
//                in the given file
// Inputs       : a pointer to DataBase struct
// Output       : none
void initialize(dataBase_ptr db);

// Function     : create_record
// Description  : Creates and adds a new employee record to the database
// Inputs       : Employee data fields and pointer to the database
// Output       : None
void create_record(char* ID, char* first_name, char* last_name, char* email,
                   double salary, date hire_date,
                   dataBase_ptr);

// Function     : print_title
// Description  : Prints the formatted column header for displaying employees
// Inputs       : None
// Output       : None
void print_title();

// Function     : display_menu
// Description  : Displays the menu and handles user interaction
// Inputs       : Pointer to the database
// Output       : None
void display_menu(dataBase_ptr);

// Function     : display_data
// Description  : Displays all employee records in the database
// Inputs       : Pointer to the database
// Output       : None
void display_data(dataBase_ptr db);

// Function     : sortId
// Description  : Sorts the database by ID by lowest to highest
// Inputs       : Pointer to the database
// Output       : None
void sortId(dataBase_ptr db);

// Function     : searchIds
// Description  : Searches for a single employee by ID and displays result
// Inputs       : Pointer to the database
// Output       : None
void searchIds(dataBase_ptr db);

// Function     : searchByLast
// Description  : Searches for employees by last name
// Inputs       : Pointer to the database
// Output       : None
void searchByLast(dataBase_ptr db);

// Function     : deleteID
// Description  : Deletes an employee record by ID
// Inputs       : Pointer to the database
// Output       : None
void deleteID(dataBase_ptr db);

// Function     : save
// Description  : Saves the current state of the database to "database_updated"
// Inputs       : Pointer to the database
// Output       : None
void save(dataBase_ptr db);

// Function     : cleanFile
// Description  : Frees all dynamically allocated memory in the database
// Inputs       : Pointer to the database
// Output       : None
void cleanFile(dataBase_ptr db);

#endif  // To prevent double inclusion of header
