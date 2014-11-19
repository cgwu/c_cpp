/**
 * 快速排序
 */
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

/**
 * 进行一趟快速排序
 */
void QuickSort(int arr[], int start_idx, int end_idx){
    if(start_idx > end_idx) return;
    int start = start_idx, end = end_idx;
    int flag = arr[start];
    while(start < end){
        for(;arr[end]>=flag && start<end; end--);
        if(start< end) arr[start++] = arr[end];
        for(;arr[start]<=flag && start<end;start++);
        if(start < end) arr[end--] = arr[start];
    }
    if(start != end) printf("start != end; error!\n");
    arr[start] = flag;
    QuickSort(arr,start_idx,start - 1);
    QuickSort(arr,start + 1, end_idx);
}

int main(){
    int arr[] = {100,9,7,8,6,5,0,0,0,1,2,3,4,5,99};
    //int arr[] = { 1, -3, 2, -1, -4};
    //int arr[] = {2, 1, 3};
    int len =sizeof(arr)/sizeof(int);
    PrintArray(arr,len);
    QuickSort(arr, 0, len-1);
    PrintArray(arr,len);
    return 0;
}
