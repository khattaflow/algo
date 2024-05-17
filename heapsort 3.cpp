#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, int &comparisons) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest, comparisons);
        comparisons++;
    }
}

void heapSort(int arr[], int n, int &comparisons) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0, comparisons);
    }
}

int main() {                                                                   
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;

    cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, arr_size, comparisons);

    cout << "Array after heapsort is \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}

