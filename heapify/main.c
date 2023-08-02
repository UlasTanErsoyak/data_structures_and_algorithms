#include <stdio.h>
int heap(int array[],int len);
void heapify(int array[],int len,int root);
int main(){
    int array[] = {3,4,1,6,9,8};
    int len = 6;
    for(int i=0;i<len;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    heap(array,len);
    for(int i=0;i<len;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}

int heap(int array[],int len){
    for(int i=(len/2)-1;i>=0;i--){
        heapify(array,len,i);
    }
}
void heapify(int array[],int len,int root){
    int largest = root;
    int left = (root*2)+1;
    int right = (root*2)+2;

    if(left<len && array[left]>array[largest]) largest = left;
    if(right<len && array[right]>array[largest]) largest = right;
    if (largest != root) {

        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;

        heapify(array, len, largest);
    }
}