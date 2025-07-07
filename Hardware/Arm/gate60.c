#include <stdio.h>
#include <string.h>

// Function to check if a string is already in the array
int is_present(char arr[][10], int size, char *str) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], str) == 0) {
            return 1; // Found
        }
    }
    return 0; // Not found
}

int main() {
    // Arrays to hold unique NOT and OR expressions
    char not_gates[10][10];
    char or_gates[10][10];
    int not_count = 0;
    int or_count = 0;

    // Add NOT gates
    if (!is_present(not_gates, not_count, "~P1")) {
        strcpy(not_gates[not_count++], "~P1");
    }
    if (!is_present(not_gates, not_count, "~P2")) {
        strcpy(not_gates[not_count++], "~P2");
    }

    // Add OR gates
    if (!is_present(or_gates, or_count, "P1+P2")) {
        strcpy(or_gates[or_count++], "P1+P2");
    }
    if (!is_present(or_gates, or_count, "c+e")) {
        strcpy(or_gates[or_count++], "c+e");
    }
    if (!is_present(or_gates, or_count, "b+c")) {
        strcpy(or_gates[or_count++], "b+c");
    }

    // Output results
    printf("Minimum NOT gates required: %d\n", not_count);
    printf("Minimum OR gates required: %d\n", or_count);

    return 0;
}

