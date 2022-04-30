#ifndef TEXT_EDITOR_EDITOR_H
#define TEXT_EDITOR_EDITOR_H

#include <string>

using namespace std;

/* Appends a file content to another */
void merge_file(const string &filename1, const string &filename2);

/* Gets number of words in a file
 * a word is a piece of text that is separated by any whitespace character (space, tab, newline) */
unsigned long long count_words_in_file(const string &filename);

/* Gets number of characters in a file */
unsigned long long count_characters_in_file(const string &filename);

/* Gets number of lines in a file */
unsigned long long count_lines_in_file(const string &filename);

/* Checks if word exists in file */
bool check_word_exists(const string &filename, string word);

#endif
