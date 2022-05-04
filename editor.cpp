#include <bits/stdc++.h>
#include "files.h"
#include "editor.h"

using namespace std;

/* Appends a file content to another */
void merge_file(const string &filename1, const string &filename2) {
    string file2Content = read_file(filename2);
    append_file(filename1, file2Content);
}

/* Gets number of words in a file
 * a word is a piece of text that is separated by any whitespace character (space, tab, newline) */
unsigned long long count_words(const string &text) {
    stringstream stream;
    stream << text;

    string curWord;
    unsigned long long count = 0;
    while (stream >> curWord) {
        count++;
    }
    return count;
}

/* Gets number of characters in a file */
unsigned long long count_characters(const string &text) {
    stringstream stream;
    stream << text;

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
unsigned long long count_lines(const string &text) {
    stringstream stream;
    stream << text;

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
bool check_word_exists(const string &text, string word) {
    stringstream stream;
    stream << text;

    for (auto &c: word) {
        c = (char) tolower(c);
    }

    string curWord;
    while (stream >> curWord) {
        for (auto &c: curWord) {
            c = (char) tolower(c);
        }
        if (curWord == word)
            return true;
    }
    return false;
}