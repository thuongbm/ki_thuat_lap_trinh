#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
struct point{
	int x;
	int y;
};
void input(int n, point *p, FILE *f){
	for (int i=0;i<n;i++){
		fscanf (f, "%d", &p[i].x);
		fscanf (f, "%d", &p[i].y);
	}
}
void output(point p){
	printf ("(%d %d)", p.x, p.y);
}
void output(int n, point *p){
	for (int i=0;i<n;i++){
		output(*(p+i));
	}
}
point find(int n, point *p){
	point f;
	float min=FLT_MAX;
	for (int i=0;i<n;i++){
		if ((p[i].x+p[i].y)%2==0&&sqrt(pow(p[i].x,2)+pow(p[i].y,2))<min){
			f=p[i];
			min=sqrt(pow(p[i].x,2)+pow(p[i].y,2));
		}
	}
	return f;
}
float min()
main(){
	int n;
	FILE *f;
	f=fopen("cau1input.txt", "r");
	point *p;
	p=(point*) malloc(n*sizeof(point));
}
