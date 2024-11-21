#include <stdio.h>
#include <stdlib.h>
int divisor(int a){
	int k=0;
	for (int i=1;i<a;i++){
		if (a%i!=0){
			k++;
		}
	}
	return k;
}
void input(int *a, int n){
	for (int i=0;i<n;i++){
		scanf ("%d", a+i);
	}
}
void output(int *a, int n){
	for (int i=0;i<n;i++){
		printf ("%d ", *(a+i));
	}
}
int *find(int *a, int n, int *k){
	*k=0;
	int *b;
	b=(int*)malloc(n*sizeof(int));
	for (int i=0;i<n;i++){
		if (divisor(a[i])>3){
			b[*k]=a[i];
			(*k)++;
		}
	}
	return b;
}
int findLastOccurrence(int arr[], int n, int x) {
    int lastOccurrence = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            lastOccurrence = i;
        }
    }
    return lastOccurrence;
}
int maxnegative(int arr[], int n) {
    int maxNegative = -1; 
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0 && (maxNegative == -1 || arr[i] > arr[maxNegative])) {
            maxNegative = i;
        }
    }
    return maxNegative; 
}
float ao_primes(int arr[], int n) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            sum += arr[i];
            count++;
        }
    }
    if (count == 0) {
        return 0;
    }
    return (float)sum / count; 
}
main(){
	int n;
	scanf ("%d", &n);
	int *a;
	a=(int*)malloc(n*sizeof(int));
	input(a,n);
	output(a,n);
	int c;
	int *b=find(a,n, &c);
	if (c==0) printf ("\nkhong co so co so uoc chung lon hon 3");
	else {
		printf ("\nnhung so co so uoc chung lon 3 la: ");
		output(b,c);
	}
}
