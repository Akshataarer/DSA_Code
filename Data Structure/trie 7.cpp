#include <iostream>
using namespace std;

// Trie Node structure for plant names
struct TrieNode {
    TrieNode* children[26];
    int plantCount; // Count of plants ending at this node

    TrieNode() {
        plantCount = 0;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

// Insert a plant name into the Trie
void insertPlant(TrieNode* root, const string& plantName) {
    TrieNode* current = root;
    for (char c : plantName) {
        int index = tolower(c) - 'a'; // convert to lowercase
        if (current->children[index] == NULL)
            current->children[index] = new TrieNode();
        current = current->children[index];
    }
    current->plantCount++;
}

// Search for a plant name in the Trie
int searchPlant(TrieNode* root, const string& plantName) {
    TrieNode* current = root;
    for (char c : plantName) {
        int index = tolower(c) - 'a';
        if (current->children[index] == NULL)
            return 0;
        current = current->children[index];
    }
    return current->plantCount > 0 ? 1 : 0;
}

// Delete a plant name from the Trie
int deletePlant(TrieNode* root, const string& plantName) {
    TrieNode* current = root;
    TrieNode* lastBranch = NULL;
    char lastBranchChar;

    for (char c : plantName) {
        int index = tolower(c) - 'a';
        if (current->children[index] == NULL)
            return 0;

        int childCount = 0;
        for (int i = 0; i < 26; i++)
            if (current->children[i] != NULL) childCount++;

        if (childCount > 1) {
            lastBranch = current;
            lastBranchChar = c;
        }
        current = current->children[index];
    }

    int childCount = 0;
    for (int i = 0; i < 26; i++)
        if (current->children[i] != NULL) childCount++;

    if (childCount > 0) {
        current->plantCount--;
    } else if (lastBranch) {
        lastBranch->children[lastBranchChar - 'a'] = NULL;
    } else {
        root->children[plantName[0] - 'a'] = NULL;
    }

    return 1;
}

// Display all plant names in the Trie
void displayPlants(TrieNode* root, string prefix) {
    if (root->plantCount > 0)
        cout << prefix << "\n";

    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            char nextChar = 'a' + i;
            displayPlants(root->children[i], prefix + nextChar);
        }
    }
}

int main() {
    TrieNode* root = new TrieNode();
    int choice;

    while (true) {
        cout << "\nPlant Nursery Trie Menu:\n"
             << "1. Insert Plant\n"
             << "2. Search Plant\n"
             << "3. Delete Plant\n"
             << "4. Display All Plants\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string plantName;
            cout << "Enter plant name to insert: ";
            cin >> plantName;
            insertPlant(root, plantName);
            cout << "Plant inserted successfully.\n";
        } else if (choice == 2) {
            string plantName;
            cout << "Enter plant name to search: ";
            cin >> plantName;
            if (searchPlant(root, plantName))
                cout << "Plant found in nursery.\n";
            else
                cout << "Plant not found in nursery.\n";
        } else if (choice == 3) {
            string plantName;
            cout << "Enter plant name to delete: ";
            cin >> plantName;
            if (deletePlant(root, plantName))
                cout << "Plant deleted successfully.\n";
            else
                cout << "Plant not found in nursery.\n";
        } else if (choice == 4) {
            cout << "Plants in the nursery:\n";
            displayPlants(root, "");
        } else if (choice == 5) {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
