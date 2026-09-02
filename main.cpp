#include <iostream>
#include "Product.hpp"
#include "ShoppingCart.hpp"

using namespace std;

int main()
{
    ShoppingCart<Product> cart;

    Product p1(1, "Laptop", 12000.00);
    Product p2(2, "Keyboard", 500.00);
    Product p3(3, "Mouse", 300.00);
    Product p4(4, "Headphones", 800.00);

    int choice;

    do
    {
        cout << "\n==============================\n";
        cout << "     ONLINE SHOPPING CART\n";
        cout << "==============================\n";
        cout << "1. Add Laptop\n";
        cout << "2. Add Keyboard\n";
        cout << "3. Add Mouse\n";
        cout << "4. Add Headphones\n";
        cout << "5. Remove Product\n";
        cout << "6. Display Cart\n";
        cout << "7. Calculate Total\n";
        cout << "8. Checkout\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cart.addProduct(p1);
            cout << "Laptop added to cart.\n";
            break;

        case 2:
            cart.addProduct(p2);
            cout << "Keyboard added to cart.\n";
            break;

        case 3:
            cart.addProduct(p3);
            cout << "Mouse added to cart.\n";
            break;

        case 4:
            cart.addProduct(p4);
            cout << "Headphones added to cart.\n";
            break;

        case 5:
        {
            int id;

            cout << "Enter product ID to remove: ";
            cin >> id;

            cart.removeProduct(id);
            break;
        }

        case 6:
            cart.displayCart();
            break;

        case 7:
            cout << "Total = R"
                 << cart.calculateTotal()
                 << endl;
            break;

        case 8:
            cart.checkout();
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
