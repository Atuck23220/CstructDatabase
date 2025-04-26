# Employee Database System (`cmsc257-p2`)

## Overview
This project implements a simple **Employee Database System** written in C,  
designed for CMSC 257 - Computer Systems coursework.

Developed by **Aaron Tuck** — April 2025.

The system allows users to:
- Load an initial employee database from a file.
- View, search, sort, modify, and save employee records.
- Interact through a clean, menu-driven command-line interface.

---

## Features
- **Load Employee Records**
  - Reads from a file called `database` or a user-provided filename.

- **Interactive Menu System**
  - Sort employees by **ID**.
  - Sort employees by **Hire Date**.
  - Display all employees.
  - Search employees by **ID**.
  - Search employees by **Last Name**.
  - Delete an employee by **ID**.
  - Save the database to a file called `database_updated`.

- **Memory Management**
  - Dynamically allocates and frees memory for employee records.

- **File Management**
  - Safely handles missing or incorrect file names.
  - Properly closes all files upon exit.

- **Bitwise-safe Utilities**
  - Careful handling of string sizes to avoid buffer overflows.
  - Uses GNU extensions (`strcasestr`) where needed.

---

## File Structure

| File | Description |
|:---|:---|
| `cmsc257-p2.c` | Main driver program. Handles file input and menu launching. |
| `p2-support.c` | Implementation of employee database operations (CRUD, sorting, searching). |
| `p2-support.h` | Header file with structure definitions and function prototypes. |
| `Makefile` | Automates the compilation process. |

---

## Compilation

Use the provided `Makefile` to compile the project easily:

```bash
make
