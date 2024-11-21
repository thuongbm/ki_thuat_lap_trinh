#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Hang{
	char mahang[100];
	char tenhang[100];
	char xuatxu[100];
	char loai;
	int soluong;
	int tgbh;
};
void nhap(Hang *h){
	printf ("nhap ma hang: ");
	fflush (stdin);
	gets(h->mahang);
	printf ("nhap ten hang: ");
	fflush (stdin);
	gets (h->tenhang);
	printf ("nhap xuat xu: ");
	fflush (stdin);
	gets (h->xuatxu);
	printf ("nhap loai hang: ");
	fflush (stdin);
	scanf ("%c", &h->loai);
	fflush (stdin);
	printf ("nhap so luong: ");
	scanf ("%d", &h->soluong);
	printf ("nhap thoi gian bao hanh: ");
	scanf ("%d", &h->tgbh);
}
void nhap(int n, Hang *h){
	for (int i=0;i<n;i++){
		nhap(h+i);
	}
}
void xuat(Hang h){
	printf ("\n%s %s %s %c %d %d", h.mahang,h.tenhang, h.xuatxu, h.loai,h.soluong, h.tgbh);
}
void xuat(int n, Hang *h){
	for (int i=0;i<n;i++){
		xuat(*(h+i));
	}
}
Hang *thongke(int n, Hang *h,int b,int *k, int *check){
	*check=0;
	*k=0;
	Hang *a;
	a=(Hang*) malloc((n+1)*sizeof(Hang));
	for (int i=0;i<n;i++){
		if (h[i].tgbh>=b){
			a[*k]=h[i];
			*k+=1;
			*check=1;
		}
	}
	return a;
}
Hang *tim(int n, Hang *h, char b[100],int *k, int *check){
	*check=0;
	*k=0;
	Hang *a;
	a=(Hang*) malloc((n+1)*sizeof(Hang));
	for (int i=0;i<n;i++){
		if (strcmp(h[i].tenhang,b)==0){
			a[*k]=h[i];
			*k+=1;
			*check=1;
		}
	}
	return a;
}
void sapxep(int n, Hang *h){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (h[i].tgbh>h[j].tgbh){
				Hang tg=h[i];
					 h[i]=h[j];
					 h[j]=tg;
			}
		}
	}
}
//de y %s cho chuoi va %c cho ki tu
main(){
	int n;
	scanf ("%d", &n);
	Hang *h;
	h=(Hang*) malloc((n+1)*sizeof(Hang));
	nhap(n,h);
	xuat(n,h);
	int d;
	int b;
	Hang *tk=thongke(n,h,12,&b,&d);
	if (d==0) printf ("\nkhong co");
	else xuat(b,tk);
	char c[100];
	printf ("\nnhap ten hang can tim: ");
	fflush (stdin);
	gets (c);
	tk=tim(n,h,c,&b,&d);
	if (d==0) printf ("\nkhong co mat hang can tim");
	else xuat(b,tk);
	printf ("\nhang sau khi duoc sap xep la: ");
	sapxep(n,h);
	xuat(n, h);
}
