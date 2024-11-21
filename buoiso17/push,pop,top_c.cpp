#include <stdio.h>
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
bool push_stack(mystack &s, int x){
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
	createstack(s);
	push_stack(s,6);
	push_stack(s,7);
	int x=pop_stack(s,x);
	printf ("%d\n",x);
}
