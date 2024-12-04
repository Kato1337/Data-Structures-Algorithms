#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <chrono>
#include <thread>

using namespace std;

class Person {
public:
    string name;
    int ticket_number;

    Person(string name, int ticket_number) : name(name), ticket_number(ticket_number) {}
};

class Queue {
private:
    queue<Person> concertQueue;
    unordered_map<string, int> positionMap;
    int ticketCounter = 1;
    bool running = true;
    int countdownTimer = 6; // Timer set to 6 seconds

public:
    void enqueue(string name) {
        Person person(name, ticketCounter);
        concertQueue.push(person);
        positionMap[name] = ticketCounter;
        cout << name << " added to the queue with Ticket #" << ticketCounter << endl;
        ticketCounter++;
        cout << "Queue size: " << concertQueue.size() << endl;
        cout << endl;
    }

    void dequeue() {
        if (!concertQueue.empty()) {
            Person front = concertQueue.front();
            cout << "\n============================" << endl;
            cout << "Dequeue: " << front.name << " received a ticket (Ticket #" << front.ticket_number << ")" << endl;
            cout << "============================\n" << endl;
            positionMap.erase(front.name);
            concertQueue.pop();
        }
    }

    void peek() {
        if (!concertQueue.empty()) {
            Person front = concertQueue.front();
            cout << "Next in line: " << front.name << " (Ticket #" << front.ticket_number << ")" << endl;
        } else {
            cout << "Queue is empty." << endl;
        }
        cout << endl;
    }

    void position(string name) {
        if (positionMap.find(name) != positionMap.end()) {
            int pos = 1;
            queue<Person> tempQueue = concertQueue;
            while (!tempQueue.empty()) {
                Person person = tempQueue.front();
                if (person.name == name) {
                    cout << "\n============================" << endl;
                    cout << name << " is currently at position " << pos << " in the queue." << endl;
                    cout << "============================\n" << endl;
                    return;
                }
                tempQueue.pop();
                pos++;
            }
        } else {
            cout << "\n============================" << endl;
            cout << name << " is not in the queue." << endl;
            cout << "============================\n" << endl;
        }
    }

    bool isEmpty() const {
        return concertQueue.empty();
    }

    void setRunning(bool state) {
        running = state;
    }

    bool isRunning() const {
        return running;
    }

    int getCountdownTimer() const {
        return countdownTimer;
    }

    void decreaseTimer() {
        if (countdownTimer > 0) {
            countdownTimer--;
        }
    }

    void resetTimer() {
        countdownTimer = 10;
    }
};

void autoDequeue(Queue& queue) {
    while (queue.isRunning()) {
        this_thread::sleep_for(chrono::seconds(1));
        queue.decreaseTimer();

        if (queue.getCountdownTimer() <= 0) {
            if (!queue.isEmpty()) {
                queue.dequeue();
                queue.resetTimer();
            }
        }
    }
}

int main() {
    Queue queue;
    int choice;

    cout << "Welcome to Olivia Rodrigo's Concert Ticketing System!" << endl;

    thread dequeueThread(autoDequeue, ref(queue));

    while (true) {
        cout << "\n1. Enqueue a person\n2. Check your position in the queue\n3. Exit\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the name: ";
            string name;
            cin >> name;
            queue.enqueue(name);
            queue.peek();
        } else if (choice == 2) {
            cout << "Enter your name: ";
            string name;
            cin >> name;
            queue.position(name);
        } else if (choice == 3) {
            queue.setRunning(false);
            cout << "Exiting the system. Thank you!" << endl;
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    dequeueThread.join();
    return 0;
}