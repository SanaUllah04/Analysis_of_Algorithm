#include <iostream>
#include <ctime>
using namespace std;

// Function to sort an array using insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// A utility function to print an array
// of size n
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    const int N = 300000;
    int arr[N];

    printf("Insertion Sort\n\n");
    printf("Total Num: %d\n\n", N);

    // Get the starting time
    clock_t start = clock();

    // Insert numbers from N to 1 into the array
    for (int i = 0; i < N; ++i)
        arr[i] = N - i;

    // Sort the array using insertion sort
    insertionSort(arr, N);

    // Get the ending time
    clock_t end = clock();

    // Calculate the execution time
    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Execution Time: " << time_taken << " seconds" << endl;

    return 0;
}
