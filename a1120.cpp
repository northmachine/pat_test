#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n;
set<int> ans;
int main(){
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		int x;
		scanf("%d",&x);
		int tmp=0;
		int r = 10;
		while(x>0){
			tmp+=x%10;
			x/=10;
		}
		ans.insert(tmp);
	}
	printf("%d\n",ans.size());
	int counter=0;
	for(auto iter = ans.begin();iter!=ans.end();iter++){
		printf("%d",*iter);
		counter++;
		if(counter!=ans.size())printf(" ");
	}
	return 0;
}
