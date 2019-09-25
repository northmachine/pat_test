#include <bits/stdc++.h>
using namespace std;
int n;
bool isLegal1(string s){
	int dot = 0;
	int dec = 0;
	int i=0;
	if(s[i]=='-')i++;
	for(;i<s.length();i++){
		if(dot>0)dec++;
		if((s[i]>'9'||s[i]<'0')&&s[i]!='.') return false;
		if(s[i]=='.') dot++;
	}
	if(dot>1)return false;
	if(dec>2) return false;
	return true;
}
int main(){
	scanf("%d",&n);
	string str;
	double sum = 0;
	double tmp = 0;
	int lgnum = 0;
	for(int  i=0;i<n;i++){
		cin>>str;
		if(isLegal1(str)){
			tmp = stof(str);
			if(tmp<=1000&&tmp>=-1000){
				sum+=tmp;
				lgnum++;
			}
			else printf("ERROR: %s is not a legal number\n",str.c_str());
		}
		else printf("ERROR: %s is not a legal number\n",str.c_str());
	}
	if(lgnum==0)printf("The average of 0 numbers is Undefined\n");
	else if(lgnum==1) printf("The average of 1 number is %.2f\n",sum);
	else printf("The average of %d numbers is %.2f\n",lgnum,sum/lgnum);
	return 0;
} 
