#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

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

class RestaurantBillingSystem
{
private:
    vector<Order> orders;
    vector<MenuItem> menu;

public:
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
        cout << "8. Exit" << endl;
        cout << "------------------------------" << endl;
    }

    void enterOrder()
    {
        string item;
        int quantity;
        double price;
        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, item);
        cout << "Enter quantity: ";
        cin >> quantity;
        price = getItemPrice(item);
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
            double total = 0.0;
            for (const auto &order : orders)
            {
                total += order.quantity * order.price;
            }
            cout << "\nTotal Bill: $" << fixed << setprecision(2) << total << endl;
        }
    }

    void addMenuItem()
    {
        string name;
        double price;
        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter price: ";
        cin >> price;
        menu.push_back({name, price});
        cout << "Menu item added successfully." << endl;
    }

    void editMenuItem()
    {
        string name;
        cout << "Enter item name to edit: ";
        cin.ignore();
        getline(cin, name);
        for (auto &menuItem : menu)
        {
            if (menuItem.name == name)
            {
                cout << "Enter new price: ";
                cin >> menuItem.price;
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
        cin.ignore();
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

    void exitSystem()
    {
        cout << "Exiting system..." << endl;
        exit(0);
    }

    void run()
    {
        while (true)
        {
            displayMenu();
            int choice;
            cout << "Select an option: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                enterOrder();
                break;
            case 2:
                viewOrders();
                break;
            case 3:
                calculateBill();
                break;
            case 4:
                addMenuItem();
                break;
            case 5:
                editMenuItem();
                break;
            case 6:
                removeMenuItem();
                break;
            case 7:
                saveMenuToFile();
                break;
            case 8:
                exitSystem();
                break;
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
