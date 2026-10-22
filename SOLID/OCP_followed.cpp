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

// 3.) Class 3 for storage which is abstract class

class Persistence {
private:
    ShoppingCart* cart;
public:
    virtual void save(ShoppingCart* cart)=0;    // pure virtual function

};

class SQLPersistence : public Persistence {
public:
    void save(ShoppingCart* cart) override {
        cout<<"Saving shopping cart to SQL"<<endl;
    }
};

class MongoPersistence : public Persistence {
public:
    void save(ShoppingCart* cart) override {
        cout<<"Saving shopping cart to MongoDB"<<endl;
    };
};

class FilePersistence : public Persistence {
public:
    void save(ShoppingCart* cart) override {
        cout<<"Saving shopping cart to File"<<endl;
    };
};


int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProducts(new Product("Laptop", 500));
    cart->addProducts(new Product("Mouse", 50));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    Persistence* db = new SQLPersistence();
    Persistence* mongo = new MongoPersistence();
    Persistence* file = new FilePersistence();
    db->save(cart);
    mongo->save(cart);
    file->save(cart);

    return 0;
}