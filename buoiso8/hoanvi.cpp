#include <stdio.h>
void hv(int *a, int *b){
	int t=*a;
	*a=*b;
	*b=t;
	printf ("\na trong ham: %d", *a);
}
main(){
	int a=6, b=7;
	hv(&a, &b);
	printf ("\n%d", a);
	printf ("\n%d", b);
}
