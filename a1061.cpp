#include <cstdio>
#include <cstring> 
char week[7][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
	char a1[61];
	char a2[61];
	char a3[61];
	char a4[61];
	scanf("%s %s %s %s",a1,a2,a3,a4);
	int f=0;
	for(;f<strlen(a1)&&f<strlen(a2);f++){
		if(a1[f]==a2[f]&&a1[f]<72&&a1[f]>64) break;
	}
	printf("%s ",week[a1[f]-65]);
	int s= f+1;
	for(;s<strlen(a1)&&s<strlen(a2);s++){
		if(a1[s]==a2[s]&&(a1[s]<='N'&&a1[s]>='A'||a1[s]>='0'&&a1[s]<='9')) break;
	}
	if(a1[s]>='A'&&a1[s]<='N')
		printf("%02d:",a1[s]-'A'+10);
	else printf("%02d:",a1[s]-'0');
//	printf("%c",a1[s]);
	int t=0;
	for(;t<strlen(a3)&&t<strlen(a4);t++){
		if(a3[t]==a4[t]&&(a3[t]>='A'&&a3[t]<'Z'||a3[t]>='a'&&a3[t]<='z')) break;
	}
	printf("%02d",t);
//	printf("%c",a3[t]);
// ||a1[s]>='0'&&a1[s]<='9'
	return 0;
}
