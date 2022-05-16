#ifndef TEXT_EDITOR_EDITOR_H
#define TEXT_EDITOR_EDITOR_H

#include <string>

using namespace std;

/* add new text at the end of the file */
void add_to_file(const string &filename, const string &text, bool isEmpty) ;

void display_file_content(const string &filename);

void empty_file(const string &filename);

string encrypt_text(const string &text);

string decrypt_text(const string &text);

/* Appends a file content to another */
void merge_file(const string &filename1, const string &filename2);

/* Gets number of words in a file
 * a word is a piece of text that is separated by any whitespace character (space, tab, newline) */
unsigned long long count_words(const string &text);

/* Gets number of characters in a file */
unsigned long long count_characters(const string &text);

/* Gets number of lines in a file */
unsigned long long count_lines(const string &text);

/* Checks if word exists in file */
bool check_word_exists(const string &text, string word);

string text_to_upper(string &text);

string text_to_lower(string &text);

string text_to_camel(string &text);

int count_word(const string &text, string word);

#endif
