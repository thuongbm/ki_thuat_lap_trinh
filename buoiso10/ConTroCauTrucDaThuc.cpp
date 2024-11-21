#include<stdio.h>
#include<stdlib.h>
#include <math.h>
struct DaThuc{
	int n;
	float *a;
};
void nhap(DaThuc *dt){
	printf("Nhap n: ");
	scanf("%d", &dt->n);
	dt->a = (float*)malloc((dt->n+1)*sizeof(float));
	for(int i=0;i<=dt->n;i++){
		printf("Nhap he so thu %d: ", i);
		scanf("%f", &dt->a[i]);
	}
}
DaThuc nhap(){
	DaThuc dt;
	printf("Nhap n: ");
	scanf("%d", &dt.n);
	dt.a = (float*)malloc((dt.n+1)*sizeof(float));
	for(int i=0;i<=dt.n;i++){
		printf("Nhap he so thu %d: ", i);
		scanf("%f", &dt.a[i]);
	}
	return dt;
}
void xuat(DaThuc dt){
	for(int i=0;i<=dt.n;i++)
		printf("%.2f ", dt.a[i]);
}

float tinh(DaThuc dt, float x){
	float s = 0;
	for(int i=0;i<=dt.n;i++)
		s+=dt.a[i]*pow(x, i);
	return s;
}

int main(){
	//DaThuc dt = nhap();
	DaThuc dt1;
	nhap(&dt1);
	xuat(dt1);
	DaThuc dt2;
	dt2 = nhap();
	xuat(dt2);
}







