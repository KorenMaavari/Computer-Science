/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


/*-------------------------------------------------------------------------
  Constants and definitions:
--------------------------------------------------------------------------*/

#define MASCULINE (1)
#define FEMININE (2)

#define UN (1)
#define UNO (2)
#define UNA (3)
#define UN_APOSTROPHE (4)


/* put your #defines and typedefs here*/
int get_gender(char* noun);
int get_indefinite_article(char* noun);
int get_length_indefinite_article(char* noun);
void add_indefinite_article(char* noun, char* noun_with_article);
void handle_indefinite_article(int max_length);


/*-------------------------------------------------------------------------
  Your implementation of the functions (describe what each function does)
 -------------------------------------------------------------------------*/

//gets a word and returns its last letter
char last_letter (char *word) {
    char the_last_letter = ' ';
    for (int i=0 ; ((('a' <= *(word+i)) && (*(word+i) <= 'z')) || (('A' <= *(word+i)) && (*(word+i) <= 'Z'))) ; i++) {
        the_last_letter = *(word+i);
    }
    return the_last_letter;
}

//gets a letter and returns if it's a vowel
bool vowel (char *letter) {
    bool res;
    if (*letter == 'a' || *letter == 'A' ||
        *letter == 'e' || *letter == 'E' ||
        *letter == 'i' || *letter == 'I' ||
        *letter == 'o' || *letter == 'O' ||
        *letter == 'u' || *letter == 'U' ||
        *letter == 'h' || *letter == 'H') {
        res = true;
    } else {
        res = false;
    }
    return res;
}

//gets a letter and returns if it's a whistling letter
bool whistling_letter (char *letter) {
    bool res;
    if (*letter == 'z' || *letter == 'Z' ||
        *letter == 'x' || *letter == 'X' ||
        *letter == 'y' || *letter == 'Y' ||
        ((*letter == 'g' || *letter == 'G') && (*(letter+1) == 'n' || *(letter+1) == 'N')) ||
        ((*letter == 'p' || *letter == 'P') && (*(letter+1) == 's' || *(letter+1) == 'S')) ||
        ((*letter == 's' || *letter == 'S') && (vowel(letter+1) == false)) ||
        ((*letter == 'i' || *letter == 'I') && (vowel(letter+1) == true))) {
        res = true;
    } else {
        res = false;
    }
    return res;
}

//gets a word which and returns "1" if it's  masculine and "2" if it's feminine
int get_gender(char* noun) {
    int res;
    char the_last_letter = last_letter(noun);
    if (the_last_letter == 'o' || the_last_letter == 'O') {
        res = MASCULINE;
    } else if (the_last_letter == 'a' || the_last_letter == 'A') {
        res = FEMININE;
    } else {
        res = 0;
    }
    return res;
}

//gets a word and returns a number according to the right indefinite article of the word: "1" for "un", "2" for "uno", "3" for "una" and "4" for "un'"
int get_indefinite_article(char* noun) {
    int res;
    if (get_gender(noun) == MASCULINE) {
        if (whistling_letter(noun) == true) {
            res = UNO;
        } else {
            res = UN;
        }
    } else {
        if (vowel(noun) == true) {
            res = UN_APOSTROPHE;
        } else {
            res = UNA;
        }
    }
    return res;
}

//gets a word and returns the length of the word resulting by adding the indefinite article before the word (including the length of the word)
int get_length_indefinite_article(char* noun) {
    int article_len;
    int noun_len = 0;
    int res;
    int indefinite_article = get_indefinite_article(noun);
    if ((indefinite_article == UNO) || (indefinite_article == UNA)) {
        article_len = 3;
    } else {
        article_len = 2;
    }
    for (int i=0 ; ((('a' <= *(noun+i)) && (*(noun+i) <= 'z')) || (('A' <= *(noun+i)) && (*(noun+i) <= 'Z'))) ; i++) {
        noun_len++;
    }
    res = article_len + 1 + noun_len;
    return res;
}

//gets a word and writes an array of right sized characters, puts in the indefinite article, a space character (if needed), and at the end the word
void add_indefinite_article(char* noun, char* noun_with_article) {
    int length_indefinite_article = get_length_indefinite_article(noun);
    int indefinite_article = get_indefinite_article(noun);
    char uno_string[] = "uno ";
    char una_string[] = "una ";
    char un_string[] = "un ";
    char un_apostrophe_string[] = "un\'";
    for (int i=0 ; i <= length_indefinite_article ; i++) {
        *(noun_with_article+i) = 0;
    }
    for (int i=0 ; i<length_indefinite_article ; i++) {
        if (indefinite_article == UNO) {
            if (i<4) {
                *(noun_with_article+i) = uno_string[i];
            } else {
                *(noun_with_article+i) = *(noun+i-4);
            }
        } else if (indefinite_article == UNA) {
            if (i<4) {
                *(noun_with_article+i) = una_string[i];
            } else {
                *(noun_with_article+i) = *(noun+i-4);
            }
        } else if (indefinite_article == UN) {
            if (i<3) {
                *(noun_with_article+i) = un_string[i];
            } else {
                *(noun_with_article+i) = *(noun+i-3);
            }
        } else {
            if (i<3) {
                *(noun_with_article+i) = un_apostrophe_string[i];
            } else {
                *(noun_with_article+i) = *(noun+i-3);
            }
        }
    }
}

//gets a bound, scans a word from the user which its length is up to the bound, prints the right indefinite article, the word and a new line character
void handle_indefinite_article(int max_length) {
    char *old_word = (char*)malloc((max_length*sizeof(char))+1);
    for (int i=0 ; i <= max_length ; i++) {
        *(old_word+i) = 0;
    }
    scanf("%s", old_word);
    int length_indefinite_article = get_length_indefinite_article(old_word);
    char *new_word = (char*)malloc((length_indefinite_article*sizeof(char))+1);
    add_indefinite_article(old_word, new_word);
    printf("%s\n", new_word);
    free(old_word);
    free(new_word);
}


/*-------------------------------------------------------------------------
  The main program
 -------------------------------------------------------------------------*/

/**
 * main - reads two integers and calls handle_indefinite_article() accordingly.
 *
 * @returns the status, for the operating system.
 */
int main() {
	int max_length, num_of_nouns;
	scanf("%d %d", &max_length, &num_of_nouns);
	for(int i = 0; i < num_of_nouns; i++) {
		handle_indefinite_article(max_length);
	}
	return 0;
}
