#include <iostream>
#include <fstream>   // for file handling (read/write)
#include <string>    // for using string type
#include <limits>    // for numeric_limits
using namespace std;

// ---------------- Helper Function: Check spaces in password ----------------
bool hasSpace(const string &str) {
    for (char c : str) {
        if (c == ' ') return true;
    }
    return false;
}

// ---------------- Function: Register New User ----------------
void registerUser() {
    string username, password;
    cout << "Enter a new username: ";
    cin >> username;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore newline after username

    // Validate password (no spaces allowed)
    while (true) {
        cout << "Enter a new password (no spaces allowed): ";
        getline(cin, password);

        if (hasSpace(password)) {
            cout << "[ERROR] Password cannot contain spaces. Try again.\n";
        } else {
            break; // valid password
        }
    }

    // Step 1: Check if username already exists
    ifstream infile("users.txt"); // open file in read mode
    string fileUser, filePass;
    bool exists = false;

    while (infile >> fileUser >> filePass) {  // read file line by line
        if (fileUser == username) {           // check if username matches
            exists = true;
            break;
        }
    }
    infile.close(); // close file

    if (exists) {
        cout << "[ERROR] Username already taken. Try another.\n";
        return; // stop function here
    }

    // Step 2: Save username + password in file
    ofstream outfile("users.txt", ios::app); // append mode (new data added at end)
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "[SUCCESS] Registration successful! You can now login.\n";
}

// ---------------- Function: Login User ----------------
void loginUser() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore newline
    cout << "Enter your password: ";
    getline(cin, password);

    ifstream infile("users.txt"); // open file in read mode
    string fileUser, filePass;
    bool success = false;

    // check file line by line
    while (infile >> fileUser >> filePass) {
        if (fileUser == username && filePass == password) {
            success = true;
            break;
        }
    }
    infile.close();

    if (success) {
        cout << "[SUCCESS] Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "[ERROR] Invalid username or password.\n";
    }
}

// ---------------- Main Function ----------------
int main() {
    int choice;

    while (true) { // infinite loop until user exits
        cout << "\n===== Login & Registration System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        // ✅ Safe input check
        if (!(cin >> choice)) {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard wrong input
            cout << "[ERROR] Please enter a number (1-3).\n";
            continue;
        }

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            loginUser();
        } else if (choice == 3) {
            cout << "[INFO] Exiting program. Goodbye!\n";
            break;
        } else {
            cout << "[ERROR] Invalid choice. Try again.\n";
        }
    }

    return 0;
}
