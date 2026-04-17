#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <conio.h>
#include <iomanip>

using namespace std;

class LoginSystem {
private:
    // Private data members
    string adminUsername;
    string adminPassword;
    int maxLoginAttempts;
    int currentAttempts;
    bool isLoggedIn;
    
    // Private helper methods
    string getSecurePassword() {
        string password;
        char ch;
        cout << "Password: ";
        
        #ifdef _WIN32
        while ((ch = _getch()) != '\r') {
            if (ch == '\b' && !password.empty()) {
                cout << "\b \b";
                password.pop_back();
            } else if (ch != '\b') {
                cout << '*';
                password += ch;
            }
        }
        #else
        cin >> password;
        #endif
        
        cout << endl;
        return password;
    }
    
    bool verifyCredentials(const string& username, const string& password) {
        return (username == adminUsername && password == adminPassword);
    }
    
    void clearInputBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
public:
    // Constructor
    LoginSystem() : adminUsername("admin"), adminPassword("password123"), 
                    maxLoginAttempts(3), currentAttempts(0), isLoggedIn(false) {
        cout << "LoginSystem initialized!" << endl;
    }
    
    // Public login method
    bool attemptLogin() {
        cout << "\n" << string(40, '=') << endl;
        cout << "         LOGIN SYSTEM" << endl;
        cout << string(40, '=') << endl;
        
        while (currentAttempts < maxLoginAttempts) {
            string username, password;
            
            cout << "Username: ";
            cin >> username;
            
            password = getSecurePassword();
            
            if (verifyCredentials(username, password)) {
                isLoggedIn = true;
                currentAttempts = 0; // Reset attempts
                cout << "\n✓ Login successful! Welcome, " << username << "!" << endl;
                return true;
            } else {
                currentAttempts++;
                int remaining = maxLoginAttempts - currentAttempts;
                cout << "\n✗ Invalid credentials! Attempts remaining: " << remaining << endl;
                
                if (remaining > 0) {
                    cout << "Press Enter to try again...";
                    cin.get();
                }
            }
            
            clearInputBuffer();
        }
        
        cout << "\n✗ Account locked! Contact administrator." << endl;
        return false;
    }
    
    // Public dashboard methods
    void showDashboard() {
        if (!isLoggedIn) {
            cout << "Error: Must login first!" << endl;
            return;
        }
        
        cout << "\n" << string(30, '-') << " DASHBOARD " << string(30, '-') << endl;
        cout << "1. View Profile" << endl;
        cout << "2. Change Password" << endl;
        cout << "3. View Login Stats" << endl;
        cout << "4. Logout" << endl;
        cout << string(65, '-') << endl;
    }
    
    void viewProfile() {
        if (!isLoggedIn) return;
        cout << "\nProfile Information:" << endl;
        cout << "Username: " << adminUsername << endl;
        cout << "Status: Active" << endl;
        cout << "Last Login: " << getCurrentTime() << endl;
    }
    
    bool changePassword() {
        if (!isLoggedIn) return false;
        
        string oldPassword, newPassword, confirmPassword;
        
        cout << "\nChange Password:" << endl;
        cout << "Enter current password: ";
        oldPassword = getSecurePassword();
        
        if (oldPassword != adminPassword) {
            cout << "✗ Current password incorrect!" << endl;
            return false;
        }
        
        cout << "Enter new password: ";
        newPassword = getSecurePassword();
        cout << "Confirm new password: ";
        confirmPassword = getSecurePassword();
        
        if (newPassword == confirmPassword && newPassword.length() >= 6) {
            adminPassword = newPassword;
            cout << "✓ Password changed successfully!" << endl;
            return true;
        } else {
            cout << "✗ Passwords don't match or too short!" << endl;
            return false;
        }
    }
    
    void showStats() {
        cout << "\nLogin Statistics:" << endl;
        cout << "Max attempts: " << maxLoginAttempts << endl;
        cout << "Current attempts used: " << currentAttempts << endl;
        cout << "Logged in: " << (isLoggedIn ? "Yes" : "No") << endl;
    }
    
    void logout() {
        isLoggedIn = false;
        currentAttempts = 0;
        cout << "\n✓ Logged out successfully!" << endl;
    }
    
    // Getters (public read-only access)
    bool getLoginStatus() const { return isLoggedIn; }
    string getCurrentUser() const { return adminUsername; }
    
private:
    // Private utility method
    string getCurrentTime() {
        // Simple timestamp (requires <ctime> for full implementation)
        return "2024-01-01 12:00:00";
    }
};

int main() {
    LoginSystem loginSys;
    
    cout << "=== Advanced C++ Login System (OOP) ===" << endl;
    
    // Login loop
    while (!loginSys.getLoginStatus()) {
        if (!loginSys.attemptLogin()) {
            cout << "\nPress Enter to exit...";
            cin.get();
            return 1;
        }
    }
    
    // Dashboard loop
    int choice;
    do {
        loginSys.showDashboard();
        cout << "Select option (0 to exit): ";
        cin >> choice;
        loginSys.clearInputBuffer(); // Add clearInputBuffer as public or use directly
        
        switch (choice) {
            case 1:
                loginSys.viewProfile();
                break;
            case 2:
                loginSys.changePassword();
                break;
            case 3:
                loginSys.showStats();
                break;
            case 4:
                loginSys.logout();
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
        
        if (loginSys.getLoginStatus() && choice != 0) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
        
    } while (choice != 0 && loginSys.getLoginStatus());
    
    return 0;
}
