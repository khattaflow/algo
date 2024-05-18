#include <iostream>

// Function to add two matrices
void addMatrix(int A[4][4], int B[4][4], int C[4][4], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void subtractMatrix(int A[4][4], int B[4][4], int C[4][4], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Function to multiply two matrices using Strassen's algorithm
void strassen(int A[4][4], int B[4][4], int C[4][4], int n) {
    // Base case: If the matrices are 1x1, perform a simple multiplication
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // Split matrices A and B into quadrants
    int half = n / 2;
    int A11[half][half], A12[half][half], A21[half][half], A22[half][half];
    int B11[half][half], B12[half][half], B21[half][half], B22[half][half];

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
    int M1[half][half], M2[half][half], M3[half][half], M4[half][half], M5[half][half], M6[half][half], M7[half][half];
    addMatrix(A11, A22, M1, half);
    addMatrix(B11, B22, M2, half);
    addMatrix(A21, A22, M3, half);
    subtractMatrix(B12, B22, M4, half);
    subtractMatrix(B21, B11, M5, half);
    addMatrix(A11, A12, M6, half);
    subtractMatrix(A21, A11, M7, half);

    // Compute result sub-matrices
    int C11[half][half], C12[half][half], C21[half][half], C22[half][half];
    int temp1[half][half], temp2[half][half];
    addMatrix(M1, M4, temp1, half);
    subtractMatrix(temp1, M5, temp2, half);
    addMatrix(temp2, M7, C11, half);
    addMatrix(M3, M5, C12, half);
    addMatrix(M2, M4, C21, half);
    subtractMatrix(M1, M2, temp1, half);
    addMatrix(temp1, M3, temp2, half);
    addMatrix(temp2, M6, C22, half);

    // Combine result matrices
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[4][4], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int A[4][4] = {{1, 2, 4, 5}, 
				   {3, 4, 7, 8},
				   {9, 8, 1, 10},
				   {13, 14, 15, 16}};
				   
    int B[4][4] = {{15, 16, 11, 12}, 
				   {17, 18, 19, 10},
				   {11, 12, 13, 14},
				   {16, 17, 19, 20}};

    std::cout << "Matrix A:" << std::endl;
    printMatrix(A, 4);
    std::cout << std::endl;
    
    std::cout << "Matrix B:" << std::endl;
    printMatrix(B, 4);
    std::cout << std::endl;

    int C[4][4];
    strassen(A, B, C, 4);

    std::cout << "Resultant Matrix C:" << std::endl;
    printMatrix(C, 4);

    return 0;
}
