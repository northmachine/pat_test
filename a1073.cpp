#include <cstdio>
#include <cstring>
char input[10000];
int main(){
	scanf("%s",input);
	int e=-1;
	while(input[++e]!='E');
	if(input[0]=='-') printf("-");
	int f=e+1;
	while(input[++f]=='0');
	int len = strlen(input)-f;
	if(input[e+1]=='+'){
		//printf("%c",input[1]);
		int j=0;
		bool zero = false;
		while(!zero){
			if(j<e-1)
				printf("%c",input[++j]);
			else printf("0");
			if(j==1)++j;
			int ff=f;
			while(ff<strlen(input)&&input[ff]=='0')++ff;
			if(ff == strlen(input)) zero=true;
			int k=strlen(input)-1;
			input[k]-=1;
			if(input[k]<'0') input[k]='9';
			for(;input[k]=='9'&&k>f;k--){
				input[k-1]-=1;
				if(input[k-1]<'0') input[k-1]='9';
			}
		}
		if(j<e-1) printf(".");
		while(j<e-1) printf("%c",input[++j]);
	}
	else{
		bool zero = false;
		bool dot = false;
		bool d = false;
		while(!zero){
			if(dot){
				printf("0");
				if(!d){
					printf(".");
					d = true;
				}
			}
			if(!dot){
				dot = true;
			}
			int ff=f;
			while(ff<strlen(input)&&input[ff]=='0')++ff;
			if(ff == strlen(input)) zero=true;
			int k=strlen(input)-1;
			input[k]-=1;
			if(input[k]<'0') input[k]='9';
			for(;input[k]=='9'&&k>f;k--){
				input[k-1]-=1;
				if(input[k-1]<'0') input[k-1]='9';
			}
		}
		for(int j =1;j<e;j++){
			printf("%c",input[j]);
			if(j==1)++j;
		}
	}
	return 0;
} 
