/**
 * CSC 249
 * M1T1 - Warmup
 * Harley Coughlin
 * 01/13/2025
 *
 * This definitely took longer than 30 minutes, though I didn't think that it
 * would.
 */

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string translate(const string& to_translate);

int main() {
    cout << "Welcome to the Pig Latin Translator.\n"
         << "Enter a phrase to see the pig latin translation: ";
    string phrase;
    getline(cin, phrase);
    cout << translate(phrase);
    return 0;
}


string translate(const string& to_translate) {
    string translated = "";
    const string vowels = "aeiou";

    istringstream stream(to_translate);
    string word;
    bool first_word = true;
    while (stream >> ws >> word) {
        if (!first_word) {
            translated += " ";
        }
        first_word = false;
        // Check to see if the word starts with a letter.
        if (isalpha(word[0])) {
            // Find the last letter of the word.
            int last_letter = word.length() - 1;
            while (last_letter > 0 && !isalpha(word[last_letter])) {
                last_letter--;
            }

            string non_letters = word.substr(last_letter + 1);
            string letters = word.substr(0, last_letter + 1);

            // Check the first letter to see if its a vowel.
            if (vowels.find(tolower(word[0])) != string::npos) {
                translated += letters + "hay" + non_letters;
            } else { 
                // If beginning letter is consonant.
                int first_vowel = 0;
                while (first_vowel < letters.length() &&
                       vowels.find(tolower(letters[first_vowel])) == string::npos) {
                    first_vowel++;
                }

                // Translate.
                translated += letters.substr(first_vowel) +
                              letters.substr(0, first_vowel) + "ay" +
                              non_letters;
            }
        } else { 
            // If the word doesn't start with a letter, just add it.
            translated += word;
        }
    }

    translated += '\n';

    if (to_translate.empty() || translated == "\n") {
        translated = "There was no input to translate.\n";
    }
    return translated;
}
