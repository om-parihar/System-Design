#include <iostream>
#include <vector>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price){
        this->name=name;
        this->price=price;
    }
};

class ShoppingCart {
private:
    vector<Product*> products;
public:

    void addProducts(Product* p){
        products.push_back(p);
    }

    const vector<Product*>& getProducts(){
        return products;
    }

    // 1.) Responsibility 1

    double calculateTotal(){
        double total=0;
        for (auto p: products){
            total+=p->price;
        }
        return total;
    }

    // 2.) Responsibility 2

    void printInvoice(){
        cout<<"Shopping cart invoice:\n";
        for(auto p: products){
            cout<<p->name<<" -$"<<p->price<<endl;
        }
        cout<<"Total: "<<calculateTotal()<<endl;
    }

    // 3.) Responsibility 3

    void saveToDB(){
        cout<<"Saving shopping cart to DataBase"<<endl;
    }
};


int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProducts(new Product("Laptop", 500));
    cart->addProducts(new Product("Mouse", 50));

    cart->printInvoice();
    cart->saveToDB();

    return 0;
}