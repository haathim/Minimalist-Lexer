#include <stdio.h>

int main(int argc, char *argv[]){

    // check if the number of arguments provided by the user is valid
    if(argc != 2){
        printf("Error --> Entered number of parameters is incorrect.");
        return -1;
    }

    // create file pointer for input file and output file
    FILE *inFile = fopen(argv[1], "r");

    // create char variable to store current character being scanned
    // and char array to store char string scanned so far
    char c;
    char lexeme[50];

    // initialize variable to iterate
    int i;

    // iterate character values until end of file is reached
    while((c=fgetc(inFile)) != EOF){

        // printf("CHARACTER READ IS --> %c\n", c);

        // skip through whitespace
        if(isspace(c) > 0){
            while(isspace((c=fgetc(inFile))) > 0);
        }
        // when you meet a character other than whitespace character
        else{
            // check if next character is a number
            if(isdigit(c) > 0){
                i = 0;
                // add digit to buffer and increment iterator
                lexeme[i++] = c;
                // keep iterating and storing as long as characters are digits
                while(isdigit((c=fgetc(inFile))) > 0) lexeme[i++] = c;

                // if float
                if(c == '.'){
                    // keep iterating and storing as long as characters are digits
                    lexeme[i++] = c;
                    while(isdigit((c=fgetc(inFile))) > 0) lexeme[i++] = c;

                    if(isspace(c) > 0){
                        // set last character of buffer as end character
                        lexeme[i] = '\0';
                        // output
                        printf("<FLOAT,%s>", lexeme);
                    }
                    // if something else --> error
                    else{
                        // set last character of buffer as end character
                        lexeme[i++] = c;
                        while(!isspace((c=fgetc(inFile))) > 0) lexeme[i++] = c;
                        lexeme[i] = '\0';
                        // output
                        printf("<ERROR,%s>", lexeme);
                    }
                }
                else{
                    // set last character of buffer as end character
                    lexeme[i] = '\0';
                    // output
                    printf("<INTEGER,%s>", lexeme);

                }
            }
            else{
                // check if next character is a character that is in the alphabet
                if(isalpha(c) > 0){
                    // do the same as checking for number except here we do for character string
                    i = 0;
                    lexeme[i++] = c;
                    while(isalpha((c=fgetc(inFile))) > 0) lexeme[i++] = c;
                    lexeme[i] = '\0';
                    printf("<STRING,%s>", lexeme);
                }
                else{
                    // if enocuntered some other characters other than above checked types then its an error
                    // set last character of buffer as end character
                    i = 0;
                    lexeme[i++] = c;
                    while(!isspace((c=fgetc(inFile))) > 0) lexeme[i++] = c;
                    lexeme[i] = '\0';
                    // output
                    printf("<ERROR,%s>", lexeme);
                }
            }
        }
        // Insert last read character back into the stream as it belongs to the next token
        ungetc(c, inFile);
    }

    fclose(inFile);

}
