#include<bits/stdc++.h>
using namespace std;
class HTTPrequest{
 private:
    string url;
    string methode;
    map<int,string>headers;
    map<int,string>queryparams;
    string body;
    int timeout;
    // private constructor can be access by the only builder 
    HTTPrequest(){}
    friend class httpbuilder;

void execute(){
  cout<<"it is printing the value that are stored in the defined variable"<<endl;
    if(!queryparams.empty()){
        for(auto &param:queryparams){
            cout<<param.first<<""<<queryparam.second<<endl;
        }
    }
cout<<"printing the headers that are mention in the header"<<endl;
for(auto &hed:headers)
{
  cout<<hed.first<<""<<hed.second<<endl;
}
if(!body.empty()){
    cout<<body<<endl;
}
    }

class httpbuilder{
    HTTPrequest req;
    public:
    httpbuilder& withUrl(const string &u)
    {
        req.url=u;
        return *this;

    }
     public:
    httpbuilder& withMethode(string methode)
    {
        req.methode=methode;
        return *this;

    }
      httpbuilder& withMethode(string methode)
    {
        req.methode=methode;
        return *this;

    }
      httpbuilder& withHeaders(int key,string &value)
    {
        req.header[key]=value;
        return*this;
        
    }
     httpbuilder& withQueryParams(int key,string &value)
    {
        req.queryparams[key]=value;
        return*this;
        
    }
    httpbuilder& withBody(string body)
    {
        req.body=body;
        return *this;

    }
    httpbuilder& withTimeout(int timeout)
    {
        req.timeout=timeout;
        return *this;

    }
    //build methode to create immutable httprequest object;
    HTTPrequest build(){
        // here i am checking the validation so that inconsistency problem does not happen;
    if(req.url.empty()){
        throw runtime_error("url can not be empty");
    }
    return req;
    }
    

}

};
int main(){
    HTTPrequest request=httpbuilder();
    .withUrl("https://api.example.com")
    .withMethode("POST")
    .withHeaders("content-type","application/json")
    .withHeaders("accept","application/json")
    .withQueryParams("key","12334")
    .withBody("{\"name\":\"aditya\"}")
    .withTimeout(60)
    .build()

    request.execute()  // gurunteed to be consistence state;
    

}