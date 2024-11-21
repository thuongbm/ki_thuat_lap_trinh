#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct SV{
	int ma;
	char ten[100];
	float diem;
};
void nhap(int n, SV *sv, FILE *f){
	for(int i=0;i<n;i++){
		fscanf(f, "%d\n", &sv[i].ma);
		fgets(sv[i].ten, 100, f);
		sv[i].ten[strlen(sv[i].ten)-1]='\0';
		fscanf(f, "%f\n", &sv[i].diem); 
	}
}
void xuat(int n, SV *sv){
	for(int i=0;i<n;i++){
		printf("\n%d %s %.2f", sv[i].ma, sv[i].ten, sv[i].diem);
	}
}
main(){
	int n;
	SV *sv;
	FILE *f;
	f = fopen("input.txt", "rt");
	fscanf(f, "%d", &n);
	sv = (SV*)malloc(n*sizeof(SV));
	nhap(n, sv, f);
	xuat(n, sv);
}
