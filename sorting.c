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
// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}
// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}
// function to find the partition position
int partition(int array[], int low, int high) {

  // select the rightmost element as pivot
  int pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}
void quickSort(int array[], int low, int high) {
  if (low < high) {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}
int main(){

  int n;
  printf("choose size of array:\n");
  scanf("%d", &n);
  int data[n];
  for(int i=0;i<n;i++){
    printf("enter the %dth element of data:\n", i);
    scanf("%d", &data[i]);
  }

  int size = sizeof(data) / sizeof(data[0]);

  int op;
 printf("which type of sorting you want to do:\n");
 printf("1. insertion sort\n");
 printf("2. Selection sort\n");
 printf("3. Bubble sort\n");
 printf("4. Merge sort\n");
 printf("5. Quick sort\n");
 printf("chosse type of sorting you want to do:\n");
 scanf("%d", &op);
 printf("Unsorted Array\n");
 printArray(data, size);
//calling insertion sort function
 if(op==1){
   insertionSort(data, size);
   printf("Sorted array in ascending order:\n");
   printArray(data, size);
 }
 //calling selection sort function
 else if (op==2)
 {
   selectionSort(data, size);
   printf("Sorted array in Acsending Order:\n");
   printArray(data, size);
 }
 //calling Bubble sort function
 else if (op==3)
 {
   bubbleSort(data, size);
   printf("Sorted Array in Ascending Order:\n");
   printArray(data, size);
 }
 //calling Merge sort function
 else if (op==4)
 {
   mergeSort(data, 0, size - 1);
   printf("Sorted arrayin Ascending order: \n");
   printArray(data, size);
 }
 //calling quick sort function
 else{
   quickSort(data, 0, size - 1);
   printf("Sorted array in ascending order: \n");
   printArray(data, size);
 }
 return 0;
}
