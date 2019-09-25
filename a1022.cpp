#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10010;
struct node{
	int id;
	string title;
	string author;
	string keyword;
	string publisher;
	int year;
};
int n,m;
node books[maxn];
set<int> s;
void SplitString(const string& s, vector<string>& v, const string& c)
{
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));
         
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}
int main(){
	scanf("%d",&n);
	for(int  i=0;i<n;i++){
		scanf("%d\n",&books[i].id);
		getline(cin,books[i].title);
		getline(cin,books[i].author);
		getline(cin,books[i].keyword);
		getline(cin,books[i].publisher);
		scanf("%d\n",&books[i].year);
	} 
	scanf("%d\n",&m);
	int q;
	string title;
	string author;
	string keyword;
	string publisher;
	int year;
	for(int  i=0;i<m;i++){
		scanf("%d: ",&q);
		switch(q){
		case 1:
			getline(cin,title);
			printf("%d: ",q);
			cout<<title<<endl;
			for(int i =0;i<n;i++){
				if(title==books[i].title){
					s.insert(books[i].id);
				}
			}
			break;
		case 2:
			getline(cin,author);
			printf("%d: ",q);
			cout<<author<<endl;
			for(int i =0;i<n;i++){
				if(author==books[i].author){
					s.insert(books[i].id);
				}
			}
			break;
		case 3:
			getline(cin,keyword);
			printf("%d: ",q);
			cout<<keyword<<endl;
			for(int  i=0;i<n;i++){
				vector<string> w;
				SplitString(books[i].keyword,w," ");
				if(find(w.begin(),w.end(),keyword)!=w.end()){
					s.insert(books[i].id);
				}
			}
			break;
		case 4:
			getline(cin,publisher);
			printf("%d: ",q);
			cout<<publisher<<endl;
			for(int  i=0;i<n;i++){
				if(publisher==books[i].publisher){
					s.insert(books[i].id);
				}
			} 
			break;
		case 5:
			scanf("%d",&year);
			printf("%d: %d\n",q,year);
			for(int i=0;i<n;i++){
				if(year==books[i].year){
					s.insert(books[i].id);
				}
			}
			break;
		default:
			break;		
		}
		if(!s.empty()){
			for(auto iter = s.begin();iter!=s.end();iter++){
				printf("%d\n",*iter);
			}
		}
		else printf("Not Found\n");
		s.clear();
	}
	return 0;
} 
