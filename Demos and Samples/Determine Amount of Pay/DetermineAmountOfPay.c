#include <stdio.h>

// Pay Rate:
#define EXTRA_PAY_RATE 18.00
#define BASIC_PAY_RATE 12.00

// Tax rate:
#define TAX_RATE_15 0.15 // 15%
#define TAX_RATE_20 0.20 // 20%
#define TAX_RATE_25 0.25 // 25%

// Time:
#define TOTAL_TIME 40

int main(void) {
    // Prompt the user to enter the number of hours worked in a week
    int hours = 0;
    printf("Enter the number of hours worked in a week: ");
    scanf("%d", &hours);

    float grossPay = 0.0f;
    float taxes = 0.0f;
    float netPay = 0.0f;

    if (hours > TOTAL_TIME) { // Check if the employee spent overtime
        const int extraHours = hours - TOTAL_TIME;
        grossPay += EXTRA_PAY_RATE * extraHours;
        hours -= extraHours;
    }
    
    // Calculation for the amount of time employee spent:
    grossPay += (float)hours * BASIC_PAY_RATE;

    // Tax rate calculation:
    if (grossPay > 450)
        taxes = ((300 * TAX_RATE_15) + (150 * TAX_RATE_20)) + (grossPay - 450) * TAX_RATE_25;

    else if (grossPay > 300 && grossPay <= 450)
        taxes = (300 * TAX_RATE_15) + (grossPay - 300) * TAX_RATE_20;
    
    else if (grossPay <= 300)
        taxes = grossPay * TAX_RATE_15;
    
    // calculate the netpay:
    netPay = grossPay - taxes;

    // Display the following output:
    printf("Gross Pay: $%.2f\n", grossPay);
    printf("Tax rate: $%.2f\n", taxes);
    printf("Net pay: $%.2f\n", netPay);

    return 0;
}