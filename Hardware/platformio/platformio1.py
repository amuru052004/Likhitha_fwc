def mux(sel, d0, d1):
    return d0 if sel == 0 else d1

def and_using_mux(a, b):
    # AND(A, B) = MUX(A, 0, B)
    return mux(a, 0, b)

def xor_using_mux(a, b):
    not_b = 1 - b
    # XOR(A, B) = MUX(A, B, NOT B)
    return mux(a, b, not_b)

def main():
    print("2-input Logic Gates Using 2:1 MUX")
    a = int(input("Enter input A (0 or 1): "))
    b = int(input("Enter input B (0 or 1): "))

    if a not in [0, 1] or b not in [0, 1]:
        print("Invalid input. Enter 0 or 1 only.")
        return

    and_result = and_using_mux(a, b)
    xor_result = xor_using_mux(a, b)

    print(f"\nAND({a}, {b}) = {and_result}")
    print(f"XOR({a}, {b}) = {xor_result}")

if __name__ == "__main__":
    main()


