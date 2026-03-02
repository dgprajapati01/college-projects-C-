#include <stdio.h>
#include <stdlib.h> // Required for malloc

// Function to sum two integer arrays element-wise
// array1: Pointer to the first integer array
// array2: Pointer to the second integer array
// size: The number of elements in both arrays (assuming they are of equal size)
// Returns: A pointer to a newly allocated array containing the sum, or NULL if memory allocation fails.
int* sumArrays(int* array1, int* array2, int size) {
    // Allocate memory for the result array
    int* sumResult = (int*)malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (sumResult == NULL) {
        printf("Memory allocation failed!\n");
        return NULL; // Return NULL to indicate an error
    }

    // Iterate through the arrays and calculate the sum of corresponding elements
    for (int i = 0; i < size; i++) {
        sumResult[i] = array1[i] + array2[i];
    }

    return sumResult; // Return the pointer to the sum array
}

int main() {
    int arrA[] = {1, 2, 3, 4, 5};
    int arrB[] = {6, 7, 8, 9, 10};
    int size = sizeof(arrA) / sizeof(arrA[0]); // Calculate the size of the array

    // Call the function to get the sum array
    int* sumArr = sumArrays(arrA, arrB, size);

    // Check if the sum array was successfully created
    if (sumArr != NULL) {
        printf("Sum of arrays: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", sumArr[i]);
        }
        printf("\n");

        // Free the dynamically allocated memory to prevent memory leaks
        free(sumArr);
        sumArr = NULL; // Set the pointer to NULL after freeing
    }

    return 0;
}
