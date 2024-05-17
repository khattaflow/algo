#include <iostream>
#include <algorithm> // for std::max_element
using namespace std;

void countSort(int arr[], int n) {
    // Find the maximum element in the array
    int max_element = *std::max_element(arr, arr + n);

    // Create a count array to store the count of each element
    int count[max_element + 1] = {0};

    // Count the occurrences of each element in the input array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Create a temporary array to store the sorted elements
    int output[n];
    int output_index = 0;

    // Fill the output array with sorted elements based on count array
    for (int i = 0; i <= max_element; i++) {
        while (count[i]--) {
            output[output_index++] = i;
        }
    }

    // Copy the sorted elements from the output array to the input array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    countSort(arr, n);

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

