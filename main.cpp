#include <bits/stdc++.h>

using namespace std;

string read_file(const string &filename);

void overwrite_file(const string &filename, const string &text);

void append_file(const string &filename, const string &text);

int main() {
    /*
    string filename = "xxxx.txt";

    string overwriteText = "Overwrite test";
    overwrite_file(filename, overwriteText);

    string appendText = "This Line Was Added Using C++!";
    append_file(filename, appendText);

    string fileContent = read_file(filename);
    cout << fileContent;
    */
    return 0;
}

/*Reads file content
 *If file doesn't exist, it prints an error*/
string read_file(const string &filename) {
    fstream stream(filename, ios::in);
    stringstream content;

    if (stream.fail()) {
        cout << "Unable to read file!";
    } else {
        string line;
        while (getline(stream, line)) {
            content << line << endl;
        }
        stream.close();
    }
    return content.str();
}

/* overwrites file content
 *if file doesn't exist, creates it */
void overwrite_file(const string &filename, const string &text) {
    fstream stream(filename, ios::out);
    if (stream.fail()) {
        cout << "Unable to read file!" << endl;
    } else {
        stream << text;
        stream.close();
    }
}

/* appends text at the end of a file
 *if file doesn't exist, creates it */
void append_file(const string &filename, const string &text) {
    fstream stream(filename, ios::app);
    if (stream.fail()) {
        cout << "Unable to read file!" << endl;
    } else {
        stream << endl << text;
        stream.close();
    }
}
