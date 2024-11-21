#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
struct diem{
	int x;
	int y;
};
struct catt{
	int diem1;
	int diem2; 
};
void nhap(diem *d){
	printf ("nhap x: ");
	scanf ("%d", &d->x);
	printf ("nhap y: ");
	scanf ("%d", &d->y);
}
void nhap(diem *d, int n){
	for (int i=0;i<n;i++){
		nhap(d+i);
	}
}
void xuat(diem d){
	printf ("%d %d\n", d.x, d.y);
}
void xuatt(catt t){
	printf ("%d %d\n", t.diem1, t.diem2);
}
diem *timdiem(diem *d, int n,int *k){
	*k=0;
	diem *a;
	a=(diem*) calloc (n,sizeof (diem));
	for (int i=0;i<n;i++){
		if (d[i].x<0&&d[i].y<0){
			a[*k]=d[i];
			(*k)++;
		}
	}
	return a;
	free(a);
}
float dientich(diem *d, int n){
	float max=FLT_MIN;
	for (int i=0;i<n;i++){
		if(sqrt(d[i].x*d[i].x+d[i].y*d[i].y)>max){
			max=sqrt(d[i].x*d[i].x+d[i].y*d[i].y);
		}
	}
	return (float)(max*max*3.14);
}
float dodai(diem *d, int n){
	float tong=0;
	for (int i=0;i<n-1;i++){
		tong+=sqrt(float(d[i+1].x-d[i].x)*(d[i+1].x-d[i].x)+(d[i+1].y-d[i].y)*(d[i+1].y-d[i].y));
	}
	return tong;
}
diem *tim(diem *d, int n,int *k, float r){
	*k=0;
	diem *a;
	a=(diem*) calloc (n,sizeof (diem));
	for (int i=0;i<n;i++){
		if (sqrt(d[i].x*d[i].x+d[i].y*d[i].y)>r){
			a[*k]=d[i];
			(*k)++;
		}
	}
	return a;
	free(a);
}
diem *tim1(diem *d, int n,int *k){
	*k=0;
	diem *a;
	a=(diem*) calloc (n,sizeof (diem));
	float min=FLT_MAX;
	for (int i=0;i<n;i++){
		if (d[i].x<0&&d[i].y>0&&sqrt(d[i].x*d[i].x+d[i].y*d[i].y)<min){
			a[*k]=d[i];
			(*k)=1;
		}
	}
	return a;
}
int giaithua(int n){
	int tich=1;
	for (int i=1;i<=n;i++){
		tich*=i;
	}
	return tich;
}
catt *cat(diem *d, catt *t , int n, int *k){
	*k=0;
	catt *a;
	a=(catt*) calloc (giaithua(n),sizeof (catt));
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (d[i].x!=d[j].x){
				a[*k].diem1=i;
				a[*k].diem2=j;
				(*k)++;
			}
		}
	}
	return a;
	free(a);
}
main(){
	int n;
	printf ("nhap so diem: ");
	scanf ("%d", &n);
	diem *d;
	d=(diem*) calloc (n,sizeof (diem));
	nhap(d,n);
	for (int i=0;i<n;i++){
		printf ("diem %d\n", i);
		xuat(d[i]);
	}
	int b;
	diem *a;
	a=timdiem(d,n,&b);
	if (b==0) printf ("khong co diem nao thuoc goc phan tu thu 3");
	else{
		printf ("diem thuoc goc phan tu thu 3 la: ");
		for (int i=0;i<b;i++){
			xuat(a[i]);
		}
	}
	float e=dientich(d,n);
	printf ("dien tich nho nhat bao trum cac diem la: %.2f", e);
	e=dodai(d,n);
	printf ("\ndo dai cua dgk la: %.2f",e);
	float r;
	printf ("\nnhap do dai doan can so sanh: ");
	scanf ("%d", &r);
	a=tim(d,n,&b,r);
	if (b==0) printf ("khong co diem nao ngoai r");
	else {
		printf ("diem thuoc ngoai r la: ");
		for (int i=0;i<b;i++){
			xuat(a[i]);
		}
	}
	a=tim1(d,n,&b);
	if (b==0) printf ("khong co diem nao thuoc goc phan tu thu 2");
	else {
		printf ("diem thuoc goc phan tu thu 2 gan nhat la: ");
		for (int i=0;i<b;i++){
			xuat(a[i]);
		}
	}
	catt *t;
	t=(catt*) calloc (giaithua(n),sizeof (catt));
	catt *h;
	h=cat(d,t,n,&b);
	if (b==0) printf ("khong co 2 diem nao cat truc hoanh");
	else {
		printf ("2 diem nao cat truc hoanh la: ");
		for (int i=0;i<b;i++){
			xuatt(h[i]);
		}
	}
	free(d);
	free(h);
}
