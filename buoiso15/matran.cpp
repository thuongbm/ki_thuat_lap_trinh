#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
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
int max(int m,int n, int **a){
	int max=INT_MIN;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (a[i][j]>max) max=a[i][j];
		}
	}
	return max;
}
int min(int m,int n, int **a){
	int min=INT_MAX;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (a[i][j]<min) min=a[i][j];
		}
	}
	return min;
}
int *maxsum(int m, int n, int **a){
	int *sum;
	sum=(int*) calloc(n,sizeof(int));
	for (int j=0;j<n;j++){
		for (int i=0;i<m;i++){
			sum[j]+=a[i][j];
		}
	}
	return sum;
}
int maxofarr(int n, int a[]){
	int max=INT_MIN;
	for (int i=0;i<n;i++){
		if (a[i]>max) max=a[i];
	}
	return max;
}
//	int max=INT_MIN;
//	for (int i=0;i<n;i++){
//		if (sum[i]>max) max=sum[i];
//	}
//	return max;
int mt_tamgiac_duoi(int m, int n, int **a){
	for (int i=0;i<m;i++){
		for (int j=i+1;j<n;j++){
			if (a[i][j]!=0){
				return 0;
				break;
			}
		}
	}
	return 1;
}
int *maxof_col(int m,int n, int **a){
	int *max;
	max=(int*) malloc(n*sizeof(int));
	for (int i=0;i<n;i++){
		max[i]=INT_MIN;
	}
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (max[i]<a[i][j]) max[i]=a[i][j];
		}
	}
	return max;
}
int tich(int m,int n,int **a){
	int tich=1;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (a[i][n-i-1]<0) tich*=a[i][j];
		}
	}
	return tich;
}
int *tong_hang(int m, int n, int **a){
	int *sum;
	sum=(int*) calloc(n,sizeof(int));
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			sum[i]+=a[i][j];
		}
	}
	return sum;
}
float ave(int m, int n, int **a){
	int sum=0;
	int check=0;
	for (int i=0;i<m;i+=2){
		for (int j=0;j<n;j++){
			if (a[i][j]>0){
				sum+=a[i][j];
				check++;
			} 
		}
	}
	if (check==0) return -1;
	else return (float)(sum/check);
}
int tamgiac_tren(int m, int n, int **a){
	for (int i=0;i<n;i++){
		for (int j=0;j<i;j++){
			if (a[i][j]==0){
				return 0;
				break;
			}
		}
	}
	return 1;
}
int nt_dx(int m, int n, int **a){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (a[i][j]!=a[j][i]){
				return 0;
				break;
			}
		}
	}
	return 1;
}
int duoicheo(int m, int n, int **a){
	int max=INT_MIN;
	for (int i=0;i<m;i++){
		for (int j=0;j<i;j++){
			if (max>a[i][j]) max=a[i][j];
		}
	}
	return max;
}
main(){
	int m,n;
	FILE *f;
	f=fopen("inputmatran.txt", "r");
	int **a;
	fscanf (f,"%d%d", &m,&n);
	a=(int**) malloc(m*sizeof(int*));
	for (int i=0;i<m;i++){
		a[i]=(int*) malloc(n*sizeof(int));
	}
	input(m,n,a,f);
	output(m,n,a);
	int *b=maxsum(m,n,a);
	for (int i=0;i<n;i++){
		printf ("\ntong cua cot %d:%d",i, b[i]);
	}
	int c=maxofarr(n,b);
	for (int i=0;i<n;i++){
		if (c==b[i]) printf ("\ncot %d co tong lon nhat",i);
	}
	b=tong_hang(m,n,a);
	c=maxofarr(m,b);
	for (int i=0;i<n;i++){
		if (c==b[i]) printf ("\nhang %d co tong lon nhat",i);
	}
	if (mt_tamgiac_duoi(m,n,a)) printf ("\nla ma tran tam giac duoi");
	else printf ("\nkhong la ma tran tam giac duoi");
}
