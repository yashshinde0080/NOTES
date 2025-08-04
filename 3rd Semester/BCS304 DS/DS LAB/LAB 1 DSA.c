





/*
Develop a Program in C for the following:
a) Declare a calendar as an array of 7 elements (A dynamically Created array) to represent
7 days of a week. Each Element of the array is a structure having three fields. The first
field is the name of the Day (A dynamically allocated String), The second field is the
date of the Day (A integer), the third field is the description of the activity for a
particular day (A dynamically allocated String).
b) Write functions create(), read() and display(); to create the calendar, to read the data
from the keyboard and to print weeks activity details report on screen.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to represent a day
struct Day {
    char *name;         // Day of the week
    int date;           // Date of the day
    char *description;  // Activity description
};

// Function to create a day
struct Day create() {
    struct Day day;
    char temp[100];

    printf("Enter day of the week: ");
    scanf("%s", temp);
    day.name = strdup(temp); // Dynamically allocate memory for the name

    printf("Enter date: ");
    scanf("%d", &day.date);

    printf("Enter activity description: ");
    scanf(" %[^\n]s", temp); // Read the entire line including spaces
    day.description = strdup(temp); // Dynamically allocate memory for the description

    return day;
}

// Function to read and populate the calendar
void read(struct Day *calendar, int numDays) {
    int i;
    for (i = 0; i < numDays; i++) {
        printf("\nEnter details for Day %d:\n", i + 1);
        calendar[i] = create();
    }
}

// Function to display the calendar
void display(const struct Day *calendar, int numDays) {
    printf("\nCalendar:\n");
    int i;
    for (i = 0; i < numDays; i++) {
        printf("Day %d: %s\n", i + 1, calendar[i].name);
        printf("Date: %d\n", calendar[i].date);
        printf("Activity: %s\n", calendar[i].description);
        printf("\n");
    }
}

int main() {
    int numDays;
    printf("Enter the number of days in the calendar: ");
    scanf("%d", &numDays);

    // Dynamically allocate memory for the calendar
    struct Day *calendar = (struct Day *)malloc(numDays * sizeof(struct Day));

    if (calendar == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    read(calendar, numDays);
    display(calendar, numDays);

    // Free dynamically allocated memory
    int i;
    for (i = 0; i < numDays; i++) {
        free(calendar[i].name);
        free(calendar[i].description);
    }
    free(calendar);

    return 0;
}



