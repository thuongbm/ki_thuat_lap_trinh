#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct car{
	int bks;
	float tt;
	char name;
};
void input(int n, car *c,FILE *f){
	for (int i=0;i<n;i++){
		fscanf (f,"%d", &c[i].bks);
		fscanf (f,"%f\n", &c[i].tt);
		fscanf (f,"%c",&c[i].name);
	}
}
void output(int n, car *c){
	for (int i=0;i<n;i++){
		printf ("%d %.2f %c\n", c[i].bks, c[i].tt, c[i].name);
	}
}
car max(int n, car *c, char x, float y){
	car f;
	int max=INT_MIN;
	for (int i=0;i<n;i++){
		if (c[i].name==x&&c[i].tt<y&&c[i].tt>max){
			max=c[i].tt;
			f=c[i];
		}
	}
	return f;
}
float min(float a, float b){
	return (a<b)?a:b;
}
float average(int n, car *c, char x){
	float sum=0;
	int check=0;
	for (int i=0;i<n;i++){
		if (c[i].name==x){
			sum+=c[i].tt;
			check++;
		}
	}
	return sum/check;
}
void bublesort(int n, car *c){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (c[i].tt>c[j].tt){
				car temp=c[i];
				c[i]=c[j];
				c[j]=temp;
			}
		}
	}
}
main(){
	int n;
	FILE *f;
	f=fopen("decau2.txt","r");
	fscanf (f,"%d", &n);
	car *c;
	c=(car*) malloc(n*sizeof(car));
	
}
