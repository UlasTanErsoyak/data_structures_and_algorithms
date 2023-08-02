#include <stdio.h>
#include <stdlib.h>
int partition(int* array,int start,int end);
void swap(int* a, int* b);
void quick_sort(int* array,int start,int end);
int main(){
    int a[] = {3,6,1,4,2,8,9,7,0};
    quick_sort(a,0,9);
    for(int i=0;i<9;i++){
        printf("%d",a[i]);
    }
    return 0;
}
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int* array,int start,int end){
    int pivot = array[end];
    int p_idx = start;
    for(int i=start;i<end;i++){
        if(array[i]<=pivot){
            swap(&array[i],&array[p_idx]);
            p_idx++;
        }
    }
    swap(&array[p_idx],&array[end]);
    return p_idx;
}
void quick_sort(int* array,int start,int end){
    if(start<=end){
        int p_idx = partition(array,start,end);
        quick_sort(array,start,p_idx-1);
        quick_sort(array,p_idx+1,end);
    }
}