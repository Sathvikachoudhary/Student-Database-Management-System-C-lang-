# STUDENT DATABASE MANAGEMENT SYSTEM


## 📚PROJECT OVERVIEW:
This project is a Student Database Management System written in the C language. It uses singly linked lists to store student records during runtime, and supports saving/loading data from a text file. Each student is assigned a unique auto-generated ID based on the first letter of their name and the count of previous students with the same initial.

## 📋 KEY FEATURES:

- 📌 Auto-generated student ID (e.g., V24HE5A1)
- ➕ Add new student records
- 📄 Display all student records
- 📝 Edit a student’s details (Name, DOB, Marks, etc.)
- ❌ Delete student record by ID
- 🔍 Search student by ID
- 🔁 Reverse display using recursion
- 💾 Save and load records from a text file
- 📂 Persistent ID generation using a binary file

## 📂FILE STRUCTURE:                                   
-	main.c -> Main menu-driven program logic 
-	student.c -> Functions: add, delete, find, edit, reverse, etc.
-	savefile.c -> File save/load operations using text & binary files
-	student.h -> Struct definition & function declarations
-	data.txt -> Text file for saving student records
-	alpha_counts.data -> Binary file for persistent ID generation count
-	makefile -> Automates compilation of all files       
 
## ⚙️ HOW TO COMPILE AND RUN:-

### ✅ METHOD 1: Using makefile (Recommended):-

Make sure the following `makefile` is in the same folder:

-	a.out: main.o student.o savefile.o 
cc -g main.o student.o savefile.o
-	main.o: main.c
  cc -c main.c
-	student.o: student.c 
cc -c student.c
-	savefile.o: savefile.c
  cc -c savefile.c

-To compile the program:  make
-To run the program: ./a.out

### ✅ METHOD 2: Manual Compilation (Alternative):-

-	gcc main.c student.c savefile.c -o student_db
./student_db

## 🖥️ MENU OPTIONS:-
1.	a/A: Add a new student
2.	p/P: Print all student records
3.	s/S: Save data to file
4.	d/D: Delete a student by ID
5.	e/E: Edit a student's details
6.	f/F: Find a student by ID
7.	r/R: Reverse display 
8.	q/Q: Quit the program

# Happy Coding.....!

