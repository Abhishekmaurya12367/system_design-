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
 vector<pair<int,int>>findcontinous()
  
}


int main(){

}