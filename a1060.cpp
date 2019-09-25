#include <iostream>
#include <string>
using namespace std;
string change(string s,int N){
	int dot=0;
	int firstNoZero=0;
	for(int i =0 ;i<s.length();i++){
		if(s[i] == '.'){
			dot = i;
			break;
		}
		if(i==s.length()-1){
			dot = i+1;
		}
	}
	for(int i =0;i<s.length();i++){
		if(s[i]!='0'&&s[i]!='.'){
			firstNoZero = i;
			break;
		}
		if(i==s.length()-1){
			firstNoZero=dot;
		}
	}
	int e = dot - firstNoZero;
	string s2 = "0.";
	for(int i =0,j=0;i<N;i++){
		if(i+firstNoZero+j<s.length()){
			if(s[i+firstNoZero+j]=='.'){
				++j;
			}
			s2+=s[i+firstNoZero+j];
		}
		else
			s2+='0';
	}
	s2+="*10^" + to_string(e);
	return s2;
}
int main(){
	int N;
	cin>>N;
	string A,B;
	cin>>A>>B;
	string a = change(A,N);
	string b = change(B,N);
	if(a==b)
		cout<<"YES "<<a;
	else
		cout<<"NO "<<a<<' '<<b;
	return 0;
}
