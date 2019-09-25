#include <bits/stdc++.h>
using namespace std;
int n,k;
bool isPrime(int x){
	if(x==0||x==1)return false;
	for(int i =2;i*i<=x;i++){
		if(x%i==0)return false;
	}
	return true;
}
int main(){
	string str;
	cin>>n>>k>>str;
	for(int i =0;i<=n-k;i++){
		string tmp = str.substr(i,k);
		int num = stoi(tmp);
	//	printf("%lld\n",num);
		if(isPrime(num)){
			cout<<tmp;
			return 0;
		}
	}
	cout<<"404\n";
	return 0;
}
