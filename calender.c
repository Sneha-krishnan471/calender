#include <stdio.h>

#define TRUE  1
#define FALSE 0

// Array to store the number of days in each month
int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Array to store month names
char *months[] = {
    " ",
    "\n\n\nJanuary",
    "\n\n\nFebruary",
    "\n\n\nMarch",
    "\n\n\nApril",
    "\n\n\nMay",
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember"
};

// Function to input the year
int input_year(void) {
    int year;
    printf("Please enter a year (example: 1999): ");
    scanf("%d", &year);
    return year;
}

// Function to determine the day code for the year
int determine_day_code(int year) {
    int day_code, d1, d2, d3;
    d1 = (year - 1) / 4;
    d2 = (year - 1) / 100;
    d3 = (year - 1) / 400;
    day_code = (year + d1 - d2 + d3) % 7;
    return day_code;
}

// Function to determine if the year is a leap year
int determine_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        days_in_month[2] = 29; // February has 29 days in a leap year
        return TRUE;
    } else {
        days_in_month[2] = 28; // February has 28 days otherwise
        return FALSE;
    }
}

// Function to display the calendar
void display_calendar(int year, int day_code) {
    int month, day;

    for (month = 1; month <= 12; month++) {
        printf("%s", months[month]);
        printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Adjust the position for the first day of the month
        for (day = 1; day <= day_code * 4; day++) {
            printf(" ");
        }

        // Print the days of the month
        for (day = 1; day <= days_in_month[month]; day++) {
            printf("%2d", day);

            // Check if the current day is Saturday
            if ((day + day_code) % 7 > 0)
                printf("   "); // Space for alignment
            else
                printf("\n"); // New line for the next week
        }

        // Update the day code for the next month
        day_code = (day_code + days_in_month[month]) % 7;
        printf("\n");
    }
}

int main(void) {
    int year, day_code, leap_year;

    year = input_year();
    day_code = determine_day_code(year);
    leap_year = determine_leap_year(year);

    display_calendar(year, day_code);

    printf("\n");
    return 0;
}