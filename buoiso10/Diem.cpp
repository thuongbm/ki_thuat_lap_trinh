#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Diem{
	float x, y;
};
void nhap(int *n, Diem **d){
	printf("Nhap n: ");
	scanf("%d", n);
	*d = (Diem*)(malloc((*n+1)*sizeof(Diem)));
	for(int i=0;i<*n;i++){
		printf("Nhap diem thu %d: ", i);
		scanf("%f%f", &(*d+i)->x, &(*d+i)->y);
	}
}
void xuat(int n, Diem *d){
	for(int i=0;i<n;i++)
		printf("(%.2f, %.2f)", (d+i)->x, (d+i)->y);
}
// tim dien tich hinh tron tam O nho nhat chua cac diem
float kc(Diem d){
	return sqrt(d.x*d.x+d.y*d.y);
}
float kcMax(int n, Diem *d){
	float m = kc(d[0]);
	for(int i=0;i<n;i++)
		if(kc(d[i]) > m)
			m=kc(d[i]);
	return m;
}
int main(){
	int n;
	Diem *d;
	nhap(&n, &d);
	xuat(n, d);
	float r = kcMax(n, d);
	printf("\nDT la: %.2f", r*r*3.14);
}
