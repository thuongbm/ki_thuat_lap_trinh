#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void input(int m, int n, int **a, FILE *f){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			fscanf (f, "%d", &a[i][j]);
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
int accumulation(int m, int n, int **a){
	int accum=1;
	int check=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (a[i][j]%2!=0){
				check=1;
				accum*=a[i][j];
			}
		}
	}
		
	if (check==1&&accum>211) return accum;
	if (check==0) return -1;
	else if (accum<=211) return 0;
}
int min_even_num(int m, int n, int **a){
	int min=INT_MAX;
	int check=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (a[i][j]%2==0&&a[i][j]<min){
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
	f=fopen("cau1input.txt", "r");
	int m, n;
	fscanf (f, "%d%d", &m, &n);
	int **a;
	a=(int**) malloc(m*sizeof(int*));
	for (int i=0;i<m;i++){
		a[i]=(int*) malloc(n*sizeof(int));
	}
	input(m,n,a,f);
	output(m,n,a);
	if (accumulation(m,n,a)==-1) printf ("\nma tran khong co so le");
	else if (accumulation(m,n,a)==0) printf ("\ntich cua ma tran khong lon hon 211");
	else printf ("\ntich cua ma tran thoa man dieu kien la %d", accumulation(m,n,a));
	if (min_even_num(m,n,a)==-1) printf ("\nkhong co so chan nao");
	else{
		printf ("\nso chan nho nhat la %d", min_even_num(m,n,a));
		printf ("\ncot va hang chua so chan nho nhat la: ");
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				if (min_even_num(m,n,a)==a[i][j]){
					printf ("%d %d", i,j);
					break;
				}
			}
		}
	} 
}
