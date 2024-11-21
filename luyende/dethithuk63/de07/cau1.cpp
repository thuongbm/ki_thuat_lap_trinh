#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>
struct point{
	int x;
	int y;
};
void input(point *p, FILE *f){
	fscanf (f, "%d", &p->x);
	fscanf (f,"%d", &p->y);
}
void input(int n, point *p, FILE *f){
	for (int i=0;i<n;i++){
		input(p+i, f);
	}
}
void output(point p){
	printf ("(%d %d) ", p.x, p.y);
}
void output(int n, point *p){
	for (int i=0;i<n;i++){
		output(*(p+i));
	}
}
int find(int n, point *p){
	int max=INT_MIN;
	int f;
	for (int i=0;i<n;i++){
		if (sqrt(pow(p[i].x,2)+pow(p[i].y,2))>max){
			max=sqrt(pow(p[i].x,2)+pow(p[i].y,2));
			f=i;
		}
	}
	return f;
}
float sum(int n, point *p){
	float sumz=0;
	for (int i=0;i<n-1;i++){
		sumz+=sqrt(pow(p[i+1].x-p[i].x,2)+pow(p[i+1].y-p[i].y,2));
	}
	return sumz;
}
main(){
	int n;
	FILE *f;
	f=fopen("cau1input.txt", "r");
	fscanf (f, "%d", &n);
	point *p;
	p=(point*) malloc (n*sizeof (point));
	input(n,p,f);
	output(n,p);
	printf ("\n");
	printf ("diem xa goc toa do nhat la: ");
	for (int i=0;i<n;i++){
		if (i=find(n,p)){
			printf ("(%d %d) ", p[i].x, p[i].y);
		}
	}
	printf ("\ntong cua duong gap khuc tren toa do la: %.2f", sum(n,p));
	fclose(f);
	free(p);
}
