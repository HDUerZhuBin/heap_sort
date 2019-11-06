#include"heapsort.h"
#include"showArr.h"

int main(){
    float test_arr[] = {5,8,7,9,4,6,2,3,1};
    int len_test_arr = sizeof(test_arr)/sizeof(test_arr[0]);

    printf("show the origin signal:\n");
    show_arr(test_arr,len_test_arr);

    heap_sort(test_arr,len_test_arr);

    printf("show the sort signal:\n");
    show_arr(test_arr,len_test_arr);


    return 0;
}