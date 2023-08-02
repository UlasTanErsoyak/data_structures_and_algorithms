#include <stdio.h>
#include <stdlib.h>

void merge(int array[],int left[],int leftSize,int right[],int rightSize);
void merge_sort(int array[],int len);

int main(){
    int array[] = {9,4,7,5,2,8,1,6,3};
    int len = sizeof(array) / sizeof(array[0]);

    printf("unsorted: ");
    for (int i=0;i<len;i++){
        printf("%d ",array[i]);
    }

    merge_sort(array, len);

    printf("\nsorted: ");
    for (int i=0;i<len;i++){
        printf("%d ",array[i]);
    }

    return 0;
}

void merge(int array[],int left[],int leftSize,int right[],int rightSize){
    int i = 0, j = 0, k = 0;

    while (i<leftSize && j<rightSize){
        if (left[i] <= right[j]){
            array[k++] = left[i++];
        }
        else {
            array[k++]=right[j++];
        }
    }

    while (i < leftSize){
        array[k++]=left[i++];
    }

    while (j < rightSize){
        array[k++]=right[j++];
    }

    free(left);
    free(right);
}

void merge_sort(int array[],int len){
    if (len <= 1) return;

    int mid = len / 2;
    int *left = (int*)malloc(mid*sizeof(int));
    int *right = (int*)malloc((len-mid)*sizeof(int));

    for (int i=0;i<mid;i++){
        left[i]=array[i];
    }

    for (int i=mid;i<len; i++){
        right[i-mid]=array[i];
    }

    merge_sort(left,mid);
    merge_sort(right,len-mid);
    merge(array,left,mid,right,len-mid);
}
