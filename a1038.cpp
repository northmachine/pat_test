#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 10010;
string nums[maxn];
bool cmp(string a,string b){
	return a+b<b+a;
}
int n;
int main(){
	scanf("%d",&n);
	int k=0;
	for(int i =0;i<n;i++){
		cin>>nums[i];
	}
	sort(nums,nums+n,cmp);
	string re;
	for(int i =0;i<n;i++)re += nums[i];
	int i=0;
	while(re[i]=='0'&&i<re.length()-1)i++;
	while(i<re.length()){
		printf("%c",re[i]);
		i++;
	} 
	return 0;
}
