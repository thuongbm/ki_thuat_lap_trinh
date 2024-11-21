#include <stdio.h>
#include <stdlib.h>
#include <float.h>
struct oto{
	int bsk;
	float tt;
	char cty;
};
void input(oto *o, FILE *f){
	fscanf (f,"%d", &o->bsk);
	fscanf (f,"%f\n", &o->tt);
	fscanf (f,"%c", &o->cty);
}
void input(int n, oto *o, FILE *f){
	for (int i=0;i<n;i++){
		input(o+i, f);
	}
}
void output(oto o){
	printf ("%d %.2f %c\n", o.bsk, o.tt, o.cty);
}
void output(int n, oto *o){
	for (int i=0;i<n;i++){
		output(*(o+i));
	}
}
oto *chiahet(int n, oto *o,int x, int *k){
	(*k)=0;
	oto *t;
	t=(oto*) malloc (n*sizeof(oto));
	for (int i=0;i<n;i++){
		if (o[i].bsk%x==0){
			t[*k]=o[i];
			(*k)++;
		}
	}
	return t;
}
oto min(int n, oto *o){
	oto t;
	float min=FLT_MAX;
	for (int i=0;i<n;i++){
		if (o[i].tt< min){
			t=o[i];
		}
	}
	return t;
}
main(){
	int n;
	FILE *f1,*f2;
	f1=fopen ("de1cau2input.txt", "r");
	f2=fopen ("de1cau2output.txt", "w");
	fscanf (f1,"%d", &n);
	oto *o;
	o=(oto*) malloc(n*sizeof(oto));
	input(n,o,f1);
	output (n,o);
	int k;
	oto *t=chiahet(n,o,3,&k);
	if (k==0) printf ("\nkhong co oto chia het cho 3");
	else{
		printf ("\noto chia het cho 3 la: \n");
		output(k,t);
	}
	oto b=min(n,o);
	printf ("\noto trong tai nho nhat la ");
	output(b);
	t=chiahet(n,o,2,&k);
	for (int i=0;i<k;i++){
		fprintf (f2, "%d %.2f %c\n", t[i].bsk, t[i].tt, t[i].cty);
	}
}

