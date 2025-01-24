#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

class HashTable {
private:
    vector<list<int>> table;
    static int num_of_elements;
    int hash_function(int key) { return key % table.size(); }

public:
    HashTable(int size) : table(size) {}

    void insert_item(int item) {
        int index = hash_function(item);

        if (!search_item(item)) {
            table[index].push_back(item);
            num_of_elements++;
        }
    }

    void delete_item(int item) {
        int index = hash_function(item);
        auto& chain = table[index];
        auto it = find(chain.begin(), chain.end(), item);
        if (it != chain.end()) {
            chain.erase(it);
            num_of_elements--;
        }
    }

    bool search_item(int item) {
        int index = hash_function(item);
        for (int key : table[index]) {
            if (item == key)
                return true;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < table.size(); ++i) {
            cout <<  "number" << i << ": ";
            for (int element : table[i])
                cout << element << " ";
            cout << endl;
        }
    }
};


int HashTable::num_of_elements = 0;

int main() {
    HashTable t1(6);
    t1.insert_item(1);
    t1.insert_item(2);
    t1.insert_item(3);
    t1.insert_item(4);
    t1.insert_item(4);

    t1.display();

    return 0;
}
