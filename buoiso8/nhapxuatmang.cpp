#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void nhap(int n, int *a){
	for (int i=0;i<n;i++){
		scanf ("%d", a+i);
	}
}
void xuat(int n, int *a){
	for (int i=0;i<n;i++){
		printf ("%d ", *(a+i));
	}
}
int tong(int n,int *a, int x, int *check){
	int tong=0;
	*check=0;
	for (int i=0;i<n;i++){
		if (*(a+i)>x){
			tong+=*(a+i);
			*check=1;
		}
	}
	return tong;
}
float tbc(int n, int *a, int *check){
	int tong=0;
	int dem=0;
	*check=0;
	for (int i=0;i<n;i++){
		if (*(a+i)%2==0) {
			tong+=*(a+i);
			dem++;
			*check++;
		}
	}
	return (float)tong/dem;
}
int tim(int n, int *a, int *vt){
	int max=*(a+0);
	for (int i=0;i<n;i++){
		if (max<*(a+i)) max=*(a+i);
	}
	for (int i=0;i<n;i++){
		if (*(a+i)==max) *vt=i; 
	}
	return max;
}
int timm(int n, int *a){
	int *pt;
	pt = (int*)malloc((n+1)*sizeof(int));
}
main(){
	int n;
	int *a;
	int x;
	printf ("nhap n ");
	scanf ("%d", &n);
	a=(int*)malloc((n+1)*sizeof(int));
	nhap(n,a);
	xuat(n,a);
	int c;
	int d;
	if (&c==0){
		printf ("\nkhong co gia tri nao lon hon x");
	}
	else printf ("\n%d", tong(n,a,1,&c));
	if (&d==0){
		printf ("\nkhong co gia tri nao chan");
	}
	else printf ("\n%.2f", tbc(n,a,&d));
	printf ("\ngia tri lon lon nhat cua day la: %d, o: %d", tim(n,a,&d), &d);
	free(a);
} 
