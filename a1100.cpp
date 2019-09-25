#include <bits/stdc++.h>
using namespace std;
map<string,int> mar_to_dec;
string dec_to_mar[30]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
				"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
void init(){
	for(int i=0;i<25;i++){
		mar_to_dec[dec_to_mar[i]] = i;
	}
}
int n ;
int main(){
	init();
	scanf("%d",&n);
	getchar();
	string s;
	for(int  i=0;i<n;i++){
		getline(cin,s);
		if(s[0]<='9'){
			stringstream ss;
			ss<<s;
			int dec;
			ss>>dec;
			int a,b;
			a = dec%13;
			b = dec/13;
			if(b!=0){
				printf("%s",dec_to_mar[b+12].data());
				if(a!=0)printf(" %s",dec_to_mar[a].data());
				printf("\n");
			}
			else printf("%s\n",dec_to_mar[a].data());
		}
		else{
			int pos = s.find(' ');
			if(pos!=s.npos){
				string tmp1,tmp2;
				int i=0;
				while(i!=pos) tmp1+=s[i++];
				i++;
				while(i<s.length())tmp2+=s[i++];
			//	printf("%s %s\n",tmp1.data(),tmp2.data());
				int dec = (mar_to_dec[tmp1]-12)*13+mar_to_dec[tmp2];
				printf("%d\n",dec);
			}
			else{
				printf("%d\n",mar_to_dec[s]<13?mar_to_dec[s]:(mar_to_dec[s]-12)*13);
			}
		}
	}
	return 0;
}
