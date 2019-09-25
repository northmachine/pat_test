#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int s[maxn];
int top = -1;
bool judge(int a[],int l,int r,bool flag){
	s[++top]=a[l];
	if(l>=r) return true;
	int root = a[l];
	int i=l+1;
	while(i<=r&&(flag^a[l]>a[i]))i++;
	int j = i-1;	
	while(i<=r&&(flag^a[l]<=a[i]))i++;
	if(i>r&&l!=j) return judge(a,j+1,r,flag)&&judge(a,l+1,j,flag);
	else if(i>r)return judge(a,j+1,r,flag);
	else return false;	
}
int a[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i =0;i<n;++i)scanf("%d",&a[i]);
	bool flag;	// ÊÇ·ñÊÇ 
	if(a[0]<=a[n-1])flag = false;
	else flag = true;
	if(judge(a,0,n-1,flag)){
		printf("YES\n");
		while(top!=-1){
			printf("%d",s[top--]);
			if(top!=-1) printf(" ");
		}
	}
	else printf("NO");
	return 0;
}
