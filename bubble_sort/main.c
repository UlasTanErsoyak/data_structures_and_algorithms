#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int array[], int len);
void peek(int array[],int len);

int main(){
  int data[] = {-2, 45, 0, 11, -9};
  
  int len = sizeof(data) / sizeof(data[0]);
  bubble_sort(data, len);
  
  peek(data, len);
    return 0;
    
}
void peek(int array[], int len) {
  for (int i=0;i<len;i++) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

void bubble_sort(int array[],int len){
    for (int i=0;i<len;i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
   } 
}