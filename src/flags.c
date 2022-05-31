/*
 * Author:      Troy Ebert
 * Filename:    flags.c
 * Description: Handles flags used for generate
 */

#include "lib/flags.h"

static uint8_t password_length = 16;

static uint8_t verbose_flag   = 0;
static uint8_t time_flag      = 0;
static uint8_t lowercase_flag = 1;
static uint8_t uppercase_flag = 1;
static uint8_t numbers_flag   = 1;
static uint8_t symbols_flag   = 1;
static uint8_t similar_flag   = 0;

static struct option long_options[] = {
    {"verbose", no_argument, 0, 'v'},
    {"help",    no_argument, 0, 'h'},
    {"Version", no_argument, 0, 'V'},

    {"time",    no_argument, 0, 't'},
    {"number",  no_argument, 0, 'n'},
    {"lower",   no_argument, 0, 'l'},
    {"upper",   no_argument, 0, 'u'},
    {"symbol",  no_argument, 0, 's'},
    {"similar", no_argument, 0, 'x'},

    {"Length", optional_argument, 0, 'L'},

    {0, 0, 0, 0}
};

uint8_t get_verbose() {
    return verbose_flag;
}

void set_verbose(uint8_t verbose) {
    verbose_flag = verbose;
}

void verbose(char* arg) {
    if(verbose_flag) {
        printf("%s\n", arg);
    }
}

uint8_t get_time() {
    return time_flag;
}

void set_time(uint8_t time) {
    time_flag = time;
}

uint8_t get_length() {
    return password_length;
}

void set_length(uint8_t length) {
    password_length = length;
}

void parse_length(char* str) {
    uint8_t length = atoi(optarg);

    if(length < LENGTH_LOWER) {
        warnx("Specified length of %d is less than %d", length, LENGTH_LOWER);
    }
    else if(length > LENGTH_HIGHER) {
        warnx("Specified length of %d is greater than %d", length, LENGTH_HIGHER);
    }
    else {
        set_length(length);
    }
}

uint8_t get_lowercase() {
    return lowercase_flag;
}

void set_lowercase(uint8_t lowercase) {
    lowercase_flag = lowercase;
}

uint8_t get_uppercase() {
    return uppercase_flag;
}

void set_uppercase(uint8_t uppercase) {
    uppercase_flag = uppercase;
}

uint8_t get_numbers() {
    return numbers_flag;
}

void set_numbers(uint8_t numbers){
    numbers_flag = numbers;
}

uint8_t get_symbols() {
    return symbols_flag;
}

void set_symbols(uint8_t symbols) {
    symbols_flag = symbols;
}

uint8_t get_similar() {
    return similar_flag;
}

void set_similar(uint8_t similar) {
    similar_flag = similar;
}

void handle_flags(int32_t argc, char** argv) {

    int16_t opt = 0;
    int32_t option_index = 0;

    while((opt = getopt_long(argc, argv, ":vhtnlusxL:V", long_options, &option_index)) != -1) {
        switch(opt) {
            case 'v':
                set_verbose(1);
                verbose("Verbose is on");
                break;
            case 'h':
                printf("%s\n", HELP_MESSAGE);
                break;
            case 'V':
                printf("Version: %s\n", VERSION);
                break;
            case 't':
                printf("Time base pseudorandom\n");
                break;
            case 'n':
                set_numbers(0);
                break;
            case 'l':
                set_lowercase(0);
                break;
            case 'u':
                set_uppercase(0);
                break;
            case 's':
                set_symbols(0);
                break;
            case 'x':
                set_similar(1);
                break;
            case 'L':
                parse_length(optarg);
                break;
            case ':':
                warnx("-%c flag needs an argument", optopt);
                break;
            case '?':
                warnx("%s is an invalid option for the -%c flag", optarg, optopt);
                break;
            default:
                errx(1, "getopt error, should not reach");
        }
    }
}