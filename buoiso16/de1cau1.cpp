#include <stdio.h>
#include <stdlib.h>
void input(int n, int **a, FILE *f){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			fscanf (f,"%d", &a[i][j]);
		}
	}
}
void output(int n, int **a){
	for (int i=0;i<n;i++){
		printf ("\n");
		for (int j=0;j<n;j++){
			printf ("%d ", a[i][j]);
		}
	}
}
float average(int n, int **a){
	int sum=0;
	float check=0;
	for (int i=0;i<n;i++){
		for (int j=n-1;j<=i;j++){
			sum+=a[i][j];
			check++;
		}
	}
	return (float)(sum/check);
}
int check(int n,int **a){
	for (int i=0;i<n;i++){
		for (int j=0;j<i;j++){
			if (a[i][j]!=0) return 0;
		}
	}
	return 1;
}
main(){
	int n;
	FILE *f;
	f=fopen("de1cau1input.txt","r");
	fscanf (f,"%d", &n);
	int **a;
	a=(int**) malloc(n*n*sizeof(int*));
	for (int i=0;i<n;i++){
		a[i]=(int*) malloc(n*sizeof(int));
	}
	input(n,a,f);
	output(n,a);
	printf ("\ntrung binh cong cac phan tu duoi duong cheo phu la: %.2f", average(n,a));
	if (check(n,a)) printf ("\nla tam giac tren");
	else printf ("\nkhong la tam giac tren");	
}
