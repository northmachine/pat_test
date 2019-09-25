#include <cstdio>
#include <algorithm>
using namespace std;
const int inf = 1<<31-1;
const int maxrn = 200010;
int a1[maxrn];
int n1,n2;
int tmp;
int main(){
	scanf("%d",&n1);
	for(int i =0;i<n1;i++)scanf("%d",&a1[i]);
	a1[n1] = inf;
	scanf("%d",&n2);
	bool f = true;
	for(int i=0,j=0;i<n1||j<n2;){
		if(f){
			if(j<n2)
				scanf("%d",&tmp);
			else tmp = inf;
		}
		if(a1[i]<=tmp){
			if(i+j == (n1+n2-1)/2){
				printf("%d",a1[i]);
				break;
			}
			i++;
			f = false;
		}
		else{
			if(i+j == (n1+n2-1)/2){
				printf("%d",tmp);
				break;
			}
			j++;
			f = true;
		}
	}
	return 0;
} 

