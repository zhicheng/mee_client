/*
 * mee_client.h 
 *
 * Copyright (c) Zhicheng Wei <zhicheng1988@gmail.com>
 *
 */

#ifndef _MEE_CLIENT_H_
#define _MEE_CLIENT_H_


#include <curl/curl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <json/json.h>
#include <getopt.h>
#define NDEBUG
#include <assert.h>

#include "utils.h"

static const struct option longOpts[] = {
    {"user", required_argument, NULL, 'u'},
    {"method", required_argument, NULL, 'm'},
    {"string", required_argument, NULL, 's'}, 
    {"int", required_argument, NULL, 'i'},
    {"object", required_argument, NULL, 'o'},
    {NULL, no_argument, NULL, 0}
};

void print_headers();
void make_json(char *key, char *value, json_type json_t);

#endif /* _MEE_CLIENT_H_ */

