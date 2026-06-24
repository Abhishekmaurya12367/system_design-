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
    FanCommand(Fan*f){
    fan=f;
    }
    void execute(){
        fan->on();
    }
    void undo(){
        fan->off();
    }

}
class RemoteComtroller{
    private:
    static const int numButtons=4;
    command*buttons[numsButtons];
    bool buttonPressed[numsButtons];
    public:
    RemoteComtroller(){
        for(int i=0;i<numsButtons;i++){
        if(buttons[i]==nullptr){
            buttonPressed[i]=false;
        }
        }
    }
    void setcommand(int idx,command*cmd){
        if(idx>=0 && idx<numsButton){
            if(buttons[idx]!=nullptr){
                delete buttons[idx];
            }
            buttons[idx]=cmd;
            buttonpdressed[idx]=false;  
        }

    }
    void pressedbutton(int idx){
        if(idx>=0 && idx<numsButton && buttons[idx]!=nullptr)
        {
            if(buttonPressed[idx]==false){
                buttons[idx]->execute();
            }
            else{
                buttons[idx]->undo();

            }
          buttonPressed[idx]=!buttonPressed[i];
        }
        else{
            cout<<"there is no command at this index"<<endl;
        }

    }
    }
