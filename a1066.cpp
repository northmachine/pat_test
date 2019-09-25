#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define For(i,a,b) for(i=(a);i<(b);++i)
using namespace std;
using namespace __gnu_pbds;
tree<int ,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> tr;
int main(){
	int n;
	scanf("%d",&n);
	int i;
	For(i,0,n){
		int x;
		scanf("%d",&x);
		tr.insert(x);
	}
	printf("%d",*tr.begin());
	return 0;
}
