#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Node for a singly linked list
struct Vehicle {
    int token;
    string number;
    string type;
    Vehicle* next;

    Vehicle(int t, string n, string ty) {
        token = t;
        number = n;
        type = ty;
        next = nullptr;
    }
};

class TrafficQueue {
private:
    Vehicle* front;
    Vehicle* rear;
    int nextToken;

public:
    TrafficQueue() {
        front = nullptr;
        rear = nullptr;
        nextToken = 1;
    }

    ~TrafficQueue() {
        while (front != nullptr) {
            Vehicle* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    // Enqueue: add a vehicle at the rear of the queue
    void addVehicle(const string& number, const string& type) {
        Vehicle* newVehicle = new Vehicle(nextToken++, number, type);

        if (isEmpty()) {
            front = rear = newVehicle;
        } else {
            rear->next = newVehicle;
            rear = newVehicle;
        }

        cout << "\nVehicle added successfully. Token: "
             << newVehicle->token << "\n";
    }

    // Dequeue: the first vehicle passes when the signal turns green
    void vehiclePassed() {
        if (isEmpty()) {
            cout << "\nNo vehicles are waiting at the signal.\n";
            return;
        }

        Vehicle* temp = front;
        cout << "\nVehicle passed: " << temp->number
             << " (" << temp->type << "), Token: " << temp->token << "\n";

        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    void displayQueue() const {
        if (isEmpty()) {
            cout << "\nThe queue is empty.\n";
            return;
        }

        cout << "\n--- VEHICLES WAITING AT RED SIGNAL ---\n";
        cout << "FRONT\n";
        Vehicle* current = front;
        while (current != nullptr) {
            cout << "[Token: " << current->token
                 << " | Number: " << current->number
                 << " | Type: " << current->type << "]\n";
            current = current->next;
        }
        cout << "REAR\n";
    }

    void searchVehicle(const string& number) const {
        Vehicle* current = front;
        while (current != nullptr) {
            if (current->number == number) {
                cout << "\nVehicle found in the queue.\n"
                     << "Token: " << current->token
                     << "\nNumber: " << current->number
                     << "\nType: " << current->type << "\n";
                return;
            }
            current = current->next;
        }
        cout << "\nVehicle not found in the waiting queue.\n";
    }

    void countVehicles() const {
        int count = 0;
        Vehicle* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        cout << "\nVehicles waiting: " << count << "\n";
    }
};

int main() {
    TrafficQueue queue;
    int choice;

    do {
        cout << "\n========== SMART TRAFFIC SIGNAL QUEUE SIMULATOR ==========\n";
        cout << "1. Add arriving vehicle (Enqueue)\n";
        cout << "2. Green signal: let first vehicle pass (Dequeue)\n";
        cout << "3. Display waiting vehicles\n";
        cout << "4. Search vehicle by number\n";
        cout << "5. Count waiting vehicles\n";
        cout << "6. Check if queue is empty\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "\nInvalid input. Please enter a menu number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            string number, type;
            cout << "Enter vehicle number (e.g., MH12AB1234): ";
            cin >> number;
            cout << "Enter vehicle type (Car/Bike/Bus/Auto): ";
            cin >> type;
            queue.addVehicle(number, type);
        } else if (choice == 2) {
            queue.vehiclePassed();
        } else if (choice == 3) {
            queue.displayQueue();
        } else if (choice == 4) {
            string number;
            cout << "Enter vehicle number to search: ";
            cin >> number;
            queue.searchVehicle(number);
        } else if (choice == 5) {
            queue.countVehicles();
        } else if (choice == 6) {
            cout << (queue.isEmpty() ? "\nQueue is empty.\n" : "\nVehicles are waiting.\n");
        } else if (choice == 0) {
            cout << "\nThank you for using the simulator!\n";
        } else {
            cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
