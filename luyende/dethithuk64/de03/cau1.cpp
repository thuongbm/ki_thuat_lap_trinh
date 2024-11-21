#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void input(int n, int *a, FILE *f){
	for (int i=0;i<n;i++){
		fscanf (f, "%d", a+i);
	}
}
void output(int n, int *a){
	for (int i=0;i<n;i++){
		printf ("%d ", *(a+i));
	}
}
float result(int n, int *a, int d){
	float sum=0;
	for (int i=0;i<n;i++){
		sum+=a[i]*pow(d, i);
	}
	return sum;
}
int max(int n, int m){
	return (n>m)?n:m;
}
int *coefficient(int *a, int *b, int m, int n){
	int *c;
	c=(int*) calloc(max(m,n),sizeof(int));
	for (int i = 0; i < n; i++) {
        c[i] += a[i];
    }
    for (int i = 0; i < m; i++) {
        c[i] -= b[i];
    }
	return c;
}
main(){
	FILE *f;
	f=fopen("cau1input.txt", "r");
	int n,m;
	fscanf (f,"%d%d", &n, &m);
	int *a,*b;
	a=(int*) malloc(n*sizeof(int));
	b=(int*) malloc(m*sizeof(int));
	input(n,a,f);
	input(m,b,f);
	output(n,a);
	printf ("\n");
	output(m,b);
	printf ("\n");
	int d,d2;
	scanf ("%d%d", &d,&d2);
	if ((result(n,a,d)-result(m,b,d2))>0) printf ("ket qua cua bieu thuc la: %.2f\n", sqrt(result(n,a,d)-result(m,b,d2)));
	else printf ("khong the thuc hien theo bieu thuc");
}
