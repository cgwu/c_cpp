/**
 * 堆排序(使用的是二叉树,递归方式)
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "util.h"

// 筛选(最小堆),数组下标从0开始,需要转换
void Sift(int arr[], int root_idx, int limit_idx){
    int left_idx = (root_idx + 1) * 2 - 1;
    if(left_idx > limit_idx) return;
    int right_idx = left_idx + 1;
    if(right_idx > limit_idx){//只有左侧结点
        if(arr[left_idx] < arr[root_idx]){ 
            Swap(& arr[root_idx], & arr[left_idx]); //左结点比根结点小，交换
            Sift(arr, left_idx, limit_idx);
        }
        return;
    }
    int min_idx = arr[left_idx] < arr[right_idx] ? left_idx : right_idx;
    if(arr[root_idx] > arr[min_idx]){
        Swap(& arr[root_idx], & arr[min_idx]);
        Sift(arr, min_idx, limit_idx);
    }
}
//创建最小堆
void CreateSmallHeap(int arr[], int start_idx, int limit_idx){
    int i = (limit_idx + 1) / 2 - 1;  //最后一个有子结点的根结点
    for(;i >= start_idx; i--) Sift(arr, i, limit_idx);
}
//按层输出
void LevelOrder(int arr[], int limit_idx){
    for(int i=0,row=1; i <= limit_idx; row++){
        int row_cnt = pow(2,row - 1);   //完全二叉树每一层的个数
        for(int j=0;j<row_cnt && i <= limit_idx; j++){
            printf("%d, ",arr[i++]);
        }
        printf("\n");
    }
}
//堆排序
void HeapSort(int arr[], int root_idx, int limit_idx){
    if(limit_idx >= root_idx){
        printf("%d ", arr[root_idx]);
        arr[root_idx] = arr[limit_idx--];   //最后一个结点放到根位置
        Sift(arr, root_idx, limit_idx);
        HeapSort(arr,root_idx,limit_idx);
    }
}
int main(){
    //int arr[] = {888,9,7,8,6,5,0,0,0,1,2,3,4,5};
    int arr[] = {8,1,2,10,9,7};
    int len =sizeof(arr)/sizeof(int);
    PrintArray(arr,len);
    //SelectionSort(arr, len);
    printf("-----------\n");
    printf("生成最小堆之前:\n");
    LevelOrder(arr, len - 1);
    printf("-----------\n");
    CreateSmallHeap(arr, 0, len - 1);
    printf("输出最小堆:\n");
    LevelOrder(arr, len - 1);
    printf("堆排序后:\n");
    HeapSort(arr, 0, len - 1);
    printf("\n-----------\n");
    PrintArray(arr,len);
    return 0;
}

