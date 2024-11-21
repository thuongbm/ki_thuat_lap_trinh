#include"stdio.h"
#include"stdlib.h"
void nhap(int *m,int *n,int ***a)
{
	printf("nhap so hang:");
	scanf("%d",m);
	printf("nhap so cot:");
	scanf("%d",n);
	*a=(int **)malloc(sizeof(int)*(*m+1)*(*n+1));
	for(int i=0;i<*m;i++)
	{
		*(*a+i) =(int *)malloc(sizeof(int)*(*n+1));
		for(int j=0;j<*n;j++)
			scanf("%d",*(*a+i)+j);
	}
}
void xuat(int m,int n,int **a)
{	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
}
// hang nao co tong nho nhat
void hangNN(int m, int n, int **a){
	int b[100];
	for(int i=0;i<m;i++){
		b[i]=0;
		for(int j=0;j<n;j++)
			b[i]+=a[i][j];
	}
	int min=b[0];
	for(int i=0;i<m;i++)
		if(b[i]<min)
			min = b[i];
	printf("\nhang co tong nho nhat la: ");
	for(int i=0;i<m;i++)
		if(b[i]==min)
			printf("%5d", i+1);
	
}

main(){
	int m, n, **a;
	nhap(&m, &n, &a);
	xuat(m, n, a);
}
