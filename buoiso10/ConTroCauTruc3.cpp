#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Sach{
	int ma;
	char ten[50];
	char tg[50];
	float gia;
};
void nhap(Sach *s){
	printf("Nhap ma: ");
	scanf("%d", &s->ma);
	printf("Nhap ten: ");
	fflush(stdin);
	gets(s->ten);
	printf("Nhap tac gia: ");
	gets(s->tg);
	printf("Nhap gia: ");
	scanf("%f", &s->gia);
}
void nhap(int n, Sach *s){
	for(int i=0;i<n;i++){
		nhap(s+i);
	}
}
void xuat(Sach s){
	printf("\n%d %s %s %.2f", s.ma, s.ten, s.tg, s.gia);
}
void xuat(int n, Sach *s){
	for(int i=0;i<n;i++)
		xuat(*(s+i));
}
// nhap ten tac gia, tim cac cuon sach cua tac gia do
void timSach(int n, Sach *s, char tg[50]){
	int check = 0;
	for(int i=0;i<n;i++){
		if(strcmp(s[i].tg, tg)==0){
			xuat(s[i]);
			check = 1;
		}
	}
	if(check == 0)
		printf("Khong co cuon sach cua tac gia %s", tg);
}
void maxSach(int n, Sach *s){
	//float m = FLT_MIN;
	float m = s[0].gia;
	for(int i=0;i<n;i++)
		if(s[i].gia > m)
			m = s[i].gia;
	// tim cac cuon sach
	for(int i=0;i<n;i++)
		if(s[i].gia == m)
			xuat(s[i]);
}
// in ra tien cua cac cuon sach, biet rang tien = gia*20%
int main(){
	int n;
	Sach *s;
	printf("Nhap n: ");
	scanf("%d", &n);
	s = (Sach*)malloc((n+1)*sizeof(Sach));
	nhap(n, s);
	xuat(n, s);
//	timSach(n, s, "A");
//	maxSach(n, s);
	for(int i=0;i<n;i++)
		printf("\nGia: %.2f", s[i].tien);
}
