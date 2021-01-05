/*
 * [] make a function using scanf
 * [] find out what fprintf does
 * [] find out how enume works
 *  */

#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

#define MAX_DATA 100

typedef enum EyeColor {
BLUE_EYES,
GREEN_EYES,
BROWN_EYES,
BLACK_EYES,
OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
"Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
    int age;
    int first_name[MAX_DATA];
    int last_name[MAX_DATA];
    EyeColor eyes;
    float income;
} Person;

typedef struct Test {
    char *name;
    char *sentance;
    int num;
} Test;

void save_name(int length, char *name_p)
{
    printf("enter your name\n");

    for(int i = 0; i < length - 1; i++)
    {
        scanf("%c", name_p + i);
        if(name_p[i] == '\n')
        {
            break;
        }
        //getchar();
    }
    name_p[length - 1] = '\0';
    printf("name enterd is: %s\n", name_p);
}

int main(int argc, char *argv[])
{
    Person you = {.age = 0};
    int i = 0;
    char *in = NULL;

    Test new;
    char *input = malloc(50 * sizeof(char));

   
    save_name(50, input);
    printf("new name is: %s\n", input);

    printf("What's your First Name?");
    in = fgets(you.first_name, MAX_DATA - 1, stdin);
    check(in != NULL, "Failed to read first name.");

    printf("What's your Last Name?");
    in = fgets(you.last_name, MAX_DATA - 1, stdin);
    check(in != NULL, "Failed to read last name.");

    printf("How old are you?");
    int rc = fscanf(stdin, "%d", &you.age);
    check(rc > 0, "you have to enter a number.");

    printf("What color are your eyes: \n");

    for(i = 0; i <= OTHER_EYES; i++)
    {
        printf("%d) %s\n", i + 1, EYE_COLOR_NAMES[i]);
    }

    printf("> ");

    int eyes = -1;
    rc = fscanf(stdin, "%d", &eyes);
    check(rc > 0, "You have to enter a number");

    you.eyes = eyes - 1;
    check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Do it right thats not an option");

    printf("How much do you make an hour?");
    rc = fscanf(stdin, "%f", &you.income);
    check(rc > 0, "Enter a floating point number");

    printf("-------RESULTS-------\n");

    printf("First name: %s", you.first_name);
    printf("Last name: %s", you.last_name);
    printf("Age : %d\n", you.age);
    printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
    printf("Income: %f\n", you.income);

   

    return 0;

error:
    return -1;
}
