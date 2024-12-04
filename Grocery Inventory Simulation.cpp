#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    vector<string> currentInventory = {"apples", "bananas", "oranges", "pears"};
    vector<string> shipment = {"kiwis", "bananas", "grapes"};
    vector<string> soldOutItems = {"apples", "oranges"};


    cout << "\nCurrent Inventory: [";
    for (int i = 0; i < currentInventory.size(); i++) {
        cout << "\"" << currentInventory[i] << "\"";
        if (i < currentInventory.size() - 1) cout << ", ";
    }
    cout << "]" << endl;


    cout << "\nShipment: [";
    for (int i = 0; i < shipment.size(); i++) {
        cout << "\"" << shipment[i] << "\"";
        if (i < shipment.size() - 1) cout << ", ";
    }
    cout << "]" << endl;


    currentInventory.insert(currentInventory.end(), shipment.begin(), shipment.end());


    cout << "\nSold-out items: [";
    for (int i = 0; i < soldOutItems.size(); i++) {
        cout << "\"" << soldOutItems[i] << "\"";
        if (i < soldOutItems.size() - 1) cout << ", ";
    }
    cout << "]" << endl;


    for (int i = 0; i < soldOutItems.size(); i++) {
        currentInventory.erase(remove(currentInventory.begin(), currentInventory.end(), soldOutItems[i]), currentInventory.end());
    }


    sort(currentInventory.begin(), currentInventory.end());
    currentInventory.erase(unique(currentInventory.begin(), currentInventory.end()), currentInventory.end());


    cout << "\nUpdated Inventory: [";
    for (int i = 0; i < currentInventory.size(); i++) {
        cout << "\"" << currentInventory[i] << "\"";
        if (i < currentInventory.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}