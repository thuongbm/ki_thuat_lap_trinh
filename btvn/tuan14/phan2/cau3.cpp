#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void input(int n, int **a, FILE *f1){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			fscanf (f1, "%d", &a[i][j]);
		}
	}
}
void output(int n, int **a){
	for (int i=0;i<n;i++){
		printf ("\n");
		for(int j=0;j<n;j++){
			printf ("%3d", a[i][j]);
		}
	}
}
float ave_ma_bel(int n, int **a){
	int sum=0;
	int check=0;
	for(int j=n-1;j>=0;j--){
		for(int i=n-1;i>=n-1-j;i--){
			sum+=a[i][j];
			check++;
		}
	}
	return (float)(sum/check);
}
int abo_tri_mat(int n, int **a){
	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			if (a[i][j]==0){
				continue;
			}
			else return 0;
		}
	}
	return 1;
}
int sym_mat(int n, int **a){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (a[i][j]!=a[j][i]) return 0;
		}
	}
	return 1;
}
int max_row(int n, int **a){
	int *b=(int*) calloc(n,sizeof(int));
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			b[i]+=a[i][j];
		}
	}
	int max=INT_MIN;
	int maxcol=INT_MIN;
	for (int i=0;i<n;i++){
		if(b[i]>max){
			max=b[i];
			maxcol=i;
		} 
	}
	return maxcol;
}
main(){
	FILE *f1;
	f1=fopen("inputc3.txt", "r");
	int n;
	fscanf(f1,"%d", &n);
	int **a;
	a=(int**) malloc(n*sizeof(int*));
	for (int i=0;i<n;i++){
		a[i]=(int*) malloc (n*sizeof(int));
	}
	input(n,a,f1);
	output(n,a);
	float b=ave_ma_bel(n,a);
	printf ("\ntrung binh cong cua ma tran duoi la: %.2f", b);
	if (abo_tri_mat(n,a)) printf ("\nla ma tran tam giac tren");
	else printf ("\nkhong phai ma tran tam giac tren");
	if (sym_mat(n,a)) printf ("\nla ma tran doi xung");
	else printf ("\nkhong la ma tran doi xung");
	printf ("\nhang co tong lon nhat la: %d", max_row(n,a)+1);
}
