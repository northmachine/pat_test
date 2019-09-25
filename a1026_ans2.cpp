#include<bits/stdc++.h>
using namespace std;
struct Player{
    int arriveTime=0,processTime=0;
    bool vip=false;
};
struct Table{
    bool occupy=false,vip=false;
    int serverPlayerNum=0;
};
Player player[10005];
Table table[105];
struct PlayerTable{
    int tableNum,playerNum,time;
    PlayerTable(int table,int p,int t):tableNum(table),playerNum(p),time(t){}
    bool operator <(const PlayerTable&p)const{
        return this->time>p.time;
    }
};
priority_queue<PlayerTable>playerTable;
list<int>waitPlayer;
const int closeTime=21*3600;
int N,M,K;
int searchTable(bool vip){
    if(vip)
        for(int i=1;i<=K;++i)
            if(!table[i].occupy&&table[i].vip)
                return i;
    for(int i=1;i<=K;++i)
        if(!table[i].occupy)
            return i;
    return -1;
}
void output(int t1,int t2){
    printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",t1/3600,t1/60%60,t1%60,t2/3600,t2/60%60,t2%60,(t2-t1+30)/60);
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        int h,m,s;
        player[i].arriveTime=closeTime;
        scanf("%d:%d:%d %d %d",&h,&m,&s,&player[i].processTime,&player[i].vip);
        player[i].arriveTime=(h*60+m)*60+s;
        player[i].processTime=min(player[i].processTime,120);
        player[i].processTime*=60;
        playerTable.push(PlayerTable(0,i,player[i].arriveTime));
    }
    scanf("%d%d",&K,&M);
    for(int i=0;i<M;++i){
        int a;
        scanf("%d",&a);
        table[a].vip=true;
    }
    while(!playerTable.empty()){
        PlayerTable p=playerTable.top();
        playerTable.pop();
        if(p.time>=closeTime)
            break;
        if(p.tableNum==0){
            int index=searchTable(player[p.playerNum].vip);
            if(index!=-1){
                table[index].occupy=true;
                int endTime=p.time+player[p.playerNum].processTime;
                playerTable.push(PlayerTable(index,p.playerNum,endTime));
                output(player[p.playerNum].arriveTime,p.time);
                ++table[index].serverPlayerNum;
            }else
                waitPlayer.push_back(p.playerNum);
        }else{
            if(waitPlayer.empty())
                table[p.tableNum].occupy=false;
            else{
                int temp;
                if(!table[p.tableNum].vip){
                    temp=waitPlayer.front();
                    waitPlayer.pop_front();
                }else{
                    auto i=waitPlayer.begin();
                    while(i!=waitPlayer.end()&&!player[*i].vip)
                        ++i;
                    if(i==waitPlayer.end()){
                        temp=waitPlayer.front();
                        waitPlayer.pop_front();
                    }else{
                        temp=*i;
                        waitPlayer.erase(i);
                    }
                }
                int endTime=p.time+player[temp].processTime;
                playerTable.push(PlayerTable(p.tableNum,temp,endTime));
                output(player[temp].arriveTime,p.time);
                ++table[p.tableNum].serverPlayerNum;
            }
        }
    }
    for(int i=1;i<=K;++i)
        printf("%s%d",i>1?" ":"",table[i].serverPlayerNum);
    return 0;
}
