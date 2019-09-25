#include <cstdio>
#include <cstdlib>
using namespace std;
const int INF = 0x0fffffff;
int n,b;
int num[INF];
int index=0;
void getNum(int n,int b){
	while(n!=0){
		num[index++] = n%b;
		n/=b;
	}
}
int main(){
	scanf("%d %d",&n,&b);
	getNum(n,b);
	bool flag = true;
	for(int i =0;i<index;i++){
		if(num[i]!=num[index-1-i]){
			flag = false;
			break;
		}
	}
	if(flag)printf("Yes\n");
	else printf("No\n");
	for(int i=index-1;i>=0;i--){
		printf("%d",num[i]);
		if(i!=0) printf(" ");
	}
	return 0;
} 
