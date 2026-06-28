#include<bits/stdc++.h>
using namespace std;
class Powersupply{
    public:
    void providepowe(){
        cout<<"power supply:providing power,,"<<endl;
    }
}
class Coolingsyste{
    public:
    void startfan(){
        cout<<"th fan has been started"<<endl;
    }
}
class Cpu{
    void initialisation()
{
    cout<<"cpu initialisaation has been started"<<endl;
}
}
class Memory{
    public:
    void selftest(){
        cout<<"memory:self test has been passed"<<endl;
    }
}
class Hardware{
    void spinup(){
        cout<<"harqjfgjbbvb vcbvbvhk"<<endl;
    }
}
class Bios{
    public:
    void boot(Cpu&cpu,Memory& memory)
    {
        cout<<" bios:booting the cpu and memory"<<endl;
        cpu.initialisation();
        memory.selftest();
        
    }
}
class Operatingsystem{
    public:
    void load(){
        cout<<"operating system:loading into memory"<<endl;
    }
}

class Computefacade
{
    private:
    Powersupply powersupply1; 
    Coolingsyste coolingsystem;
    Cpu cpu;
    Memory memory;
    Hardware hardware;
    Bios bios;
    Operatingsystem operatingsystem;


public:
 void Startcomputer()
 {

 }
}
