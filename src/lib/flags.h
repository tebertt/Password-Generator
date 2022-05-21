/*
 * Author:      Troy Ebert
 * Filename:    flags.h
 * Description: Header file for flags
 */

#ifndef _FLAGS_H
#define _FLAGS_H

#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <getopt.h>

#include "constants.h"

uint8_t get_verbose();

void set_verbose(uint8_t verbose);

void verbose(char* arg);

uint8_t get_length();

void set_length(uint8_t length);

void parse_length(char* str);

uint8_t get_lowercase();

void set_lowercase(uint8_t lowercase);

uint8_t get_uppercase();

void set_uppercase(uint8_t uppercase);

uint8_t get_numbers();

void set_numbers(uint8_t numbers);

uint8_t get_symbols();

void set_symbols(uint8_t symbols);

uint8_t get_similar();

void set_similar(uint8_t similar);

void handle_flags(int32_t argc, char** argv);

#endif