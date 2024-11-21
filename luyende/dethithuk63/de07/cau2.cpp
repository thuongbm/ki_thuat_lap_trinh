#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct student{
	char name[50];
	int point;
	char uni;
};
void input(student *st, FILE *f){
	fgets(st->name, 50, f);
	st->name[strlen(st->name)-1]='\0';
	fscanf (f, "%d\n", &st->point);
	fscanf (f, "%c\n", &st->uni);
}
void input(int n, student *st, FILE *f){
	for (int i=0;i<n;i++){
		input(st+i, f);
	}
}
void output(student st){
	printf ("%s %d %c\n", st.name, st.point, st.uni);
}
void output(int n, student *st){
	for (int i=0;i<n;i++){
		output(*(st+i));
	}
}
int max(int a, int b){
	return (a>b)? a:b; 
}
int sum_uni(int n, student *st, char x){
	int sum=0;
	for (int i=0;i<n;i++){
		if (st[i].uni==x){
			sum+=st[i].point;
		}
	}
	return sum; 
}
student max(int n ,student *st){
	student max;
	max.point=INT_MIN;
	for (int i=0;i<n;i++){
		if (st[i].point>max.point) max=st[i];
	}
	return max;
}
main(){
	FILE *f,*f2;
	f=fopen("cau2input.txt", "r");
	f2=fopen("cau2output.txt", "w");
	student *st;
	st=(student*) malloc(3*sizeof(student));
	input(3,st,f);
	output(3,st);
	fprintf (f2, "tong diem cua truong A= %d, B= %d, C=%d", sum_uni(3,st,'A'), sum_uni(3,st,'B'), sum_uni(3,st,'C'));
	fprintf (f2, "\nthi sinh diem cao nhat trong 3 thi sinh la: ");
	student m=max(3,st);
	fprintf (f2, "%s %d %c\n", m.name, m.point, m.uni);
}
