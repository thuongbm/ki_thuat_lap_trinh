#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Hang{
	int ma;
	char ten[50];
	int loai;
	int sl;
	int tgbh;
};
// Nhap 1 hang
void Nhap(Hang *h){
	printf("nhap ma: ");
	scanf("%d", &h->ma);
	printf("Nhap ten: ");
	fflush(stdin);
	//scanf("%c", &h->ten);
	gets(h->ten);
	printf("Nhap loai: ");
	scanf("%d", &h->loai);
	printf("Nhap sl: ");
	scanf("%d", &h->sl);	
	printf("nhap tgbh: ");
	scanf("%d", &h->tgbh);
}
// nhap nhieu hang
void Nhap(int n, Hang *h){
	for(int i=0;i<n;i++)
		Nhap(h+i);
}
//xuat 1 hang
void Xuat(Hang h){
	printf("%d %s %d %d %d\n", h.ma, h.ten, h.loai, h.sl, h.tgbh);
}
//xuat nhieu hang
void Xuat(int n, Hang *h){
	for(int i=0;i<n;i++)
		Xuat(*(h+i)); // h[i]
}

main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	Hang *h;
	h = (Hang*) malloc((n+1) * sizeof(Hang));
	Nhap(n, h);
	Xuat(n, h);
	free(h);
	return 0;
}
