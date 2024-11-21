#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct sv{
	char name[50];
	char homet[50];
	char aca_abi;
};
void input(sv *s, FILE *f){
	fgets(s->name, 20, f);
	s->name[strlen(s->name)-1]='\0';
	fgets(s->homet, 20, f);
	s->homet[strlen(s->homet)-1]='\0';
	fscanf (f, "%c\n", &s->aca_abi);
}
void input(int n, sv *s, FILE *f){
	for (int i=0;i<n;i++){
		input(s+i, f);
	}
}
void output(sv s){
	printf ("%s %s %c\n", s.name, s.homet, s.aca_abi);
}
void output(int n, sv *s){
	for (int i=0;i<n;i++){
		output(*(s+i));
	}
}
sv findst(int n, sv *s, char x[], int *k){
	sv findx;
	*k=0;
	for (int i=0;i<n;i++){
		if (strcmp(s[i].name, x)==0){
			findx=s[i];
			(*k)=1;
		}
	}
	return findx;
}
int count(int n, sv *s, char x){
	int cnt=0;
	for (int i=0;i<n;i++){
		if (s[i].aca_abi==x){
			cnt++;
		}
	}
	return cnt;
}
sv *find_abi(int n, sv *s, char x,int *k){
	sv *find;
	*k=0;
	find=(sv*) malloc (n*sizeof(sv));
	for (int i=0;i<n;i++){
		if (s[i].aca_abi==x){
			find[*k]=s[i];
			(*k)++;
		}
	}
	return find;
	free(find);
}
main(){
	FILE *f1;
	f1=fopen("cau4.txt", "r");
	int n;
	fscanf (f1, "%d\n", &n);
	sv *s;
	s=(sv*) malloc (n*sizeof(sv));
	input(n,s,f1);
	output(n,s);
	printf ("nhap sinh vien can tim: ");
	char x[50];
	gets(x);
	int k;
	sv findx=findst(n,s,x,&k);
	if (k==0) printf ("\nkhong co sinh vien can tim");
	else{
		printf ("\nsinh vien can tim la: ");
		output(findx);
	}
	k=count(n,s,'A');
	if (k==0) printf ("\nkhong co sinh vien nao hoc luc a");
	else printf ("\nso sinh vien hoc luc a la: %d", k);
	sv *find_=find_abi(n,s,'A',&k);
	if (k==0) printf ("\nkhong co sinh vien co hoc luc can tim");
	else{
		printf ("\nsinh vien co hoc luc can tim la");
		printf ("\n");
		output(k, find_);
	}
	fclose(f1);
	free(s);
	free(find_);
}
