#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
struct point{
	int x;
	int y;
};
void input(point *p, FILE *f){
	fscanf (f, "%d", &p->x);
	fscanf (f, "%d", &p->y);
}
void input(int n, point *p, FILE *f){
	for (int i=0;i<n;i++){
		input(p+i,f);
	}
}
void output(point p){
	printf ("(%d, %d) ", p.x, p.y);
}
void output(int n, point *p){
	for (int i=0;i<n;i++){
		output(*(p+i));
	}
}
point furthest(int n, point *p){
	float max=FLT_MIN;
	point f;
	for (int i=0;i<n;i++){
		if (sqrt(pow(p[i].x,2)+pow(p[i].y,2))>max){
			max=sqrt(pow(p[i].x,2)+pow(p[i].y,2));
			f=p[i];
		}
	}
	return f;
}
int count(int n, point *p){
	int cnt=0;
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			cnt++;
		}
	}
	return cnt;
}
int st_in3(int n, point *p){
	int cnt=0;
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (p[i].x<0&&p[i].y<0&&p[j].x<0&&p[j].y<0){
				cnt++;
			}
		}
	}
	return cnt;
}
main(){
	FILE *f;
//	char x[50];
//	gets(x);
	f=fopen("cau1input.txt", "r"); 
	int n;
	fscanf (f, "%d", &n);
	point *p;
	p=(point*) malloc(n*sizeof(point));
	input(n,p,f);
	output(n,p);
	point a=furthest(n,p);
	printf ("\ndiem o xa goc toa do nhat la: ");
	output(a);
	printf ("\nso doan thang duoc tao boi cac diem la: %d", count(n,p));
	if (st_in3(n,p)==0) printf ("\nkhong co doan thang nao nam trong goc phan tu thu 3");
	else printf ("\nso doan thang nam trong goc phan tu thu 3 la: %d", st_in3(n,p));
}
