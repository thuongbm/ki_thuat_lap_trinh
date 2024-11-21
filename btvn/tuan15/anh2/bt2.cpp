#include <iostream>
using namespace std;
int dequy(int n){
	if (n==0) return 1;
	else {
		return n*dequy(n-1);
	}
}
float day1(int n){
	if (n==1) return 1;
	else{
		return (float)(1/n+1/day1(n-1));
	} 
}
int day2(int n){
	if (n==1) return 1;
	else{
		return (n*10+n+day2(n-1));
	}
}
int day3(int n, int x){
	if (n==1) return x;
	else {
		return (x*day3(n-1,x)/dequy(n));
	}
}
main(){
	int n;
	cin>>n;
	int x;
	cin>>x;
	cout<<day1(n)<<endl;
	cout<<day2(n)<<endl;
	cout<<day3(n,x)<<endl;
}
