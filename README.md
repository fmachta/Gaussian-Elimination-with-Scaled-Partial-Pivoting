** Gaussian Elimination with Scaled Partial Pivoting - Report**

**Objective:**
To develop a C++ program that can solve a system of linear equations (up to 10 equations) using the Gaussian elimination method with scaled partial pivoting.

**Background:**
Gaussian elimination is a method for solving matrix equations of the form \(Ax = b\). The process involves three types of elementary row operations:
1. Swapping two rows.
2. Multiplying a row by a nonzero number.
3. Adding or subtracting the multiple of one row to another row.

The aim is to transform the matrix to its upper triangular form, and then to its diagonal form, from which the solution is readily available.

Scaled partial pivoting is a strategy used to prevent small pivot elements which can lead to large rounding errors in the computed solution. The technique involves interchanging rows based on a scaled maximum value in the column.

**Implementation Details:**

**1. Matrix Input:**
   The program begins by asking the user to specify the number of linear equations they wish to solve. The user is then given a choice: 
   - To input the coefficients of the augmented matrix directly via the command line.
   - To provide a filename from which the program can read the augmented matrix.

**2. Scaled Partial Pivoting:**
   For every column, the program computes the scaled ratios of the elements with respect to the maximum element in their respective rows. The row with the highest scaled ratio is selected as the pivot row for that column. If necessary, this row is swapped with the current row to place the pivot element in the correct position.

**3. Gaussian Elimination:**
   The matrix is transformed into its upper triangular form by iteratively performing the elimination process on each row below the pivot element, for every column.

**4. Back Substitution:**
   Once the matrix is in its upper triangular form, the program applies the back substitution method to determine the values of the unknowns, resulting in the solution vector.
Code:

**Conclusion:**
The developed program successfully utilizes the Gaussian elimination method with scaled partial pivoting to solve a system of linear equations. The program is flexible, allowing the user to input the system either manually or from a file. 
