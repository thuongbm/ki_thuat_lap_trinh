#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void nhap(int *a, int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf ("nhap a[%d][%d]", i,j);
			scanf ("%d", (a+n*i+j));
		}
	}
}
void xuat(int *a, int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf ("%3d", *(a+n*i+j));
		}
		printf ("\n");
	}
}
int max(int *a, int n){
	int max=INT_MIN;
	for (int i=0;i<n;i++){
		for (int j=i;j<i+1;j++){
			if (*(a+n*i+j)>max) max=*(a+n*i+j);
		}
	}
	return max;
}
float tb(int *a, int n, int x, int *check){
	*check=0;
	int tong=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (*(a+n*i+j)>x){
				tong+=*(a+n*i+j);
				(*check)++;
			}
		}
	}
	return (float)(tong/((*check)));
}
int maxtong(int *a, int n){
	int *b=(int *) calloc (n, sizeof (int ));
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			b[i]+=*(a+n*i+j);
		}
	}
	int dongln=0;
	int max=INT_MIN;
	for (int i=0;i<n;i++){
		if (b[i]>max){
			max =b[i];
			dongln=i;
		} 
	}
	return (dongln+1);
}
void lonbe(int *a ,int n){
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
//	for (int i=0;i<n-1;i++){
//		for (int j=i+1;j<n;j++){
//			if (*(a+n*(i/n)+(i%n))>*(a+n*(j/n)+(j%n))){
//				int tg=*(a+n*(i/n)+(i%n));
//					*(a+n*(i/n)+(i%n))=*(a+n*(j/n)+(j%n));
//					*(a+n*(j/n)+(j%n))=tg;
//			}
//		}
//	}
}
main(){
	int n;
	printf ("nhap n: ");
	scanf ("%d", &n);
	int *a;
	a=(int*) malloc (n*n*sizeof(int));
	nhap(a,n);
	xuat(a,n);
	int b=max(a,n);
	printf ("\ngia tri lon nhat o duong cheo la: %d", b);
	int x;
	printf ("\nnhap x: ");
	scanf ("%d", &x);
	float c=tb(a,n,x,&b);
	if (b==0) printf ("khong co gia tri nao thoa man");
	else printf ("gia tri trung binh cua phan tu nho hon x la: %.2f", c);
	b=maxtong(a,n);
	printf ("\ndong lon nhat la: %d\n", b);
	lonbe(a,n);
	printf ("\nma tran sau khi sap xep la: \n");
	xuat(a,n);
}
