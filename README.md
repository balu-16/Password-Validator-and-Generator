# Password Manager and Generator

This C++ program provides a password manager and generator with password strength validation and classification.  It allows users to either enter their own password for evaluation or generate a strong, randomized password based on specified criteria.

## Features

* **Password Validation:** Checks if a user-provided password meets the following criteria:
    * Minimum length of 8 characters.
    * Contains at least one number.
    * Contains at least one special character.
    * (Optional, for stronger passwords) Contains both uppercase and lowercase letters.
* **Password Strength Classification:** Classifies passwords as "weak," "better," or "strong" based on length and character composition.  Passwords of 12 or more characters, or those containing both upper and lowercase letters, are classified as "strong".
* **Password Generation:** Generates random passwords of a specified length.  Generated passwords are customizable and incorporate elements from the user's first and last names, and date of birth, along with special characters, ensuring a mix of character types.  This helps create more memorable yet reasonably secure passwords.
* **Customizable Character Sets:** The password generator uses a combination of user-provided information (name, date) and predefined special characters to create passwords.
* **User Interaction:**  The program interacts with the user through a command-line interface, prompting for input and displaying results.
* **Error Handling:** Includes basic error handling, such as checking for minimum password length.
* **Object-Oriented Design:**  The code utilizes classes (`PasswordManager` and `PasswordGenerator`) to encapsulate functionality and promote code reusability.  `PasswordGenerator` inherits from `PasswordManager` to leverage password validation capabilities.

## How to Use

1.  **Compilation:**  Compile the C++ code using a C++ compiler (e.g., g++):
    ```bash
    g++ password_manager.cpp -o password_manager
    ```
2.  **Execution:** Run the compiled executable:
    ```bash
    ./password_manager
    ```
3.  **Interaction:** Follow the prompts in the console to either enter your own password for validation or generate a new password.

## Code Structure

*   `PasswordManager`: Base class responsible for password validation and strength classification.
*   `PasswordGenerator`: Derived class that inherits from `PasswordManager` and adds password generation functionality.

## Example Usage
