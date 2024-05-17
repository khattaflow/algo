#include <iostream>
#include <vector>
using namespace std;

// Function to add two matrices
vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Function to subtract two matrices
vector<vector<int>> subtractMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Function to multiply two matrices using Strassen's algorithm
vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Base case: If the matrices are 1x1, perform a simple multiplication
    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1, 0));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Split matrices A and B into quadrants
    int half = n / 2;
    vector<vector<int>> A11(half, vector<int>(half)), A12(half, vector<int>(half)), A21(half, vector<int>(half)), A22(half, vector<int>(half));
    vector<vector<int>> B11(half, vector<int>(half)), B12(half, vector<int>(half)), B21(half, vector<int>(half)), B22(half, vector<int>(half));

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // Compute intermediate sub-matrices
    vector<vector<int>> M1 = strassen(addMatrix(A11, A22), addMatrix(B11, B22));
    vector<vector<int>> M2 = strassen(addMatrix(A21, A22), B11);
    vector<vector<int>> M3 = strassen(A11, subtractMatrix(B12, B22));
    vector<vector<int>> M4 = strassen(A22, subtractMatrix(B21, B11));
    vector<vector<int>> M5 = strassen(addMatrix(A11, A12), B22);
    vector<vector<int>> M6 = strassen(subtractMatrix(A21, A11), addMatrix(B11, B12));
    vector<vector<int>> M7 = strassen(subtractMatrix(A12, A22), addMatrix(B21, B22));

    // Compute result sub-matrices
    vector<vector<int>> C11 = addMatrix(subtractMatrix(addMatrix(M1, M4), M5), M7);
    vector<vector<int>> C12 = addMatrix(M3, M5);
    vector<vector<int>> C21 = addMatrix(M2, M4);
    vector<vector<int>> C22 = addMatrix(subtractMatrix(addMatrix(M1, M3), M2), M6);

    // Combine result matrices
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }

    return C;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {{1, 2, 4, 5}, 
							{3, 4, 7, 8},
							{9, 8, 1, 10},
							{13, 14, 15, 16}};
							
    vector<vector<int>> B = {{15, 16, 11, 12}, 
							 {17, 18, 19, 10},
							 {11, 12, 13, 14},
							 {16, 17, 19, 20}};

    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout<<endl;
    
    cout << "Matrix B:" << endl;
    printMatrix(B);
    cout<<endl;

    vector<vector<int>> C = strassen(A, B);

    cout << "Resultant Matrix C:" << endl;
    printMatrix(C);

    return 0;
}

