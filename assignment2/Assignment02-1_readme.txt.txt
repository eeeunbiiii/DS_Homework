# Sparse Matriz Transposition in C
This C code demonstrates the transposition of a sparse matrix (represented as a list of non-zero elements) and prints both the original matrix and its transpose. It uses structures to store the sparse matrix and its elements.

## How to Run
To run this code, you need a 'Microsoft Visual Studio'. Just open the Visual Studio Solution(.sln) file and run it (crtl+F5).

if you do not have a Visual Studio tool, you need a C compiler, such as GCC, installed on your system. and following each step.

1. Open your terminal or command prompt.
2. Navigate to the directory containing the code files (C source code file is located in \Assignment02-1_code_2271069_고은비\Assignment02_code_2271069_고은비)
3. Compile the code using the following command :
`gcc -o Assignment02_code_2271069_고은비.c`
4. Run the compiled program :
`./Assignment02_code_2271069_고은비`

## Code Structure
- element structure: Represents a single element of the sparse matrix, including its position(row, column) and value.
- SparseMatrix structure: Represents a sparse matrix, including its dimensions (rows, columns) and the number of non-zero elements (terms).
- printMat function: Prints a matrix (sparse or transpose) based on the data provided in the form of an array of `element` structures.
- main function: Demonstrates the transposition of a sparse matrix, initializes the result matrix, performs transposition, sorts the result matrix, and then prints both the original and its transpose.

## Customization
- You can customize the size of the sparse matrix by changing the values of `ROWS` and `COLS` in the code.
- Modify `SparseMatrix B` initialization to represent your specific sparse matrix data.

## Author
2271069_EunbiKo