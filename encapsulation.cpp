#include<iostream>
#include<string>
using namespace std;
// class car{
//     public:
//     virtual void startengine()=0;
//     virtual void stopengine()=0;
//     virtual void accelerate()=0;
//     virtual void brake()=0;
//     virtual void changegear(int gear)=0;
//     virtual ~car(){};
// };
class sportcar{
 private://charecter; no one can change any variable outside the class 
 // but if he want see then make methode setter and getter 
 // setter is used to set the value;
 // getter is used to get the value;
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
    // behaviour-->methode;

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
    // void stopengine()
    // {
    //     engineon=false;
    //     currentspeed=0;
    //     currentgear=0;
    //     cout<<"engine stopped"<<endl;

    // }
    int getcurrentspeed(){
        return this->currentspeed;
    }
    void setcurrentspeed(int speed){
        this->currentspeed=speed;
    }
//when we are setting or getting the value it can not be set or get by directly can be set by using getter and setter function 
//why we are using because we can put many condition such you passed any string to check that the given string is valid or not 
// or we can check that the given model or input actually exist or not 


};
int main(){
    sportcar*mycar=new sportcar("ferrari","spider");
    mycar->startengine();
    mycar->changegear(1);
    mycar->accelerate();
    mycar->brake();
    mycar->stopengine();
    delete mycar;
    return 0;

}
