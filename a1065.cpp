#include <cstdio>
#include <cstdlib>
using namespace std;
int n;
long long a,b,c;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		long long res = a+b;
		if(a>>63!=b>>63||res>>63==a>>63){
			if(res>c)
				printf("Case #%d: true\n",i+1);
			else printf("Case #%d: false\n",i+1);
		}
		else{
			if(a>>63==0) printf("Case #%d: true\n",i+1);
			else printf("Case #%d: false\n",i+1);
		}
	} 
	return 0;
} 
