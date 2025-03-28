# 🧮 Big Integer Arithmetic Using Doubly Linked Lists in C

### 👤 Author: Mariam Turk  


## 📚 Overview

This C program implements **arithmetic operations (Addition, Subtraction, Multiplication, and Division)** on **large integers** using **doubly linked lists**. It is designed to handle integers that are too large for standard data types by processing them digit by digit, simulating manual calculations.

---

## 🧰 Features

- ✅ Add two large integers  
- ✅ Subtract one large integer from another  
- ✅ Multiply two large integers  
- 🚧 Divide two large integers (function declared, not implemented yet)  
- 📂 Read numbers from a text file  
- 💾 Write results to a text file  
- 🧾 Menu-driven CLI interface  

---

## 🧠 How It Works

- Each digit of the number is stored in a node of a doubly linked list.
- Operations are performed from tail to head (least to most significant digit).
- The result is built dynamically into a new linked list and can be printed or saved to file.

---

## 📁 Project Structure

. ├── main.c # Main source code file ├── input.txt # Input file with two lines, each representing a large integer ├── output.txt # Output file to save result └── README.md # Project documentation


## 🧪 Example Input (`input.txt`)

123456789012345678901234567890 987654321098765432109876543210


## 📤 Example Output (Addition)

1111111110111111111011111111100

This will also be saved in `output.txt` if option 5 is chosen from the menu.


🧭 Menu Options
1. Add
2. Subtract
3. Multiply
4. Divide
5. Print result to output file
6. Exit

🔍 Key Functions
Function	Purpose
InsertEND	Appends a digit to the end of a linked list
InsertBEGINNING	Prepends a digit to a linked list
ADDITION	Adds two linked list numbers
SUBTRACTION	Subtracts the second number from the first
multiply	Multiplies two linked list numbers
divide	Placeholder for future division logic
READ_F_F	Reads two numbers from file
WRITE_F_F	Saves result to file

🚧 To Do
 Implement division functionality

 Handle negative number results gracefully

 Add input validation and error handling

