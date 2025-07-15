#include "productService.hpp"
#include <iostream>
#include <iomanip>

void ProductService::addProduct(const Product& product) {
    products.push_back(product);
}

void ProductService::getAllProduct()const {
    std::cout << std::left 
              << std::setw(6) << "ID"
              << std::setw(25) << "NAME"
              << std::setw(15) << "Price"
              << std:: setw(20) << "qty" << std::endl;
    for (const auto& p : products) {
        std::cout << std::left 
              << std::setw(6) << p.getId()
              << std::setw(25) << p.getName()
              << std::setw(15) << p.getPrice()
              << std:: setw(20) << p.getQty() << std::endl;
    }
}

void ProductService::getAllProductById(int id)const {
    for (auto it = products.begin(); it != products.end(); it++) {
        if (it->getId() == id){
            std::cout << "Product Id: " << it->getId() << std::endl;
            std::cout << "Product namew: " << it->getName() << std::endl;
            std::cout << "Product Price: " << it->getPrice() << std::endl;
            std::cout << "Product qty: " << it->getQty() << std::endl;
        }
    }
}

void ProductService::deleteProductById(int id) {
     for (auto it = products.begin(); it != products.end(); it++) {
        if (it->getId() == id){
            products.erase(it);
            break;
        }
    }
}

void ProductService::updateProductById(int id, const std::string name, double price, int qty){
    for (auto it = products.begin(); it != products.end(); it++) {
        if (it->getId() == id){
            it->setName(name);
            it->setPrice(price);
            it->setQty(qty);
            break;
        }
    }
}

bool ProductService::existsById(int id){
    for (auto it = products.begin(); it != products.end(); it++) {
         if (it->getId() == id) {
            return true;
            break;
         }
    }
    return false;
}
