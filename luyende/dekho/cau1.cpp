#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct time{
	int hour;
	int minute;
};
struct train{
	int train_n;
	char from[50];
	char to[50];
	time star;
	time end;
	char type;
};
void input(int n, train *t, time *ti, FILE *f){
	for (int i=0;i<n;i++){
		fscanf (f, "%d\n", &t[i].train_n);
		fgets (t[i].from, sizeof (t[i].from), f);
		fgets (t[i].to, sizeof (t[i].to), f);
		fscanf (f, "%d", &t[i].star.hour);
		fscanf (f, "%d", &t[i].star.minute);
		fscanf (f, "%d", &t[i].end.hour);
		fscanf (f, "%d\n", &t[i].end.minute);
		fscanf (f, "%c\n", &t[i].type);
	}
}
void output(int n, train *t, time *ti){
	for (int i=0;i<n;i++){
		printf ("%d\n%s%s%d %d\n%d %d\n%c\n", t[i].train_n, t[i].from, t[i].to, t[i].star.hour, t[i].star.minute, t[i].end.hour, t[i].end.minute, t[i].type);
	}
}
int sumtime(int n, train *t, time *ti, char x){
	int sum=0;
	for (int i=0;i<n;i++){
		if (t[i].type==x){
			sum+=(t[i].end.hour*60-t[i].star.hour*60)+(t[i].end.minute-t[i].star.minute);
		}
	}
	if (sum==0) return 0;
	return sum;
}
int *shorter(int n, train *t, time *ti, char x, char y){
	int min=INT_MAX;
	int *find;
	find =(int*) malloc (n*sizeof(int)); 
	for (int i=0;i<n;i++){
		if (((t[i].end.hour*60-t[i].star.hour*60)+(t[i].end.minute-t[i].star.minute))<min&&t[i].type==x){
			min=((t[i].end.hour*60-t[i].star.hour*60)+(t[i].end.minute-t[i].star.minute));
		}
	}
	for (int i=0;i<n;i++){
		if (t[i].type==y&&((t[i].end.hour*60-t[i].star.hour*60)+(t[i].end.minute-t[i].star.minute))<min){
			find[i]=t[i].train_n;
		}
	}
	return find;
}
int furthest(int n, train *t, time *ti){
	int max=INT_MIN;
	int furthest;
	for (int i=0;i<n;i++){
		if (((t[i].end.hour*60-t[i].star.hour*60)+(t[i].end.minute-t[i].star.minute))>max){
			max=((t[i].end.hour*60-t[i].star.hour*60)+(t[i].end.minute-t[i].star.minute));
			furthest=t[i].train_n;
		}
	}
	return furthest;
}
void compare(int n, train *t, time *ti){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (strcmp(t[i].from, t[j].from)==0&&strcmp(t[i].to, t[j].to)==0){
				printf ("%d %d\n", t[i].train_n, t[j].train_n);
			}
		}
	}
}
int latest(int n, train *t, time *ti){
	int max=INT_MIN;
	int latest;
	for (int i=0;i<n;i++){
		if (max<((t[i].star.hour*60+t[i].star.minute))){
			max=(t[i].star.hour*60+t[i].star.minute);
			latest=t[i].train_n;
		}
	}
	return latest;
}
void find(int n, train *t, time *ti, char x[], char y[]){
	for (int i=0;i<n;i++){
		if (strcmp(t[i].from,x)==0, strcmp(t[i].to, y)==0)
		printf ("%d\n%s%s%d %d\n%d %d\n%c\n", t[i].train_n, t[i].from, t[i].to, t[i].star.hour, t[i].star.minute, t[i].end.hour, t[i].end.minute, t[i].type);
	}
}
main(){
	FILE *f;
	f=fopen ("inputcau1.txt", "r");
	int n;
	fscanf (f, "%d", &n);
	train *t;
	t=(train*) malloc (n*sizeof(train));
	time *ti;
	input(n,t,ti,f);
	output(n,t,ti);
}
