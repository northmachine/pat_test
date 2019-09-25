#include <bits/stdc++.h>
using namespace std;
int main(){
	int d,n;
	scanf("%d %d",&d,&n);
	string ans,tmp;
	tmp+=(d+'0');
	ans = tmp;
	for(int i=0;i<n-1;i++){
		int j=0;
		char t = tmp[j];
		ans.clear();
		while(j<tmp.length()){
			int c=0;
			while(tmp[j]==t&&j<tmp.length()){
				c++;
				j++;
			}
			ans+=(t);
			ans+=(c+'0');
			if(j<tmp.length())t = tmp[j];			
		}
		tmp = ans;
	}
	cout<<ans;
	return 0; 
} 
