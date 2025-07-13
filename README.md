
# 🔢 Big Integer Arithmetic using Doubly Linked List in C

This project implements **arithmetic operations on arbitrarily large integers** using **doubly linked lists** in the C programming language. It supports four fundamental operations—**Addition, Subtraction, Multiplication, and Division**—on numeric inputs that are too large for native data types like `int`, `long`, or `long long`.

---

## 🧠 Project Objective

C lacks built-in support for handling very large numbers (like 100-digit integers). This project provides a manual solution to that limitation by:
- Storing each digit as a node in a doubly linked list.
- Performing operations digit by digit, mimicking manual arithmetic.
- Ensuring accurate carry, borrow, and overflow control.

---

## ✅ Features

- ✔ Handles numbers with hundreds or thousands of digits.
- ➕ Performs Addition using carry-forward logic.
- ➖ Performs Subtraction with negative result handling.
- ✖️ Implements long Multiplication via positional multiplication and carry.
- ➗ Performs Division through repeated subtraction.
- ⚠️ Handles edge cases like division by zero.
- 🧱 All data stored and manipulated using a **custom doubly linked list structure**.
- 🧼 Proper memory management and list cleanup for every operation.

---

## 📂 File Structure

| File             | Description |
|------------------|-------------|
| `main.c`         | Accepts user input via command line and dispatches to arithmetic functions |
| `header.h`       | Contains function declarations, macros, and the doubly linked list structure |
| `add.c`          | Implements digit-wise addition with carry |
| `sub.c`          | Handles subtraction including sign and leading zeros |
| `mul.c`          | Uses nested loops and carry management for multiplication |
| `div.c`          | Performs integer division using comparison and repeated subtraction |
| `digit_to_list.c`| Converts input strings into linked list nodes |
| `sub.list.c`     | Contains helper functions: `sub_list`, `copy_list`, `clear_list` |

---

## 🧱 Data Structure

Each number is represented as a doubly linked list where each node contains one digit.

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

Example for number `1234`:  
`1 <-> 2 <-> 3 <-> 4`


## ⚙️ Compilation Instructions

To compile all source files into a single executable:

gcc main.c add.c sub.c mul.c div.c digit_to_list.c sub.list.c -o bigint


## 🚀 Program Usage

### Syntax:
```bash
./bigint <operand1> <operator> <operand2>


### Supported Operators:
- `+` → Addition
- `-` → Subtraction
- `x` → Multiplication
- `/` → Division

### Example Commands:
./bigint 123456789 + 987654321
./bigint 1000000 - 999999
./bigint 12345 x 6789
./bigint 99999 / 3


## 🧪 Example Outputs

$ ./bigint 123456789 + 987654321
The result is: 1111111110
Successfully performed addition

$ ./bigint 1000 - 1234
The result is: -234
Successfully performed Subtraction

$ ./bigint 123 x 456
The Result is: 56088
Successfully performed Multiplication

$ ./bigint 10000 / 2
The Result is 5000
Successfully performed Division


## 🔄 Operation Flow

### 1. Input Parsing (`main.c`)
- Accepts three arguments from command-line: operand1, operator, operand2.
- Verifies format and selects the operation based on the operator.

### 2. Operand Conversion (`digit_to_list.c`)
- Converts operand strings to digit-wise doubly linked lists.
- Example: `"123"` becomes `1 <-> 2 <-> 3`

### 3. Arithmetic Operations
- Each operation reads from the end of the list (least significant digit).
- Handles carry/borrow as appropriate.
- Stores result in a new linked list (`head3`).

### 4. Output
- Final result is printed from the result list.
- Additional status messages indicate success or failure.


## ⚠️ Edge Cases Handled

- 🚫 Division by zero is detected and reported.
- ➖ Negative results in subtraction are properly displayed.
- 🧹 Leading zeros in the result are automatically removed.
- ❌ Invalid characters in input result in graceful failure.


## 🧼 Memory Management

- Every list created during an operation is freed or reused.
- Functions like `clear_list` and `copy_list` ensure no memory leaks.


## 📌 Limitations

- Only handles **non-negative integer operands**.
- Does not support floating point or decimal arithmetic.
- Input validation is minimal; assumes correct syntax unless otherwise handled.


## 📝 Summary

This project demonstrates how to perform big integer arithmetic in C using custom data structures. It emulates manual operations through linked list manipulation, enabling the handling of large values far beyond native type limits. The modular design, proper memory handling, and full operator support make this a comprehensive learning and practical tool for understanding both data structures and arithmetic logic at a low level in systems programming.



