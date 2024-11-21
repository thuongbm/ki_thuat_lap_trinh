#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book{
	int code_book;
	char name_b[50];
	char name_wri[50];
	int year;
	int price;
};
void inputx(book k){
	scanf ("%d", &k.code_book);
	fflush (stdin);
	gets (k.name_b);
	fflush (stdin);
	gets(k.name_wri);
	scanf ("%d", &k.year);
	scanf ("%d", &k.price);
}
void input(book *b, FILE *f){
	fscanf (f, "%d\n", &b->code_book);
	fgets(b->name_b, sizeof(b->name_b), f);
	b->name_b[strlen(b->name_b)-1]='\0';
	fgets(b->name_wri, sizeof(b->name_wri), f);
	b->name_wri[strlen(b->name_wri)-1]='\0';
	fscanf (f, "%d", &b->year);
	fscanf (f, "%d\n", &b->price);
}
void input(int n, book *b, FILE *f){
	for (int i=0;i<n;i++){
		input(b+i, f);
	}
}
void output(int n,book *b, FILE *f){
	for (int i=0;i<n;i++){
		fprintf (f,"%d %s %s %d %d\n", b[i].code_book, b[i].name_b, b[i].name_wri, b[i].year, b[i].price);
	}
}
book *find(int n, book *b, char x[], int f, int *k){
	*k=0;
	book *s=(book*) malloc (n*sizeof(book));
	for (int i=0;i<n;i++){
		if (strcmp(b[i].name_b, x)==0&&b[i].price==f){
			s[*k]=b[i];
			(*k)++;
		}
	}
	return s;
}
void swap(book *a, book *b){
	book temp=*a;
	*a=*b;
	*b=temp;
}
void sort(int n, book *b){
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n-1;j++){
			if (b[i].year>b[j].year){
				swap(&b[i], &b[j]);
			}
		}
	}
}
main(){
	int n;
	FILE *f1, *f2;
	f1=fopen("inputcau2.txt", "r");
	f2=fopen("outputcau2.txt", "w");
	fscanf (f1,"%d", &n);
	book *b;
	b=(book*) malloc (n*sizeof(book));
	input(n,b,f1);
	output(n,b,f2);
	printf ("nhap ten sach can tim: ");
	char x[50];
	gets (x);
	int fi;
	printf ("\nnhap gia tien cua cuon sach: ");
	scanf ("%d", &fi);
	fprintf (f2, "\n");
	int q;
	book *s=find(n,b,x,fi,&q);
	if (q==0) fprintf (f2,"\nkhong co quyen sach nhu the");
	else{
		fprintf (f2, "\nquyen sach can tim la: \n");
		output(q,s,f2);
	}
	fprintf (f2,"\nthu tu sau khi duoc sap xep la\n");
	output(n,b,f2);
}
