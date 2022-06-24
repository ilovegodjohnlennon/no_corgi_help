#include "student.h"

#include <stdio.h>
#include <string.h>

int menu_prompt()
{
    char input = 0;
    printf("\n\n=== MAIN MENU ===\n\n");
    printf("t - teacher mode\n");
    printf("s - student mode\n");
    printf("q - quit application\n\n");

    if(scanf(" %c", &input) != 1)
    {
        printf("INVALID INPUT! Try again.\n");
        return MODE_NONE;
    }

    switch(input)
    {
        case 't':
            printf("Entering teacher mode...\n");
            return MODE_TEACHER;
            break;
        case 's':
            printf("Entering student mode...\n");
            return MODE_STUDENT;
            break;
        case 'q':
            printf("Bye!\n");
            return WANT_TO_EXIT;
            break;
        default:
            printf("No such mode! Try again.\n");
            return MODE_NONE;
    }

    return MODE_NONE;
}

// =================================================

int teacher_prompt(student_array *arr)
{
    char input = 0;

    while(input != 'q')
    {
        printf("\n\n=== TEACHER MODE ===\n\n");
        printf("a - add new student\n");
        printf("q - quit to menu\n");

        if(scanf(" %c", &input) != 1)
        {
            printf("INVALID INPUT! Try again\n");
            input = 0;
            continue;
        }

        switch(input)
        {
            case 'q':
                printf("Returning to main menu!\n");
                return MODE_NONE;
            case 'a':
                add_student(arr);
                break;
            default:
                printf("Invalid input. Try again.\n");
                input = 0;
                
        }
    }

    return MODE_NONE;

}

// ==============================================

int add_student(student_array *arr)
{
    if(arr->count >= MAX_STUDENTS)
    {
        printf("ERROR! No space for new student\n");
        return 0;
    }

    student* cur = &arr->data[arr->count];
    printf("Register number of new student: ");
    if(scanf(" %d", &cur->register_number) != 1)
    {
        printf("Error! Invalid input\n");
        return 0;
    }    
    printf("Name of new student: ");

    // initialize name string to 0s to avoid problems
    for(int i = 0; i < MAX_NAME_LEN; i++) cur->name[i] = 0;

    if(scanf(" %49[^\n]", cur->name) != 1)
    {
        printf("Error! Invalid input\n");
        return 0;
    }
    printf("Class of new student: ");
    if(scanf(" %c", &cur->class_) != 1)
    {
        printf("Error! Invalid input\n");
        return 0;
    }
    printf("Maths mark: ");
    if(scanf(" %f", &cur->maths_mark) != 1)
    {
        printf("Error! Invalid input\n");
        return 0;
    }
    printf("History mark: ");
    if(scanf(" %f", &cur->history_mark) != 1)
    {
        printf("Error! Invalid input\n");
        return 0;
    }

    printf("Successfully added new student!\n");
    printf("%d %s %c\nmaths: %.2f\nhistory: %.2f\n\n", cur->register_number, cur->name, cur->class_, cur->maths_mark, cur->history_mark);
    arr->count++;
    return 1;
}

// ==============================================================

int student_prompt(student_array *arr)
{
    char input = 0;

    while(input != 'q')
    {
        printf("\n\n=== STUDENT MODE ===\n\n");
        printf("q - exit to menu\n");
        printf("s - student data\n");

        if(scanf(" %c", &input) != 1)
        {
            printf("Invalid input! Please try again.\n");
            input = 0;
            continue;
        }

        switch(input)
        {
            case 'q':
                return MODE_NONE;
            case 's':
                query_student(arr);
                break;
            default:
                break;
        }
    }

    return MODE_NONE;
}

// ===========================================================

int query_student(student_array *arr)
{
    int i = 0;
    int _id = 0;
    char _class = 0;
    char _name[MAX_NAME_LEN];
    int max = arr->count;

    for(int j = 0; j < MAX_NAME_LEN; j++) _name[j] = 0;

    printf("Enter student's reg number: ");
    if(scanf(" %d", &_id) != 1)
    {
        printf("Input invalid.\n");
        return 0;
    }
    printf("Enter student's class: ");
    if(scanf(" %c", &_class) != 1)
    {
        printf("Input invalid\n");
        return 0;
    }
    printf("Enter student's name: ");
    if(scanf(" %49[^\n]", _name) != 1)
    {
        printf("Input invalid\n");
        return 0;
    }

    for(i = 0; i < max; i++)
    {
        if(arr->data[i].register_number == _id && arr->data[i].class_ == _class && !strcmp(arr->data[i].name, _name))
        {
            printf("\n\nFound student %d %s in class %c! \n", _id, _name, _class);
            print_student(&arr->data[i]);
            break;
        }
    }

    if(i >= max)
    {
        printf("Student not found!\n");
    }

    return 1;

}

// =============================================

void print_student(student *s)
{
    char wait;

    printf("Marks: \n");
    printf("Maths - %.2f\n", s->maths_mark);
    printf("History - %.2f\n", s->history_mark);


    return;
}