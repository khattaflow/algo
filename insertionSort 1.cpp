#include <iostream>
using namespace std;

// Function to perform insertion sort and return the number of comparisons
int insertionSort(int arr[], int n) {
    int count = 0;
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            count++;
        }
        arr[j + 1] = key;
    }
    return count;
}

// Function to display the array
void displayArray(int arr[], int n) {
    
    for (int i = 0; i < n; i++) {
        cout << " "<< arr[i] << " ";
        }
        return;
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
    
    cout << "Original array: " << endl;
    cout<< "[";
    displayArray(arr, n);
    cout<< "]" << endl;
    
    int comparisons = insertionSort(arr, n);
    
    cout << "Sorted array: " << endl;
    cout<< "[";
    displayArray(arr, n);
    cout<< "]" << endl;
    
    cout << "Number of comparisons: " << comparisons << endl;
    
    return 0;
}

