#include <stdio.h>
#include <stdlib.h>
struct commodity{
	char type;
	float mass;
	int time;
};
void input(int n, commodity *c, FILE *f){
	for (int i=0;i<n;i++){
		fscanf (f,"%c", &c[i].type);
		fscanf (f,"%f", &c[i].mass);
		fscanf (f,"%d", &c[i].time);
	}
}
void output(int n, commodity *c){
	for (int i=0;i<n;i++){
		printf ("%c %.2f, %d\n", c[i].type, c[i].mass, c[i].time);
	}
}
void swap(commodity *a, commodity *b){
	commodity temp = *a;
			*a = *b;
			*b = temp;
}
void ascending(int n, commodity *c){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (c[i].mass>c[j].mass){
				swap(&c[i], &c[j]);
			}
		}
	}
}
commodity *goods_of_t(int n, commodity *c,char x, int *k){
	*k=0;
	commodity *t;
	t=(commodity*) malloc(n*sizeof(commodity));
	for (int i=0;i<n;i++){
		if (c[i].type==x){
			t[*k]=c[i];
			*k++;
		}
	}
}
void grease(int n, commodity *c){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (c[i].time<c[j].time){
				swap(&c[i], &c[j]);
			}
		}
	}
}
commodity *find(int n, commodity *c, char x, int *k){
	commodity *f;
	f=(commodity*) malloc(n*sizeof(commodity));
	(*k)=0;
	for (int i=0;i<n;i++){
		if (c[i].type==x&&c[i].time>180){
			f[*k]=c[i];
			(*k)++;
		}
	}
	return f;
}
main(){
	FILE *f,*f2;
	f=fopen("de3cau2input.txt", "r");
	f2=fopen("de3cau2output.txt", "w");
	int n;
	fscanf (f,"%d\n", &n);
	commodity *c;
	c=(commodity*) malloc(n*sizeof(commodity));
}
