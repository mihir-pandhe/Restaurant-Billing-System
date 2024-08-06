#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Order
{
    string item;
    int quantity;
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
        cout << "3. Exit" << endl;
        cout << "------------------------------" << endl;
    }

    void enterOrder()
    {
        string item;
        int quantity;
        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, item);
        cout << "Enter quantity: ";
        cin >> quantity;
        orders.push_back({item, quantity});
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
                cout << i + 1 << ". Item: " << orders[i].item << ", Quantity: " << orders[i].quantity << endl;
            }
            cout << "------------------------------" << endl;
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
