#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
struct lap{
	char max[50];
	char ten[50];
	float gia;
};
void nhap(int n, lap *l, FILE *f){
	for (int i=0;i<n;i++){
		fgets(l[i].max, 10, f);
		l[i].max[strlen(l[i].max)-1]='\0';
		fgets(l[i].ten, 10, f);
		l[i].ten[strlen(l[i].ten)-1]='\0';
		fscanf(f, "%f\n", &l[i].gia);
	}
}
void xuat(int n, lap *l, FILE *f){
	for (int i=0;i<n;i++){
		fprintf (f,"%s %s %.2f\n", l[i].max, l[i].ten, l[i].gia);
	}
}
//dem so luong lap loai x
int demlap(int n, lap *l, char x[50]){
	int check=0;
	for (int i=0;i<n;i++){
		if (strcmp(l[i].ten,x)==0){
			check++;
		}
	}
	return check;
}
//tim lap top gia cao nhat va in thong tin vao tep vua tao
void max(int n ,lap *l, FILE *f){
	float m= FLT_MIN;
	int vt=0;
	for (int i=0;i<n;i++){
		if (l[i].gia>m){
			m=l[i].gia;
			vt=i;
		}
	}
	fprintf (f,"\nlap gia cao nhat la: ");
	fprintf (f,"%s %s %.2f\n", l[vt].max, l[vt].ten, l[vt].gia);
}
main(){
	int n;
	FILE *f1, *f2;
	lap *l;
	f1=fopen("inputlap.txt", "r");
	f2=fopen("outputlap.txt", "w");
	fscanf (f1,"%d\n", &n);
	l=(lap*) malloc (n*sizeof (lap));
	nhap(n,l,f1);
	xuat(n,l, f2);
	fprintf (f2, "%d", demlap(n,l,"DELL"));
	max(n, l, f2);
	fclose(f1);
	fclose(f2);
	free(l);
}
