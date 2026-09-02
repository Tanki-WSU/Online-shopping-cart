#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include <vector>
#include "Product.hpp"

template <typename T>
class ShoppingCart
{
private:
    std::vector<T> products;

public:
    void addProduct(const T& product);
    void removeProduct(int id);
    double calculateTotal() const;
    void displayCart() const;
    void checkout() const;
};

template <typename T>
void ShoppingCart<T>::addProduct(const T& product)
{
    products.push_back(product);
}

template <typename T>
void ShoppingCart<T>::removeProduct(int id)
{
    for (auto it = products.begin(); it != products.end(); ++it)
    {
        if (it->getId() == id)
        {
            products.erase(it);

            std::cout << "Product removed successfully.\n";
            return;
        }
    }

    std::cout << "Product not found.\n";
}

template <typename T>
double ShoppingCart<T>::calculateTotal() const
{
    double total = 0;

    for (const T& product : products)
    {
        total += product.getPrice();
    }

    return total;
}

template <typename T>
void ShoppingCart<T>::displayCart() const
{
    if (products.empty())
    {
        std::cout << "Shopping cart is empty.\n";
        return;
    }

    std::cout << "\n===== SHOPPING CART =====\n";

    for (const T& product : products)
    {
        product.display();
    }

    std::cout << "Total: R" << calculateTotal() << "\n";
}

template <typename T>
void ShoppingCart<T>::checkout() const
{
    if (products.empty())
    {
        std::cout << "Cart is empty. Nothing to checkout.\n";
        return;
    }

    std::cout << "\n===== CHECKOUT =====\n";
    displayCart();

    std::cout << "Thank you for your purchase!\n";
}

#endif
