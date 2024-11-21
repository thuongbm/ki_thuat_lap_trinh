#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void input(int m,int n, int **a, FILE *f){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			fscanf (f,"%d", &a[i][j]);
		}
	}
}
void output(int m, int n, int **a){
	for (int i=0;i<m;i++){
		printf ("\n");
		for (int j=0;j<n;j++){
			printf ("%d ", a[i][j]);
		}
	}
}
float average(int m, int n, int **a){
	int sum=0;
	int check=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j+=2){
			sum+=a[i][j];
			check++;
		}
	}
	if (check==0) return 0;
	else return (float)(sum/check);
}
int find(int m, int n, int **a){
	int min=INT_MAX;
	int check=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (a[i][j]>0&&a[i][j]<min){
				check=1;
				min=a[i][j];
			}
		}
	}
	if (check==0) return -1;
	else return min;
}
main(){
	FILE *f;
	int m,n;
	f=fopen("cau1input.txt","r");
	fscanf (f,"%d%d", &m,&n);
	int **a;
	a=(int**) malloc(m*sizeof(int*));
	for (int i=0;i<n;i++){
		a[i]=(int*) malloc(n*sizeof(int));
	}
}
