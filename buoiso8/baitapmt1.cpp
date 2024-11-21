#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void nhap(int *a, int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf ("nhap [%d][%d]", i,j);
			scanf ("%d", (a+n*i+j));
		}
	}
}
void xuatmatran(int *a, int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf ("%3d", *(a+n*i+j));
		}
		printf ("\n");
	}	
}
void xuat(int n, int *a){
	for(int i=0;i<n;i++)
		printf("%d ", *(a+i));
}
int timmin(int *a, int n){
	int min=*(a+0);
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (*(a+n*i+j)<min) min=*(a+n*i+j);
		}
	}
	return min;
}
int minam(int *a, int n, int *check){
	int min;
	*check=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (*(a+n*i+j)<min&&*(a+n*i+j)<0){
				min =*(a+n*i+j);
				*check++;
			}
		}
	}
	return min;
}
/*int *maxcot(int *a, int n){
	int *tc;
	tc=(int*)malloc((n+1)*sizeof(int));
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			tc[i]+=*(a+n*j+i);
		}
	}
	/*int max=*tc;
	for (int i=0;i<n;i++){
		if (max<*(tc+i)) max=*(tc+i);
	}*/
//	return tc;
	//free(tc);
//}
int maxcot(int *a, int n){
    int *tc;
    tc = (int*)calloc(n, sizeof(int)); //dung calloc khoi tao gia tri ve khong
    if (tc == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            tc[i] += *(a + n * j + i);
        }
    }
    int max=*tc;
	for (int i=0;i<n;i++){
		if (max<*(tc+i)) max=*(tc+i);
	}
    return max;
    free(tc);
}
int *maxhang(int *a, int n){
	int *tc;
    tc = (int*)calloc(n, sizeof(int)); //dung calloc khoi tao gia tri ve khong
    if (tc == NULL) {
        return NULL;
    }
    int i=0;
    while (i<n){
    	tc[i]=INT_MIN;//cho gia tri ve min cua int
    	i++;
	}
    for (int i=0;i<n;i++){
    	for (int j=0;j<n;j++){
    		if (tc[i]<*(a+n*i+j)) tc[i]=*(a+n*i+j);
		}
	}
	return tc;
	free(tc);
}
int lonhon(int *a, int n, int c){
	int *tc;
    tc = (int*)calloc(n, sizeof(int)); //dung calloc khoi tao gia tri ve khong
    if (tc == NULL) {
        return NULL;
    }
	int check=0;
    for (int i=0;i<n;i++){
    	for (int j=0;j<n;j++){
    		if (*(a+n*i+j)>c&&*(a+n*i+j)>0){
    			tc[i]=*(a+n*i+j);
    			check++;
			}
		}
	}
	return check;
	free(tc);
}
int cheoduoi(int *a, int n){
	int check=0;
	for (int i=0;i<n;i++){	
		for (int j=i+1;j<n;j++){
			if (*(a+n*i+j)==0) continue;
			else check++;
		}
	}
	return check;
}
int tichcheo(int *a, int n, int *dem){
	int tich=1;
	*dem=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (*(a+n*i+j)<0){
				tich*=*(a+n*i*j);
				*dem++;
			} 
		}
	}
	return tich;
}
float tbc(int *a, int n, int c, int *check){
	int tong=0;
	*check=0;
    for (int i=0;i<n;i++){
    	for (int j=0;j<n;j++){
    		if (*(a+n*i+j)>c){
    			tong+=*(a+n*i+j);
    			*check++;
			}
		}
	}
	return (float)(tong/(*check));
}
int khoang(int *a, int n, int c, int d){
	int dem=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (*(a+n*i+j)>c&&*(a+n*i+j)<d){
    			dem++;
			}
		}
	}
	return dem;
}
int hanglonnhat(int *a, int n){
    int *tc;
    tc = (int*)calloc(n, sizeof(int)); //dung calloc khoi tao gia tri ve khong
    if (tc == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            tc[i] += *(a + n * i + j);
        }
    }
    int max=*tc;
	for (int i=0;i<n;i++){
		if (max<*(tc+i)) max=*(tc+i);
	}
	int check=0;
    for (int i=0;i<n;i++){
    	if (max==*(tc+i)) check=i;
	}
	return check;
int main(){
	int n;
	scanf ("%d", &n);
	/*int **a;
	a=(int**) malloc(n*sizeof(int*));
	for (int i=0;i<n;i++){
		a[i]=(int*) malloc(n*sizeof(int));
	}*///cach 1
	int *a;
	a=(int*)malloc(n*n*sizeof(int));
	nhap(a,n);//1
	xuatmatran(a,n);
	int c=timmin(a,n);//2
	printf ("gia tri nho nhat cua ma tran la: %d",c);
	minam(a,n,&c);//3
	if (c==0){
		printf ("\nkhong co gia tri am\n");
	}
	else printf("\ngia tri am nho nhat cua ma tran la: %d", minam(a,n,&c));
	printf ("tong cot lon nhat la : %d\n", maxcot(a,n));
	int *k=maxhang(a,n);//4
	printf("cac hang co so lon nhat lan luot la: ");
	xuat(n,k);
	int b=10;
	printf ("\nso gia tri lon hon 10 thoa man la: %d", lonhon(a,n,b));
	b=cheoduoi(a,n);
	if (b==0) printf ("\nma tran cheo duoi");
	else printf ("\nma tran khong cheo duoi");
	b=tichcheo(a,n,&c);
	if (c==0)	printf ("\nduong cheo khong co so am");
	else printf ("tich duong cheo ma tran la: %d", b);
	b=tbc(a,n,10,&c);
	if (c==0) printf ("\nkhong co gia tri lon hon 10");
	else printf ("tbc cua nhung so lon hon 10 la: %.2f", b);
	b=5;
	c=30;
	if (khoang(a,n,b,c)==0) printf ("\nkhong co gia tri nao thoa man");
	else printf ("\nso gia tri thoa man la: %d", khoang(a,n,b,c));
	return 0;
}
