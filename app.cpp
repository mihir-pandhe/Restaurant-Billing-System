#include <iostream>
using namespace std;

class RestaurantBillingSystem
{
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
        cout << "Entering order..." << endl;
    }

    void viewOrders()
    {
        cout << "Viewing orders..." << endl;
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
