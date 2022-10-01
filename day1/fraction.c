#include <math.h>
#include <stdio.h>

struct Fraction {
    int numerator;
    int denominator;
};

void inputFraction(struct Fraction *fraction) {
    printf("Input the numerator = ");
    scanf("%d", fraction->numerator);
    printf("Input the denominator = ");
    scanf("%d", fraction->denominator);
}

int validateFraction(struct Fraction fraction) {
    if (fraction.denominator == 0) return -1;
    return 1;
}

void printFraction(struct Fraction fraction) {
    printf("Your fraction: %d / %d\n", fraction.numerator, fraction.denominator);
}

void addTwoFraction(struct Fraction firstFraction, struct Fraction secondFraction) {
    int numerator = firstFraction.numerator * secondFraction.denominator + firstFraction.denominator * secondFraction.numerator;
    int denominator = firstFraction.denominator * secondFraction.denominator;
    printf("Result by add 2 fraction: ");
    struct Fraction fraction;
    fraction.numerator = numerator;
    fraction.denominator = denominator;
    printFraction(fraction);
}

int main(int argc, char const *argv[]) {
    struct Fraction *firstFraction, *secondFraction;
    inputFraction(&firstFraction);
    if (validateFraction(firstFraction) == -1) {
        printf("Invalid fraction by denominator = %d", firstFraction.denominator);
        return 0;
    }
    inputFraction(&secondFraction);
    if (validateFraction(secondFraction) == -1) {
        printf("Invalid fraction by denominator = %d", secondFraction.denominator);
        return 0;
    }
    printFraction(firstFraction);
    printFraction(secondFraction);
    addTwoFraction(firstFraction, secondFraction);
    return 0;
}
