#include <iostream>
using namespace std;
void daonguoc(int n){
	if (n<10) cout<<n;
	else{
		cout<<n%10;
		n/=10;
		daonguoc(n);
	} 
}
main(){
	int n;
	cin>>n;
	daonguoc(n);
}
