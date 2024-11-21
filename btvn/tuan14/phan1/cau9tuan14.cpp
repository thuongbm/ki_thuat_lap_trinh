#include <stdio.h>
#include <stdlib.h>
int divisor(int a){
	int k=0;
	for (int i=1;i<a;i++){
		if (a%i!=0){
			k++;
		}
	}
	return k;
}
void input(int *a, int n){
	for (int i=0;i<n;i++){
		scanf ("%d", a+i);
	}
}
void output(int *a, int n){
	for (int i=0;i<n;i++){
		printf ("%d ", *(a+i));
	}
}
int *find(int *a, int n, int *k){
	*k=0;
	int *b;
	b=(int*)malloc(n*sizeof(int));
	for (int i=0;i<n;i++){
		if (divisor(a[i])>3){
			b[*k]=a[i];
			(*k)++;
		}
	}
	return b;
}
//int* find(int *a, int n, int *k) {
//    int count = 0;
//    for (int i = 0; i < n; i++) {
//        if (divisor(a[i]) > 3) {
//            count++;
//        }
//    }
//
//    *k = count;
//    int *b = (int*)malloc(count * sizeof(int));
//    if (b == NULL) {
//        printf("Khong du bo nho!\n");
//        exit(1);
//    }
//
//    int index = 0;
//    for (int i = 0; i < n; i++) {
//        if (divisor(a[i]) > 3) {
//            b[index++] = a[i];
//        }
//    }
//    return b;
//}
int findLastOccurrence(int arr[], int n, int x) {
    int lastOccurrence = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            lastOccurrence = i;
        }
    }
    return lastOccurrence;
}
int maxnegative(int arr[], int n) {
    int maxNegative = -1; // Kh?i t?o maxNegative là -1
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0 && (maxNegative == -1 || arr[i] > arr[maxNegative])) {
            maxNegative = i;
        }
    }
    return maxNegative; // Tr? v? ch? s? c?a ph?n t? âm l?n nh?t
}
main(){
	int n;
	scanf ("%d", &n);
	int *a;
	a=(int*)malloc(n*sizeof(int));
	input(a,n);
	output(a,n);
	int c;
	int *b=find(a,n, &c);
	if (c==0) printf ("\nkhong co so co so uoc chung lon hon 3");
	else {
		printf ("\nnhung so co so uoc chung lon 3 la: ");
		output(b,c);
	}
}
