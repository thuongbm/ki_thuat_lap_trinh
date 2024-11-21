#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
int random(int minN, int maxN){
	return minN + rand() % (maxN + 1 - minN);
}
void inputrandom(int a[], int n){
	for (int i=0;i<n;i++){
		a[i]=random(0,20000);
	}
}
void listed(int a[], int n){
	int mark[30000]={0};
	for (int i=0;i<n;i++){
		if (mark[a[i]]==0){
			printf ("%d ", a[i]);
			mark[a[i]]=1;
		}
	}
}
int *frequency(int a[], int n){
	int *cnt=(int*)calloc(30000, sizeof(int));
	for (int i=0;i<n;i++){
		cnt[a[i]]++; 
	}
	return cnt;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void arrange(int a[], int n){
	for (int i=0;i<n-1;i++){
		for (int j=0;j<n-i-1;j++){
			if (a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
			}
		}
	}
}
int *del(int a[], int n, int x){
	int *cnt=(int*)calloc(30000, sizeof(int));
	for(int i=0;i<n;i++){
		if (a[i]!=x){
			cnt[i]=a[i];
		}
	}
	return cnt;
}
int max(int a[], int n){
	int max=INT_MIN;
	for (int i=0;i<n;i++){
		if (a[i]>max) max=a[i];
	}
	return max;
}
void insert(int a[], int n, int x){//khong chac dung
	int check;
	for (int i=0;i<n;i++){
		if (a[i]==max(a,30000)) check++;
	}
	for (int i=0;i<n+check;i++){
		if (a[i]==max(a,30000)){
			a[i]=a[i+1];
			a[i]=x;
		}
	}
}
main(){
	srand(time(NULL));
	int a[30000];
	inputrandom(a,30000);
//	int *b;
//	b=frequency(a,30000);
//	for (int i=0;i<30000;i++){
//		if (b[i]>1){
//			printf ("%d: %d\n", i, b[i]);
//		}
//	}
//	arrange(a, 30000);
//	for (int i=0;i<30000;i++){
//		printf ("%d ", a[i]);
//	}
	int x;
	scanf ("%f", &x);
}
