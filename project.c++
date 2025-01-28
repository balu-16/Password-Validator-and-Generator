#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <string>
#include <algorithm>
#include <cctype>    // For isdigit, ispunct, isupper, islower
#include <random>

using namespace std;

// Base class to manage password validation and classification
class PasswordManager{
protected:
    string password;

    bool hasNumber(const string &pass){
        for(char ch : pass){
            if(isdigit(ch))
                return true;
        }
        return false;
    }

    bool hasSpecialCharacter(const string &pass){
        for(char ch : pass){
            if(ispunct(ch))
                return true;
        }
        return false;
    }

    bool hasUpperAndLower(const string &pass){
        bool hasUpper = false, hasLower = false;
        for(char ch : pass){
            if(isupper(ch))
                hasUpper = true;
            if(islower(ch))
                hasLower = true;
        }
        return hasUpper && hasLower;
    }

public:
    // Default Constructor
    PasswordManager(){
        
    }

    // PasswordManager(const string &pass) : password(pass) {}
    PasswordManager(const string &pass){
        password = pass;
    }

    // Setter for the password
    void setPassword(const string &pass){
        password = pass;
    }

    // Function to classify password strength
    void validateAndClassifyPassword(){
        try {
            if(password.length() < 8){
                throw runtime_error("Error: Password must be at least 8 characters long.");
            }
            if(!hasNumber(password)){
                throw runtime_error("Error: Password must contain at least one number.");
            }
            if(!hasSpecialCharacter(password)){
                throw runtime_error("Error: Password must contain at least one special character.");
            }

            bool containsUpperLower = hasUpperAndLower(password);

            if(password.length() >= 12 || containsUpperLower){
                cout << "Password is strong!\n" << endl;
            }else if(password.length() >= 9){
                cout << "Password is better.\n" << endl;
            }else{
                cout << "Password is weak.\n" << endl;
            }

        }catch(const runtime_error &e){
            cout << e.what() << endl;
        }
    }

    // Destructor
    ~PasswordManager() {
        cout << "\nPasswordManager object is being destroyed." << endl;
    }
};

// Derived class to generate a random password
class PasswordGenerator : public PasswordManager{
private:
    int length;
    string nameChars;
    string dateNumbers;

    // Function to generate a random character from a given string
    char getRandomChar(const string &charSet){
        int index = rand() % charSet.length();
        return charSet[index];
    }

public:
    // Constructor to set the password length and customize name and date chars
    PasswordGenerator(int len, const string &firstName, const string &lastName, int date, int month, int year) : PasswordManager(""){
        length = len;
        
        // Combine characters from the first name and last name for the password
        nameChars = firstName + lastName;
    
        // Convert date, month, and year to a string for number use
        dateNumbers = to_string(date) + to_string(month) + to_string(year);
    }

    // Function to generate the password
    string generatePassword(){
        password = "";

        // Character sets for the password, including customized characters
        string specialChars = "!@#$%^&*()";

        // Ensure password contains at least one character from each customized set
        password += getRandomChar(nameChars);        // Add a random character from nameChars
        password += getRandomChar(specialChars);     // Add a random special character
        password += getRandomChar(dateNumbers);      // Add a random number from dateNumbers

        // Fill the rest of the password with random characters from all sets
        string allChars = specialChars + nameChars + dateNumbers;
        for(int i = 3;i < length;i++){ // Start from 3 since 3 characters are already added
            password += getRandomChar(allChars);
        }

        // Shuffle the password characters randomly
        random_shuffle(password.begin(), password.end());

        return password;
    }

    // Destructor
    ~PasswordGenerator(){
        cout << "\nPasswordGenerator object is being destroyed." << endl;
    }
};

int main(){
    srand(time(0)); // Seed the random number generator with current time

    string firstName, department, lastName, email;
    int date, month, year, experience;
    char choice, publications;
    long int phoneNum;
       
    cout << "Enter your Phone Number: ";
    cin >> phoneNum;
    
    cout << "Enter you email-id: ";
    cin >> email;
    
    cout << "Enter your First Name: ";
    cin >> firstName;

    cout << "Enter your Last Name: ";
    cin >> lastName;
    
    cout << "Do you have any research Publications(Y|N): ";
    cin >> publications;
    
    cout << "How many years of experience do you have? ";
    cin >> experience;

    cout << "Enter your Department: ";
    cin >> department;

    cout << "Enter your Date Of Birth (dd mm yyyy): ";
    cin >> date >> month >> year;

    while(true){
        cout << "\nEnter your Password(e):\n\tor\t\nShall I Suggest a Password(g): ";
        cin >> choice;

        if(choice == 'g'){
            int passwordLength;
            cout << "\nEnter the desired password length (minimum 8): ";
            cin >> passwordLength;

            if(passwordLength < 8){
                cout << "Error: Password length must be at least 8 characters." << endl;
                continue;
            }

            PasswordGenerator generator(passwordLength, firstName, lastName, date, month, year);
            string generatedPassword = generator.generatePassword();
            cout << "Generated password: " << generatedPassword << endl;

            generator.validateAndClassifyPassword();

            char likeOrNot;
            cout << "Do you like the password? (y for YES and n for NO): ";
            cin >> likeOrNot;

            if(tolower(likeOrNot) == 'y')
                break;
            else
                continue;
            
        }else if(choice == 'e'){
            string enteredPassword, confirmedPassword;

            while(true){
                cout << "\nEnter your Password: ";
                cin >> enteredPassword;

                cout << "Confirm your Password: ";
                cin >> confirmedPassword;

                if(enteredPassword == confirmedPassword){
                    PasswordManager manager;
                    manager.setPassword(enteredPassword);  // Use the setter instead of direct access
                    manager.validateAndClassifyPassword();
                    break;
                }else{
                    cout << "The password you entered does not match the confirmed password! 
                    Please try again!" << endl;
                }
            }
            break;
        }else{
            cout << "Invalid choice. Please enter 'g' or 'e'." << endl;
        }
    }

    return 0;
}
