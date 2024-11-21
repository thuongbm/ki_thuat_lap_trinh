#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void input(int **a, int m, int n, FILE *f1){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			fscanf (f1, "%d", &a[i][j]);
		}
	}
}
void output(int **a, int m, int n, FILE *f2){
	for (int i=0;i<m;i++){
		fprintf(f2, "\n"); 
		for (int j=0;j<n;j++){
			fprintf(f2, "%3d", a[i][j]);
		}
	}
}
int prime(int n){
    if(n < 2) return 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return 0;
    }
    return 1;
}
main(){
	FILE *f1, *f2;
	f1 = fopen("input55.txt", "r");
	f2 = fopen("output55.txt", "w");
	int m,n;
	fscanf (f1,"%d%d", &m,&n);
	int **a;
	a=(int**) malloc (m*sizeof(int*));
	for (int i=0;i<m;i++){
		a[i]=(int*) malloc(n*sizeof(int));
	}
	fprintf (f2,"%d %d", m,n);
	input(a,m,n,f1);
	output(a,m,n,f2);
	fprintf (f2, "\n");
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (prime(a[i][j])){
				fprintf (f2, "%d ", a[i][j]);
			}
		}
	}
}
