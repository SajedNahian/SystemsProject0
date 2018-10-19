#ifndef LIBRARY_H
#define LIBRARY_H

#include "linked-list.h"

struct library {
    struct song_node * table[27];
    int totalSongs;
};

int char_to_index (char c);
struct library * add_song_to_library (struct library * lib, char * name, char * artist);
struct song_node * find_song (struct library * lib, char * name, char * artist);
struct song_node * find_song_by_arist (struct library * lib, char * artist);
struct song_node * get_random_song_from_lib (struct library * lib);
void print_by_char (struct library * lib, char c);
void print_by_artist (struct library * lib, char * artist);
void print_library(struct library * lib);
void print_shuffle (struct library * lib);
struct library * delete_song(struct library * lib, char * name, char * artist);
void free_library(struct song_node * [27]);

#endif