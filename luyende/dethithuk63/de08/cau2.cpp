#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct staff{
	int staff_num;
	char name[50];
	float coe_salary;
	int room;
	float wage;
};
void input(int n, staff *s, FILE *f, float x){
	for (int i=0;i<n;i++){
		fscanf (f,"%d\n", &s[i].staff_num);
		fgets(s[i].name, sizeof(s[i].name), f);
		s[i].name[strlen(s[i].name)-1]='\0';
		fscanf (f, "%f", &s[i].coe_salary);
		fscanf (f, "%d", &s[i].room);
		s[i].wage=x*s[i].coe_salary;
	}
}
void swap(staff *a, staff *b){
	staff temp=*a;
	*a=*b;
	*b=temp;
}
void bubble_sort(int n, staff *s){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (s[i].wage>s[j].wage){
				swap(&s[i], &s[j]);
			}
		}
	}
}
void output (staff s, FILE *f){
	fprintf (f, "%d %s %.2f %d %.2f\n", s.staff_num,s.name, s.coe_salary,s.room, s.wage);
} 
void output(int n, staff *s){
	for (int i=0;i<n;i++){
		printf ("%d %s %.2f %d %.2f\n", s[i].staff_num,s[i].name, s[i].coe_salary,s[i].room, s[i].wage);
	}
}
float max(float a, float b){
	return (a>b)?a:b;
}
float ave_wage(int n, staff *s, int x){
	float ave=0;
	int check=0;
	for (int i=0;i<n;i++){
		if (s[i].room==x){
			ave+=s[i].wage;
			check++;
		}
	}
	if (check==0) return 0;
	else return ave/check;
}
staff find(int n, staff *s, char x[], int y, int *check){
	staff find;
	*check=0;
	for (int i=0;i<n;i++){
		if (s[i].room==y&&strcmp(x,s[i].name)==0){
			find= s[i];
			*check=1;
			break;
		}
	}
	return find;
}
main(){
	FILE *f, *f2;
	f=fopen("cau2input.txt", "r");
	f2=fopen("cau2output.txt", "w");
	int n;
	fscanf (f, "%d", &n);
	staff *s;
	s=(staff*) malloc(n*sizeof (staff));
	input(n,s,f,10000);
	bubble_sort(n,s);
	output(n,s);
	if (ave_wage(n,s,1)==0) printf ("\nkhong co ai o phong ban 1");
	else {
		printf ("\nluong cua phong ban 1 la %.2f", ave_wage(n,s,1));
	}
	if (ave_wage(n,s,2)==0) printf ("\nkhong co ai o phong ban 2");
	else {
		printf ("\nluong cua phong ban 2 la %.2f", ave_wage(n,s,2));
	}
	if (ave_wage(n,s,3)==0) printf ("\nkhong co ai o phong ban 3");
	else {
		printf ("\nluong cua phong ban 3 la %.2f", ave_wage(n,s,3));
	}
	printf ("\nluong tb cua phong ban cao nhat la %.2f", max(ave_wage(n,s,1),max(ave_wage(n,s,2),ave_wage(n,s,3))));
	int d;
	staff w=find(n,s,"nv1", 1, &d);
	if (d==0) printf ("\nkhong co nguoi can tim");
	else{
		output(w,f2);
	}
}
