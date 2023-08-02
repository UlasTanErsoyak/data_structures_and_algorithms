#include <stdio.h>
#include <stdlib.h>
void insertion_sort(int array[],int len);
void print_array(int array[], int len);
int main(){
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    insertion_sort(arr, n);
    print_array(arr, n);
 
    return 0;
}
 
void insertion_sort(int array[],int len){
    for(int i=1;i<len;i++){
        int current = array[i];
        int previous = i -1;
        while(previous>=0 && array[previous]>current){
            array[previous+1] = array[previous];
            previous = previous - 1;
        }
        array[previous + 1] = current;

    }
}
void print_array(int array[], int len){
    for (int i = 0; i < len; i++){
        printf("%d ", array[i]);
    }

}