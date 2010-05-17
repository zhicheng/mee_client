/*
 * mee_client.c 
 *
 * Copyright (c) Zhicheng Wei <zhicheng1988@gmail.com>
 *
 */

#include "main.h"

#define JSON_BUFFER  1024

struct json_object *json = NULL; 

void make_json(char *key, char *value, json_type json_t)
{
    struct json_object *new_json_object;

    if (NULL == json) 
        json = json_object_new_object();

    if (json_type_string == json_t) {
        new_json_object = json_object_new_string(value);
        json_object_object_add(json, key, new_json_object);
    } else if (json_type_int == json_t) {
        new_json_object = json_object_new_int(atoi(value));
        json_object_object_add(json, key, new_json_object);
    }
}

void print_header_str(char *header, CURLINFO type, CURL *curl)
{
    char *value;
    CURLcode res;
    res = curl_easy_getinfo(curl, type, &value);
    if ((CURLE_OK == res) && value)
        printf("%s: %s\n", header, value);
}

void print_header_int(char *header, CURLINFO type, CURL *curl)
{
    long value;
    CURLcode res;
    res = curl_easy_getinfo(curl, type, &value);
    if ((CURLE_OK == res) && value)
        printf("%s: %ld\n", header, value);
}

void print_headers(CURL *curl)
{
    print_header_str("Content-Type", CURLINFO_CONTENT_TYPE, curl);
    print_header_int("Response-Code", CURLINFO_RESPONSE_CODE, curl);
}

void build_header(CURL *curl)
{
    struct curl_slist *chunk = NULL;
    chunk = curl_slist_append(chunk, "Accept: application/json; charset=UTF-8");
    chunk = curl_slist_append(chunk, "Content-Type: application/json; charset=UTF-8");
    chunk = curl_slist_append(chunk, "Expect:");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
}

int main(int argc, char *argv[])
{
    int post = 0;
    int opt = 0;
    int longIndex = 0;
    char userpwd[100];
    char **kv;
    static const char *optString = "u:r:s:i:";

    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    opt = getopt_long(argc, argv, optString, longOpts, &longIndex);
    while (opt != -1) {
        switch (opt) {
            case 'u':
                curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
                curl_easy_setopt(curl, CURLOPT_USERPWD, optarg);
                break;
            case 'm':
                if (strcmp(optarg, "PUT") == 0) {
                    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
                }
                if (strcmp(optarg, "DELETE") == 0) {
                    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
                    post = 0;
                }
                break;
            case 's':
                post = 1;
                kv = keyvalue(optarg);
                make_json(kv[0], kv[1], json_type_string);
                break;
            case 'i':
                post = 1;
                kv = keyvalue(optarg);
                make_json(kv[0], kv[1], json_type_int);
                break;
            default:
                break;
        }
        opt = getopt_long(argc, argv, optString, longOpts, &longIndex);
    }
    curl_easy_setopt(curl, CURLOPT_URL, argv[argc - 1]);
    printf("%s", argv[argc - 1]);
    build_header(curl);
    if (1 == post) {
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_object_to_json_string(json));
        curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE, (curl_off_t)strlen(json_object_to_json_string(json)));
    }

    printf("\n==================content=================\n");
    res = curl_easy_perform(curl);
    printf("\n==================header=================\n");
    if (CURLE_OK == res)
        print_headers(curl);
    printf("\n================== end  =================\n");
    return EXIT_SUCCESS;
}

