#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void input(int *a, int n, FILE *f1){
	for(int i=0;i<n;i++){
		fscanf (f1,"%d", a+i);
	}
}
void output(int *a, int n){
	for (int i=0;i<n;i++){
		printf ("%d ", *(a+i));
	}
}
int max(int *a, int n){
	int max=INT_MIN;
	for (int i=0;i<n;i++){
		if (*(a+i)>max){
			max=*(a+i);
		}
	}
	return max;
}
void swap(int *a, int *b){
	int temp=*a;
		*a=*b;
		*b=temp;;
}
void bubblesort(int *a, int n){
	for(int i=0;i<n-1;i++){
		for (int j=0;j<n;j++){
			if (*(a+i)>*(a+j)){
				swap(&a[i], &a[j]);
			}
		}
	}
}
main(){
	FILE *f1;
	f1=fopen("input1.txt", "r");
	int m,n;
	fscanf (f1, "%d%d", &m, &n);
	int *a, *b;
	a=(int*) malloc(m*sizeof(int));
	b=(int*) malloc(n*sizeof(int));
	input(a,m,f1);
	input(b,n,f1);
	printf ("\nday so sau khi duoc nhap la: ");
	printf ("\n");
	output(a,m);
	printf ("\n");
	output(b,n);
	int d=max(a,m);
	printf ("\nso lon nhat cua a la: %d", d);
	d=max(b,n);
	printf ("\nso lon nhat cua b la: %d\n", d);
	printf ("day so sau khi duoc sap xep la: \n");
	bubblesort(a,m);
	bubblesort(b,n);
	output(a,m);
	printf ("\n");
	output(b,n);
}
