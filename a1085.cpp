#include <cstdio>
#include <algorithm>
using namespace std;
const long long maxn = 100010;
long long ary[maxn];
long long n,p;
bool cmp(long long a,long long b){
	return a<b;
}
long long res=0;
int main(){
	scanf("%d %d",&n,&p);
	for(int i =0;i<n;i++) scanf("%d",&ary[i]);
	sort(ary,ary+n,cmp);
	for(int i =0;i<n;i++){
		int j = i+1;
		int k = n;
		if(k-i<=res) break;
		while(k>j){
			if(ary[i]*p>=ary[(j+k)/2]){
				j = (j+k)/2+1;
			}
			else k = (j+k)/2;
		}
		if(k-i>res)res = k-i;
	}
	printf("%d",res);
	return 0;
} 
