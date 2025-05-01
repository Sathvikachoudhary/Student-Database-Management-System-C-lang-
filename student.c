#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include <ctype.h>

void save_cnts(int alpha_cnt[26])
{
    FILE *file = fopen("alpha_counts.dat", "wb");
    if (file != NULL)
    {
        fwrite(alpha_cnt, sizeof(int), 26, file);
        fclose(file);
    }
}

void load_cnts(int alpha_cnt[26])
{
    FILE *file = fopen("alpha_counts.dat", "rb");
    if (file != NULL)
    {
        fread(alpha_cnt, sizeof(int), 26, file);
        fclose(file);
    }
}

void generate_id(char *name,char *id)
{
        static int alpha_cnt[26]={0};
        load_cnts(alpha_cnt);
        char ch=toupper(name[0]);
        int index=ch-'A';
        alpha_cnt[index]++;
        sprintf(id,"V24HE5%c%d",ch,alpha_cnt[index]);
        save_cnts(alpha_cnt);
}
void add_record(Student **head)
{
    Student *new_node = (Student *)malloc(sizeof(Student));
    if(!new_node)
    {
            printf("mem allocation failed\n");
            return;
    }
    printf("Enter  Name, DOB, Marks(3), Contact, Email:\n");
    getchar();
    fgets(new_node->name, sizeof(new_node->name), stdin);
    int len = strlen(new_node->name);
    if (len > 0 && new_node->name[len - 1] == '\n')
    {
        new_node->name[len - 1] = '\0';
    }
    scanf("%s %f %f %f %s %s",new_node->dob,
          &new_node->marks[0], &new_node->marks[1], &new_node->marks[2],
          new_node->contact, new_node->email);
    generate_id(new_node->name,new_node->id);
    new_node->next = *head;
    *head = new_node;
}

void print_records(Student *head)
{
    Student *temp = head;
    while (temp)
    {
        printf("ID:%s\n Name: %s\n DOB: %s\n Marks: %.2f %.2f %.2f\n Contact: %s\n Email: %s\n",
                temp->id,temp->name, temp->dob,
               temp->marks[0], temp->marks[1], temp->marks[2],
               temp->contact, temp->email);
        temp = temp->next;
        printf("\n\n");
    }
}
void delete_record(Student **head)
{
    char id1[10];
    printf("Enter ID to delete: ");
    scanf("%s", id1);
    Student *temp = find_record(*head, id1);
    if (!temp)
    {
        printf("Record not found.\n");
        return;
    }
    if (*head == temp)
    {
        *head = temp->next;
    }
    else
    {
        Student *prev = *head;
        while (prev && prev->next != temp)
        {
            prev = prev->next;
        }
        if (prev)
        {
            prev->next = temp->next;
        }
    }
    free(temp);
    printf("Record deleted successfully.\n");
}


Student* find_record(Student *head,char *id1)
{
    while (head)
    {
        if (strcmp(head->id, id1) == 0)
        {
                return head;
        }
        head = head->next;
     }
    return NULL;
}

void edit_record(Student *head)
{
    char id[20];
    printf("Enter ID to edit: ");
    scanf("%s", id);
    Student *s = find_record(head, id);
    if (!s)
    {
        printf("Student not found.\n");
        return;
    }
    int choice;
    printf("1-Name 2-DOB 3-Marks 4-Contact 5-Email: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1: scanf("%s", s->name); break;
        case 2: scanf("%s", s->dob); break;
        case 3: scanf("%f %f %f", &s->marks[0], &s->marks[1], &s->marks[2]); break;
        case 4: scanf("%s", s->contact); break;
        case 5: scanf("%s", s->email); break;
    }
}

void reverse_display(Student *head)
{
    if (head == NULL)
            return;
    reverse_display(head->next);
    printf("ID: %s, Name: %s\n", head->id, head->name);
}
~                                           