#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b)
{
    printf("%p\n%p\n", &a, &b);
    printf("%d\n%d\n", *a, *b);
    int t=*a; *a=*b; *b=t;
    printf("%p\n%p\n", &a, &b);
    printf("%d\n%d\n", *a, *b);
}

void sort(int arr[], int beg, int end)
{
    if (end > beg + 1) {
        int piv = arr[beg], l = beg + 1, r = end;
        while (l < r) {
            if (arr[l] <= piv)
                l++;
            else
                swap(&arr[l], &arr[--r]);
        }
        swap(&arr[--l], &arr[beg]);
        sort(arr, beg, l);
        sort(arr, r, end);
}
}

void sort_idx(int arr[], int beg, int end){
    if (end > beg + 1) {
        int piv = arr[beg], l = beg + 1, r = end;
        while (l < r) {
            if (arr[l] <= piv)
            // if (arr[beg+1] <= arr[beg])
                l++;
            else
                swap(&arr[l], &arr[--r]);
                // arr[beg+1], arr[end-1] (last element)
                // r changes value to end-1
        }
        swap(&arr[--l], &arr[beg]);
        sort(arr, beg, l);
        sort(arr, r, end);
}
}



int main(){
    int x = 4;
    int y = 5;
    printf("%p\n", &x);
    int *a = &x;
    int *b = &y; 
    swap(a, b); 
    // swap(&x,&y);

    printf("%p\n%p\n", &a, &b);
    printf("%d\n%d\n", *a, *b);

    double arr[5]; 
    printf("%d\n", x);
    printf("%.2f\n%.2f\n", arr[1], arr[--x]);
    printf("%d\n", x);

    return 0;
}