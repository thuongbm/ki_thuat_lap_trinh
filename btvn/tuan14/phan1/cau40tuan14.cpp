#include <stdio.h>
#include <stdlib.h>
int random(int minN, int maxN){
	return minN + rand() % (maxN + 1 - minN);
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void rarray(int *a, int c){
	for (int i=0;i<c;i++){
		*(a+i)=random(0,100);
	}
	for (int i = 0; i < c - 1; i++) {
        for (int j = 0; j < c - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}
main(){
	int n=random(0,100);
	int *a;
	a=(int*)malloc (n *sizeof(int));
	rarray(a,n);
	for (int i=0;i<n;i++){
		printf ("%d ", a[i]);
	}
	free(a);
}
