//
// Created by Salah on 30/04/2022.
//

#ifndef TEXT_EDITOR_FILES_H
#define TEXT_EDITOR_FILES_H

#include <string>
using namespace std;

/* Checks if file exists */
bool is_file(const string &filename);

/*Reads file content
 *If file doesn't exist, it prints an error*/
string read_file(const string &filename);

/* overwrites file content
 *if file doesn't exist, creates it */
void overwrite_file(const string &filename, const string &text);

/* appends text at the end of a file
 *if file doesn't exist, creates it */
void append_file(const string &filename, const string &text);

#endif //TEXT_EDITOR_FILES_H
