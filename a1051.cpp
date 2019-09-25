#include <cstdio>
#include <map>
using namespace std;
map<int,int> table;
int main(){
	int m,n,k;
	scanf("%d %d %d",&m,&n,&k);
	for(int i =1;i<=m;i++){
		table[i] = 1;
	}
	for(int i =0;i<k;i++){
		int x;
		bool f = true;
		for(int j=0;j<n;j++){
			scanf("%d",&x);
			if(f){
			//	printf("yes:%d\n",j+1);
				if(table[x]==0||table[x]==-1) f=false;
				if(j+m<n) table[j+m+1] = 1;
				table[x] = -1;
				int tmp = x-1;
				while((table[tmp]==-1)&&tmp>0)tmp--;
				if(tmp>0)table[tmp] = 1;
				for(int t = tmp-1;t>0;t--) if(table[t]!=-1)table[t] = 0;
			}
		}
		for(int j =1;j<=m;j++){
			table[j] = true;
		}
		for(int j = m+1;j<=n;j++){
			table[j] = false;
		}
		if(f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
