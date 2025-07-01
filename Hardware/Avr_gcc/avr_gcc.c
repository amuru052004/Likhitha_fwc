#include <stdio.h>
#include <string.h>

// Define number of cycles
#define CYCLES 6

// JK Flip-Flop logic
int jk_flipflop(int q, int j, int k) {
    if (j == 0 && k == 0)
        return q;           // No change
    else if (j == 0 && k == 1)
        return 0;           // Reset
    else if (j == 1 && k == 0)
        return 1;           // Set
    else
        return 1 - q;       // Toggle
}

// Simulate counter for 6 cycles
void simulate_counter(char states[CYCLES][3]) {
    int q1 = 0, q2 = 0;

    for (int i = 0; i < CYCLES; i++) {
        sprintf(states[i], "%d%d", q1, q2); // Save state as string

        int j1 = q2;
        int k1 = 1;

        int j2 = 1 - q1;
        int k2 = 1;

        int next_q1 = jk_flipflop(q1, j1, k1);
        int next_q2 = jk_flipflop(q2, j2, k2);

        q1 = next_q1;
        q2 = next_q2;
    }
}

// Check cyclic match
int is_cyclic_match(char actual[CYCLES][3], char option[CYCLES][3]) {
    for (int i = 0; i < CYCLES; i++) {
        int match = 1;
        for (int j = 0; j < CYCLES; j++) {
            int index = (i + j) % CYCLES;
            if (strcmp(actual[index], option[j]) != 0) {
                match = 0;
                break;
            }
        }
        if (match)
            return 1; // Found a cyclic match
    }
    return 0;
}

// Main function
int main() {
    // Simulate counter output
    char actual[CYCLES][3];
    simulate_counter(actual);

    printf("Simulated State Sequence (Q1 Q2):\n");
    for (int i = 0; i < CYCLES; i++) {
        printf("%s", actual[i]);
        if (i < CYCLES - 1) printf(" → ");
    }
    printf("\n\nChecking options:\n");

    // Define options
    char option_A[CYCLES][3] = { "11", "10", "00", "11", "10", "00" };
    char option_B[CYCLES][3] = { "01", "10", "11", "00", "01", "10" };
    char option_C[CYCLES][3] = { "00", "11", "01", "10", "00", "11" };
    char option_D[CYCLES][3] = { "01", "10", "00", "01", "10", "00" };

    // Check all options
    char correct_option = '\0';
    if (is_cyclic_match(actual, option_A)) {
        printf("Option A: ✅\n");
        correct_option = 'A';
    } else {
        printf("Option A: ❌\n");
    }

    if (is_cyclic_match(actual, option_B)) {
        printf("Option B: ✅\n");
        correct_option = 'B';
    } else {
        printf("Option B: ❌\n");
    }

    if (is_cyclic_match(actual, option_C)) {
        printf("Option C: ✅\n");
        correct_option = 'C';
    } else {
        printf("Option C: ❌\n");
    }

    if (is_cyclic_match(actual, option_D)) {
        printf("Option D: ✅\n");
        correct_option = 'D';
    } else {
        printf("Option D: ❌\n");
    }

    if (correct_option != '\0') {
        printf("\n✅ Correct Option: (%c)\n", correct_option);
    } else {
        printf("\n❌ No option matches cyclically.\n");
    }

    return 0;
}
