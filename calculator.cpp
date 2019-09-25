#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;
struct node{
	int num;
	char op;
	bool flag;
};
string str;
stack<node> s;
queue<node> q;
map<char,int> op;
void change(){
	node temp;
	for(int i =0;i<str.length();){
		if(str[i]>='0'&&str[i]<='9'){
			temp.flag=true;
			temp.num = str[i++] - '0';
			q.push(temp);
		}
		else{
			temp.flag = false;
			while(!s.empty()&&op[str[i]]<=op[s.top().op]){
				q.push(s.top());
				s.pop();
			}
			temp.op = str[i];
			s.push(temp);
			i++;
		}
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
}
int cal(){
	int temp1,temp2;
	node cur,temp;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		if(cur.flag==true) s.push(cur);
		else{
			temp2 = s.top().num;
			s.pop();
			temp1 = s.top().num;
			s.pop();
			temp.flag = true;
			if(cur.op == '+') temp.num = temp1+temp2;
			else temp.num = temp1*temp2;
			s.push(temp);
		}
	}
	return s.top().num;
}
int main(){
	op['+']=1;
	op['*']=2;
	int n = 0;
	scanf("%d\n",&n); 
	while(n--){
		getline(cin,str);
		while(!s.empty()) s.pop();
		change();
		printf("%d\n",cal());
	}
	return 0;
}
