#include <stdio.h>
int sum(int n){
	if (n==1) return 1;
	else return n+sum(n-1);
}
main(){
	int n;
	scanf("%d", &n);
	printf ("\n%d", sum(n));
}
