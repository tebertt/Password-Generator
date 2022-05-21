/*
 * Author:      Troy Ebert
 * Filename:    main.c
 * Description: Generates a random password, parameters
 *              can be modified with options
 */

#include <stdio.h>
#include <err.h>
#include <string.h>

#include "sodium.h"
#include "lib/flags.h"
#include "lib/constants.h"

static char char_space[256];

uint8_t check_legality() {
    return !(get_lowercase() |
             get_uppercase() |
             get_numbers()   |
             get_symbols()   |
             get_similar()
            );
}

void create_char_space() {
    
    if(get_lowercase()) {
        strcat(char_space, lower_case);
    }
    if(get_uppercase()) {
        strcat(char_space, upper_case);
    }
    if(get_numbers()) {
        strcat(char_space, numbers);
    }
    if(get_symbols()) {
        strcat(char_space, symbols);
    }
    if(get_similar()) {
        strcat(char_space, similar);
    }

}

void generate_password(char* password) {

    uint32_t mod = strlen(char_space);
    uint32_t rng;
    for(size_t i = 0; i < get_length(); i++) {
        rng = randombytes_uniform(mod);
        password[i] = char_space[rng];
    }

}

int main(int argc, char** argv) {

    handle_flags(argc, argv);

    if(check_legality()) {
        errx(EXIT_FAILURE, "No characters are used");
    }
    create_char_space();

    if (sodium_init() < 0) {
        
        err(EXIT_FAILURE, NULL); 
    }

    char* password = calloc(get_length(), sizeof(char));
    generate_password(password);
    printf("Password: %s\n", password);

    free(password);

    return(EXIT_SUCCESS);

}