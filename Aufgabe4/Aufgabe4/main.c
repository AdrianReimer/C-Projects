//
//  main.c
//  Aufgabe4
//
//  Created by Adrian Reimer on 06.05.19.
//  Copyright © 2019 Adrian Reimer. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define df_length 50
#define df_seperator 0

static short df_rem_ele = -df_length + 2; // remaining unused elements of the datafield
static short df_op_count = 1; // amount of operations used on the datafield
static char df[df_length];
static char *df_set_ptr = &df[1]; // pointer to set new key-value pairs inside the Datafield
static char *df_get_ptr = &df[1]; // pointer to search for keys inside the Datafield
// mit array element löschen


void assoziative_print(void);
int assoziative_set(char *key, char *element);
int assoziative_get(char *key);
int assoziative_remove(char *key);

int main(int argc, const char * argv[]) {
    // define datafield
    df[0] = df_seperator;
    df[1] = df_op_count;
    for(int i = 2; i < (sizeof(df) / sizeof(df[0]));i++) {
        df[i] = df_op_count;
    }
    // use functions
    assoziative_set("key1", "value1");
    assoziative_set("key2", "value2");
    assoziative_get("key2");
    assoziative_get("key1");
    assoziative_get("key10");
    assoziative_remove("key1");
    assoziative_print();
    
    printf("%d\n",df_op_count);
    return 0;
}

/* Sets Key-Value Pairs inside the Datafield */
int assoziative_set(char *key, char *element) {
    short key_space = (short)strlen(key) + 1; // length of key (including \0)
    short element_space = (short)strlen(element) + 1; // length of element (including \0)
    short req_space = key_space + element_space; // required space of the pure key-value pair
    df_rem_ele += req_space + 2; // total amount
    if(df_rem_ele <= 0) {
        *df_set_ptr++ = req_space;
        while(key_space > 0) { // Adds Key
            *df_set_ptr++ = *key++;
            key_space--;
        }
        while(element_space > 0) { // Adds Element
            *df_set_ptr++ = *element++;
            element_space--;
        }
        *df_set_ptr++ = 0; // Adds seperator
        *df_set_ptr = df_rem_ele; // Adds remaining elements value
        {
            // Updates operation count used on the datafield
            df_op_count++;
            char *df_op_upd_ptr = df_set_ptr;
            df_op_upd_ptr++;
            for (int i = df_rem_ele; i < 0; i++) {
                *df_op_upd_ptr++ = df_op_count;
            }
        }
        return 0;
    }
    return -1;
}

/* Searches key in Datafield and return a pointer to the respective value */
char *search_key_value(char *key) {
    short key_space = (short)strlen(key) + 1; // length of key (including \0)
    short key_count = 0; // counts similar characters to find the key
    int i = 1;
    short key_value_length = *df_get_ptr++;
    while((i < (df_rem_ele + df_length)) && key_space != key_count) { // search only in "used" space
        if(*df_get_ptr == *key) { // similar character found
            df_get_ptr++;
            key++;
            key_count++;
        } else {
            short dist_to_next_key = key_value_length + 1 - key_count; // byte distance to next key
            df_get_ptr+= dist_to_next_key;
            i+= dist_to_next_key;
            key_value_length = *df_get_ptr++;
            key -= key_count; // resets key-ptr to original position
            key_count = 0; // resets count
        }
        i++;
    }
    char *n_df_get_ptr = df_get_ptr; // copy pointer
    df_get_ptr -= i; // resets ptr to beginning of Datafield
    if(key_space == key_count) {
        return n_df_get_ptr;
    }
    return NULL;
}

/* Gets the Value of the key from the Datafield */
int assoziative_get(char *key) {
    return printf("%s\n",search_key_value(key)) ? 0 : -1;
}

/* Removes the key-value pair from the datafield and "cleans" it */
int assoziative_remove(char *key) {
    char *value = search_key_value(key);
    if (value != NULL) {
        key = value - (strlen(key)+1); // pointer to datafield key
        short key_value_space = *--key; // amount of space deleted
        while(*key >= 0) {
            *key = *(key + key_value_space + 2);
            key++;
        }
        df_rem_ele -= (key_value_space + 2); // more datafield space
        key -= (key_value_space + 2);
        *key++ = df_rem_ele;
        ++df_op_count; // update datafield operation count
        for(int i = df_rem_ele; i < 0; i++) {
            *key++ = df_op_count;
        }
        return 0;
    }
    return -1;
}

/* Prints the Datafield */
void assoziative_print() {
    for (int i = 0; i < df_length; i++) {
        printf("%d \t %x \t %d \t %c\n", i, df[i], (int)df[i], (int)df[i]);
    }
}
