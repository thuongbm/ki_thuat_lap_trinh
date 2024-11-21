#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Thisinh{
	char hoten[100];
	float diem;
	char truong;
};
void nhap(Thisinh *ts){
	printf ("nhap ho ten thi sinh: ");
	fflush (stdin);
	gets (ts->hoten);
	printf ("nhap diem: ");
	scanf ("%f", &ts->diem);
	printf ("nhap ten truong: ");
	fflush (stdin);
	scanf ("%c", &ts->truong);
}
void nhap(int n, Thisinh *ts){
	for (int i=0;i<n;i++){
		nhap((ts+i));
	}
}
void xuat(Thisinh ts){
	printf ("\n%s %.2f %c ", ts.hoten, ts.diem,ts.truong);
}
void xuat(int n, Thisinh *ts){
	for (int i=0;i<n;i++){
		xuat(*(ts+i));
	}
}
float tong(int n, Thisinh *ts, char a){
	float tongt=0;
	for (int i=0;i<n;i++){
		if (ts[i].truong==a) tongt+=ts[i].diem;
	}
	return tongt;
}
float max(float a, float b, float c){
	float maxValue = a;
 
    if(b > maxValue){
        maxValue = b;
    }
 
    if(c > maxValue){
        maxValue = c;
    }
    return maxValue;
}
Thisinh *tim(int n, Thisinh *ts, char a, int *k){
	float max;
	Thisinh *b;
	b=(Thisinh*) malloc ((n+1)*sizeof(Thisinh));
	for (int i=0;i<n;i++){
		if (ts[i].truong==a){
			max=ts[i].diem;
			break;
		} 
	}
	for (int i=0;i<n;i++){
		if (ts[i].truong==a&&max<ts[i].diem) max=ts[i].diem;
	}
	*k=0;
	for (int i=0;i<n;i++){
		if (max==ts[i].diem){
			b[*k]=ts[i];
			(*k)++;
		} 
	}
	return b;
}
void sapxep(int n, Thisinh *ts){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (ts[i].diem>ts[j].diem){
				Thisinh tg=ts[i];
					 ts[i]=ts[j];
					 ts[j]=tg;
			}
		}
	}
}
main(){
	int n;
	scanf ("%d", &n);
	Thisinh *ts;
	ts=(Thisinh*) malloc ((n+1)*sizeof(Thisinh));
	nhap(n,ts);
	xuat(n,ts);
	float a=tong(n,ts,'A');
	printf ("\ntong diem truong a la: %d", a);
	float b=tong(n,ts,'B');
	printf ("\ntong diem truong b la: %d", b);
	float c=tong(n,ts,'C');
	printf ("\ntong diem truong c la: %d", c);
	float d=max(a,b,c);
	if (d==a) printf ("\ntruong a diem cao nhat");
	if (d==b) printf ("\ntruong b diem cao nhat");
	if (d==c) printf ("\ntruong c diem cao nhat");
	int e;
	Thisinh *t=tim(n,ts,'a',&e);
	printf ("\nthi sinh diem cao nhat truong a la: \n");
	xuat(e,t);
	sapxep(n,ts);
	xuat(n,ts);
	//chuaxong
}
