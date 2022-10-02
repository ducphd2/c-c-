#include <stdio.h>

#define MAX 100

void inputArray(int* array, int* number) {
    printf("Enter number of element in array = ");
    scanf("%d", number);
    for (int i = 0; i < *number; i++) {
        printf("Enter array[%d] = ", i);
        scanf("%d", &array[i]);
    }
}

void displayArray(int array[], int number) {
    for (int i = 0; i < number; i++) {
        printf("Value of array[%d] = %d\n", i, array[i]);
    }
}

int getFirstIndexByFactor(int array[], int number) {
    int factor;
    printf("Enter number that find = ");
    scanf("%d", &factor);
    for (int i = 0; i < number; i++) {
        if (factor == array[i]) {
            printf("Found that factor at first index: array[%d]\n", i);
            return 1;
        }
    }
    printf("Could not found that factor");
    return -1;
}

int getLastIndexByFactor(int array[], int number) {
    int factor;
    printf("Enter number that find = ");
    scanf("%d", &factor);
    for (int i = number - 1; i >= 0; i--) {
        if (factor == array[i]) {
            printf("Found that factor at last index: array[%d]\n", i);
            return 1;
        }
    }
    printf("Could not found that factor");
    return -1;
}

int insertElementByIndex(int* array, int* number) {
    int index;
    int value;
    printf("Insert that value = ");
    scanf("%d", &value);
    printf("By index = ");
    scanf("%d", &index);
    if (index <= 0 || index > *number) {
        printf("Invalid index = %d\n", index);
        return -1;
    }

    (*number)++;
    for (int i = *number; i >= index; i--) {
        array[i] = array[i - 1];
    }
    array[index - 1] = value;
    return 1;
}

int removeElementByIndex(int* array, int* number) {
    int index;
    printf("Remove value by index = ");
    scanf("%d", &index);
    if (index <= 0 || index > *number) {
        printf("Invalid index = %d\n", index);
        return -1;
    }

    for (int i = index; i < *number; i++) {
        array[i] = array[i + 1];
    }
    (*number)--;
    return 1;
}

int main(int argc, char const* argv[]) {
    int array[MAX];
    int number;
    inputArray(array, &number);
    displayArray(array, number);
    getFirstIndexByFactor(array, number);
    getLastIndexByFactor(array, number);
    insertElementByIndex(array, &number);
    displayArray(array, number);
    removeElementByIndex(array, &number);
    displayArray(array, number);
    return 0;
}
