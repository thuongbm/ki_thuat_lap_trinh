#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct point{
	float x,y;
};
struct line{
	point s;
	point e;
};
void inputpoint(struct point *p) {
    printf("Nhap toa do x: ");
    scanf("%f", &p->x);
    printf("Nhap toa do y: ");
    scanf("%f", &p->y);
}
void inputline(struct line *l) {
    printf("Nhap toa do cho diem bat dau (s):\n");
    inputpoint(&l->s);
    printf("Nhap toa do cho diem ket thuc (e):\n");
    inputpoint(&l->e);
}
float dodai(struct line *l){
	float kc=sqrt(float(l->s.x-l->e.x)*(l->s.x-l->e.x)+(l->s.y-l->e.y)*(l->s.y-l->e.y));
	return kc;
}
int kt(struct point p, struct line l) {
    int dx = l.e.x - l.s.x;
    int dy = l.e.y - l.s.y;
    if ((p.y - l.s.y) * dx == (p.x - l.s.x) * dy) {
        return 1;
    } else {
        return 0;
    }
}
void xuat(struct line *l){
	printf("(s): (%.2f, %.2f)\n", l->s.x, l->s.y);
    printf("(e): (%.2f, %.2f)\n", l->e.x, l->e.y);
}
main(){
	struct line l;
	struct point p;
	inputline(&l);
	printf ("do dai doan thang la: %.2f", dodai(&l));
	printf("\nNhap toa do diem can kiem tra:\n");
    printf("x: ");
    scanf("%f", &p.x);
    printf("y: ");
    scanf("%f", &p.y);
	if (kt(p, l)) {
        printf("diem (%.2f, %.2f) nam tren duong thang.\n", p.x, p.y);
    } else {
        printf("diem (%.2f, %.2f) khong nam tren duong thang.\n", p.x, p.y);
    }
    printf ("\n");
    xuat(&l);
}
