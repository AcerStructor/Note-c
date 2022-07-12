#include <stdio.h>
#include <stdlib.h> // for random generation
#include <time.h> // for time_t

#include "DEFINITONS.h"
#include "ConsoleDeco.h"

_Bool ageCoverage(int age, int minimum, int maximum) {
    if (age >= minimum && age < maximum) {
        printf("Age is between %d - %d\n", minimum, maximum);
        return 1;
    }
    else
        return 0;
}

void displayDescriptions(char* description[], int randomNum) {
    printf("Description: \"%s\"\n", description[randomNum]);
}

int main() {
    // Random Number Generator:
    time_t t;
    srand((unsigned)time(&t));
    _Bool isGameOver = 0;

    // Individual's description init:
    char* toddlerDesc[4] = {_TODDLER_DESC_1_, _TODDLER_DESC_2_, _TODDLER_DESC_3_, _TODDLER_DESC_4_};
    char* childrenDesc[4] = {_CHILDREN_DESC_1_, _CHILDREN_DESC_2_, _CHILDREN_DESC_3_, _CHILDREN_DESC_4_};
    char* teenagerDesc[4] = {_TEENAGER_DESC_1_, _TEENAGER_DESC_2_, _TEENAGER_DESC_3_, _TEENAGER_DESC_4_};
    char* youngAdultDesc[4] = {_Y_ADULT_DESC_1_, _Y_ADULT_DESC_2_, _Y_ADULT_DESC_3_, _Y_ADULT_DESC_4_};
    char* adultDesc[4] = {_ADULT_DESC_1_, _ADULT_DESC_2_, _ADULT_DESC_3_, _ADULT_DESC_4_};
    char* elderDesc[4] = {_ELDER_DESC_1_, _ELDER_DESC_2_, _ELDER_DESC_3_, _ELDER_DESC_4_};

    // Program Flow:
    while (!isGameOver) {
        system("cls");
        // Initialize Random Age:
        int myAge = rand() % 71;
        int randomNum = rand() % 4;
        _Bool isGuessed = 0;

        setFontColor(green);
        // Check the coverage of a person's age:
        if (ageCoverage(myAge, 0, 3))
            displayDescriptions(toddlerDesc, randomNum);
        else if (ageCoverage(myAge, 3, 13))
            displayDescriptions(childrenDesc, randomNum);
        else if (ageCoverage(myAge, 13, 18))
            displayDescriptions(teenagerDesc, randomNum);
        else if (ageCoverage(myAge, 18, 30))
            displayDescriptions(youngAdultDesc, randomNum);
        else if (ageCoverage(myAge, 30, 55))
            displayDescriptions(adultDesc, randomNum);
        else if (ageCoverage(myAge, 55, 71))
            displayDescriptions(elderDesc, randomNum);

        for (unsigned int tries = 5; tries != 0; tries--) {
            //printf("Debug: Age = %d\n", myAge); // Debug
            printf("You have %d tries left\n", tries);
            int userInput = 0;
            setFontColor(white);
            scanf("%d", &userInput);

            // If user input does not matched at person's age:
            if (userInput != myAge) {
                setFontColor(red);
                if (userInput > myAge)
                    printf("My age is lower than that\n");
                else
                    printf("My age is higher than that\n");
            }
            else {
                system("cls");
                setFontColor(yellow);
                printf("Congratulations! You've guessed my age!\n");
                isGameOver = 1;
                isGuessed = 1;
                system("pause");
                break;
            }
        }

        // If the user doesn't guess the age:
        if (!isGuessed) {
            system("cls");
            setFontColor(green);
            printf("My age is %d\n", myAge);
            system("pause");
        }
    }
    return 0;
}
