#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Movie {
    string title;
};


void add_movie(vector<Movie>& collection) {
    Movie m;
    cout << "\nEnter movie title: ";
    cin.ignore();
    getline(cin, m.title);
    collection.push_back(m);
    cout << "Movie '" << m.title << "' added successfully!\n";
}


void view_movies(const vector<Movie>& collection) {
    cout << "\nMovie Collection:\n";
    if (collection.empty()) cout << "No movies.\n";
    else for (size_t i = 0; i < collection.size(); ++i)
        cout << i + 1 << ". " << collection[i].title << endl;
    cout << endl;
}


void update_movie(vector<Movie>& collection) {
    view_movies(collection);
    int i; 
    cout << "Movie number to update: "; 
    cin >> i; 
    --i;
    if (i >= 0 && i < collection.size()) {
        cout << "Enter new title: ";
        string new_title;
        cin.ignore();
        getline(cin, new_title);
        if (!new_title.empty()) collection[i].title = new_title;
        cout << "Movie updated successfully!\n\n";
    } else cout << "Invalid selection.\n\n";
}


void delete_movie(vector<Movie>& collection) {
    view_movies(collection);
    int i; 
    cout << "Movie number to delete: "; 
    cin >> i; 
    --i;
    if (i >= 0 && i < collection.size()) { 
        cout << "Movie '" << collection[i].title << "' deleted successfully!\n\n";
        collection.erase(collection.begin() + i);
    } else cout << "Invalid selection.\n\n";
}

int main() {
    vector<Movie> collection;
    while (true) {
        cout << "\n1. Add\n2. View\n3. Update\n4. Delete\n5. Exit\nChoose: ";
        int choice; cin >> choice;
        if (choice == 1) add_movie(collection);
        else if (choice == 2) view_movies(collection);
        else if (choice == 3) update_movie(collection);
        else if (choice == 4) delete_movie(collection);
        else break;
    }
}