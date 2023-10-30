#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

const int MAXN = 10;

// Function to print a matrix
void printMatrix(vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Function to fetch matrix from user or file
bool getMatrix(int n, vector<vector<double>>& matrix) {
    char choice;
    cout << "Enter coefficients from command line (c) or from a file (f)? (c/f): ";
    cin >> choice;

    if (choice == 'c') {
        cout << "Enter the augmented coefficient matrix:" << endl;
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n + 1);
            for (int j = 0; j < n + 1; j++) {
                cin >> matrix[i][j];
            }
        }
    } else if (choice == 'f') {
        string filename;
        cout << "Enter the filename: ";
        cin >> filename;

        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file." << endl;
            return false;
        }

        for (int i = 0; i < n; i++) {
            matrix[i].resize(n + 1);
            for (int j = 0; j < n + 1; j++) {
                file >> matrix[i][j];
            }
        }
        file.close();
    } else {
        cout << "Invalid choice." << endl;
        return false;
    }
    return true;
}

// Function to swap two rows of the matrix
void swapRows(vector<vector<double>>& matrix, int row1, int row2) {
    swap(matrix[row1], matrix[row2]);
}

// Function to perform scaled partial pivoting
int partialPivot(int n, vector<vector<double>>& matrix, int col) {
    double maxRatio = -1.0;
    int pivotRow = col;
    
    for (int i = col; i < n; i++) {
        double ratio = fabs(matrix[i][col]) / matrix[i][col];
        if (ratio > maxRatio) {
            maxRatio = ratio;
            pivotRow = i;
        }
    }
    
    if (pivotRow != col) {
        swapRows(matrix, pivotRow, col);
    }
    
    cout << "Scaled Ratios: " << endl;
    for (int i = col; i < n; i++) {
        cout << fabs(matrix[i][col]) / matrix[i][col] << " ";
    }
    cout << endl << "Pivot Row: " << pivotRow + 1 << endl;
    return pivotRow;
}

// Function to perform gaussian elimination
void gaussianElimination(int n, vector<vector<double>>& matrix) {
    for (int i = 0; i < n - 1; i++) {
        partialPivot(n, matrix, i);
        
        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n + 1; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
        cout << "Matrix after step " << i + 1 << ":" << endl;
        printMatrix(matrix);
    }
}
// Function to perform back substitution and get the results
vector<double> backSubstitution(int n, const vector<vector<double>>& matrix) {
    vector<double> results(n);
    
    for (int i = n - 1; i >= 0; i--) {
        results[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++) {
            results[i] -= matrix[i][j] * results[j];
        }
        results[i] /= matrix[i][i];
    }

    return results;
}

int main() {
    int n;
    cout << "Enter the number of linear equations to solve (<=10): ";
    cin >> n;

    if (n < 1 || n > MAXN) {
        cout << "Invalid number of equations." << endl;
        return 1;
    }

    vector<vector<double>> matrix(n);

    if (!getMatrix(n, matrix)) {
        return 1;
    }

    gaussianElimination(n, matrix);
    
    vector<double> results = backSubstitution(n, matrix);

    cout << "Solution:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << results[i] << endl;
    }

    return 0;
}

