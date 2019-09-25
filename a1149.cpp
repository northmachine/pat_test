#include <bits/stdc++.h>
using namespace std;
map<int,set<int>> table;
set<int> tmp;
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i =0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		table[a].insert(b);
		table[b].insert(a);
	}
	for(int i =0;i<m;i++){
		tmp.clear();
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int x;
			scanf("%d",&x);
			tmp.insert(x);
		}
		bool f  =true;
		for(auto iter = tmp.begin();iter!=tmp.end();iter++){
			for(auto iter2 = table[*iter].begin();iter2!=table[*iter].end();iter2++){
				if(tmp.find(*iter2)!=tmp.end()){
					f  =false;
				}
				if(!f)break;
			}
			if(!f)break;
		}
		if(f)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
