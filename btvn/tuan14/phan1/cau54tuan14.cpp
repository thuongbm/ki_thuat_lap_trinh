//#include <stdio.h>
//#include <stdlib.h>
//
//void swap(int *a, int *b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//void bubbleSort(int arr[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (arr[j] > arr[j + 1]) {
//                swap(&arr[j], &arr[j + 1]);
//            }
//        }
//    }
//}
//
//int main() {
//    FILE *f_in, *f_out;
//    f_in = fopen("ARRAY.INP", "r");
//    f_out = fopen("ARRAY.OUT", "w");
//
//    int n;
//    fscanf(f_in, "%d", &n);
//    int arr[n];
//
//    for (int i = 0; i < n; i++) {
//        fscanf(f_in, "%d", &arr[i]);
//    }
//
//    bubbleSort(arr, n);
//
//    fprintf(f_out, "Sorted array: ");
//    for (int i = 0; i < n; i++) {
//        fprintf(f_out, "%d ", arr[i]);
//    }
//
//    fclose(f_in);
//    fclose(f_out);
//    return 0;
//}
//
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void arrange(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
            }
        }
    }
}

int main() {
    FILE *f;
    f = fopen("input54.txt", "r");
    int n;
    fscanf(f, "%d", &n);
    int a[n];
    FILE *f2;
    f2 = fopen("output54.txt", "w");
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d", &a[i]);
    }
    arrange(a, n);
    fprintf (f2,"%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(f2, "%d ", a[i]);
    }
    fclose(f);  
    fclose(f2); 
    return 0;
}

