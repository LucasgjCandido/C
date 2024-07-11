#include <stdio.h> 
 
void merge(int arr[], int left, int middle, int right) { 
    int helper[right - left + 1]; 
    int i = left, j = middle + 1, k = 0; 
  
    while (i <= middle && j <= right) { 
        if (arr[i] <= arr[j]) { 
            helper[k] = arr[i]; 
            i++; 
        } else { 
            helper[k] = arr[j]; 
            j++; } 
        k++; } 
    while (i <= middle) { 
        helper[k] = arr[i]; 
        i++; 
        k++;} 
    for (int p = 0; p < k; p++) { 
        arr[left + p] = helper[p];}} 
  
  
void mergeSort(int arr[], int left, int right) { 
    if (left < right) { 
        int middle = (left + right) / 2; 
        mergeSort(arr, left, middle); 
        mergeSort(arr, middle + 1, right); 
        merge(arr, left, middle, right);}} 
  
int main() { 
    int arr[] = {12, 11, 13, 5, 6, 7, 8}; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
    printf("Array antes da ordenacao:\n"); 
    for (int i = 0; i < arr_size; i++) { 
        printf("%d ", arr[i]);} 
 
    printf("\n"); 
 
 
 
    mergeSort(arr, 0, arr_size - 1); 
    printf("Array ordenado:\n"); 
    for (int i = 0; i < arr_size; i++) { 
        printf("%d ", arr[i]); } 
    printf("\n"); 
    return 0;} 
