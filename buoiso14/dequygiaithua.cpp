#include <stdio.h>
int gt(int n){
	if (n==0) return 1;
	else return n*gt(n-1);
}
main(){
	int n;
	scanf ("%d", &n);
	printf ("%d", gt(n));
}
