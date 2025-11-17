#include <iostream>
using namespace std;

// Node for each pizza order
class Order {
public:
    int orderID;
    Order* next;
    Order* prev;

    Order(int id) {
        orderID = id;
        next = NULL;
        prev = NULL;
    }
};

// Pizza Parlour using DEQUE
class PizzaParlour {
    Order* front;
    Order* rear;

public:
    PizzaParlour() {
        front = rear = NULL;
    }

    // Customer places order at the front
    void addOrderFront(int id) {
        Order* o = new Order(id);

        if (front == NULL) {
            front = rear = o;
        } else {
            o->next = front;
            front->prev = o;
            front = o;
        }
        cout << "Order " << id << " added at FRONT\n";
    }

    // Customer places order at the rear
    void addOrderRear(int id) {
        Order* o = new Order(id);

        if (rear == NULL) {
            front = rear = o;
        } else {
            rear->next = o;
            o->prev = rear;
            rear = o;
        }
        cout << "Order " << id << " added at REAR\n";
    }

    // Chef processes order from the front
    void processFront() {
        if (front == NULL) {
            cout << "No orders to process.\n";
            return;
        }

        cout << "Processing Order " << front->orderID << " from FRONT\n";

        Order* temp = front;
        front = front->next;

        if (front != NULL)
            front->prev = NULL;
        else
            rear = NULL;

        delete temp;
    }

    // Chef processes order from the rear
    void processRear() {
        if (rear == NULL) {
            cout << "No orders to process.\n";
            return;
        }

        cout << "Processing Order " << rear->orderID << " from REAR\n";

        Order* temp = rear;
        rear = rear->prev;

        if (rear != NULL)
            rear->next = NULL;
        else
            front = NULL;

        delete temp;
    }

    // Display orders
    void showOrders() {
        cout << "Current Orders: ";
        Order* t = front;
        while (t != NULL) {
            cout << t->orderID << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    PizzaParlour p;

    p.addOrderFront(101);
    p.addOrderRear(102);
    p.addOrderFront(100);
    p.addOrderRear(103);

    p.showOrders();

    p.processFront();
    p.processRear();

    p.showOrders();
}