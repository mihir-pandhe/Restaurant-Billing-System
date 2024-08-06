#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

struct Order
{
    string item;
    int quantity;
    double price;
};

struct MenuItem
{
    string name;
    double price;
};

class MenuManager
{
private:
    vector<MenuItem> menu;

public:
    double getItemPrice(const string &itemName)
    {
        for (const auto &menuItem : menu)
        {
            if (menuItem.name == itemName)
            {
                return menuItem.price;
            }
        }
        return -1;
    }

    void addMenuItem()
    {
        string name;
        double price;
        cout << "Enter item name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        cout << "Enter price: ";
        while (!(cin >> price) || price < 0)
        {
            cout << "Invalid price. Enter a valid positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        menu.push_back({name, price});
        cout << "Menu item added successfully." << endl;
    }

    void editMenuItem()
    {
        string name;
        cout << "Enter item name to edit: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        for (auto &menuItem : menu)
        {
            if (menuItem.name == name)
            {
                cout << "Enter new price: ";
                while (!(cin >> menuItem.price) || menuItem.price < 0)
                {
                    cout << "Invalid price. Enter a valid positive number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Menu item updated successfully." << endl;
                return;
            }
        }
        cout << "Item not found in menu." << endl;
    }

    void removeMenuItem()
    {
        string name;
        cout << "Enter item name to remove: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        for (auto it = menu.begin(); it != menu.end(); ++it)
        {
            if (it->name == name)
            {
                menu.erase(it);
                cout << "Menu item removed successfully." << endl;
                return;
            }
        }
        cout << "Item not found in menu." << endl;
    }

    void saveMenuToFile()
    {
        ofstream file("menu.txt");
        if (file.is_open())
        {
            for (const auto &menuItem : menu)
            {
                file << menuItem.name << "," << menuItem.price << endl;
            }
            file.close();
            cout << "Menu saved to file successfully." << endl;
        }
        else
        {
            cout << "Error opening file." << endl;
        }
    }
};

class BillingManager
{
private:
    vector<Order> orders;
    double discountPercentage;
    double taxPercentage;

public:
    BillingManager() : discountPercentage(0.0), taxPercentage(0.0) {}

    void enterOrder(MenuManager &menuManager)
    {
        string item;
        int quantity;
        double price;
        cout << "Enter item name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, item);
        cout << "Enter quantity: ";
        while (!(cin >> quantity) || quantity <= 0)
        {
            cout << "Invalid quantity. Enter a valid positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        price = menuManager.getItemPrice(item);
        if (price != -1)
        {
            orders.push_back({item, quantity, price});
            cout << "Order entered successfully." << endl;
        }
        else
        {
            cout << "Item not found in menu." << endl;
        }
    }

    void viewOrders()
    {
        if (orders.empty())
        {
            cout << "No orders have been placed yet." << endl;
        }
        else
        {
            cout << "\nCurrent Orders:" << endl;
            cout << "------------------------------" << endl;
            for (size_t i = 0; i < orders.size(); ++i)
            {
                cout << i + 1 << ". Item: " << orders[i].item << ", Quantity: " << orders[i].quantity << ", Price: $" << fixed << setprecision(2) << orders[i].price << endl;
            }
            cout << "------------------------------" << endl;
        }
    }

    void calculateBill()
    {
        if (orders.empty())
        {
            cout << "No orders have been placed yet." << endl;
        }
        else
        {
            double subtotal = 0.0;
            cout << "\nDetailed Bill:" << endl;
            cout << "------------------------------" << endl;
            for (const auto &order : orders)
            {
                double itemTotal = order.quantity * order.price;
                subtotal += itemTotal;
                cout << "Item: " << order.item << ", Quantity: " << order.quantity << ", Price: $" << fixed << setprecision(2) << order.price << ", Total: $" << itemTotal << endl;
            }
            double discount = (discountPercentage / 100) * subtotal;
            double tax = (taxPercentage / 100) * (subtotal - discount);
            double total = subtotal - discount + tax;
            cout << "------------------------------" << endl;
            cout << "Subtotal: $" << fixed << setprecision(2) << subtotal << endl;
            cout << "Discount (" << discountPercentage << "%): -$" << discount << endl;
            cout << "Tax (" << taxPercentage << "%): +$" << tax << endl;
            cout << "Total: $" << total << endl;
        }
    }

    void setDiscount()
    {
        cout << "Enter discount percentage: ";
        while (!(cin >> discountPercentage) || discountPercentage < 0 || discountPercentage > 100)
        {
            cout << "Invalid percentage. Enter a number between 0 and 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Discount set to " << discountPercentage << "%" << endl;
    }

    void setTax()
    {
        cout << "Enter tax percentage: ";
        while (!(cin >> taxPercentage) || taxPercentage < 0 || taxPercentage > 100)
        {
            cout << "Invalid percentage. Enter a number between 0 and 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Tax set to " << taxPercentage << "%" << endl;
    }
};

class RestaurantBillingSystem
{
private:
    MenuManager menuManager;
    BillingManager billingManager;

    void displayMenu()
    {
        cout << "\n--- Restaurant Billing System ---" << endl;
        cout << "1. Enter Order" << endl;
        cout << "2. View Orders" << endl;
        cout << "3. Calculate Bill" << endl;
        cout << "4. Add Menu Item" << endl;
        cout << "5. Edit Menu Item" << endl;
        cout << "6. Remove Menu Item" << endl;
        cout << "7. Save Menu to File" << endl;
        cout << "8. Set Discount" << endl;
        cout << "9. Set Tax" << endl;
        cout << "10. Exit" << endl;
        cout << "------------------------------" << endl;
    }

public:
    void run()
    {
        while (true)
        {
            displayMenu();
            int choice;
            cout << "Select an option: ";
            while (!(cin >> choice))
            {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            switch (choice)
            {
            case 1:
                billingManager.enterOrder(menuManager);
                break;
            case 2:
                billingManager.viewOrders();
                break;
            case 3:
                billingManager.calculateBill();
                break;
            case 4:
                menuManager.addMenuItem();
                break;
            case 5:
                menuManager.editMenuItem();
                break;
            case 6:
                menuManager.removeMenuItem();
                break;
            case 7:
                menuManager.saveMenuToFile();
                break;
            case 8:
                billingManager.setDiscount();
                break;
            case 9:
                billingManager.setTax();
                break;
            case 10:
                cout << "Exiting system..." << endl;
                return;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
            }
        }
    }
};

int main()
{
    RestaurantBillingSystem rbs;
    rbs.run();
    return 0;
}
