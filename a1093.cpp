#include <cstdio>
#define maxn 100010
int main(){
	char str[maxn];
	scanf("%s",str);
	int l =0;
	while(str[++l]!='\0');
	int leftP[maxn]={0};
	int rightT[maxn]={0};
	for(int i=0;i<l;i++){
		if(str[i]=='P') leftP[i+1] = leftP[i]+1;
		else leftP[i+1] = leftP[i];
	}
	for(int i=l-1;i>0;i--){
		if(str[i]=='T') rightT[i-1] = rightT[i]+1;
		else rightT[i-1] = rightT[i];
	}
	int count = 0;
	for(int i=0;i<l;i++){
		if(str[i]=='A'){
			int cP = leftP[i];
			int cT = rightT[i];
			count = (count +(cP*cT))%1000000007; 
		}
	}
	printf("%d",count);
	return 0;
}
