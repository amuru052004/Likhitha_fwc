#include <stdio.h>

// MUX function: returns d0 if sel == 0, else d1
int mux(int sel, int d0, int d1) {
    return (sel == 0) ? d0 : d1;
}

// AND gate using MUX: AND(A, B) = MUX(A, 0, B)
int and_using_mux(int a, int b) {
    return mux(a, 0, b);
}

// XOR gate using MUX: XOR(A, B) = MUX(A, B, NOT B)
int xor_using_mux(int a, int b) {
    int not_b = 1 - b;
    return mux(a, b, not_b);
}

int main() {
    int a, b;

    printf("2-input Logic Gates Using 2:1 MUX\n");
    printf("Enter input A (0 or 1): ");
    scanf("%d", &a);
    printf("Enter input B (0 or 1): ");
    scanf("%d", &b);

    // Input validation
    if ((a != 0 && a != 1) || (b != 0 && b != 1)) {
        printf("Invalid input. Enter 0 or 1 only.\n");
        return 1;
    }

    int and_result = and_using_mux(a, b);
    int xor_result = xor_using_mux(a, b);

    printf("\nAND(%d, %d) = %d\n", a, b, and_result);
    printf("XOR(%d, %d) = %d\n", a, b, xor_result);

    return 0;
}
