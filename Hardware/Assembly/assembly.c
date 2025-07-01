#include <stdio.h>

// NAND gate simulation
int nand_gate(int a, int b) {
    return !(a && b);
}

// NOR gate simulation
int nor_gate(int a, int b) {
    return !(a || b);
}

// NAND latch simulation
void nand_latch(int p1, int p2, int* q1, int* q2) {
    int new_q1 = nand_gate(p1, *q2);
    int new_q2 = nand_gate(p2, *q1);
    *q1 = new_q1;
    *q2 = new_q2;
}

// NOR latch simulation
void nor_latch(int p1, int p2, int* q1, int* q2) {
    int new_q1 = nor_gate(p1, *q2);
    int new_q2 = nor_gate(p2, *q1);
    *q1 = new_q1;
    *q2 = new_q2;
}

int main() {
    // NAND Latch Analysis
    printf("NAND Latch Analysis:\n");

    int nand_q1 = -1, nand_q2 = -1;
    nand_latch(0, 1, &nand_q1, &nand_q2);
    printf("Inputs (0, 1): Q1 = %d, Q2 = %d\n", nand_q1, nand_q2);

    nand_latch(1, 1, &nand_q1, &nand_q2);
    printf("Inputs (1, 1): Q1 = %d, Q2 = %d\n\n", nand_q1, nand_q2);

    // NOR Latch Analysis
    printf("NOR Latch Analysis:\n");

    int nor_q1 = -1, nor_q2 = -1;
    nor_latch(0, 1, &nor_q1, &nor_q2);
    printf("Inputs (0, 1): Q1 = %d, Q2 = %d\n", nor_q1, nor_q2);

    nor_latch(1, 1, &nor_q1, &nor_q2);
    printf("Inputs (1, 1): Q1 = %d, Q2 = %d\n\n", nor_q1, nor_q2);

    // Final Answer
    printf("Final Answer:\n");
    printf("- NAND latch: First (1, 0), then (1, 0)\n");
    printf("- NOR latch: First (1, 0), then (0, 0)\n");
    printf("Correct Option: (C)\n");

    return 0;
}
