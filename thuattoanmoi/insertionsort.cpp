#include <stdio.h>
main(){
	int n;
	int a[100];
	scanf ("%d", &n);
	for (int i=0;i<n;i++){
		scanf ("%d", &a[i]);
	}
	for (int i=1;i<n;i++){
		int j=i;
		while(a[j]<=a[j-1]&&j>0){
			int temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			j--;
		}
	}
	printf ("\n");
	for (int i=0;i<n;i++){
		printf ("%d", a[i]);
	}
}
