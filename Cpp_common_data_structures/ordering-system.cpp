#include <iostream>
#include <queue>
using namespace std;

class MerchOrderSystem
{
private:
    queue<int> regularOrders;
    queue<int> priorityOrders;

public:
    void place_order(int orderID, bool isPriority = false) {
        if (isPriority) {
            cout << "Placing  the order " << orderID << " to priority orders queue." << endl;
            priorityOrders.push(orderID);
        }
        else {
            cout << "Placing the order " << orderID << " to regular orders queue." << endl;
            regularOrders.push(orderID);
        }
    }


    int fulfill_order() {

        int processedOrderID = -1;
        if (!priorityOrders.empty()) {
            processedOrderID = priorityOrders.front();
            cout << "Processing order: " << processedOrderID << endl;
            priorityOrders.pop();
        }
        else {
            if (!regularOrders.empty()) {
                processedOrderID = regularOrders.front();
                cout << "Processing order: " << processedOrderID << endl;
                regularOrders.pop();
            }
            else {
                cout << "There are no orders to process." << endl;
            }
        }

        return processedOrderID;
    }

};

int main()
{
    MerchOrderSystem orderSystem; // Instantiate MerchOrderSystem object

    // Placing some orders
    orderSystem.place_order(201);       // Regular order
    orderSystem.place_order(202);       // Regular order
    orderSystem.place_order(101, true); // Priority order
    orderSystem.place_order(203);       // Regular order

    // Fulfilling all orders
    int orderID;
    while ((orderID = orderSystem.fulfill_order()) != -1)
    {
        cout << "Order with ID " << orderID << " has been fulfilled.\n";
    }

    return 0;
}