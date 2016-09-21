#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <libgen.h>

// ^xor && ^and && ^or

void usage(char *progname)
{
    printf("Usage: %s <binary_string> <binary_string>\ne.g. %s 000110 110\n",
            progname, progname);
    exit(0);
}

bool string_is_valid_binary_num(char *wurd)
{
    int len = strlen(wurd);
    for (int i = 0; i < len; i++) {
        if (wurd[i] != '0' && wurd[i] != '1') {
            return false;
        }
    }
    return true;
}

int int_val(int len, char *wurd)
{
    int multiplier = 1;
    int integer_val = 0;

    for (int i = len - 1; i >= 0; i--) {
        if ( wurd[i] == '0' ) {
            // no-op
        } 
        else if (wurd[i] == '1') {
            integer_val += multiplier * 1;
        } 
        else {
            printf("Git out of here, ya pest!\n");
            exit(1);
        }
        multiplier *= 2;
    }

    return integer_val;
}

int xorry(char *first, char *sec, char *answer)
{

    int len = strlen(first);

    for (int i = 0 ; i < len; i++ )
    {
        if (first[i] != sec[i]) {
            answer[i] = '1';
        }
    }
    answer[len] = '\0';
    return 0;
}

int orry(char *first, char *sec, char *answer)
{

    int len = strlen(first);

    for (int i = 0 ; i < len; i++ )
    {
        if (first[i] == '1' || sec[i] == '1') {
            answer[i] = '1';
        }
    }
    answer[len] = '\0';
    return 0;
}

int xandy(char *first, char *sec, char *answer)
{

    int len = strlen(first);

    for (int i = 0 ; i < len; i++ )
    {
        if (first[i] == '1' && sec[i] == '1') {
            answer[i] = '1';
        }
    }
    answer[len] = '\0';
    return 0;
}


int main(int argc, char **argv)
{

    if (argc != 3) {
        usage(argv[0]);
    }

    if ( !string_is_valid_binary_num(argv[1]) || !string_is_valid_binary_num(argv[2]) ) {
        usage(argv[0]);
    }

    // pad
    int len_diff = strlen(argv[1]) - strlen(argv[2]);

    char first_string[28];
    char second_string[28];
    int i;
    for ( i = 0; i < abs(len_diff); i++) {
        second_string[i] = '0';
    }
    second_string[abs(len_diff)] = '\0';

    char answer_string[28];
    for (int i = 0 ; i < 28; i++) 
        answer_string[i] = '0';
    answer_string[27] = '\0';

    if (len_diff > 0) {
        strncpy(first_string, argv[1], 27);
        strncat(second_string, argv[2], 27);
    }
    else {
        strncpy(first_string, argv[2], 27);
        strncat(second_string, argv[1], 27);
    }

    //
    // xorry or xandy
    if (strcmp(basename(argv[0]), "xorry") == 0) {
        printf("XOR\n");
        xorry(first_string, second_string, answer_string);
    }
    else if (strcmp(basename(argv[0]), "orry") == 0) {
        printf("OR\n");
        orry(first_string, second_string, answer_string);
    }
    else if (strcmp(basename(argv[0]), "xandy") == 0) {
        printf("AND\n");
        xandy(first_string, second_string, answer_string);
    }
    else {
        printf("Play the game, eh, mate?\n");
        return -1;
    }

    printf("%s\n%s\n%s\n", first_string, second_string, answer_string);

}
