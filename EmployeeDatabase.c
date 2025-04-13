#define _GNU_SOURCE  // strcasestr is a nonstandard GNU extension,
// we need this line while serching for matching last name
#include "p2-support.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_record(char* ID, char* first_name, char* last_name, char* email,
                   double salary, date hire_date, dataBase_ptr db) {
  int i = db->total;

  strncpy(db->emp[i].ID, ID, idSIZE - 1);
  db->emp[i].ID[idSIZE - 1] = '\0';

  strncpy(db->emp[i].first_name, first_name, nameSIZE - 1);
  db->emp[i].first_name[nameSIZE - 1] = '\0';

  strncpy(db->emp[i].last_name, last_name, nameSIZE - 1);
  db->emp[i].last_name[nameSIZE - 1] = '\0';

  strncpy(db->emp[i].email, email, emailSIZE - 1);
  db->emp[i].email[emailSIZE - 1] = '\0';

  db->emp[i].salary = salary;
  db->emp[i].hire_date = hire_date;

  db->total++;
}

void print_title() {
  printf("No. ID    Name          Email        Salary     Hire Date\n");
  printf("--- ----- ------------- ------------ ---------- --/--/----\n");
}

void save(dataBase_ptr db) {
  FILE* dbfu;
  dbfu = fopen("database_updated", "w");  // open an Std IO file to write into
  if (dbfu == NULL) {
    printf("File cannot be created");
    return;
  }
  for (int i = 0; i < db->total; i++) {
    fprintf(dbfu, "%s %s %s %s %.2f %d/%d/%04d\n", db->emp[i].ID,
            db->emp[i].first_name, db->emp[i].last_name, db->emp[i].email,
            db->emp[i].salary, db->emp[i].hire_date.month,
            db->emp[i].hire_date.day, db->emp[i].hire_date.year);
  }

  fclose(dbfu);  // close file after writing
  return;
}

void display_data(dataBase_ptr db) {
  print_title();

  for (int i = 0; i < db->total; i++) {
    char full_name[14];
    snprintf(full_name, sizeof(full_name), "%s %s", db->emp[i].first_name,
             db->emp[i].last_name);
    full_name[13] = '\0';

    printf("%-3d %05d %-13.13s %-12.12s $%9.2f %02d/%02d/%04d\n", i,
           atoi(db->emp[i].ID), full_name, db->emp[i].email, db->emp[i].salary,
           db->emp[i].hire_date.month, db->emp[i].hire_date.day,
           db->emp[i].hire_date.year);
  }
}

int compareId(const void* one, const void* two) {
  const employee* emp1 = (const employee*)one;
  const employee* emp2 = (const employee*)two;

  int iD1 = atoi(emp1->ID);
  int iD2 = atoi(emp2->ID);

  return iD1 - iD2;
}

void sortId(dataBase_ptr db) {
  qsort(db->emp, db->total, sizeof(employee), compareId);
}

int compareByDate(const void* one, const void* two) {
  const employee* emp1 = (const employee*)one;
  const employee* emp2 = (const employee*)two;

  date date1 = emp1->hire_date;
  date date2 = emp2->hire_date;

  if (date1.year != date2.year) {
    return date1.year - date2.year;
  }
  if (date1.month != date2.month) {
    return date1.month - date2.month;
  }
  return date1.day - date2.day;
}

void sortByDate(dataBase_ptr db) {
  qsort(db->emp, db->total, sizeof(employee), compareByDate);
}

void searchIds(dataBase_ptr db) {
  char idInput[idSIZE];
  printf("Enter the ID you need to locate\n");
  scanf("%s", idInput);

  for (int i = 0; i < db->total; i++) {
    if (atoi(db->emp[i].ID) == atoi(idInput)) {
      print_title();
      char full_name[14];
      snprintf(full_name, sizeof(full_name), "%s %s", db->emp[i].first_name,
               db->emp[i].last_name);
      full_name[13] = '\0';

      printf("%-3d %05d %-13.13s %-12.12s $%9.2f %02d/%02d/%04d\n", i,
             atoi(db->emp[i].ID), full_name, db->emp[i].email,
             db->emp[i].salary, db->emp[i].hire_date.month,
             db->emp[i].hire_date.day, db->emp[i].hire_date.year);
      return;
    }
  }
  printf("Employee ID not found.\n");
}

void searchByLast(dataBase_ptr db) {
  char lastName[nameSIZE];
  printf("Enter the last name you need to locate\n");
  scanf("%s", lastName);
  int count = 0;

  for (int i = 0; i < db->total; i++) {
    if (strcasestr(db->emp[i].last_name, lastName) != NULL) {
      if (count == 0) {
        print_title();
      }

      char full_name[14];
      snprintf(full_name, sizeof(full_name), "%s %s", db->emp[i].first_name,
               db->emp[i].last_name);
      full_name[13] = '\0';

      printf("%-3d %05d %-13.13s %-12.12s $%9.2f %02d/%02d/%04d\n", i,
             atoi(db->emp[i].ID), full_name, db->emp[i].email,
             db->emp[i].salary, db->emp[i].hire_date.month,
             db->emp[i].hire_date.day, db->emp[i].hire_date.year);
      count++;
    }
  }
  if (count == 0) {
    printf("Employee last name not found.\n");
  }
}

void deleteID(dataBase_ptr db) {
  char idInput[idSIZE];
  printf("Enter the ID you need to delete\n");
  scanf("%s", idInput);

  for (int i = 0; i < db->total; i++) {
    if (atoi(db->emp[i].ID) == atoi(idInput)) {
      char full_name[14];
      snprintf(full_name, sizeof(full_name), "%s %s", db->emp[i].first_name,
               db->emp[i].last_name);
      full_name[13] = '\0';

      printf("The following employee is deleted:\n");
      print_title();
      printf("%-3d %05d %-13.13s %-12.12s $%9.2f %02d/%02d/%04d\n", i,
             atoi(db->emp[i].ID), full_name, db->emp[i].email,
             db->emp[i].salary, db->emp[i].hire_date.month,
             db->emp[i].hire_date.day, db->emp[i].hire_date.year);

      for (int j = i; j < db->total - 1; j++) {
        db->emp[j] = db->emp[j + 1];
      }
      db->total--;
      return;
    }
  }
  printf("Employee ID to delete not found.\n");
}

void cleanFile(dataBase_ptr db) {
  free(db->emp);
  free(db);
}

void display_menu(struct DataBase* db) {
  int input = 0;
  while (input != 8) {
    puts("\n**************************************************************");
    printf("********** Employee Database - Total Employees: %03d **********\n",
           db->total);
    puts("**************************************************************\n");

    puts("Choose one of the menu options below:");
    puts("1. Sort by ID");
    puts("2. Sort by Hire Date");
    puts("3. Display all employees");
    puts("4. Search employees by ID");
    puts("5. Search employees by Last Name");
    puts("6. Delete employee by ID");
    puts("7. Save");
    puts("8. Exit");

    scanf("%d", &input);

    switch (input) {
      case 1:
        sortId(db);
        break;
      case 2:
        sortByDate(db);
        break;
      case 3:
        display_data(db);
        break;
      case 4:
        searchIds(db);
        break;
      case 5:
        searchByLast(db);
        break;
      case 6:
        deleteID(db);
        break;
      case 7:
        save(db);
        break;
      case 8:
        printf("Bye!\n");
        cleanFile(db);
        break;
    }
  }
}
