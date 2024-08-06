#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Order
{
    string item;
    int quantity;
    double price;
};

class RestaurantBillingSystem
{
private:
    vector<Order> orders;

public:
    void displayMenu()
    {
        cout << "\n--- Restaurant Billing System ---" << endl;
        cout << "1. Enter Order" << endl;
        cout << "2. View Orders" << endl;
        cout << "3. Calculate Bill" << endl;
        cout << "4. Exit" << endl;
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
        cout << "Enter price: ";
        cin >> price;
        orders.push_back({item, quantity, price});
        cout << "Order entered successfully." << endl;
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
