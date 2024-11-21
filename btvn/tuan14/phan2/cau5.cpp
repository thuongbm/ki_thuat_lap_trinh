#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
struct point{
	int x;
	int y;
};
void input(point *p, FILE *f){
	fscanf (f,"%d", &p->x);
	fscanf (f,"%d", &p->y);
}
void input(int n, point *p, FILE *f){
	for (int i=0;i<n;i++){
		input(p+i, f);
	}
}
void output(point p){
	printf ("(%d; %d) ", p.x, p.y);
}
void output(int n, point *p){
	for (int i=0;i<n;i++){
		output(*(p+i));
	}
}
point furthest(int n, point *p){
	point fs;
	float max=FLT_MIN;
	for (int i=0;i<n;i++){
		if (sqrt(p[i].x*p[i].x+p[i].y*p[i].y)>max){
			max=sqrt(p[i].x*p[i].x+p[i].y*p[i].y);
			fs=p[i];
		}
	}
	return fs;
}
int cnt_strai_sect(int n){
	int cnt=0;
	for (int i=1;i<=n-1;i++){
		cnt+=i;
	}
	return cnt;
}
int count(int n, point *p,int *k){
	*k=0;
	int cnt=0;
	for (int i=0;i<n;i++){
		if (p[i].x<0&&p[i].y<0){
			cnt++;
			*k=1;
		}
	}
	return cnt_strai_sect(cnt);
}
float max(int n, point *p){
	float max=FLT_MIN;
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (sqrt(pow(p[j].x-p[i].x,2)+pow(p[j].y-p[i].y,2))>max){
				max=sqrt(pow(p[j].x-p[i].x,2)+pow(p[j].y-p[i].y,2));
			}
		}
	}
	return max;
}
int fist_(int n, point *p){
	int cnt=0;
	for (int i=0;i<n;i++){
		if (p[i].x>0&&p[i].y>0){
			cnt++;
		}
	}
	return cnt;
}
main(){
	int n;
	FILE *f;
	f=fopen("inputc5.txt", "r");
	fscanf (f,"%d", &n);
	point *p;
	p=(point*) malloc(n*sizeof(point));
	input(n,p,f);
	output(n,p);
	point furt=furthest(n,p);
	printf ("\ndiem xa goc toa do nhat la: ");
	output(furt);
	int d;
	int e=count(n,p, &d);
	if (d==0) printf ("\nkhong co diem nao thuoc goc phan tu thu 3");
	else{
		if (e==1) printf ("\nkhong co doan thang nao thoa man");
		else printf ("\nso duong thang thuoc goc phan tu thu 3 la: %d", e);
	}
	float g=max(n,p);
	printf ("\ndoan thang dai nhat la: %.2f", g);
	d=fist_(n,p);
	printf ("\nso diem thuoc goc phan tu thu nhat la: %d", d);
}
