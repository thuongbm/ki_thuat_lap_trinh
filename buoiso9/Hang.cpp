#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef struct Hang{
	int ma;
	char ten[100];
	int loai;
	int sl;
	int tgbh;
};
void nhap(int n, Hang *h){
	for(int i=0;i<n;i++){
		printf("Nhap ma: ");
		scanf("%d", &h[i].ma);//h+i
		printf("Nhap ten: ");
		fflush(stdin);
		gets(h[i].ten);
		printf("Nhap loai: ");
		scanf("%d", &h[i].loai);
		printf("Nhap SL:");
		scanf("%d", &h[i].sl);
		printf("Nhap TGBH: ");
		scanf("%d", &h[i].tgbh);;
	}
}

void xuat(int n, Hang *h){
	for(int i=0;i<n;i++){
		printf("\n%d %s %d %d %d", h[i].ma, h[i].ten, h[i].loai, h[i].sl, h[i].tgbh);
	}
}
int thongKe(int n, Hang *h, int loai){
	int d=0;
	for(int i=0;i<n;i++){
		if(h[i].loai == loai && h[i].tgbh > 12){
			d+=1;
		}
	}
	return d;
}
// tim mot mat hang co ten cho truoc
void tim(int n, Hang *h, char ten[100]){
	int check = 0;
	for(int i=0;i<n;i++){
		if(strcmp(h[i].ten, ten)==0){
			printf("\n%d %s %d %d %d",
			h[i].ma, h[i].ten, h[i].loai, h[i].sl, h[i].tgbh);
			check = 1;
		}
	}
	if(check == 0)
		printf("Khong co mat hang can tim");
}
// tim so luong lon nhat cua mat hang loai 2
int maxSL(int n, Hang *h, int loai, int *check){
	int m = INT_MIN;
	*check = 0;
	for(int i=0;i<n;i++)
		if(h[i].sl > m && h[i].loai == loai){
				m = h[i].sl;
				*check = 1;
		}
	return m;
}
// sap xep hang giam dan theo thoi gian bao hanh
void sapXep(int n, Hang *h){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(h[i].tgbh<h[j].tgbh){
				Hang t = h[i];
				h[i] = h[j];
				h[j] = t;
			}
}
int main(){
	int n;
	Hang *h;
	printf("Nhap n: ");
	scanf("%d", &n);
	h = (Hang*)(malloc((n+1)*sizeof(int)));
	nhap(n, h);
	xuat(n, h);
	printf("\ntong so loai hang 1 la: %d", thongKe(n, h, 1));
	printf("\ntong so loai hang 2 la: %d", thongKe(n, h, 2));
	printf("\ntong so loai hang 3 la: %d", thongKe(n, h, 3));
	char ten[100];
	printf("\nnhap ten hang can tim: ");
	fflush(stdin);
	gets(ten);
	tim(n, h, ten);
	int check;
	int kq = maxSL(n, h, 2, &check);
	if(check == 0)
		printf("\nkhong co mat hang loai 2");
	else
		printf("\nKQ la: %d", kq);
	sapXep(n, h);
	printf("\nsau khi sap xep la: ");
	xuat(n, h);
}
