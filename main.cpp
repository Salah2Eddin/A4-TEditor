#include <bits/stdc++.h>
#include "files.cpp"

using namespace std;

string mainFile;

//-----------------
void main_loop_operations_prints();

void main_loop();

//-----------------
void merge_file(const string &filename1, const string &filename2);

unsigned long long count_words_in_file(const string &filename);

unsigned long long count_characters_in_file(const string &filename);

unsigned long long count_lines_in_file(const string &filename);

bool check_word_exists(const string &filename, string word);
//-----------------

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
            case 1:
                break;
            case 6: {
                string filename2;
                cout << "Please enter second file name: ";
                cin >> filename2;
                merge_file(mainFile, filename2);
                break;
            }
            case 7: {
                unsigned long long size = 0;
                size = count_words_in_file(mainFile);
                cout << "Number of words in file: " << size << endl;
                break;
            }
            case 8: {
                unsigned long long size = 0;
                size = count_characters_in_file(mainFile);
                cout << "Number of characters in file: " << size << endl;
                break;
            }
            case 9: {
                unsigned long long size = 0;
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

//-----------------

/* Appends a file content to another */
void merge_file(const string &filename1, const string &filename2) {
    string file2Content = read_file(filename2);
    append_file(filename1, file2Content);
}

/* Gets number of words in a file
 * a word is a piece of text that is separated by any whitespace character (space, tab, newline) */
unsigned long long count_words_in_file(const string &filename) {
    stringstream stream;
    stream << read_file(filename);

    string curWord;
    unsigned long long count = 0;
    while (stream >> curWord) {
        count++;
    }
    return count;
}

/* Gets number of characters in a file */
unsigned long long count_characters_in_file(const string &filename) {
    stringstream stream;
    stream << read_file(filename);

    string curWord;
    unsigned long long count = 0;
    while (stream >> curWord) {
        count += curWord.length();
        char nextChar = stream.peek();
        if (isspace(nextChar) && nextChar != '\n') {
            count++;
        }
    }
    return count;
}

/* Gets number of lines in a file */
unsigned long long count_lines_in_file(const string &filename) {
    stringstream stream;
    stream << read_file(filename);

    string curWord;
    unsigned long long count = 0;
    while (stream >> curWord) {
        char nextChar = stream.peek();
        if (nextChar == '\n') {
            count++;
        }
    }
    return count;
}

/* Checks if word exists in file */
bool check_word_exists(const string &filename, string word) {
    stringstream stream;
    stream << read_file(filename);

    for(auto &c : word){
        c = (char)tolower(c);
    }

    string curWord;
    while (stream >> curWord) {
        for(auto &c : curWord){
            c = (char)tolower(c);
        }
        if (curWord == word)
            return true;
    }
    return false;
}
