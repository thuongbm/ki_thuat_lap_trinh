#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
struct point{
	int x;
	int y;
};
void input(int n, point *p, FILE *f){
	for (int i=0;i<n;i++){
		fscanf (f, "%d", &p[i].x);
		fscanf (f, "%d",&p[i].y);
	}
}
void output(int n, point *p){
	for (int i=0;i<n;i++){
		printf ("(%d %d) ", p[i].x,p[i].y);
	}
}
int count(int n, point *p, int x){
	int check=0;
	for (int i=0;i<n-1;i++){
		for (int j=0;j<n;j++){
			if (sqrt(pow(p[i].x,2)+pow(p[i].y,2))<=x&&sqrt(pow(p[j].x,2)+pow(p[j].y,2)<=x)){
				check++;
			}
		}
	}
	return check;
}
float distance(point p1, point p2){
	return (float)(sqrt(pow(p1.x-p2.x, 2)+pow(p1.y-p2.y,2)));
}
int check(int n, point *p){
	for (int i=0;i<n-2;i++){
		for (int j=i+1;j<n-1;j++){
			for (int k=j+1;k<n;k++){
				double AB = distance(p[i],p[j]);
			    double BC = distance(p[j],p[k]);
			    double CA = distance(p[k],p[i]);
			    if (fabs(AB*AB + BC*BC - CA*CA) < 1e-9 || fabs(AB*AB + CA*CA - BC*BC) < 1e-9 || fabs(BC*BC + CA*CA - AB*AB) < 1e-9) {
			        return 1; 
			    } else {
			        return 0; 
			    }
			}
		}
	}
}
float acreage(point p1, point p2, point p3){
	double AB = distance(p1,p2);
    double BC = distance(p2,p3);
    double CA = distance(p3,p1);
    double s = (AB + BC + CA) / 2;
    double area = sqrt(s * (s - AB) * (s - BC) * (s - CA));
    return area;
}
float rig_tria(int n, point *p, int *cnt){
	*cnt=0;
	float s_max=FLT_MIN;
	for (int i=0;i<n-2;i++){
		for (int j=i+1;j<n-1;j++){
			for (int k=j+1;k<n;k++){
				if (check(n,p)){
					if (s_max<acreage(p[i], p[j], p[k])){
						s_max=acreage(p[i], p[j], p[k]);
					}
					(*cnt)++;
					
				}
			}
		}
	}
	return s_max;
}
main(){
	int n;
	FILE *f;
	f=fopen("cau1input.txt", "r");
	fscanf (f,"%d", &n);
	point *p;
	p=(point*) malloc (n*sizeof(point));
	input(n,p,f);
	output(n,p);
}
