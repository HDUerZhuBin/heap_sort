// #include<stdio.h>
#include"heapsort.h"
#include"showArr.h"

/******************************************************************************************************************************
 * 自下向上将一颗完全二叉树转换为大顶堆
 * 完全二叉树节点编号0,1,2,3,4,....
 * 则当前节点编号为i,如果有左孩子，则左孩子节点编号为2*i+1;如果有右孩子，则节点编号为2*i+2;其如果不是根节点（编号为0），则其父亲节点编号为(i-1)//2
 * 大顶堆的递归定义是根节点的数据始终大于其左右孩子节点数据
 * 
 * 为了将一个无序数组对应的二叉树转变为大顶堆，逻辑结构上需要从二叉树最右边叶子节点开始（从存储结构来说，要从数组末尾开始），递归查看其和父亲节点的数值大
 * 小比较，如果父亲节点数值小于当前节点，则将父亲节点和当前节点的数据进行交换，直到递归结束条件（当前节点为根节点，数组中编号为0）未知，此时构建出大顶堆，
 * 堆顶元素是当前数据堆中的最大值，但是子节点中数据大小排序未知
 ******************************************************************************************************************************/
 
 void swap(float* a,float* b){
     float temp_data = *a;
     *a = *b;
     *b = temp_data;

     return ;
 }
 
 
 void max_heapify(float arr[],int len_arr){
    int i;
    // printf("\nshow the input signal:\n");
    // show_arr(arr,len_arr);
    for(i=len_arr-1;i>0;i--){//从数组末尾开始遍历元素，对堆的递归定义进行检验，直到堆顶元素，这里仅仅是将当前数组中最大元素至于堆顶，但并不是二叉堆，如果是堆排序，仅仅这里就够了，否则需要向下遍历对堆进行更新
        float current_node_data = arr[i];
        int father_node_idx = (int)((i-1)/2);
        float father_node_data = arr[father_node_idx];
        if(current_node_data>father_node_data){
            swap(&(arr[i]),&(arr[father_node_idx]));
        }
    }
    // printf("\nshow the heapify and put it into tail\n");
    // show_arr(arr,len_arr);
    swap(&(arr[0]),&(arr[len_arr-1]));
    // printf("\nput the max into tail:\n");
    // show_arr(arr,len_arr);
    // printf("\n*************************************************\n");
}

void heap_sort(float arr[],int len_arr){
    int i;
    for(i=len_arr;i>1;i--){//迭代计算出子序列最大值，将最大值
        max_heapify(arr,i);
    }
}