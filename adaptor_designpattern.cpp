#include<bits/stdc++.h>
using namespace std;
// targated interfacae expected by the client 
class Report{
    public:
    vertual string getJsonData(const string data)=0;
    vertual ~IReports(){}
};
class Xmldataprovider{
    public:
    string XmlData(const string& data){
        size_t sep=data.find(':');
        string name=data.substr(0,sep);
        string id=data.substr(sep+1);
        return "<user>"
               "<name>"+name+"</name>"
               "<id>"+id+"</id"
               "</user>"
                }
}
class XmlDataProviderAdaptor: public IReports
{
private:
Xmldataprovider*xmlprovider;

public:
XmlDataProviderAdaptor(Xmldataprovider*provider){
    this->xmlprovider=provider;
}

string getJsonData(const string data)override{
    // get xml data from the adaptor
    string xml=xmlprovider-> XmlData(data);

}


}
