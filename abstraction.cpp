#include<iostream>
#include<string>
using namespace std;
class car{
    public:
    virtual void startengine()=0;
    virtual void stopengine()=0;
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual void changegear(int gear)=0;
    virtual ~car(){};
};
class sportcar:public car{
    string brand;
    string model;
    bool engineon;
    int currentspeed;
    int currentgear;
    public:
    sportcar(string b,string m)
    {
        this->brand=b;
        this->model=m;
        engineon=false;
        currentspeed=0;
        currentgear=0;
    }
    void startengine()
    {
        engineon=true;
        cout<<"engine started"<<endl;

    }
    void changegear(int gear)
    {
        if(!engineon){
            cout<<"engine is not on"<<endl;
            return; 
        }
        currentgear=gear;
        cout<<"successfully gear shift "<<gear<<endl;

    }
    void accelerate()
    {
      if(!engineon){
        cout<<"engine is not on"<<endl;
        return;
      }
      currentspeed+=20;
      cout<<"speed increased to "<<currentspeed<<endl;
    }
    void brake(){
        currentspeed-=20;
        if(currentspeed<0){
            currentspeed=0;
        }
        cout<<"speed decreased to "<<currentspeed<<endl;

    }
    void stopengine()
    {
        engineon=false;
        currentspeed=0;
        currentgear=0;
        cout<<"engine stopped"<<endl;

    }

};
int main(){
    car*mycar=new sportcar("ferrari","spider");
    mycar->startengine();
    mycar->changegear(1);
    mycar->accelerate();
    mycar->brake();
    mycar->stopengine();
    delete mycar;
    return 0;

}