#include <cstdio>
#define maxn 100010
int a[maxn];
int maxseqsum(int l,int r){
	if(l==r) return a[l];
	int mid = (l+r)>>1;
	int maxl = maxseqsum(l,mid);
	int maxr = maxseqsum(mid+1,r);
	int maxm = 0,i=mid,j=mid+1;
	while(a[i]>=0&&i>=l)maxm+=a[i--];
	while(a[j]>=0&&j<=r)maxm+=a[j++];
	maxr = maxr>maxl?maxr:maxl;
	maxm = maxr>maxm?maxr:maxm;
	return maxm;
}
int main(){
	int n ;
	scanf("%d",&n);
	for(int i =0;i<n;i++)scanf("%d",&a[i]);
	printf("%d",maxseqsum(0,n-1));
	return 0;
}
