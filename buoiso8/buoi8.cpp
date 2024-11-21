#include <stdio.h>
#include <stdlib.h>
void nhap(int n, int *a){
	for (int i=0;i<n;i++){
		scanf("%d", a+i);
	}
}
void xuat(int n,int *a){
	for (int i=0;i<n;i++){
		printf ("%d", *(a+1));
	}
}
int lonnhat(int n, int *a){
	int max=*(a+0);
	for (int i=0;i<n;i++){
		if (max<*(a+i)) max=*(a+i);
	}
	return max;
}
int *giam(int n, int *a){
	int *pt;
	pt=(int*)malloc((n+1)*sizeof(int));
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n-1;j++){
			if (*(pt+i)>*(pt+j)){
				int tg=*(pt+i);
					*(pt+i)=*(pt+j);
					*(pt+j)=tg;
			}
		}
	}
	return pt;
}
main(){
	int n;
	scanf ("%d", &n);
	int *a;
	int *b;
	a=(int*)malloc((n+1)*sizeof(int));
	b=(int*)malloc((n+1)*sizeof(int));	
	printf ("nhap day 1");
	nhap(n,a);
	xuat(n,a);
	printf ("nhap day 2");
	nhap(n,b);
	xuat(n,b);
	int *x;
	printf ("\ngia tri lon nhat cua day 1 la: %d", lonnhat(n,a));
	printf ("\ngia tri lon nhat cua day 1 la: %d", lonnhat(n,b));
	printf ("\ngia tri theo giam dan la: ");
	x=giam(n,a);
	xuat(n,x);
}
