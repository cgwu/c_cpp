/**
 * 冒泡排序
 */
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void BubbleSort(int arr[], int len){
    for(int i=0; i < len-1; i++){
        for(int j = 0; j< len-1-i; j++){
            if(arr[j] > arr[j+1]) Swap(&arr[j], &arr[j+1]);
        }
    }
}
int main(){
    //int arr[] = {100,9,7,8,6,5,0,0,0,1,2,3,4,5,99};
    int arr[] = { 1, -3, 2, -1, -4};
    int len =sizeof(arr)/sizeof(int);
    PrintArray(arr,len);
    BubbleSort(arr, len);
    PrintArray(arr,len);
    return 0;
}
