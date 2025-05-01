#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main() {
    Student *head = load_from_file("data.txt");
    char choice, id[20];

    while (1) {
        printf("\na/A: Add | p/P: Print | s/S: Save | d/D: Delete\n");
        printf("e/E: Edit | f/F: Find | r/R: Reverse | q/Q: Quit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case 'a':
            case 'A': add_record(&head);
                                break;
            case 'p':
            case 'P': print_records(head);
                                break;
            case 's':
            case 'S': save_to_file(head, "data.txt");
                                break;
            case 'd':
            case 'D':delete_record(&head);
                               break;
            case 'e':
            case 'E': edit_record(head);
                                break;
            case 'f':
            case 'F':printf("enter id to find\n");
                     scanf("%s",id);
                     Student *s=find_record(head,id);
                     if(!s)
                     {
                             printf("recordnot found\n");
                     }
                     else
                     {
                             printf("Id:%s\n name:%s DOB:%s\n marks-ssc:%f marks-sscplus:%f marks-grad:%f\n contact:%s\n mail:%s\n",s->id,s->name,s->dob,s->marks[0],s->marks[1],s->marks[2],s->contact,s->email);
                     }
                     break;
            case 'r':
            case 'R': reverse_display(head);
                                break;
            case 'q':
            case 'Q': return 0;
        }
    }
}