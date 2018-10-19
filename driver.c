#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked-list.h"
#include "library.h"

int main()
{
	srand(time(NULL));
	printf("---------- TESTING LINKED LIST ----------\n");

	printf("========== insert_front & print_single_song_node ==========\n");
	struct song_node * mySongs = insert_front(mySongs, "Getter", "Tetter");
	print_single_song_node(mySongs);
	mySongs = insert_front(mySongs, "Jeans", "John");
	print_single_song_node(mySongs);

	printf("========== print_song_node ==========\n");
	print_song_node(mySongs);

	printf("========== insert_in_order ==========\n");
	mySongs = insert_in_order(mySongs, "Zebra", "Chida");
	mySongs = insert_in_order(mySongs, "Gaga", "Soui");
	mySongs = insert_in_order(mySongs, "Blackskin", "Badboys");
	mySongs = insert_in_order(mySongs, "Dada", "Aou");
	print_song_node(mySongs);

	printf("========== get_song_node ==========\n");
	printf("Looking for Gaga by Soui:\n");
	print_single_song_node(get_song_node(mySongs, "Gaga", "Soui"));

	printf("========== get_song_by_artist ==========\n");
	printf("Looking for song by John:\n");
	print_single_song_node(get_song_by_artist(mySongs, "John"));

	printf("========== get_random_song ==========\n");
	print_single_song_node(get_random_song(mySongs));

	printf("========== remove_node ==========\n");
	printf("Removing Jeans by John\n");
	mySongs = remove_node(mySongs, "Blacksin", "Badboys");
	print_song_node(mySongs);

	printf("========== free_list ==========\n");
	mySongs = free_list(mySongs);
	print_song_node(mySongs);


	printf("---------- TESTING LIBRARY ----------\n");

	printf("========== add_song_to_library & print_library ==========\n");
	struct library * myLib = malloc(sizeof(struct library)); 
	myLib = add_song_to_library(myLib, "Gasso", "Wasso");
	myLib = add_song_to_library(myLib, "Tanline", "Burnt");
	myLib = add_song_to_library(myLib, "Food", "Burnt");
	myLib = add_song_to_library(myLib, "Cookies", "Bookie");
	myLib = add_song_to_library(myLib, "Elepho", "Balon");
	myLib = add_song_to_library(myLib, "Chicken", "Hotpeas");
	myLib = add_song_to_library(myLib, "Turbul", "Huhas");
	myLib = add_song_to_library(myLib, "Dadas", "Zugas");
	print_library(myLib);

	printf("========== find_song ==========\n");
	printf("Looking for Tanline by Burnt: \n");
	print_single_song_node(find_song(myLib, "Tanline", "Burnt"));

	printf("========== find_song_by_arist ==========\n");
	printf("Looking for song by Wasso: \n");
	print_single_song_node(find_song_by_arist(myLib, "Wasso"));

	printf("========== print_by_char ==========\n");
	printf("Songs by artists starting with 'B'\n");
	print_by_char(myLib, 'B');

	printf("========== print_by_artist ==========\n");
	printf("Songs by 'Burnt':\n");
	print_by_artist(myLib, "Burnt");

	printf("========== print_shuffle ==========\n");
	print_shuffle(myLib);

	printf("========== delete_song ==========\n");
	printf("Deleting Dadas by Zugas\n");
	myLib = delete_song(myLib, "Dadas", "Zugas");
	print_library(myLib);

	printf("========== free_library ==========\n");
	free_library(myLib -> table);
	return 0;
}