#include "ShoppingCart.hpp"
#include <iostream>

using namespace std;

// Add a product to the shopping cart
void ShoppingCart::addProduct(const Product& product)
{
    products.push_back(product);

    cout << product.getName()
         << " added to cart successfully." << endl;
}

// Remove a product from the shopping cart
void ShoppingCart::removeProduct(int id)
{
    for (auto it = products.begin(); it != products.end(); ++it)
    {
        if (it->getId() == id)
        {
            cout << it->getName()
                 << " removed from cart." << endl;

            products.erase(it);
            return;
        }
    }

    cout << "Product with ID "
         << id
         << " not found." << endl;
}

// Calculate the total price
double ShoppingCart::calculateTotal() const
{
    double total = 0.0;

    for (const Product& product : products)
    {
        total += product.getPrice();
    }

    return total;
}

// Display all products in the cart
void ShoppingCart::displayCart() const
{
    if (products.empty())
    {
        cout << "Shopping cart is empty." << endl;
        return;
    }

    cout << "\n===== SHOPPING CART =====" << endl;

    for (const Product& product : products)
    {
        product.display();
    }

    cout << "-------------------------" << endl;
    cout << "Total: R" << calculateTotal() << endl;
}

// Checkout
void ShoppingCart::checkout() const
{
    if (products.empty())
    {
        cout << "Cart is empty. Nothing to checkout."
             << endl;
        return;
    }

    cout << "\n===== CHECKOUT =====" << endl;

    displayCart();

    cout << "Thank you for your purchase!" << endl;
}
