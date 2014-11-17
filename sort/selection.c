/**
 * 选择排序
 */
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void SelectionSort(int arr[], int len){
    for(int i=0; i < len; i++){
        for(int j = i+1; j< len; j++){
            if(a[i] > a[j]) Swap(&a[i], &a[j]);
        }
    }
}
int main(){
    int arr[] = {9,7,8,6,5,0,0,0,1,2,3,4,5};
    int len =sizeof(arr)/sizeof(int);
    PrintArray(arr,len);
    SelectionSort(arr, len);
    PrintArray(arr,len);
    return 0;
}
