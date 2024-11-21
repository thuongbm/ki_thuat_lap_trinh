#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
struct dathuc{
	int n;
	int *a;
};
void nhap(dathuc *dt){
	printf ("nhap bac cua da thuc: ");
	scanf ("%d", &dt->n);
	dt->a=(int*) calloc ((dt->n+1),sizeof (int));
	printf ("nhap he so cua da thuc: ");
	for (int i=0;i<dt->n;i++){
		scanf ("%d", &dt->a[i]);
	}
}
void xuat(dathuc dt){
	for (int i=0;i<dt.n;i++){
		printf ("%d ", dt.a[i]);
	}
}
int tongdt(dathuc *dt, int x){
	int tong=0;
	for (int i=0;i<dt->n;i++){
		tong+=dt->a[i]*pow(x,i);
	}
	return tong;
}
int daoham(dathuc *dt, int x){
	int tong=0;
	for (int i=0;i<dt->n;i++){
		tong+=i*(dt->a[i])*pow(x,i-1);
	}
	return tong;
}
int lonnhat(dathuc *dt){
	int max=INT_MIN;
	for (int i=0;i<dt->n;i++){
		if (dt->a[i]>max) max=dt->a[i];
	}
	return max;
}
int tongam(dathuc *dt, int *check){
	int tong=0;
	*check=0;
	for (int i=0;i<dt->n;i++){
		if (dt->a[i]<0){
			tong+=dt->a[i];
			*check=1;
		}
	}
	return tong;
}
//dathuc *heso(dathuc *dt, dathuc *q){
//	int m;
//	if ((dt->n)>(q->n)) m=dt->n;
//	else m=q->n;
//	dathuc *trave;
////	trave =(dathuc*) malloc((m+1)*sizeof (dathuc*));
//	trave.a = (int*)malloc((m + 1) * sizeof(int));
//	if (dt->n!=q->n){
//		for (int i=0;i<m;i++){
//			trave->a[i]=dt->a[i]-q->a[i];
//		}
//	}
//	return trave;
//}
dathuc *heso(dathuc *dt, dathuc *q) {
    int m;
    if ((dt->n) > (q->n)) m = dt->n;
    else m = q->n;
    dathuc *trave = (dathuc *)malloc(sizeof(dathuc));
    trave->n = m;
    trave->a = (int *)calloc((m + 1), sizeof(int));
    if (dt->n == q->n) return 0;
    if (dt->n != q->n) {
        for (int i = 0; i < m; i++) {
            trave->a[i] = dt->a[i] - q->a[i];
        }
		return trave;
    }
}
main(){
	dathuc dt;
	nhap(&dt);
	xuat(dt);
	int x;
	printf ("\nnhap so x: ");
	scanf ("%d", &x);
	int b=tongdt(&dt,x);
	int c=daoham(&dt,x);
	float s = x + sqrt(b + c + 2023);
	printf ("\ntong s cua da thuc la: %.2f",s);
	b=lonnhat(&dt);
	printf ("\ngia tri lon nhat cua day so la: %d", b);
	b=tongam(&dt, &c);
	if(c==0) printf ("\nkhong co so am\n");
	else printf ("\ntong am cua he so la: %d\n", b);
	dathuc q;
	nhap(&q);
	dathuc *e=heso(&dt,&q);
	if (e==0) printf ("hai he so bang nhau");
	else xuat(*e);
}
