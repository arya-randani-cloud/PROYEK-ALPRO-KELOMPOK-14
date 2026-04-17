#include <iostream>
#include <string>
#include <limits>
#include <conio.h> // For _getch() on Windows (hide password input)

using namespace std;

// Function to hide password input (Windows)
string getPassword() {
    string password;
    char ch;
    while ((ch = _getch()) != '\r') { // Enter key
        if (ch == '\b') { // Backspace
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        } else {
            cout << '*';
            password += ch;
        }
    }
    cout << endl;
    return password;
}

// Cross-platform password input (fallback)
string getPasswordCrossPlatform() {
    string password;
    cout << "Enter password: ";
    cin >> password;
    return password;
}

bool login() {
    const string CORRECT_USERNAME = "admin";
    const string CORRECT_PASSWORD = "password123";
    
    int maxAttempts = 3;
    
    while (maxAttempts > 0) {
        string username, password;
        
        cout << "\n=== LOGIN SYSTEM ===" << endl;
        cout << "Username: ";
        cin >> username;
        
        cout << "Password: ";
        // Use getPassword() for Windows, fallback for others
        #ifdef _WIN32
            password = getPassword();
        #else
            password = getPasswordCrossPlatform();
        #endif
        
        if (username == CORRECT_USERNAME && password == CORRECT_PASSWORD) {
            cout << "\n✓ Login successful! Welcome, " << username << "!" << endl;
            return true;
        } else {
            maxAttempts--;
            if (maxAttempts > 0) {
                cout << "\n✗ Invalid credentials! Attempts remaining: " << maxAttempts << endl;
            } else {
                cout << "\n✗ Account locked! Too many failed attempts." << endl;
            }
        }
        
        // Clear input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    return false;
}

int main() {
    cout << "Simple C++ Login System" << endl;
    
    if (login()) {
        // Successful login - show dashboard
        cout << "\n--- DASHBOARD ---" << endl;
        cout << "1. View Profile" << endl;
        cout << "2. Change Password" << endl;
        cout << "3. Logout" << endl;
        
        int choice;
        cout << "Select option: ";
        cin >> choice;
        
        // Handle dashboard options
        switch (choice) {
            case 1:
                cout << "Profile loaded successfully!" << endl;
                break;
            case 2:
                cout << "Password change feature coming soon!" << endl;
                break;
            case 3:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    }
    
    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}
