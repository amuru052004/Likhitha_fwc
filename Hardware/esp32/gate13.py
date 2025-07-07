# Step 1: Define NAND and NOR functions
def NAND(a, b):
    return int(not (a and b))

def NOR(a, b):
    return int(not (a or b))

# Step 2: Build NOT, AND, and OR using NAND gates
def NOT_using_NAND(a):
    return NAND(a, a)

def AND_using_NAND(a, b):
    return NOT_using_NAND(NAND(a, b))

def OR_using_NAND(a, b):
    return NAND(NOT_using_NAND(a), NOT_using_NAND(b))

# Step 3: Build NOT, AND, and OR using NOR gates
def NOT_using_NOR(a):
    return NOR(a, a)

def OR_using_NOR(a, b):
    return NOT_using_NOR(NOR(a, b))

def AND_using_NOR(a, b):
    return NOR(NOT_using_NOR(a), NOT_using_NOR(b))

# Step 4: Define the input combinations to test
inputs = [(0, 0), (0, 1), (1, 0), (1, 1)]

# Step 5: Print the results for NAND-based gates
print("Results using NAND gates:")
for a, b in inputs:
    and_result = AND_using_NAND(a, b)
    or_result = OR_using_NAND(a, b)
    not_result = NOT_using_NAND(a)
    print(f"A={a}, B={b} => AND: {and_result}, OR: {or_result}, NOT A: {not_result}")

# Step 6: Print the results for NOR-based gates
print("\nResults using NOR gates:")
for a, b in inputs:
    and_result = AND_using_NOR(a, b)
    or_result = OR_using_NOR(a, b)
    not_result = NOT_using_NOR(a)
    print(f"A={a}, B={b} => AND: {and_result}, OR: {or_result}, NOT A: {not_result}")

# Step 7: Define the options
options = {
    "A": "NAND gates can implement AND, OR, and NOT gates.",
    "B": "NOR gates can implement AND, OR, and NOT gates.",
    "C": "Both NAND and NOR gates can implement AND, OR, and NOT gates.",
    "D": "Only NAND gates can implement NOT gates."
}

# Step 8: Compare and find the correct option
correct_option = "C"  # Both NAND and NOR gates are universal

# Step 9: Print result and explanation
print(f"\nCorrect Option: ({correct_option})")
print(f"\nExplanation:")
print("""
Using universal gates:
- NAND gates can be used to build AND, OR, and NOT gates.
- NOR gates can also be used to build AND, OR, and NOT gates.

Hence, both NAND and NOR gates are universal gates.

Therefore, the correct option is:
(C) Both NAND and NOR gates can implement AND, OR, and NOT gates.
""")

