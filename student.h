#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    char id[20];
    char name[100];
    char dob[15];
    float marks[3]; // 0: Matric, 1: Inter/Diploma, 2: Graduation
    char contact[15];
    char email[50];
    struct Student *next;
} Student;

void add_record(Student **head);
void print_records(Student *head);
void delete_record(Student **head);
void edit_record(Student *head);
Student* find_record(Student *head,char *id);
void reverse_display(Student *head);
void save_to_file(Student *head, const char *filename);
Student* load_from_file(const char *filename);

#endif