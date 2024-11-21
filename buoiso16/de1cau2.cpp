#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu{
	char name[50];
	char hometown[50];
	char aca_abili;
};
void input(int n, stu *s, FILE *f){
	for (int i=0;i<n;i++){
		fgets(s[i].name, sizeof(s[i].name), f);
		s[i].name[strlen(s[i].name)-1]='\0';
		fgets(s[i].hometown, sizeof(s[i].hometown), f);
		s[i].hometown[strlen(s[i].hometown)-1]='\0';
		fscanf (f, "%c\n", &s[i].aca_abili);
	}
}
void output(stu s){
	printf ("%s %s %c\n", s.name, s.hometown, s.aca_abili);
}
void output(int n, stu *s){
	for (int i=0;i<n;i++){
		output(*(s+i));
	}
}
stu find(int n, stu *s,char x[]){
	stu f;
	for (int i=0;i<n;i++){
		if (strcmp(s[i].name, x)==0){
			f=s[i];
			return f;
		}
	}
}
main(){
	FILE *f;
	f=fopen("de1cau2input.txt", "r");
	int n;
	fscanf (f,"%d\n", &n);
	stu *s;
	s=(stu*) malloc(n*sizeof(int));
	input(n,s,f);
	output(n,s);
	stu t=find(n,s,"sv1");
	if (t.name=="") printf ("\nkhong co sinh vien can tim");
	else{
		output(t);
	}
	
}
