#include <stdio.h>
#include <stdlib.h>
void merge(int a[], int left, int middle, int right){
	//kich thuoc mang
	int len_left=middle-left+1;
	int len_right=right-middle;
	//mang tam thoi
	int a_left[len_left];
	int a_right[len_right];
	for (int i=0;i<len_left;i++){
		a_left[i]=a[left+i];
	}
	for (int i=0;i<len_right;i++){
		a_right[i]=a[middle+1+i];
	}
	//sap xep lai cac mang voi thu tu voi be truoc lon sau
	int i=0;
	int j=0;
	int k=left;
	while(i<len_left&&j<len_right){
		if (a_left[i]<a_right[j]){
			a[k]=a_left[i];
			i++;
		}
		else {
			a[k]=a_right[j];
			j++;
		}
		k++;
	}
	//copy nhung phan tu ben trai chua duoc dua vao
	while(i<len_left){
		a[k]=a_left[i];
		i++;
		k++;
	}
}
void mergesort(int a[], int left, int right){
	if (left<right){
		//tim vi tri o giua
		int middle=(left+right)/2;
		//de quy tung phan ben trai va phai
		mergesort(a,left,middle);
		mergesort(a,middle+1,right);
		//gop cac mang lai voi nhau
		merge(a,left,middle,right);
	}
}
void xuat(int a[],int n){
	for (int i=0;i<n;i++){
		printf ("%d ",a[i]);
	}
}
main(){
	int n;
	printf ("nhap so phan tu cua day: ");
	scanf ("%d", &n);
	int a[1000];
	printf ("nhap day so: ");
	for (int i=0;i<n;i++){
		scanf ("%d", &a[i]);
	}
	mergesort(a,0,n-1);
	xuat(a,n);
}
