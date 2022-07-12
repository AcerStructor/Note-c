#include <stdio.h>

int main() {
    // Prompt the user to enter number of minutes:
    int minutes = 0; 
    printf("Enter the number of minutes to convert to days and years: ");
    scanf("%d", &minutes);

    // Minutes to days and years calculation:
    const double days = ((double)minutes / 60) / 24;
    const double years = days / 365;
    const double minutesInYear = years * 365 * 24 * 60; 

    // Display Output:
    printf("Days\t\t:\t%.0lf\n", days);
    printf("Years\t\t:\t%.0lf\n", years);
    printf("Minutes in year :\t%.0lf\n", minutesInYear);
    
    return 0;
}