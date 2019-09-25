#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int a[maxn];
int k,n;
int main(){
	scanf("%d",&k);
	for(int i =0;i<k;i++){
		scanf("%d",&n);
		bool f = true;
		for(int i =0;i<n;i++){
			scanf("%d",&a[i]);
			for(int j=0;j<i;j++){
				if(f&&(abs(j-i)==abs(a[i]-a[j])||a[i]==a[j]))f = false;
			}
		}
		if(f)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
