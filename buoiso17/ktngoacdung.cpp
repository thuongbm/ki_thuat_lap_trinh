#include <stdio.h>
#include <string.h>
#define max 10000
struct mystack{
	int t;
	int a[max];
};
void createstack(mystack &s){
	s.t=-1;
}
bool is_empty(mystack s){
	if (s.t==-1) return true;
	else return false;
}
bool push_stack(mystack &s, char x){
	if (s.t>=max){
		return false;
	}
	else {
		s.t++;
		s.a[s.t]=x;
		return true;
	}
}
bool pop_stack(mystack &s, int &x){
	if (is_empty(s)==true) return false;
	else {
		x=s.a[s.t];
		s.t--;
		return true;
	}
}
bool top_stack(mystack &s, int &x){
	if (is_empty(s)==true) return false;
	else {
		x=s.a[s.t];
		return true;
	}
}
main(){
	mystack s;
	createstack (s);
	char chuoi[100];
	gets(chuoi);
	puts(chuoi);
	int n=strlen(chuoi);
	for (int i=0;i<n;i++){
		if (chuoi[i]=='{'){
			push_stack(s,chuoi[i]);
			else 
		}
		else if (chuoi[i]=='['){
			if (chuoi[i-1]=='{'){
				printf ("sai");
			}
			else push_stack(s,chuoi[i]);
		}
		else if (chuoi[i]=='('){
			if (chuoi[i-1]=='{'||chuoi[i-1]=='['){
				printf ("sai");
			}
			else push_stack(s,chuoi[i]);
		}
	}
	//chuaxong
}
