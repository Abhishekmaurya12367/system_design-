#include<bits/stdc++.h>
using namespace std;
class Screen{
    int r,c;
    Screen(int r,int c){
     r=r;
     c=c;
     }
}
class Show{
  int showid;
  int cinemaid,movieid;
  int screenindex;
  vector<vector<int>>screen;
 int freesheet;
 Show(int sid,int cid,int mid,int sindex,int r,int c){
    this->showid=sid;
    this->cinemaid=cid;
    this->movieid=mid;
    this->screenindex=sindex;
    this->freesheet=r*c;
   this->screen=vector<vector<int>>(r,vector<int>(c,0));
 }
 // find out the continous 
 vector<pair<int,int>>findcontinous(int k)
 {
    int row=screen.size();
    int column=screem[0].size();
    for(int i=0;i<row;i++){
        int count=0;
    for(int j=0;j<column;j++)
    {
        if(screen[i][j]==0)
        count++;
        else
        count=0;
        
        vector<pair<int,int>>result;
        if(count==k){
            int start=j-k+1;
            for(int p=0;p<k;p++)
            result.push_back({i,start+p});
           return result;
        }
    }
    }
 }
 //find the any position that are free;
vector<pair<int,int>>findany(int k){
 int count=0;
 int row=screen.size();
 int column=screen[0].size();
 for(int i=0;i<row;i++){
    for(int j=0;j<column;j++)
    {
       if(screen[i][j]==0){
        count++;
        result.push_back({i,j});
       }
       if(count==k){
        return count;
          
    }
 }
 return {};
}
}
// book the ticket;
vector<pair<int,int>>bookticket(int k){
    if(freesheet<k){
        return {};
    }
    auto ans=findcontinous(k);
    if(ans.empty()){
        ans=findany(k);
    }
    if(ans.size()<k){
        return {};
    }
    for(auto it:ans){
        screen[it.first][it.second]=1;
        freesheet--;
    }
    return ans;
}
//free the booking sheet 
void freethebookingposition(vector<pair<int,int>>&ans)
{
    for(auto it:ans){
        screen[it.first][it.second]=0;
        freesheet++;
    }
}
}
// making the cinema entity;
class cinema{
  int cinemaid,cityid;
  vector<Screen>screen;
  cinema(int cinemaid,int cityid,int totalscreen,int row,int column)
  {
    this->cinemaid=cinemaid;
    this->cityid=cityid;
    for(int i=0;i<totalscreen;i++)
    {
        screen.push_back(Screen(row,column));
    }   
    
  }

}
class Ticket
{
    string ticketid;
    int showid;
    vector<pair<int,int>>seats;
    bool iscancelled;
    Ticket(string ticketid,int showid,vector<pair<int,int>>seats)
    {
        this->ticketid=ticketid;
        this->showid=showid;
        this->seats=seats;
        this->iscancelled=false;
    }

}
// solution to solve this problem;
class solution{
    Helper*helper;
    unordered_map<int,cinema*>mapping_cinama;
    unordered_map<int,Show*>mapping_show;
    unordered_map<int,Ticket*>mapping_ticket;
    unordered_map<int,set<int>>cityToCinemas;
    unordered_map<int,vector<int>>cinema_to_show;
    unordered_map<int,vector<int>>moving_to_show;

    public:
    void init(Helper*h){
        this->helper=h;
    }
    void addcinema(int cinid,int cityid,int total_screen,int row,int column)
    {
     cinema*c=new cinema(cinid,cityid,total_screen,row,column);
     mapping_cinama[cinid]=c;
     cityToCinemas[cityid].insert(cinid);
    }
    void addshow(int showid,int cinemaid,int movieid,int screenindex,int r,int c)
    {
     Show*s=new Show(showid,cinemaid,movieid,screenindex,r,c);
     mapping_show[showid]=s;
     cinema_to_show[cinemaid].push_back(showid);
     moving_to_show[movieid].push_back(showid);
    }
  
vector<string> bookTicket(String ticketId,
int showId, int ticketsCount)
{
    if(mapping_show.find(showId)==mapping_show.end())
    {
        return {};
    }
    Show*s=mapping_show[showId];
    auto booked=s->bookticket(ticketsCount);
    if(booked.empty()){
        return {};
    }
    vector<string>result;
    for(auto it:booked){
        result.push_back(to_string(it.first)+"_"+to_string(it.second));
    }
    return result;

}
 bool cancelticket(string ticketid)
 {
   if(mapping_ticket.find(ticketid)==mapping_ticket.end()){
    return false;
   }
 Ticket *t=mapping_ticket[ticketid];
 bool isticketcancelled=t->iscancelled;
 if(isticketcancelled){
    return false;
 }
Show*s=mapping_show[t->showid];
s->freethebookingposition(t->seats);
t->iscancelled=true;
return true;
 
}

int getfreeseatcount(int showid)
{
    if(mapping_show.find(showid)==mapping_show.end()){
        return -1;
    }
    Show*s=mapping_show[showid];
    return s->freesheet;
vector<int>listofcinamas(int movieid,int cityid)
{
if(moving_to_show.find(movieid)==moving_to_show.end()){
    return {};
}
if(cityToCinemas.find(cityid)==cityToCinemas.end()){
    return {};
}
vector<int>result;
for(int cinid:cityToCinemas[cityid]){
    for(int showid:cinema_to_show[cinid])
    {
        if(moving_to_show[showid]->movieid==movieid){
            result.push_back(cinid);
            break;
        }

    }
}
return result;
}

vector<int>listofshow(int movieid,int cinemaid)
{
    if(cinema_to_show.find(cinemaid)==cinema_to_show.end()){
        return {};
    }
    if(moving_to_show.find(movieid)==moving_to_show.end()){
        return {};
    }
    vector<int>result;
    for(int showid:cinema_to_show[cinemaid])
    {
        if(moving_to_show[showid]->movieid==movieid){
            result.push_back(showid);
        }
    }
    return result;
    

}
}
}
