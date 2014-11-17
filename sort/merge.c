/**
 *归并排序
 */
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void Merge(int a[], int l, int m, int r){
    if(!( l <= m && m <= r)) return;
    int i=l, j = m + 1, idx = 0;
    int * pa = calloc(r-l+1, sizeof(int));
    while( i <= m && j <= r){
        if(a[i] < a[j]) pa[idx++] = a[i++];
        else pa[idx++] = a[j++];
    }
    while( i<= m){ pa[idx++] = a[i++]; }
    while( j<= r){ pa[idx++] = a[j++]; }   //右边有余
    for(idx = l,i = 0; idx <= r; idx++,i++){
        a[idx] = pa[i];
    }
    free(pa);
}

void MergeSort(int a[], int start, int end){
    if(end - start <= 1){
        Merge(a, start, start, end);
    }
    else{
        int m = (start + end) / 2;
        MergeSort(a, start, m);
        MergeSort(a, m+1, end);
        Merge(a, start, m, end);
    }
}

int main(){
    int arr[] = {9,7,8,6,5,0,0,0,1,2,3,4,5};
    int len =sizeof(arr)/sizeof(int);
    PrintArray(arr,len);
    MergeSort(arr, 0, len - 1);
    PrintArray(arr,len);

    /*
    int arr[] = {3,4,1,2};
    PrintArray(arr,sizeof(arr)/sizeof(int));
    Merge(arr, 0, 1, 3);
    PrintArray(arr,sizeof(arr)/sizeof(int));
    
    int arr1[] = {3,4,1};
    PrintArray(arr1,sizeof(arr1)/sizeof(int));
    Merge(arr1, 0, 1, 2);
    PrintArray(arr1,sizeof(arr1)/sizeof(int));

    int arr2[] = {4,1,2};
    PrintArray(arr2,sizeof(arr2)/sizeof(int));
    Merge(arr2, 0, 0, 2);
    PrintArray(arr2,sizeof(arr2)/sizeof(int));
    */
    /*
    int * parr = calloc(10,sizeof(int*));
    free(parr);
    printf("sizeof(int*):%d\n",sizeof(int*));
    */
    printf("done.\n");
    return 0;
}
