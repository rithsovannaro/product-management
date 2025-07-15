#pragma once
#include "product.hpp"
#include <vector>

class ProductService{
    private:
        std::vector<Product> products;

    public:
        void addProduct(const Product& product);
        void getAllProduct () const;
        void getAllProductById(int id) const;

        bool existsById(int id);
        void deleteProductById(int id) ;
        void updateProductById(int id, const std::string name, double price, int qty);
};