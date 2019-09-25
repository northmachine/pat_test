#include <cstdio>
#include <map>
using namespace std;
int m,n;
map<int,int> counter;
int main(){
	scanf("%d %d",&m,&n);
	int x;
	int r=0;
	for(int i =0;i<m*n;i++){
		scanf("%d",&x);
		counter[x]++;
		if(counter[x]>counter[r])r = x;
	}
	printf("%d",r);
	return 0;
}
