#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct daynguyen{
	int n;
	int *a;
};
void nhap(daynguyen *dn){
	printf ("nhap n: ");
	scanf ("%d", &dn->n);
	dn->a=(int*) malloc((dn->n+1)*sizeof (int));
	for (int i=0;i<dn->n;i++){
		scanf ("%d", &dn->a[i]);
	}
}
void xuat(daynguyen dn){
	for (int i=0;i<dn.n;i++){
		printf ("%d ", dn.a[i]);
	}
}
int tim(daynguyen *dn){
	int max=INT_MIN;
	for (int i=0;i<dn->n;i++){
		if (max<dn->a[i]) max=dn->a[i];
	}
	return max;
}
int tong(daynguyen *dn){
	int tong=0;
	for (int i=0;i<dn->n;i++){
		tong+=dn->a[i];
	}
	return tong;
}
int tbc(daynguyen *dn, int x, int *check){
	int tong=0;
	*check=0;
	for (int i=0;i<dn->n;i++){
		if(dn->a[i]>x){
			tong+=dn->a[i];
			(*check)++;
		}
	}
	return (float)(tong/(*check));
}
main(){
	daynguyen dn;
//	dn=(daynguyen*) malloc((dn->n+1)*sizeof (daynguyen));
	nhap(&dn);
	xuat(dn);
	int b=tong(&dn);
	printf ("\ntong cua day nguyen la: %d", b);
	printf ("\nnhap so x: ");
	int x;
	scanf ("%d", &x);
	int c;
	float d=tbc(&dn,x,&c);
	if (c==0){
		printf ("\nkhong co so nao thoa man");
	}
	else printf ("\ntrung binh cong cua day so la: %.2f", d);
}
