#include <stdio.h>

int main() {
    int n, i;
    float sum = 0.0, average;

    // Ask user for number of elements
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // Declare an array to hold the integers
    int arr[n];

    // Input the elements
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Calculate average
    average = sum / n;

    // Print the average
    printf("Average of the entered integers: %.2f\n", average);

    return 0;
}
