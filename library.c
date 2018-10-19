#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "linked-list.h"
#include "library.h"


int char_to_index (char c) {
	if (isalpha(c)) {
		return c -'A';
	}
	return 26;
}

struct library * add_song_to_library (struct library * lib, char * name, char * artist) {
	lib -> table[char_to_index(artist[0])] = insert_in_order(lib -> table[char_to_index(artist[0])], name, artist);
	lib -> totalSongs = lib -> totalSongs + 1;
	return lib;
}

struct song_node * find_song (struct library * lib, char * name, char * artist) {
	return get_song_node(lib -> table[char_to_index(artist[0])], name, artist);
}

struct song_node * find_song_by_arist (struct library * lib, char * artist) {
	return get_song_by_artist(lib -> table [char_to_index(artist[0])], artist);
}

struct song_node * get_random_song_from_lib (struct library * lib) {
	struct song_node * random = lib -> table [0];
	while (get_length(random) < 1) {
		random = lib -> table [rand() % 26];
	}	
	return get_random_song(random);
}

void print_by_char (struct library * lib, char c) {
	print_song_node(lib -> table[char_to_index(c)]);
}

void print_by_artist (struct library * lib, char * artist) {
	struct song_node * temp = lib -> table[char_to_index(artist[0])];
	while (get_song_by_artist(temp, artist) != NULL) {
		printf("-%s\n", get_song_by_artist(temp, artist) -> name);
		temp = get_song_by_artist(temp, artist) -> next;
	}
}

void print_library(struct library * lib){
    for(int i = 0; i < 27; i++){
    	struct song_node * n = lib->table[i];
    	if (n) {
	    	printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	    	print_song_node(n);
	    	printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    	}
    }
}

void print_shuffle (struct library * lib) {
	for (int i = 0; i < 3; i++) {
		struct song_node * temp = get_random_song_from_lib(lib);
		printf("-%s by %s\n", temp -> name, temp -> artist);
	}
}

struct library * delete_song(struct library * lib, char * name, char * artist){
    lib->table[char_to_index(artist[0])] = remove_node(lib->table[char_to_index(artist[0])], name, artist);
    lib->totalSongs--;
    return lib;
}

void free_library(struct song_node * lib [27]){
   for (int i = 0; i < 27; i++) {
    free_list(lib[i]);
    lib[i] = NULL;
  }
}