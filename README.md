# 🔐 Password Manager and Generator 🚀

This C++ program provides a password manager and generator with password strength validation and classification.  It allows users to either enter their own password for evaluation or generate a strong, randomized password based on specified criteria.

## ✨ Features ✨

*   **Password Validation:** ✅ Checks if a user-provided password meets the following criteria:
    *   Minimum length of 8 characters.
    *   Contains at least one number.
    *   Contains at least one special character.
    *   (Optional, for stronger passwords) Contains both uppercase and lowercase letters.
*   **Password Strength Classification:** 💪 Classifies passwords as "weak," "better," or "strong" based on length and character composition.  Passwords of 12 or more characters, or those containing both upper and lowercase letters, are classified as "strong".
*   **Password Generation:** 💡 Generates random passwords of a specified length.  Generated passwords are customizable and incorporate elements from the user's first and last names, and date of birth, along with special characters, ensuring a mix of character types.  This helps create more memorable yet reasonably secure passwords.
*   **Customizable Character Sets:** ⚙️ The password generator uses a combination of user-provided information (name, date) and predefined special characters to create passwords.
*   **User Interaction:** 💬 The program interacts with the user through a command-line interface, prompting for input and displaying results.
*   **Error Handling:** ⚠️ Includes basic error handling, such as checking for minimum password length.
*   **Object-Oriented Design:** 💻 The code utilizes classes (`PasswordManager` and `PasswordGenerator`) to encapsulate functionality and promote code reusability.  `PasswordGenerator` inherits from `PasswordManager` to leverage password validation capabilities.

## 🧑‍💻 How to Use 🧑‍💻

1.  **Compilation:**  Compile the C++ code using a C++ compiler (e.g., g++):
    ```bash
    g++ password_manager.cpp -o password_manager
    ```
2.  **Execution:** Run the compiled executable:
    ```bash
    ./password_manager
    ```
3.  **Interaction:** Follow the prompts in the console to either enter your own password for validation or generate a new password.

## 📂 Code Structure 📂

*   `PasswordManager`: Base class responsible for password validation and strength classification.
*   `PasswordGenerator`: Derived class that inherits from `PasswordManager` and adds password generation functionality.

## 📝 Example Usage 📝
```bash
Enter your Phone Number: 1234567890
Enter you email-id: [email address removed]
Enter your First Name: John
Enter your Last Name: Doe
Do you have any research Publications(Y|N): N
How many years of experience do you have? 5
Enter your Department: Computer Science
Enter your Date Of Birth (dd mm yyyy): 15 03 1990

Enter your Password(e):
or
Shall I Suggest a Password(g): g

Enter the desired password length (minimum 8): 12
Generated password: J!3n9D0oe1539
Password is strong!

Do you like the password? (y for YES and n for NO): y
```
## 🛠️ Future Improvements 🛠️

*   More robust error handling and input validation.
*   Support for storing and retrieving passwords (securely, of course!).  This would likely involve encryption or integration with a secure password manager.
*   Improved password generation algorithms to increase randomness and security.
*   A graphical user interface (GUI) for easier interaction.
*   Integration with online password strength checkers.

## 🙌 Contributing 🙌

Contributions are welcome!  Please feel free to submit pull requests or open issues.

---

## License
This project is licensed as **proprietary and confidential**.  
**You may not reuse, modify, or redistribute any part of this code.**
