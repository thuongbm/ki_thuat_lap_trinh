#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void input(int *a, int n){
	for (int i=0;i<n;i++){
		scanf ("%d", a+i);
	}
}
void output(int *a,int n){
	for (int i=0;i<n;i++){
		printf ("%d ",*(a+i));
	}
}
int min(int m, int n) {
    return (m < n) ? m : n;
}
//int *just1(int *a, int n){
//	int *c;
//	c=(int*) calloc(max(a,n),sizeof(int));
//	for (int i=0;i<n;i++){
//		c[a[i]]++;
//	}
//	return c;
//}
int *hop(int *a, int *b, int m, int n, int *h){
	int *hop;
	hop=(int*) calloc((m+n),sizeof(int));
	int i=0, j=0;
	*h=0;
	while(i<n&&j<m){
		if(a[i]==b[j]){
			hop[*h]=a[i];
			i++; j++;
			(*h)++; 
		}
		else if (a[i]>b[j]){
			hop[(*h)++]=b[j++];
		}
		else{
			hop[(*h)++]=a[i++];
		}
	}
	while(i<n){
		hop[(*h)++]=a[i++];
	}
	while(j<m){
		hop[(*h)++]=b[j++];
	}
	return hop;
	free(hop);
}
int *giao(int *a, int *b, int n, int m, int *g){
	int *giao;
	giao=(int*) calloc(min(m,n),sizeof(int));
	if (giao == NULL) {
        return NULL;
    }
	int i=0, j=0;
	*g=0;
	while(i<n&&j<m){
		if(a[i]==b[j]){
			giao[*g]=a[i];
			i++; j++;
			(*g)++; 
		}
		else if(a[i]>b[j]){
			j++;
		}
		else{
			i++;
		}
	}
	return giao;
	free(giao);
}
main(){
	int m,n;
	scanf ("%d%d", &n,&m);
	int *a,*b;
	a=(int*) malloc(n*sizeof(int));
	b=(int*) malloc(m*sizeof(int));
	input(a,n);
	input(b,m);
	output(a,n);
	printf ("\n");
	output(b,m);
	printf("\n");
	int e;
	int *c=hop(a,b,m,n,&e);
	printf ("\nhop cua 2 tap hop la: ");
	output(c,e);
	c=giao(a,b,m,n,&e);
	if (e==0) printf ("\nkhong co phan tu nao giao");
	else{
		printf ("\ngia cua 2 tap hop la: ");
		output(c,e);
	}
	free(a);
	free(b);
	free(c);
}
