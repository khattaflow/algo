#include <iostream>
using namespace std;

// Function to merge two subarrays of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
int merge(int arr[], int p, int q, int r, int &comparisons) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = p; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        comparisons++; // Increment comparison count
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted
int mergeSort(int arr[], int p, int r, int &comparisons) {
    if (p < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int q = p + (r - p) / 2;

        // Sort first and second halves
        mergeSort(arr, p, q, comparisons);
        mergeSort(arr, q + 1, r, comparisons);

        // Merge the sorted halves
        merge(arr, p, q, r, comparisons);
    }
}

// Function to display the array with square brackets
void displayArray(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int comparisons = 0;

    cout << "Original array: ";
    displayArray(arr, n);

    mergeSort(arr, 0, n - 1, comparisons);

    cout << "Sorted array: ";
    displayArray(arr, n);

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}

