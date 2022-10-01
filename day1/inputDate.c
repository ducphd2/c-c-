#include <stdio.h>

#define JANUARY 1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUGUST 8
#define SEPTEMBER 9
#define OCTOBER 10
#define NOVEMBER 11
#define DECEMBER 12

#define COMMON_DAY 28
#define LEAP_DAY 29
#define THIRTIETH 30
#define THIRTY_FIRST 31

#define TRUE 1
#define FALSE -1

struct Date {
    int day;
    int month;
    int year;
};

void inputDate(struct Date *date) {
    printf("Input day: ");
    scanf("%d", &date->day);
    printf("\nInput month: ");
    scanf("%d", &date->month);
    printf("\nInput year: ");
    scanf("%d", &date->year);
}

int isLeapYear(int year) {
    if ((year % 4 == 0) && (year % 4 != 100) && (year % 400 == 0)) return TRUE;
    return FALSE;
}

int getDayByMonth(int year, int month) {
    switch (month) {
        case JANUARY:
        case MARCH:
        case MAY:
        case JULY:
        case AUGUST:
        case OCTOBER:
        case DECEMBER:
            return THIRTY_FIRST;
            break;
        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            return THIRTIETH;
            break;
        case FEBRUARY:
            if (isLeapYear(year) == TRUE) return LEAP_DAY;
            return COMMON_DAY;
            break;
        default:
            return FALSE;
            break;
    }
}

int validateInputDate(int day, int month, int year) {
    if (day <= 0 || day > 31) return FALSE;
    if (month <= 0 || month > 12) return FALSE;
    if (year <= 0) return FALSE;
    if (getDayByMonth(year, month) == FALSE) return FALSE;
    return TRUE;
}

int isValidDate(struct Date inputDate) {
    validateInputDate(inputDate.day, inputDate.month, inputDate.year);
}

void printDate(struct Date date) {
    printf("Your date: %d/%d/%d", date.day, date.month, date.year);
}

int main(int argc, char const *argv[]) {
    struct Date myDate;
    inputDate(&myDate);
    printf("\n----\n");
    if (isValidDate(myDate) == FALSE) {
        printf("Invalid date by ");
        printDate(myDate);
        return 0;
    }
    printDate(myDate);
    return 0;
}
