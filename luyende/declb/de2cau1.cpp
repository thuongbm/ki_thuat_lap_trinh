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
		fscanf (f,"%d", &p[i].x);
		fscanf (f,"%d", &p[i].y);
	}
}
void output(int n, point *p){
	for (int i=0;i<n;i++){
		printf ("%d %d\n", p[i].x,p[i].y);
	}
}
int count(int n, point *p, int x){
	int check=0;
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (sqrt(pow(p[i].x,2)+pow(p[i].y,2))<x&&sqrt(pow(p[j].x,2)+pow(p[j].y,2))<x){
				check++;
			}
		}
	}
	return check;
}
int check(float a, float b, float c){
	if (a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a) return 1;
	else return 0;
}
point *right_tria(int n, point *p){
	float max=FLT_MIN;
	point *f;
	f=(point*) malloc(3*sizeof (point));
	for (int i=0;i<n-2;i++){
		for (int j=i+1;j<n-1;j++){
			for (int k=j+1;k<n;k++){
				float a=sqrt(pow(p[i].x-p[j].x,2)+pow(p[i].y-p[j].y,2));
				float b=sqrt(pow(p[i].x-p[k].x,2)+pow(p[i].y-p[k].y,2));
				float c=sqrt(pow(p[j].x-p[k].x,2)+pow(p[j].y-p[k].y,2));
				float d=(a+b+c)/2;
				if (check(a,b,c)==1&&sqrt(d*(d-a)*(d-b)*(d-c))>max){
					max=sqrt(d*(d-a)*(d-b)*(d-c))>max;
					f[1]=p[i];
					f[2]=p[j];
					f[3]=p[k];
				}
			}
		}
	}
	return f;
}
main(){
	int n;
	FILE *f;
	f=fopen("de2cau1.txt","r");
	fscanf (f,"%d",&n);
	point *p;
	p=(point*) malloc(n*sizeof(point));
}
