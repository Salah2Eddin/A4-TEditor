#include<bits/stdc++.h>
#include "files.h"
#include "editor.h"

using namespace std;
/*
void Add_to_file(const string &filename, const string &text){
          cin.ignore();
          getline(cin ,text,'\n');
          filename<<text;
}
void Display_the_content(const string &filename){
     stringstream stream ;
            while(getline(filename,stream)){
               cout<<stream<<endl;
            }
}
void Empty (){
     myFile.open(File ,ios:: out |  ios::trunc);
}
void Encrypt (){
    myFile.open(File , ios::in);
    if(myFile.is_open()){
               string line , allFile;
               while(getline(myFile,line)){
                 allFile +=line;
                 allFile +='\n';
               }
               myFile.close();
               myFile.open(File , ios::out);
               string encrypt;
                   for(int i = 0 ; i<allFile.size(); i++){
                        if(allFile[i] == '\n'){
                            encrypt +='\n';
                        }else{
                       char e = allFile[i]+1;
                       encrypt+=e;

                        }
               }

                         myFile<<encrypt<<endl;
                         myFile.close();
    }
}
void Decrypt (){
     myFile.open(File , ios::in);
    if(myFile.is_open()){
               string line , allFile;
               while(getline(myFile,line)){
                 allFile +=line;
                 allFile +='\n';
               }
               myFile.close();
               myFile.open(File , ios::out);
               string encrypt;
                   for(int i = 0 ; i<allFile.size(); i++){
                        if(allFile[i] == '\n'){
                            encrypt +='\n';
                        }else{
                       char e = allFile[i]-1;
                       encrypt+=e;

                        }
               }

                         myFile<<encrypt<<endl;
                         myFile.close();
    }
}

*/

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

int count_word(const string &text, string word) {
    stringstream stream;
    int nWord = 0;
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
            nWord++;
    }
    return nWord;
}


string text_to_upper(string &text) {
    string uWord;
    stringstream inStream, outStream;

    inStream << text;
    while (inStream >> uWord) {
        for (char &i: uWord) {
            i = toupper(i);
        }
        outStream << uWord << (char) inStream.peek();

    }
    return outStream.str();
}


string text_to_lower(string &text) {
    string uWord;
    stringstream inStream, outStream;

    inStream << text;
    while (inStream >> uWord) {
        for (char &i: uWord) {
            i = tolower(i);
        }
        outStream << uWord << (char) inStream.peek();

    }
    return outStream.str();
}


string text_to_camel(string &text) {
    string uWord;
    stringstream inStream, outStream;

    inStream << text;
    while (inStream >> uWord) {
        uWord[0] = toupper(uWord[0]);

        outStream << uWord << (char) inStream.peek();

    }
    return outStream.str();
}