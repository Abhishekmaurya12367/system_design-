#include<bits/stdc++.h>
using namespace std;
class powersupply{
    public:
    void providepowe(){
        cout<<"power supply:providing power,,"<<endl;
    }
}
class coolingsyste{
    public:
    void startfan(){
        cout<<"th fan has been started"<<endl;
    }
}
class cpu{
    void initialisation()
{
    cout<<"cpu initialisaation has been started"<<endl;
}
}
class memory{
    public:
    void selftest(){
        cout<<"memory:self test has been passed"<<endl;
    }
}
class hardware{
    void spinup(){
        cout<<"harqjfgjbbvb vcbvbvhk"<<endl;
    }
}
class bios{
    public:
    void boot(cpu&cp,memory& mem)
    {
        cout<<" bios:booting the cpu and memory"<<endl;
        cp.initialisation();
        mem.selftest();
        
    }
}
class operatingsystem{
    public:
    void load(){
        cout<<"operating system:loading into memory"<<endl;
    }
}

class computefacade
{

}
