#include<bits/stdc++.h>
using namespace std;
class product{
public:
    string name;
    double price;
// product class representing any  item of any ecomerce;
    product(string name,double price)
    {
        this->name=name;
        this->price=price;
    }
}
//voilating the single responsibility principle when shopping cart handling the multiple function within the class;

class shoppingcart{
  private:
   vector<product*>product;
    public:
     voud addproduct(product*item){
        product.push_back(item);
     }
     vector<product*>getproduct(){
        return product;
     }
     double totalammout(){
        double total=0;
        for(auto it:product){
            total+=it->price;
        }
        return total;
     }
     // we are commenting this part because these are voilating the voilating the single responsibility 
     // principle why we are doing because i want that it create messy in the code and become difficult to debug any problem 
     // so i am using this;
    //  void printinvoice(){
    //     for(auto it:product){
    //         cout<<it->name<<"$"<<it->price<<endl;
    //     }
    //     cout<<"total"<<totalammout()<<endl;
    //  }
    //  void databasesave(){
    //     cout<<"item is successfully saved in the database"<<endl;
    //  }
}
class shopppingprinter{
    private:
    shoppingcart*cart;// getting the reference from the shopping cart 
    public:
    shopppingprinter(shoppingcart*cart){
        this->cart=cart;
    }
    void printinvoice(){
        cout<<"printing the invoice"<<endl;
        for(auto it:cart->getproduct()){
            cout<<it->name<<"$"<<it->price<<endl;
        }
        cout<<"total"<<cart->totalammout()<<endl;
    }
}
class shoppingstoradge{
    private:
    shoppingcart*cart;
    public:
    shoppingstoradge(shoppingcart*cart){
        this->cart=cart;
    }
    void databasesave(){
        cout<<"item is successfully saved in the database"<<endl;
    }

}
int main()
{
    shoppingcart*cart= new shoppingcart();
    cart->addproduct(new product("milk",20));
    cart->addproduct(new product("egg",30));
    cart->addproduct(new product("rice",40));
    shopppingprinter*printer= new shopppingprinter(cart);
    cart->printinvoice();
    shoppingstoradge*storage=new shoppingstoradge(cart);
    cart->databasesave();
    return 0;

}