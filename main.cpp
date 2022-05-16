#include <bits/stdc++.h>
#include "editor.h"
#include "files.h"

using namespace std;

string mainFile;
string curText;

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
        curText = read_file(mainFile);
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
            case 1: {
                string text;
                cout << "Enter your text:";

                cin.ignore();
                getline(cin, text, '\n');
                add_to_file(mainFile, text, curText.empty());
                curText = read_file(mainFile);
                break;
            }
            case 2: {
                display_file_content(mainFile);
                break;
            }
            case 3: {
                empty_file(mainFile);
                curText.clear();
                break;
            }
            case 4: {
                curText = encrypt_text(curText);
                overwrite_file(mainFile, curText);
                break;
            }
            case 5 : {
                curText = decrypt_text(curText);
                overwrite_file(mainFile, curText);
                break;
            }
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
                curText = read_file(mainFile);
                break;
            }
            case 7: {
                unsigned long long size;
                size = count_words(curText);
                cout << "Number of words in file: " << size << endl;
                break;
            }
            case 8: {
                unsigned long long size;
                size = count_characters(curText);
                cout << "Number of characters in file: " << size << endl;
                break;
            }
            case 9: {
                unsigned long long size;
                size = count_lines(curText);
                cout << "Number of lines in file: " << size << endl;
                break;
            }
            case 10: {
                string word;
                cout << "Word:";
                cin >> word;
                if (check_word_exists(curText, word)) {
                    cout << "Word was found in the file." << endl;
                } else {
                    cout << "Word was not found in the file." << endl;
                }
                break;
            }
            case 11: {
                string word;
                unsigned long long size;
                cout << "Word:";
                cin >> word;
                size = count_word(curText, word);
                cout << "The word repeated: " << size << " times" << endl;
                break;
            }
            case 12: {
                curText = text_to_upper(curText);
                cout << "Text transformed to upper" << endl;
                overwrite_file(mainFile, curText);
                break;
            }
            case 13: {
                curText = text_to_lower(curText);
                cout << "Text transformed to lower" << endl;
                overwrite_file(mainFile, curText);
                break;
            }
            case 14: {
                curText = text_to_camel(curText);
                cout << "Text transformed to camelcase" << endl;
                overwrite_file(mainFile, curText);
                break;
            }
            case 15: {
                string filename;
                cout << "Enter filename:";
                cin >> filename;
                overwrite_file(filename, curText);
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
