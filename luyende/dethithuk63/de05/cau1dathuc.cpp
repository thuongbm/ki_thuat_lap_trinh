#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void input(int n, int *a, FILE *f){
	for (int i=0;i<=n;i++){
		fscanf (f,"%d", a+i);
	}
}
void output (int n, int *a){
	for (int i=0;i<=n;i++){
		printf ("%d", *(a+i));
	}
}
int derivative(int n, int *a, int x){
	int sum=0;
	for (int i=0;i<=n;i++){
		sum+=i*a[i]*pow(x,i-1);
	}
	return sum;
}
int sum(int n, int *a, int x){
	int sum=0;
	for (int i=0;i<=n;i++){
		sum+=a[i]*pow(x,i);
	}
	return sum;
}
int max(int a,int b){
	return (a>b)?a:b;
}
int poly_2(int m, int n, int *a, int *b, int x, int y){
	int sum=0;
	for (int i=0;i<=max(m,n);i++){
		sum+=a[i]*pow(x,i)+b[i]*pow(y,i);
	}
	return sum;
}
main(){
	int n;
	FILE *f;
	f=fopen("dathuc.txt", "r");
	int *a;
	a=(int*) malloc(n*sizeof(int));
}
