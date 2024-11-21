#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void input(int *a, int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			scanf ("%d", a+i*n+j);
		}
	}
}
void output(int *a, int n){
	for (int i=0;i<n;i++){
		printf ("\n");
		for (int j=0;j<n;j++){
			printf ("%3d", *(a+i*n+j));
		}
	}
}
int max(int *a, int n){
	int max=INT_MIN;
	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			if (i==j&&*(a+i*n+j)>max){
				max=*(a+i*n+j);
			}
		}
	}
	return max;
}
float average(int *a, int n, int x, int *check){
	int sum=0;
	int k=0;
	*check=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (*(a+i*n+j)<x){
				sum+=*(a+i*n+j);
				k++;
				(*check)=1;
			}
		}
	}
	return (float)(sum/k);
}
int maxrow(int *a, int n){
	int sumrow[n];
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			sumrow[i]+=*(a+i*n+j);
		}
	}
	int maxr=INT_MIN;
	for (int i=0;i<n;i++){
		if (sumrow[i]>maxr){
			maxr=i;
		}
	}
	return maxr;
}
void arrange(int *a ,int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n-1;j++){
			for (int k=j+1;k<n;k++){
				if (*(a+n*i+j)>*(a+n*i+k)){
					int tg=*(a+n*i+j);
						*(a+n*i+j)=*(a+n*i+k);
						*(a+n*i+k)=tg;
				}
			}
		}
	}
	for (int j=0;j<n;j++){
		for (int i=0;i<n-1;i++){
			for (int k=j+1;k<n;k++){
				if (*(a+n*i+j)>*(a+n*k+j)){
					int tg=*(a+n*i+j);
						*(a+n*i+j)=*(a+n*k+j);
						*(a+n*k+j)=tg;
				}
			}
		}
	}
}
main(){
	int n;
	scanf ("%d", &n);
	int *a;
	a=(int*) malloc(n*n*sizeof(int));
	input(a,n);
	printf ("\n");
	output(a,n);
	int b;
	b=max(a,n);
	printf ("\ngia tri lon nhat cua mt la: %d", b);
	float c;
	int x;
	printf ("\nnhap gia tri cua x: ");
	scanf ("%d", &x);
	c=average(a,n,x, &b);
	if (b==0) printf ("\nkhong co gia tri nao thoa man");
	else{
		printf ("\ntrung binh cac so so hon x trong mt la: %.2f", c);
	}
	b=maxrow(a,n);
	printf ("\nhang co tong lon nhat la: %d", b);
	arrange(a,n);
	output(a,n);
}
