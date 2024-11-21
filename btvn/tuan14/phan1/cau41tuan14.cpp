#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void input(int *a, int n){
	for(int i=0;i<n;i++){
		scanf ("%d", a+i);
	}
}
void output(int *a, int n){
	for (int i=0;i<n;i++){
		printf ("%d ", *(a+i));
	}
}
bool prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int *prime(int *a, int n, int *check){
	*check=0;
	int *b;
	b=(int*)malloc(n*sizeof(int));
	for (int i=0;i<n;i++){
		if (prime(a[i])){
			b[*check]=a[i];
			(*check)++;
		}
	}
	return b;
}
main(){
	int n;
	scanf ("%d", &n);
	int *a;
	a=(int*)malloc(n*sizeof(int));
	input(a,n);
	output(a,n);
	int c;
	int *b=prime(a,n, &c);
	if (c==0) printf ("\nkhong co so nguyen to");
	else{
		printf ("\nso nguyen to trong day la: ");
		output(b,c);
	}
}
