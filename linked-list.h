#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node * next;
};

struct song_node * insert_front (struct song_node * n, char * song_name, char * song_artist);
void print_song_node (struct song_node * n);
void print_single_song_node (struct song_node * n);
int compare_song(struct song_node * one, struct song_node * two);
struct song_node * insert_in_order( struct song_node * head, char name[100], char artist[100]);
struct song_node * get_song_node (struct song_node * head, char * name, char * artist);
struct song_node * get_song_by_artist (struct song_node * head, char * artist);
int get_length (struct song_node * head);
struct song_node * get_random_song (struct song_node * head);
struct song_node * remove_node(struct song_node * head, char *name, char * artist);
struct song_node * free_list(struct song_node * n);

#endif