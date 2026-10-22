#include<iostream>
#include<vector>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this->name=name;
        this->price=price;
    }

};

// 1.) Class 1 for shopping cart related logic

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

    // Calculate the total price
    double calculateTotal(){
        double total=0;
        for(auto p: products){
            total+=p->price;
        }
        return total;
    }
};

// 2.) Class 2 for invoice printing logic

class ShoppingCartPrinter {
private:
    ShoppingCart* cart;
public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart=cart;
    }

    void printInvoice(){
        cout<<"Shopping cart invoice:\n";
        for(auto p: cart->getProducts()){
            cout<<p->name<<" -$"<<p->price<<endl;
        }
        cout<<"Total: "<<cart->calculateTotal()<<endl;
    }
};

// 3.) Class 3 for storage

class ShoppingCartStorage {
private:
    ShoppingCart* cart;
public:
    ShoppingCartStorage(ShoppingCart* cart){
        this->cart=cart;
    }

    void saveToDB(){
        cout<<"Saving shopping cart to DataBase"<<endl;
    }

};


int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProducts(new Product("Laptop", 500));
    cart->addProducts(new Product("Mouse", 50));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToDB();

    return 0;
}