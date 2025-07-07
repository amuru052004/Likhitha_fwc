#include <stdio.h>

// Step 1: Define NAND and NOR functions
int NAND(int a, int b) {
    return !(a && b);
}

int NOR(int a, int b) {
    return !(a || b);
}

// Step 2: Build NOT, AND, and OR using NAND gates
int NOT_using_NAND(int a) {
    return NAND(a, a);
}

int AND_using_NAND(int a, int b) {
    return NOT_using_NAND(NAND(a, b));
}

int OR_using_NAND(int a, int b) {
    return NAND(NOT_using_NAND(a), NOT_using_NAND(b));
}

// Step 3: Build NOT, AND, and OR using NOR gates
int NOT_using_NOR(int a) {
    return NOR(a, a);
}

int OR_using_NOR(int a, int b) {
    return NOT_using_NOR(NOR(a, b));
}

int AND_using_NOR(int a, int b) {
    return NOR(NOT_using_NOR(a), NOT_using_NOR(b));
}

int main() {
    int inputs[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    int a, b;

    // Step 5: Print the results for NAND-based gates
    printf("Results using NAND gates:\n");
    for (int i = 0; i < 4; i++) {
        a = inputs[i][0];
        b = inputs[i][1];
        int and_result = AND_using_NAND(a, b);
        int or_result = OR_using_NAND(a, b);
        int not_result = NOT_using_NAND(a);
        printf("A=%d, B=%d => AND: %d, OR: %d, NOT A: %d\n", a, b, and_result, or_result, not_result);
    }

    // Step 6: Print the results for NOR-based gates
    printf("\nResults using NOR gates:\n");
    for (int i = 0; i < 4; i++) {
        a = inputs[i][0];
        b = inputs[i][1];
        int and_result = AND_using_NOR(a, b);
        int or_result = OR_using_NOR(a, b);
        int not_result = NOT_using_NOR(a);
        printf("A=%d, B=%d => AND: %d, OR: %d, NOT A: %d\n", a, b, and_result, or_result, not_result);
    }

    // Step 7–9: Show conclusion
    printf("\nCorrect Option: (C)\n");
    printf("\nExplanation:\n");
    printf("Using universal gates:\n");
    printf("- NAND gates can be used to build AND, OR, and NOT gates.\n");
    printf("- NOR gates can also be used to build AND, OR, and NOT gates.\n");
    printf("Hence, both NAND and NOR gates are universal gates.\n");
    printf("Therefore, the correct option is:\n");
    printf("(C) Both NAND and NOR gates can implement AND, OR, and NOT gates.\n");

    return 0;
}
