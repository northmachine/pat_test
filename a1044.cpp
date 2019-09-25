#include <cstdio>
const int maxn = 100010;
int n,m;
int a[maxn];
int res[2*maxn];
int count;
int main(){
	scanf("%d %d",&n,&m);
	for(int i =1;i<n+1;i++){
		scanf("%d",&a[i]);
	}
	for(int i =1;i<n+1;i++){
		a[i] += a[i-1];
	}
	int smallest=1000000000;
	for(int i =0;i<n;i++){
		int l = i+1;
		int r = n;
		if(a[r]-a[i]<m) break;
		while(r>l){
			if(a[(l+r)/2]-a[i]<m)
				l = (l+r)/2+1;
			else r = (l+r)/2;
		//	printf("%d %d\n",l,r);
		}
		if(a[l]-a[i]<smallest){
			smallest = a[l]-a[i];
			count=0;
			res[count++] = i+1;
			res[count++] = l;
		}
		else if(a[l]-a[i]==smallest){
			res[count++] = i+1;
			res[count++] = l;
		}
	}
	for(int i =0 ;i<count;i++){
		printf("%d-",res[i++]);
		printf("%d\n",res[i]);
	}
	return 0;
}
