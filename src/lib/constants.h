/*
 * Author:      Troy Ebert
 * Filename:    constants.h
 * Description: Header file for all constants
 */

#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#define VERSION "1.0"

#define HELP_MESSAGE "usage: generate [options]\n\
  options:\n\
    -v, --verbose          Sets program to be verbose\n\
    -h, --help             Prints out this help message\n\
    -V, --Version          Prints the app\'s version\n\
\n\
    -t, --time             Changes the RNG to be time based pseudorandom\n\
    -n, --number           Password now will not generate with numbers. Default is on\n\
    -l, --lower            Password now will not generate with lower case letters. Default is on\n\
    -u, --upper            Password now will not generate with upper case letters. Default is on\n\
    -s, --symbols          Password now will not generate with symbols. Default is on\n\
    -x, --similar          Password now will generate with similar characters. Default is off\n\
\n\
    -L, --Length [integer] Set a new password length. Argument must be an integer between 8-32\n"

static char* numbers = "23456789";
static char* lower_case = "abcdefghjkmnpqstuvwxyz";
static char* upper_case = "ABCDEFGHJKMNPQRSTUVWXYZ";
static char* symbols = "~!@#$%^&*()_-+=?/";
static char* similar = "iIlLoO01";

#define LENGTH_LOWER 8
#define LENGTH_HIGHER 32

#endif