#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct thisinh{
	char hoten[100];
	int diem;
	char truong;
};
void nhap(thisinh *ts){
	printf ("nhap ten sv: ");
	fflush (stdin);
	gets(ts->hoten);
	printf ("nhap diem sinh vien: ");
	scanf ("%d", &ts->diem);
	printf ("nhap ten truong: ");
	fflush(stdin);
	scanf ("%s", &ts->truong);
}
void nhap(thisinh *ts, int n){
	for (int i=0;i<n;i++){
		nhap(ts+i);
	}
}
void xuat(thisinh ts){
	printf ("\n%s %d %c",ts.hoten,ts.diem,ts.truong);
}
void xuat(thisinh *ts, int n){
	for (int i=0;i<n;i++){
		xuat(*(ts+i));
	}
}
int diemtr(thisinh *ts, int n, char a){
	int tong=0;
	for (int i=0;i<n;i++){
		if (ts[i].truong==a) tong+=ts[i].diem;
	}
	return tong;
}
int timmax(int a, int b, int c){
	int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}
int demsv(thisinh *ts, int n, char a){
	int dem=0;
	for (int i=0;i<n;i++){
		if (ts[i].truong==a){
			dem++;
		}
	}
	return dem; 
}
thisinh *timsv(thisinh *ts, int n, char a, int *k){
	thisinh *b;
	b=(thisinh*) malloc ((n+1)*sizeof (thisinh));
	int max=INT_MIN;
	*k=0;
	for (int i=0;i<n;i++){
		if (ts[i].truong==a&&ts[i].diem>max){
			max=ts[i].diem;
		}
	}
	for (int i=0;i<n;i++){
		if (ts[i].diem==max){
			b[*k]=ts[i];
			(*k)++;
		}
	}
	return b;
	free(b);
}
thisinh *insv(thisinh *ts, int n, char ten[100], int *k){
	thisinh *b;
	b=(thisinh*) malloc ((n+1)*sizeof (thisinh));
	*k=0;
	for (int i=0;i<n;i++){
		if(strcmp(ts[i].hoten,ten)==0){
			b[*k]=ts[i];
			(*k)=1;
		}
	}
	return b;
	free(b);
}
int kt(thisinh *ts, int n, int x, char a){
	int dem=0;
	for (int i=0;i<n;i++){
		if (ts[i].diem>x&&ts[i].truong==a){
			dem=1;
		}
		else {
			dem=0;
			break;
		}
	}
	return dem;
}
main(){
	int n;
	printf ("nhap so thi sinh: ");
	scanf ("%d", &n);
	thisinh *ts;
	ts=(thisinh*) malloc ((n+1)*sizeof (thisinh));
	nhap(ts,n);
	xuat(ts,n);
	int a=diemtr(ts,n,'a');
	int b=diemtr(ts,n,'b');
	int c=diemtr(ts,n,'c');
	printf ("\ntong diem truong a,b,c la: %d %d %d", a,b,c);
	a=timmax(a,b,c);
	if (a==b) printf ("\ntruong b diem cao nhat");
	if (a==c) printf ("\ntruong c diem cao nhat");
	else printf ("\ntruong a diem cao nhat");
	a=demsv(ts,n,a);
	b=demsv(ts,n,b);
	c=demsv(ts,n,c);
	printf ("\ntruong a co: %d", a);
	printf ("\ntruong b co: %d", b);
	printf ("\ntruong c co: %d", c);
	thisinh *e=timsv(ts,n,'a',&b);
	printf ("\nthi sinh diem cao nhat truong a la: ");
	printf ("\n");
	xuat(e,b);
	char t[100];
	printf ("\nnhap ten sinh vien can tim: ");
	fflush(stdin);
	gets(t);
	e=insv(ts,n,t,&b);
	if(b==0) printf ("\nkhong co sinh vien");
	else{
		printf ("\nthong tin sinh vien can tim la: ");
		xuat(e,1);
	}
	int x;
	printf ("\nnhap x: ");
	scanf ("%d", &x);
	a=kt(ts,n,x,'b');
	if (a==0) printf ("\nthi sinh truong b co nguoi nho hon x");
	else printf ("\ntoan bo thi sinh truong b lon hon x");
}
