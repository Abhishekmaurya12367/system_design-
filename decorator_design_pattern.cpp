#include<bits/stdc++.h>
using namespace std;
// command interference
class command{
    virtual void execute()=0;
    virtual void undo()=0;
    virual ~command(){}

};
//receivers
class Light{
    public:
    void on(){
        cout<<"light on"<<endl;
    }
    void off(){
        cout<<"light off"<<endl;
    }
}
// there can be more reciever i am taking only two command 
class Fan{
    public:
    void on(){
        cout<<"fan is on"<<endl;
    }
    void off(){
        cout<<"fan is off"<<endl;
    }
}

class LightCommand:public command{
    private:
    Light*light;
    public:
    LightCommand(Light*l){
        light=l;
    }
     void excute(){
        light->on();
    }
   void undo(){
    light->off();
   }
}

class FanCommand:public command{
    private:
    Fan*fan;
    public:
    
}