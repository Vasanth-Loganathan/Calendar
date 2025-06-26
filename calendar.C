#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to represent an event
struct Event {
    char name[50];
    char date[20];
    char time[20];
};

// Function that returns the index of the
// day for date DD/MM/YYYY
int dayNumber(int day, int month, int year) {
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

// Function that returns the name of the
// month for the given month Number
char* getMonthName(int monthNumber) {
    char* month;

    switch (monthNumber) {
        case 0:
            month = "January";
            break;
        case 1:
            month = "February";
            break;
        case 2:
            month = "March";
            break;
        case 3:
            month = "April";
            break;
        case 4:
            month = "May";
            break;
        case 5:
            month = "June";
            break;
        case 6:
            month = "July";
            break;
        case 7:
            month = "August";
            break;
        case 8:
            month = "September";
            break;
        case 9:
            month = "October";
            break;
        case 10:
            month = "November";
            break;
        case 11:
            month = "December";
            break;
    }
    return month;
}

// Function to return the number of days
// in a month
int numberOfDays(int monthNumber, int year) {
    if (monthNumber == 0)
        return (31);

    if (monthNumber == 1) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    }

    if (monthNumber == 2)
        return (31);

    if (monthNumber == 3)
        return (30);

    if (monthNumber == 4)
        return (31);

    if (monthNumber == 5)
        return (30);

    if (monthNumber == 6)
        return (31);

    if (monthNumber == 7)
        return (31);

    if (monthNumber == 8)
        return (30);

    if (monthNumber == 9)
        return (31);

    if (monthNumber == 10)
        return (30);

    if (monthNumber == 11)
        return (31);
}

// Function to print the calendar of
// the given year and month
void printCalendar(int year, int month, struct Event events[]) {
    printf("    Calendar - %d %s\n\n", year, getMonthName(month));
    int days;

    // Index of the day from 0 to 6
    int current = dayNumber(1, month + 1, year);

    // Print the columns
    printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Print appropriate spaces
    int k;
    for (k = 0; k < current; k++)
        printf("    ");

    // i for Iterate through days of the month
    for (int j = 1; j <= numberOfDays(month, year); j++) {
        printf("%4d", j);

        if (++k > 6) {
            k = 0;
            printf("\n");
        } else {
            printf(" ");
        }
    }

    if (k)
        printf("\n");

    printf("\n");

    // Print events for the month
    printf("    Events for %s:\n", getMonthName(month));
    for (int i = 0; i < 3; i++) {
        if (atoi(events[i].date) != 0 && atoi(events[i].date) <= numberOfDays(month, year)) {
            printf("    %s (%s) at %s\n", events[i].name, events[i].date, events[i].time);
        }
    }
    printf("\n");
}

// Function to add an event to the array
void addEvent(struct Event events[], const char* name, const char* date, const char* time, int index) {
    strcpy(events[index].name, name);
    strcpy(events[index].date, date);
    strcpy(events[index].time, time);
}

int main() {
    int year, month;

    // Get year from the user
    printf("Enter the year: ");
    scanf("%d", &year);

    // Get month from the user
    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    // Validate month input
    if (month < 1 || month > 12) {
        printf("Invalid month input. Exiting program.\n");
        return 1;
    }

    // Create an array to store events
    struct Event events[3];

    // Get events from the user for one month
    for (int i = 0; i < 3; i++) {
        printf("Enter details for Event %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]s", events[i].name);
        printf("Date (DD): ");
        scanf(" %[^\n]s", events[i].date);
        printf("Time: ");
        scanf(" %[^\n]s", events[i].time);
        printf("\n");
    }

    // Function Call to print the calendar with events
    printCalendar(year, month - 1, events);

    return 0;
}
