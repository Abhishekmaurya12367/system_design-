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
}
class sportcar:public car{
    
}
int main(){

}
