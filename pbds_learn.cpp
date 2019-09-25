#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
gp_hash_table<string,int> h;
void judge(string s){
	if(h.find(s)!=h.end())
		cout<<"orz %%%";
	else 
		cout<<"tan90";
	cout<<endl;
} 
int main(){
	h["Ican'tAKIOI"]=1;
	h.insert(make_pair("UAKIOI",1));
	string str;
	while(cin>>str)
		judge(str);
	return 0;
}
