//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//struct Sach{
//	int ma;
//	char ten[50];
//	char tg[50];
//	float gia;
//};
//float tien(Sach s){
//	return s.gia*0.2;
//}
//void nhap(Sach *s){
//	printf("Nhap ma: ");
//	scanf("%d", &s->ma);
//	printf("Nhap ten: ");
//	fflush(stdin);
//	gets(s->ten);
//	printf("Nhap tac gia: ");
//	gets(s->tg);
//	printf("Nhap gia: ");
//	scanf("%f", &s->gia);
//}
//void nhap(int n, Sach *s){
//	for(int i=0;i<n;i++){
//		nhap(s+i);
//	}
//}
//void xuat(Sach s){
//	printf("\n%d %s %s %.2f", s.ma, s.ten, s.tg, s.gia);
//}
//void xuat(int n, Sach *s){
//	for(int i=0;i<n;i++)
//		xuat(*(s+i));
//}
//// nhap ten tac gia, tim cac cuon sach cua tac gia do
//Sach *timSach(int n, Sach *s, char tg[50], int *k, int *check){
//	*k=0;
//	*check = 0;
//	Sach *a;
//	a = (Sach*)malloc((n+1)*sizeof(Sach));
//	for(int i=0;i<n;i++){
//		if(strcmp(s[i].tg, tg)==0){
//			a[*k] = s[i];
//			*k=*k+1;
//			*check = 1;
//		}
//	}
//	return a;
//}
//
//// tim cac cuon sach có gia dat nhat
//Sach *maxSach(int n, Sach *s, int *k){
//	*k = 0;
//	Sach *a;
//	a = (Sach*)malloc((n+1)*sizeof(Sach));
//	float m = s[0].gia;
//	for(int i=0;i<n;i++)
//		if(s[i].gia > m)
//			m = s[i].gia;
//	// tim cac cuon sach
//	for(int i=0;i<n;i++)
//		if(s[i].gia == m){
//			a[*k] = s[i];
//			*k+=1;
//		}
//	return a;
//}
//
//int main(){
//	int n;
//	Sach *s;
//	printf("Nhap n: ");
//	scanf("%d", &n);
//	s = (Sach*)malloc((n+1)*sizeof(Sach));
//	nhap(n, s);
//	xuat(n, s);
//	int k, check;
//	Sach *kq = timSach(n, s, "Thay At", &k, &check);
//	if(check == 0)
//		printf("\nKhong co cuon sach nao cua tac gia 1");
//	else{
//		printf("\nCac cuon sach cua tac gia %s la: ");
//		xuat(k, kq);	
//	}
//	for(int i=0;i<n;i++)
//		printf("\ntien: %.2f", tien(s[i]));
//}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sach {
    int ma;
    char ten[50];
    char tg[50];
    float gia;
};

float tien(Sach s) {
    return s.gia * 0.2;
}

void nhap(Sach* s) {
    printf("Nhap ma: ");
    scanf("%d", &s->ma);
    printf("Nhap ten: ");
    scanf(" %[^\n]", s->ten); // Use fgets or scanf with format specifier to read strings
    printf("Nhap tac gia: ");
    scanf(" %[^\n]", s->tg); // Use fgets or scanf with format specifier to read strings
    printf("Nhap gia: ");
    scanf("%f", &s->gia);
}

void nhap(int n, Sach* s) {
    for (int i = 0; i < n; i++) {
        nhap(s + i);
    }
}

void xuat(Sach s) {
    printf("\n%d %s %s %.2f", s.ma, s.ten, s.tg, s.gia);
}

void xuat(int n, Sach* s) {
    for (int i = 0; i < n; i++)
        xuat(*(s + i));
}

Sach* timSach(int n, Sach* s, char tg[50], int* k, int* check) {
    *k = 0;
    *check = 0;
    Sach* a;
    a = (Sach*)malloc((n + 1) * sizeof(Sach));
    for (int i = 0; i < n; i++) {
        if (strcmp(s[i].tg, tg) == 0) {
            a[*k] = s[i];
            *k = *k + 1;
            *check = 1;
        }
    }
    return a;
}

Sach* maxSach(int n, Sach* s, int* k) {
    *k = 0;
    Sach* a;
    a = (Sach*)malloc((n + 1) * sizeof(Sach));
    float m = s[0].gia;
    for (int i = 0; i < n; i++)
        if (s[i].gia > m)
            m = s[i].gia;
    // tim cac cuon sach
    for (int i = 0; i < n; i++)
        if (s[i].gia == m) {
            a[*k] = s[i];
            *k += 1;
        }
    return a;
}

int main() {
    int n;
    Sach* s;
    printf("Nhap n: ");
    scanf("%d", &n);
    s = (Sach*)malloc((n + 1) * sizeof(Sach));
    nhap(n, s);
    xuat(n, s);
    int k, check;
    Sach* kq = timSach(n, s, "Thay At", &k, &check);
    if (check == 0)
        printf("\nKhong co cuon sach nao cua tac gia 1");
    else {
        printf("\nCac cuon sach cua tac gia Thay At la: "); // Include the author's name
        xuat(k, kq);
    }
    for (int i = 0; i < n; i++)
        printf("\ntien: %.2f", tien(s[i]));

    // Free dynamically allocated memory
    free(kq);
    free(s);
    return 0;
}

