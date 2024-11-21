#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct Cty{
	char ma[100];
	char ten[100];
	int nam;
	int sonv;
};
void nhap(Cty *ct){
	printf ("nhap ma cty: ");
	fflush(stdin);
	gets(ct->ma);
	printf ("nhap ten cty: ");
	fflush(stdin);
	gets(ct->ten);
	printf ("nhap nam thanh lap: ");
	scanf ("%d", &ct->nam);
	printf ("nhap so nv: ");
	scanf ("%d", &ct->sonv);
}
void nhap(int n, Cty *ct){
	for (int i=0;i<n;i++){
		nhap(ct+i);
	}
}
void xuat(Cty ct){
	printf("\n%s %s %d %d", ct.ma, ct.ten, ct.nam, ct.sonv);
}
void xuat(int n, Cty *ct){
	for (int i=0;i<n;i++){
		xuat(*(ct+i));
	}
}
Cty *tim(int n, Cty *ct, int *k){
	int min=INT_MAX;
	for (int i=0;i<n;i++){
		if (min>ct[i].nam) min=ct[i].nam;
	}
	Cty *a=(Cty*) malloc((n+1)*sizeof (Cty));
	*k=0;
	for (int i=0;i<n;i++){
		if (ct[i].nam==min){
			a[*k]=ct[i];
			*k+=1;
		}
	}
	return a;
}
Cty *in(int n, Cty *ct, int x, int y, int *k, int *check){
	*check=0;
	Cty *a=(Cty*) malloc((n+1)*sizeof (Cty));
	for (int i=0;i<n;i++){
		if (ct[i].sonv>x,ct[i].nam<y){
			a[*k]=ct[i];
			*k++;
			*check=1;
		}
	}
	return a;
}
main(){
	int n;
	scanf ("%d", &n);
	Cty *ct;
	ct=(Cty*) malloc((n+1)*sizeof (Cty));
	nhap(n,ct);
	xuat(n,ct);
	int b;
	Cty *lau=tim(n,ct,&b);
	printf ("\ncong ty co nam thanh lap lau nam nhat la: \n");
	xuat(b,lau);
	int x,y;
	printf ("\nnhap so nhan vien va so nam thanh lap can so sanh: ");
	scanf ("%d%d", &x, &y);
	int c;
	lau=in(n,ct,x,y,&b,&c);
	if (c==0) printf ("\nkhong co cong ty nao thoa man");
	else {
		printf ("\ncong ty thoa man la: ");
		xuat(b,lau);
	}
}
