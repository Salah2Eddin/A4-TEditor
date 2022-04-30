#include <bits/stdc++.h>
#include "editor.h"
#include "files.h"

using namespace std;

string mainFile;

//-----------------
void main_loop_operations_prints();

void main_loop();

int main() {
    cout << "Welcome to TEditor!" << endl;
    cout << "Please enter your file name:";
    cin >> mainFile;

    // adds extension if not added
    if (mainFile.size() < 4 || mainFile.compare(mainFile.size() - 4, 4, ".txt") != 0) {
        mainFile += ".txt";
    }

    if (is_file(mainFile)) {
        main_loop();
    } else {
        cout << "Your file doesn't exist. I created it for you." << endl;
        ofstream file(mainFile);
        file.close();
        main_loop();
    }
    return 0;
}

//-----------------
// Program Loops

void main_loop_operations_prints() {
    cout << "1. Add new text to the end of the file\n"
            "2. Display the content of the file\n"
            "3. Empty the file\n"
            "4. Encrypt the file content \n"
            "5. Decrypt the file content\n"
            "6. Merge another file\n"
            "7. Count the number of words in the file\n"
            "8. Count the number of characters in the file\n"
            "9. Count the number of lines in the file\n"
            "10. Search for a word in the file\n"
            "11. Count the number of times a word exists in the file\n"
            "12. Turn the file content to upper case.\n"
            "13. Turn the file content to lower case.\n"
            "14. Turn file content to 1st caps (1st char of each word is capital) \n"
            "15. Save\n"
            "16. Exit" << endl;
}

void main_loop() {
    bool loop = true;
    while (loop) {
        int operation;
        cout << endl;
        main_loop_operations_prints();
        cout << "Operation No.";
        cin >> operation;
        switch (operation) {
            case 6: {
                string filename2;
                cout << "Please enter second file name: ";
                cin >> filename2;

                if (filename2.size() < 4 || filename2.compare(filename2.size() - 4, 4, ".txt") != 0) {
                    filename2 += ".txt";
                }

                while (!is_file(filename2)) {
                    cout << "This file doesn't exist!" << endl;
                    cout << "Please enter second file name: ";
                    cin >> filename2;
                }
                merge_file(mainFile, filename2);
                break;
            }
            case 7: {
                unsigned long long size;
                size = count_words_in_file(mainFile);
                cout << "Number of words in file: " << size << endl;
                break;
            }
            case 8: {
                unsigned long long size;
                size = count_characters_in_file(mainFile);
                cout << "Number of characters in file: " << size << endl;
                break;
            }
            case 9: {
                unsigned long long size;
                size = count_lines_in_file(mainFile);
                cout << "Number of lines in file: " << size << endl;
                break;
            }
            case 10: {
                string word;
                cout << "Word:";
                cin >> word;
                if (check_word_exists(mainFile, word)) {
                    cout << "Word was found in the file." << endl;
                } else {
                    cout << "Word was not found in the file." << endl;
                }
                break;
            }
            case 16: {
                loop = false;
                break;
            }
            default: {
                cout << "Invalid operation!" << endl;
                break;
            }
        }
    }
}
