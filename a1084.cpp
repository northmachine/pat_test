#include <cstdio>
#include <map>
#include <cstring> 
using namespace std;
int main(){
	char original[100];
	char typed_out[100];
	map<char,bool> broken;
	int o=0,t=0;
	scanf("%s\n%s",original,typed_out);
	while(o<strlen(original)||t<strlen(typed_out)){
		if(original[o]!=typed_out[t]){
			if(!broken[original[o]&-33]){
				broken[original[o]&-33]=true;
				if(original[o]<97)
					printf("%c",original[o]);
				else printf("%c",original[o]&-33);
			}
			o++;
		}
		else{
			if(t<strlen(typed_out))
				t++;
			if(o<strlen(original))
				o++;
		}
	}
	return 0;
}
