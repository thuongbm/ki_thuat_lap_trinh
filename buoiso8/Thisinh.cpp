#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Thisinh{
	char msv[100];
	char ten[100];
	char truong;
	float diem;
};
void nhap(Thisinh *ts, int n){
	for (int i=0;i<n;i++){
		printf ("nhap msv: ");
		fflush (stdin);
		gets(ts[i].msv);
		printf ("\nnhap ten sv: ");
		fflush (stdin);
		gets(ts[i].ten);
		printf ("\nnhap ten truong: ");
		fflush(stdin);
		scanf ("%c", &ts[i].truong);
		printf ("\nnhap so diem: ");
		scanf ("%f", &ts[i].diem);
	}
}
void xuat(Thisinh *ts, int n, int d){
	for (int i=0;i<n;i++){
		if (ts[i].diem>d)	printf("\n%s %s %c %.2f", ts[i].ten, ts[i].msv, ts[i].truong, ts[i].diem);
	}
}
void xuatts(Thisinh *ts, int n,float d){
	for (int i=0;i<n;i++){
		if (ts[i].diem==d) printf("\n%s %s %c %.2f", ts[i].ten, ts[i].msv, ts[i].truong, ts[i].diem);
	}
}
int tim(Thisinh *ts, int n){
	float max=ts[1].diem;
	for (int i=0;i<n;i++){
		if (max<ts[i].diem) max=ts[i].diem;
	}
	return max;
}
void sapxep(Thisinh *ts, int n){
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
void truong(Thisinh *ts, int n, int d, char c){
	for (int i=0;i<n;i++){
		if (ts[i].diem>d&&ts[i].truong=='c') printf("\n%s %s %c %.2f", ts[i].ten, ts[i].msv, ts[i].truong, ts[i].diem);
	}
}
main(){
	int n;
	scanf ("%d", &n);
	Thisinh *ts;
	ts=(Thisinh*) malloc((n+1)*sizeof(Thisinh));
	nhap(ts,n);
	xuat(ts,n,0);
	float d=tim(ts,n);
	printf ("\nsinh vien diem cao nhat la: ");
	xuatts(ts,n,d);
	sapxep(ts,n);
	printf ("\ndanh sach sau khi sap xep la: ");
	xuat (ts,n,0);
	printf ("\nsinh vien co diem trung binh lon hon 5 o truong b la: ");
	truong(ts,n,5,'B');
	//bo
}
