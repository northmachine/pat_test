#include <cstdio>
int main(){
	char str[256];
	while(scanf("%s",str)!=EOF){
		int i = 0;
		while(str[i]!='\0')i++;
		i--;
		int j=0;
		while(i>j) if(str[i--]!=str[j++]) break;
		if(i-j<=0)printf("YES\n");
		else printf("NO\n"); 
	}
	return 0;
}
