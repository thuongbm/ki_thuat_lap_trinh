#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct stu{
	char name[50];
	int score;
	char school;
};
void input(int n, stu *s, FILE *f){
	for (int i=0;i<n;i++){
		fgets(s[i].name, sizeof(s[i].name), f);
		s[i].name[strlen(s[i].name)-1]='\0';
		fscanf (f,"%d\n", &s[i].score);
		fscanf (f,"%c\n", &s[i].school);
	}
}
void output(int n, stu *s){
	for (int i=0;i<n;i++){
		printf ("|%s| %d| %c|\n", s[i].name, s[i].score, s[i].school);
	}
}
int max(int a, int b){
	return (a>b)?a:b;
}
int sum(int n, stu *s, char x){
	int sum=0;
	for (int i=0;i<n;i++){
		if (s[i].school==x) sum+=s[i].score;
	}
	return sum;
}
char* find(int n, stu *s) {
    int max = INT_MIN;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (s[i].score > max) {
            max = s[i].score;
            index = i;
        }
    }
    if (index != -1) {
        return s[index].name;
    }
    return NULL;
}
main(){
	FILE *f;
	f=fopen("cau2input.txt", "r");
	int n;
	fscanf (f,"%d\n", &n);
	stu *s;
	s=(stu*) malloc(n*sizeof(stu));
	input(n,s,f);
	output(n,s);
	int a=sum(n,s,'A');
	int b=sum(n,s,'B');
	int c=sum(n,s,'C');
	if (a==max(a,max(b,c))) printf ("\ntruong a diem cao nhat");
	else if (b==max(a,max(b,c))) printf ("\ntruong b diem cao nhat");
	else if (c==max(a,max(b,c))) printf ("\ntruong c diem cao nhat");
	printf ("\nthi sinh diem cao nhat la: ");
	char *x=find(n,s);
	printf ("%s", x);
}
