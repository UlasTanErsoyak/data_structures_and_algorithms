#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);
void selection_sort(int array[], int len);
void peek(int array[], int len);

int main(){
    int data[] = {202, 12, 5, 2, 52};
    int size = sizeof(data) / sizeof(data[0]);
    selection_sort(data, size);
    peek(data, size);
    return 0;
}

void selection_sort(int array[], int len){
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        swap(&array[i], &array[min]);
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void peek(int array[], int len){
    for (int i = 0; i < len; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}
