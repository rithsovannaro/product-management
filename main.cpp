#include <iostream>
#include "include/Product.hpp"
#include "include/productService.hpp"
using namespace std;

ProductService productService;

void menu() {
    cout << "1. add" << endl;
    cout << "2. Get all" << endl;
    cout << "3. get by id" << endl;
    cout << "4. delete by id" << endl;
    cout << "5. update by id" << endl;
    cout << "0. exit" << endl;
}




int main(){
    // system("cls");

    int op;
    do {
        menu();
        cout << "enter an option -> ";
        cin >> op;

        if (op == 0) {
            cout << "exting..." << endl;
            return 0;
        }

    switch (op)
    {
    case 1:{
       int id, qty;
       string name;
       double price;

       cout << "Enter id: "; cin >> id;
        if (productService.existsById(id)) {
            cout << "Product with id: " << id << " already exists" << endl;
            break;
        }
       cout << "enter name: "; cin >> name;
       cout << "enter price: "; cin >> price;
       cout << "enter qty: "; cin >> qty;

       Product P(id, name, price, qty);
       productService.addProduct(P);
        break;
    }
    case 2:{
        productService.getAllProduct();
        break;
    }
    case 3:{
        int id;
        cout << "enter an id: "; cin >> id;
        productService.getAllProductById(id);
        break;
    }
    case 4:{
        int id;
        cout << "enter an id to delete: "; cin >> id;
        if (!productService.existsById(id)) {
            cout << "Product with id: " << id << " does not exist" << endl;
            break;
        productService.deleteProductById(id);
        break;
    }
     case 5: {
        int id;
        cout << "enter product id to update: "; cin >> id;
            if (!productService.existsById(id)) {
                    cout << "Product with id: " << id << " does not exist" << endl;
                    break;
                }
        string name;
        double price;
        int qty;
            cin.ignore();
            cout << "Enter new Name: "; getline(cin, name);
            cout << "Enter new Price: "; cin >> price;
            cout << "Enter new Quantity: "; cin >> qty;
            productService.updateProductById(id, name, price, qty);
            break;
            }
    default:
        cout << "Invalided option" << endl;
        break;
    }

    } 
    } while (op != 0);


    
    return 0;
}

   
// Product p1(01, "coka", 1.5, 100);
    // cout << p1.getId() << endl;
    // cout << p1.getName() << endl;
    // cout << p1.getPrice()<< endl;
    // cout << "=========================" << endl;
    
    // int id, qty;
    // string name;
    // double price;

    // cout << "enter Product Id: ";
    // cin >> id;
    // cout << "enter Product name: ";
    // cin >> name;
    // cout << "enter Product Price: ";
    // cin >> price;
    // cout << "enter Product qty: ";
    // cin >> qty;

    // Product p2(id, name, price, qty);
    // cout << p2.getId() << endl;
    // cout << p2.getName() << endl;
    // cout << p2.getPrice()<< endl;
