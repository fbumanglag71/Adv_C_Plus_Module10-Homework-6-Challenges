//Francisco Bumanglag
//Date: September 4, 2024
//Chapter 10 Assignments -- CMPR121 Chapter 10 C-Strings and Strings

#include <iostream>     //for input-output operations
#include <string>       //for string handling
#include <cctype>       //for isspace(), isupper(), and isdigit() functions
#include <cstring>      //for C-string handling
#include <algorithm>    //for any_of function
//#include "input.h"    //code from professor -- didnt use or need


using namespace std;    //simplifies code syntax


//function prototypes
void challenge3();      //for challenge3 function (Word Counter)
void challenge6();      //for challenge6 function (Vowels and Consonants)
void challenge8();      //for challenge8 function (Sum of digits in a string)
//void challenge10();   //code include but commented out -- interferes with main form
void challenge12();     //for challenge12 function (Password Verifier)

//function -- check if user inputs an integer
int inputInteger(const string& promptMessage, int minValue, int maxValue) {
    //loop to get valid user input within range
    int userInput;
    do {
        cout << promptMessage;
        cin >> userInput;
        if (userInput < minValue || userInput > maxValue) {
            cout << "Invalid input. Please enter a number between " << minValue << " and " << maxValue << ".\n";
        }
    } while (userInput < minValue || userInput > maxValue);
    return userInput;
}

//          CHALLENGE 3            
//         WORD COUNTER

//function -- counting the words in C-String 
int countWordsInCstring(const char* str) {
    //count words by detecting space separators
    int wordCount = 0;
    bool inWord = false;

    while (*str) {
        if (isspace(*str)) {
            inWord = false;
        }
        else if (!inWord) {
            inWord = true;
            ++wordCount;
        }
        ++str;
    }
    return wordCount;
}

//function -- count words in the string 
int countWordsInString(const string& str) {
    //count words by detecting space separators
    int count = 0;
    bool inWord = false;

    for (char ch : str) {
        if (isspace(ch)) {
            inWord = false;
        }
        else if (!inWord) {
            inWord = true;
            ++count;
        }
    }
    return count;
}

//function -- challenge 3 sub form word counter
void challenge3() {
    //displays menu, takes user input, clears screen
    char usersChoice;
    do {
        system("cls");
        cout << "\n Challenge 3 -- Word Counter";
        cout << "\n" << string(80, char(205));
        cout << "\n A. C-string (array of characters)";
        cout << "\n B. String (object)";
        cout << "\n" << string(80, char(196));
        cout << "\n R. Return";
        cout << "\n" << string(80, char(205));
        cout << "\n Option: ";
        cin >> usersChoice;
        cin.ignore();

        //error checks -- user must enter a valid option (A/a, B/b or R/r)
        while (usersChoice != 'A' && usersChoice != 'a' &&
            usersChoice != 'B' && usersChoice != 'b' &&
            usersChoice != 'R' && usersChoice != 'r') {
            cout << "\n Not a valid option, try again.\n";
            cout << "\n Option: ";
            cin >> usersChoice;
            cin.ignore();
        }

        //choice A, counts words and pauses execution
        if (usersChoice == 'A' || usersChoice == 'a') {
            const int SIZE = 256;
            char cstr[SIZE];
            cout << "\n Enter a C-string (array of characters): ";
            cin.getline(cstr, SIZE);
            int wordCount = countWordsInCstring(cstr);
            cout << "\n # of word(s) in the C-string (array of characters): " << wordCount << "\n";
            system("pause");  //wait for the user to select return 
        }
        //choice B, counts words and pauses execution
        else if (usersChoice == 'B' || usersChoice == 'b') {
            string str;
            cout << "\n Enter a string (object): ";
            getline(cin, str);
            int wordCount = countWordsInString(str);
            cout << "\n # of word(s) in the string (object): " << wordCount << "\n";
            system("pause");  //wait for the user to select return 
        }
    } while (usersChoice != 'R' && usersChoice != 'r'); //returns the user to the main screen 
}

//             CHALLENGE 6
//        VOWELS AND CONSONANTS

//function to count vowels in C-string (array of characters)
int countVowelsCStr(const char* cStr) {
    int vowelCount = 0;
    for (int i = 0; cStr[i] != '\0'; i++) {
        char ch = tolower(cStr[i]);  //convert to lowercase for easier comparison
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCount++;
        }
    }
    return vowelCount;
}

//function to count consonants in C-string (array of characters)
int countConsonantsCStr(const char* cStr) {
    int consonantCount = 0;
    for (int i = 0; cStr[i] != '\0'; i++) {
        char ch = tolower(cStr[i]);  //convert to lowercase for easier comparison
        if (isalpha(ch) && !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
            consonantCount++;
        }
    }
    return consonantCount;
}

//function to count vowels in string object
int countVowelsStr(const string& str) {
    int vowelCount = 0;
    for (size_t i = 0; i < str.length(); i++) {
        char ch = tolower(str[i]);  //convert to lowercase for easier comparison
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCount++;
        }
    }
    return vowelCount;
}

//function to count consonants in string object
int countConsonantsStr(const string& str) {
    int consonantCount = 0;
    for (size_t i = 0; i < str.length(); i++) {
        char ch = tolower(str[i]);  //convert to lowercase for easier comparison
        if (isalpha(ch) && !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
            consonantCount++;
        }
    }
    return consonantCount;
}

//function -- challenge 6 (vowels and consonants)
void challenge6() {
    char subOption;
    char inputCStr[256];
    string inputStr;

    do {
        //clear screen, display main options
        system("cls");
        cout << "\nChallenge 6 - Vowels and Consonants";
        cout << "\n" << string(80, char(205));
        cout << "\nA. Enter a C-string (array of characters)";
        cout << "\nB. Enter a string (object)";
        cout << "\nR. Return";
        cout << "\n" << string(80, char(205));
        cout << "\nOption: ";
        cin >> subOption;
        cin.ignore();  //clear input buffer

        if (subOption == 'A' || subOption == 'a') {
            cout << "Enter a C-string (array of characters): ";
            cin.getline(inputCStr, 256);  //get C-string input

            do {
                //clear screen, display sub-options for C-string
                system("cls");
                cout << "\nC-string (array of characters): " << inputCStr;
                cout << "\nChallenge 6 - Vowels and Consonants";
                cout << "\n" << string(80, char(205));
                cout << "\nA. Count the number of vowels";
                cout << "\nB. Count the number of consonants";
                cout << "\nC. Count both vowels and consonants";
                cout << "\nD. Enter a new C-string (array of characters)";
                cout << "\n" << string(80, char(196));
                cout << "\nR. Return";
                cout << "\n" << string(80, char(205));
                cout << "\nOption: ";
                cin >> subOption;
                cin.ignore();  //clear input buffer

                if (subOption == 'A' || subOption == 'a') {
                    int vowels = countVowelsCStr(inputCStr);
                    cout << "Number of vowel(s): " << vowels << endl;
                }
                else if (subOption == 'B' || subOption == 'b') {
                    int consonants = countConsonantsCStr(inputCStr);
                    cout << "Number of consonant(s): " << consonants << endl;
                }
                else if (subOption == 'C' || subOption == 'c') {
                    int vowels = countVowelsCStr(inputCStr);
                    int consonants = countConsonantsCStr(inputCStr);
                    cout << "Number of vowel(s): " << vowels << endl;
                    cout << "Number of consonant(s): " << consonants << endl;
                }
                else if (subOption == 'D' || subOption == 'd') {
                    cout << "Enter a new C-string (array of characters): ";
                    cin.getline(inputCStr, 256);  //get new C-string
                }

                system("pause");  //pause before clearing screen

            } while (subOption != 'R' && subOption != 'r');  //loop until 'R'
        }
        else if (subOption == 'B' || subOption == 'b') {
            cout << "Enter a string (object): ";
            getline(cin, inputStr);  //get string input

            do {
                //clear screen, display sub-options for string
                system("cls");
                cout << "\nString (object): " << inputStr;
                cout << "\nChallenge 6 - Vowels and Consonants";
                cout << "\n" << string(80, char(205));
                cout << "\nA. Count the number of vowels";
                cout << "\nB. Count the number of consonants";
                cout << "\nC. Count both vowels and consonants";
                cout << "\nD. Enter a new string (object)";
                cout << "\n" << string(80, char(196));
                cout << "\nR. Return";
                cout << "\n" << string(80, char(205));
                cout << "\nOption: ";
                cin >> subOption;
                cin.ignore();  //clear input buffer

                if (subOption == 'A' || subOption == 'a') {
                    int vowels = countVowelsStr(inputStr);
                    cout << "Number of vowel(s): " << vowels << endl;
                }
                else if (subOption == 'B' || subOption == 'b') {
                    int consonants = countConsonantsStr(inputStr);
                    cout << "Number of consonant(s): " << consonants << endl;
                }
                else if (subOption == 'C' || subOption == 'c') {
                    int vowels = countVowelsStr(inputStr);
                    int consonants = countConsonantsStr(inputStr);
                    cout << "Number of vowel(s): " << vowels << endl;
                    cout << "Number of consonant(s): " << consonants << endl;
                }
                else if (subOption == 'D' || subOption == 'd') {
                    cout << "Enter a new string (object): ";
                    getline(cin, inputStr);  //get new string
                }

                system("pause");  //pause before clearing screen

            } while (subOption != 'R' && subOption != 'r');  //loop until 'R'
        }

    } while (subOption != 'R' && subOption != 'r');  //return when 'R' chosen
}

//              CHALLENGE 8 
//        SUM OF DIGITS IN STRING

//function to sum digits in a string
void challenge8() {
    char choice;
    do {
        system("cls");
        cout << "\n Sum of digits in a string";
        cout << "\n" << string(80, char(205));
        cout << "\n A. C-string (array of characters)";
        cout << "\n B. String (object)";
        cout << "\n" << string(80, char(196));
        cout << "\n R. Return";
        cout << "\n" << string(80, char(205));
        cout << "\n Option: ";
        cin >> choice;
        cin.ignore();

        //validate user input
        while (choice != 'A' && choice != 'a' &&
            choice != 'B' && choice != 'b' &&
            choice != 'R' && choice != 'r') {
            cout << "\n Invalid option, try again.\n";
            cout << "\n Option: ";
            cin >> choice;
            cin.ignore();
        }

        //handle C-string input
        if (choice == 'A' || choice == 'a') {
            const int SIZE = 256;
            char inputStr[SIZE];
            cout << "\n Enter a C-string of numbers (any combination from 0 to 9):  ";
            cin.getline(inputStr, SIZE);

            int total = 0;
            int digitCount[10] = { 0 }; //array holds digit frequencies
            int maxDigit = -1, minDigit = 10;

            //loop through C-string, sum digits, track frequency
            for (int i = 0; inputStr[i] != '\0'; i++) {
                if (isdigit(inputStr[i])) {
                    int num = inputStr[i] - '0'; //convert char to integer
                    total += num;
                    digitCount[num]++;

                    if (num > maxDigit) maxDigit = num;
                    if (num < minDigit) minDigit = num;
                }
            }

            //display sum, frequencies, and min/max digits
            cout << "\n Sum: " << total;
            cout << "\n Digit frequencies:";
            cout << "\n" << string(20, char(205));
            for (int i = 0; i < 10; i++) {
                cout << "\n " << i << " : " << digitCount[i];
            }
            cout << "\n" << string(20, char(196));
            cout << "\n Highest digit: " << maxDigit;
            cout << "\n Lowest digit: " << minDigit;
            cout << "\n";

            system("pause");
        }
        //handle string object input
        else if (choice == 'B' || choice == 'b') {
            string inputStr;
            cout << "\n Enter a string of numbers (any combination from 0 to 9): ";
            getline(cin, inputStr);

            int total = 0;
            int digitCount[10] = { 0 }; //array holds digit frequencies
            int maxDigit = -1, minDigit = 10;

            //loop through string, sum digits, track frequency
            for (char ch : inputStr) {
                if (isdigit(ch)) {
                    int num = ch - '0'; //convert char to integer
                    total += num;
                    digitCount[num]++;

                    if (num > maxDigit) maxDigit = num;
                    if (num < minDigit) minDigit = num;
                }
            }

            //display sum, frequencies, and min/max digits
            cout << "\n Sum: " << total;
            cout << "\n Digit frequencies:";
            cout << "\n" << string(20, char(205));
            for (int i = 0; i < 10; i++) {
                cout << "\n " << i << " : " << digitCount[i];
            }
            cout << "\n" << string(20, char(196));
            cout << "\n Highest digit: " << maxDigit;
            cout << "\n Lowest digit: " << minDigit;
            cout << "\n";

            system("pause");
        }
    } while (choice != 'R' && choice != 'r');
}

////                CHALLENGE 10
////         REPLACESUBSTRING FUNCTION
////       CODE INCLUDED BUT COMMENTED OUT 
////  INTERFERES WITH MAIN FORM (INT MAIN FUNCTION) 

////function -- challenge 10
//void challenge10() {
//    //displays menu, takes user input, clears screen
//    char usersChoice;
//    do {
//        system("cls");
//        cout << "\n Challenge 10 – Replace Substring";
//        cout << "\n" << string(80, char(205));
//        cout << "\n A. Replace substring in C-string";
//        cout << "\n B. Replace substring in string object";
//        cout << "\n" << string(80, char(196));
//        cout << "\n R. Return";
//        cout << "\n" << string(80, char(205));
//        cout << "\n Option: ";
//        cin >> usersChoice;
//        cin.ignore();
//
//        //error checks -- user must enter a valid option (A/a, B/b, or R/r)
//        while (usersChoice != 'A' && usersChoice != 'a' &&
//            usersChoice != 'B' && usersChoice != 'b' &&
//            usersChoice != 'R' && usersChoice != 'r') {
//            cout << "\n Not a valid option, try again.\n";
//            cout << "\n Option: ";
//            cin >> usersChoice;
//            cin.ignore();
//        }
//
//        //choice A, finds and replaces word, then pauses
//        if (usersChoice == 'A' || usersChoice == 'a') {
//            const int SIZE = 256;
//            char cstr[SIZE];
//            cout << "\n Enter a C-string (array of characters): ";
//            cin.getline(cstr, SIZE);
//            string orig = cstr; // Convert C-string to std::string before using replaceSubstring
//            string rep = "the";
//            string with = "that";
//            cout << "\n Original string: " << orig << endl;
//            cout << " Modified string: " << replaceSubstring(orig, rep, with) << endl;
//            system("pause"); //wait for user input
//        }
//        //choice B, finds and replaces word, then pauses
//        else if (usersChoice == 'B' || usersChoice == 'b') {
//            string str;
//            cout << "\n Enter a string (object): ";
//            getline(cin, str);
//            string orig = "the dog jumped over the fence";
//            string rep = "the";
//            string with = "that";
//            cout << "\n Original string: " << orig << endl;
//            cout << " Modified string: " << replaceSubstring(orig, rep, with) << endl;
//            system("pause"); //wait for user input
//        }
//    } while (usersChoice != 'R' && usersChoice != 'r');
//}
//
////function to replace all occurrences of 'replace_string' with 'with_string' in 'orig_str'
//string replaceSubstring(string orig_str, const string& replace_string, const string& with_string) {
//    size_t pos = 0; //keep replacing occurrences of 'replace_string' until none are found
//    while ((pos = orig_str.find(replace_string, pos)) != string::npos) {
//        orig_str.replace(pos, replace_string.length(), with_string);
//        pos += with_string.length(); //move past the last replaced string
//    }
//    return orig_str;
//}


//            CHALLENGE 12 
//        PASSWORD VERIFIER

//function -- verify password criteria
bool verifyPassword(const string& password) {
    bool hasUpper = false, hasDigit = false;
    bool lengthOk = password.length() >= 6;

    //check each character in the password
    for (char ch : password) {
        if (isupper(ch)) hasUpper = true;
        if (isdigit(ch)) hasDigit = true;
    }

    //return true if all conditions are met
    return lengthOk && hasUpper && hasDigit;
}

//function -- challenge 12
void challenge12() {
    //displays menu, takes user input, clears screen
    char usersChoice;
    do {
        system("cls");
        cout << "\n Challenge 12 -- Password Verifier";
        cout << "\n" << string(80, char(205));
        cout << "\n A. C-string (array of characters)";
        cout << "\n B. String (obj)";
        cout << "\n" << string(80, char(196));
        cout << "\n R. Return";
        cout << "\n" << string(80, char(205));
        cout << "\n Option: ";
        cin >> usersChoice;
        cin.ignore();

        //error checks -- user must enter a valid option (A/a, B/b, or R/r)
        while (usersChoice != 'A' && usersChoice != 'a' &&
            usersChoice != 'B' && usersChoice != 'b' &&
            usersChoice != 'R' && usersChoice != 'r') {
            cout << "\n Not a valid option, try again.\n";
            cout << "\n Option: ";
            cin >> usersChoice;
            cin.ignore();
        }

        //choice A, verifies C-string password
        if (usersChoice == 'A' || usersChoice == 'a') {
            const int SIZE = 256;
            char cstr[SIZE];
            string password;
            bool validPassword = false;

            while (!validPassword) {
                cout << "\n Enter a password (C-string) to verify: ";
                cin.getline(cstr, SIZE);
                password = cstr;
                validPassword = verifyPassword(password);

                if (password.length() < 6) {
                    cout << "ERROR: The password must be at least 6 characters long.\n";
                }
                else if (!any_of(password.begin(), password.end(), ::isupper)) {
                    cout << "ERROR: The password must contain at least one uppercase character.\n";
                }
                else if (!any_of(password.begin(), password.end(), ::isdigit)) {
                    cout << "ERROR: The password must contain at least one digit.\n";
                }
                else if (validPassword) {
                    cout << "Password, " << password << ", meets all criteria.\n";
                }
            }
            system("pause"); //wait for the user to select return 
        }
        //choice B, verifies string password
        else if (usersChoice == 'B' || usersChoice == 'b') {
            string password;
            bool validPassword = false;

            while (!validPassword) {
                cout << "\n Enter a password (String) to verify: ";
                getline(cin, password);
                validPassword = verifyPassword(password);

                if (password.length() < 6) {
                    cout << "ERROR: The password must be at least 6 characters long.\n";
                }
                else if (!any_of(password.begin(), password.end(), ::isupper)) {
                    cout << "ERROR: The password must contain at least one uppercase character.\n";
                }
                else if (!any_of(password.begin(), password.end(), ::isdigit)) {
                    cout << "ERROR: The password must contain at least one digit.\n";
                }
                else if (validPassword) {
                    cout << "Password, " << password << ", meets all criteria.\n";
                }
            }
            system("pause"); //wait for the user to select return 
        }
    } while (usersChoice != 'R' && usersChoice != 'r'); //repeat until user chooses to return
}

//        CHALLENGE 13
//        DATE PRINTER

//function -- convert and print date in the desired format
void challenge13() {
    //displays menu, takes user input
    char option;
    do {
        system("cls");
        cout << "\n Challenge 13 -- Date Printer";
        cout << "\n" << string(80, char(205));
        cout << "\n A. C-string (array of characters)";
        cout << "\n B. String (obj)";
        cout << "\n" << string(80, char(196));
        cout << "\n R. Return";
        cout << "\n" << string(80, char(205));
        cout << "\n Option: ";
        cin >> option;
        cin.ignore();

        //error check -- valid option required
        while (option != 'A' && option != 'a' &&
            option != 'B' && option != 'b' &&
            option != 'R' && option != 'r') {
            cout << "\n Not a valid option, try again.\n";
            cout << "\n Option: ";
            cin >> option;
            cin.ignore();
        }

        //choice A -- C-string input
        if (option == 'A' || option == 'a') {
            const int BUFFER_SIZE = 256;
            char dateCstr[BUFFER_SIZE];
            cout << "\n Enter a date (C-string) with format mm/dd/yyyy: ";
            cin.getline(dateCstr, BUFFER_SIZE);

            //process date and print result
            string dateStr(dateCstr);
            //split the date into parts
            string monthStr = dateStr.substr(0, 2);
            string dayStr = dateStr.substr(3, 2);
            string yearStr = dateStr.substr(6, 4);
            //convert month from string to integer
            int month = stoi(monthStr);
            int day = stoi(dayStr);
            int year = stoi(yearStr);

            //array of month names
            const string months[] = { "Invalid", "January", "February", "March", "April", "May", "June",
                                      "July", "August", "September", "October", "November", "December" };

            //print formatted date
            if (month >= 1 && month <= 12 && day >= 1 && day <= 31) {
                cout << months[month] << " " << day << ", " << year << endl;
            }
            else {
                cout << "Invalid date. Please use format mm/dd/yyyy." << endl;
            }
            system("pause"); //wait for the user to select return 

        }
        //choice B -- string input
        else if (option == 'B' || option == 'b') {
            string dateStr;
            cout << "\n Enter a date (string) with format mm/dd/yyyy: ";
            getline(cin, dateStr);

            //split the date into parts
            string monthStr = dateStr.substr(0, 2);
            string dayStr = dateStr.substr(3, 2);
            string yearStr = dateStr.substr(6, 4);
            //convert month from string to integer
            int month = stoi(monthStr);
            int day = stoi(dayStr);
            int year = stoi(yearStr);

            //array of month names
            const string months[] = { "Invalid", "January", "February", "March", "April", "May", "June",
                                      "July", "August", "September", "October", "November", "December" };

            //print formatted date
            if (month >= 1 && month <= 12 && day >= 1 && day <= 31) {
                cout << months[month] << " " << day << ", " << year << endl;
            }
            else {
                cout << "Invalid date. Please use format mm/dd/yyyy." << endl;
            }
            system("pause"); //wait for the user to select return 
        }

    } while (option != 'R' && option != 'r');
}



//main program
int main() {
    do {
        //displays main menu, clears screen, formats output
        system("cls");
        cout << "\n\tCMPR121: Chapter 10 - Char, C-Strings and Strings - assignments by Francisco Bumanglag";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t 3. Word Counter";
        cout << "\n\t 6. Vowels and Consonants";
        cout << "\n\t 8. Sum of digits in a string";
        cout << "\n\t10. Replace Substring Function (code included but commented out)";
        cout << "\n\t12. Password Verifier";
        cout << "\n\t13. Date Printer";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t 0. Exit";
        cout << "\n\t" << string(80, char(205));
        cout << "\n";

        //handles user choice, execute specific cases
        switch (inputInteger("\tOption: ", 0, 13))
        {
        case 0: exit(0);
        case 3: challenge3(); break;
        case 6: challenge6(); break;
        case 8: challenge8(); break;
        //case 10: challenge10(); break;
        case 12: challenge12(); break;
        case 13: challenge13(); break;
        default: cout << "\n\tERROR: Invalid option.\n";
        }
        system("pause");
    } while (true);

    return 0;  //exit program
}
