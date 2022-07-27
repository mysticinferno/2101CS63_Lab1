//sorting program
#include <stdio.h>
// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
//function to swap
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
//insertion sort
void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}
//selection sort
void selectionSort(int array[], int size) {
 for (int step = 0; step < size - 1; step++) {
   int min_idx = step;
   for (int i = step + 1; i < size; i++) {

     // To sort in descending order, change > to < in this line.
     // Select the minimum element in each loop.
     if (array[i] < array[min_idx])
       min_idx = i;
   }

   // put min at the correct position
   swap(&array[min_idx], &array[step]);
 }
}
//bubble sort
void bubbleSort(int array[], int size) {

  // loop to access each array element
  for (int step = 0; step < size - 1; ++step) {

    // loop to compare array elements
    for (int i = 0; i < size - step - 1; ++i) {

      // compare two adjacent elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {

        // swapping occurs if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}
