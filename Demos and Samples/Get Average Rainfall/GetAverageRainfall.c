#include <stdio.h>

#define MONTHS  12
#define YEARS   5

int main(void) {
    // Declare and initialize a 2D array for monthly average rainfall each year:
    float averageRainfallPerMonth[YEARS][MONTHS] = {
        // Hard Coded Random Monthly Rainfall from January to December:
        { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 }, // 2010
        { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 }, // 2011
        { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 }, // 2012
        { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 }, // 2013
        { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }  // 2014
    };

    float total = 0.0f, subTotal = 0.0f;
    short int year = 2010;
    
    // Display Yearly Average Rainfall:
    printf("YEAR:\tRAINFALL:\n");
    for (int i = 0; i < YEARS; i++) {
        // Calculate Yearly Average Rainfall
        for (int j = 0; j < MONTHS; j++) 
            subTotal += averageRainfallPerMonth[i][j];
        
        // Display Output:
        printf("%5d:\t %.1f\n", year, subTotal);

        year++;
        total += subTotal;
        subTotal = 0.0f; // Resets to 0
    }

    // Get the yearly average from 2010 - 2014:
    printf("\nThe yearly average is %.1f inches.\n\n", total/YEARS);

    // Display Monthly Average Rainfall:
    printf("MONTHLY AVERAGES:\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
    for (int i = 0; i < MONTHS; i++) {
        // Calculate Monthly Average Rainfall
        for (int j = 0; j < YEARS; j++)
            subTotal += averageRainfallPerMonth[j][i];

        // Display Output:
        printf("%4.1f ", subTotal/YEARS);
        subTotal = 0.0f;
    }
    printf("\n");

    return 0;
}