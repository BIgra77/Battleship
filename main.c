#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "function.h"


//MAIN ALGORITHM
int main()
{

    char** mymap;
    char** cmap;
    char** myshoot_map;
    char** cshoot_map, alphabet [27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}, ship_marker = 'a';
    int map_size = 10, main_access = 0, replay, dir_shoot_ia;
    srand(time(NULL));

    while (main_access != 5)
    {
        printf("\n**************************************************************************************\n");
        printf("MENU \n\n Here you can choose the menu you want by entering the value corresponding : \n\n");
        printf("     1 - PLAY \n     2 - Change the size of your map (The actual size is %d) \n", map_size);
        printf("     3 - Change parameters of your boats \n     4 - TABLE SCORES \n     5 - Quite the game... \n\n\n");
        scanf("%d", &main_access);

/// MENU 1 ///
        if (main_access == 1)
        {
// creation of your map
            mymap = (char**) malloc(sizeof(char*)*map_size);
            for (int i = 0 ; i < map_size ; i++)
            {
                mymap[i] = (char*) malloc(sizeof(char)*map_size);
            }
            create_map (mymap, map_size);
            print_map(alphabet, mymap, map_size);

            do
            {
                printf("\nPlace your Aircraft Carrier (5 cells)\n");
                coord_boat(5, mymap, alphabet, ship_marker, map_size,1);
                if (check_ship(mymap, 5, ship_marker, map_size) == false)
                    erase_ship(mymap, ship_marker, map_size,'~');
            }while (check_ship(mymap, 5, ship_marker, map_size) == false);
            print_map(alphabet, mymap, map_size);


            do
            {
                printf("Place your Battleship (4 cells)\n");
                ship_marker = 'b';
                coord_boat(4, mymap, alphabet, ship_marker, map_size,1);
                if (check_ship(mymap, 4, ship_marker, map_size) == false)
                    erase_ship(mymap, ship_marker, map_size, '~');
            }while (check_ship(mymap, 4, ship_marker, map_size) == false);
            print_map(alphabet, mymap, map_size);

            do
            {
                printf("Place your Cruiser (3 cells)\n");
                ship_marker = 'c';
                coord_boat(3, mymap, alphabet, ship_marker, map_size, 1);
                if (check_ship(mymap, 3, ship_marker, map_size) == false)
                    erase_ship(mymap, ship_marker, map_size, '~');
            }while (check_ship(mymap, 3, ship_marker, map_size) == false);
            print_map(alphabet, mymap, map_size);

            do
            {
                printf("Place your Yellow Submarine (3 cells)\n");
                ship_marker = 'd';
                coord_boat(3, mymap, alphabet, ship_marker, map_size, 1);
                if (check_ship(mymap, 3, ship_marker, map_size) == false)
                    erase_ship(mymap, ship_marker, map_size, '~');
            }while (check_ship(mymap, 3, ship_marker, map_size) == false);
            print_map(alphabet, mymap, map_size);

            do
            {
                printf("Place your Destroyer (2 cells)\n");
                ship_marker = 'e';
                coord_boat(2, mymap, alphabet, ship_marker, map_size, 1);
                if (check_ship(mymap, 2, ship_marker, map_size) == false)
                    erase_ship(mymap, ship_marker, map_size, '~');
            }while (check_ship(mymap, 2, ship_marker, map_size) == false);
            print_map(alphabet, mymap, map_size);

// computer map creation
            cmap = (char**) malloc(sizeof(char*)*map_size);
            for (int i = 0 ; i < map_size ; i++)
            {
                cmap[i] = (char*) malloc(sizeof(char)*map_size);
            }
            create_map (cmap, map_size);
            print_map(alphabet, cmap, map_size);

            do
            {
                printf("\nPlace your Aircraft Carrier (5 cells)\n");
                ship_marker = 'a';
                coord_boat(5, cmap, alphabet, ship_marker, map_size,0);
                if (check_ship(cmap, 5, ship_marker, map_size) == false)
                    erase_ship(cmap, ship_marker, map_size, '~');
            }while (check_ship(cmap, 5, ship_marker, map_size) == false);
            print_map(alphabet, cmap, map_size);


            do
            {
                printf("Place your Battleship (4 cells)\n");
                ship_marker = 'b';
                coord_boat(4, cmap, alphabet, ship_marker, map_size,0);
                if (check_ship(cmap, 4, ship_marker, map_size) == false)
                    erase_ship(cmap, ship_marker, map_size, '~');
            }while (check_ship(cmap, 4, ship_marker, map_size) == false);
            print_map(alphabet, cmap, map_size);

            do
            {
                printf("Place your Cruiser (3 cells)\n");
                ship_marker = 'c';
                coord_boat(3, cmap, alphabet, ship_marker, map_size, 0);
                if (check_ship(cmap, 3, ship_marker, map_size) == false)
                    erase_ship(cmap, ship_marker, map_size, '~');
            }while (check_ship(cmap, 3, ship_marker, map_size) == false);
            print_map(alphabet, cmap, map_size);

            do
            {
                printf("Place your Yellow Submarine (3 cells)\n");
                ship_marker = 'd';
                coord_boat(3, cmap, alphabet, ship_marker, map_size, 0);
                if (check_ship(cmap, 3, ship_marker, map_size) == false)
                    erase_ship(cmap, ship_marker, map_size, '~');
            }while (check_ship(cmap, 3, ship_marker, map_size) == false);
            print_map(alphabet, cmap, map_size);

            do
            {
                printf("Place your Destroyer (2 cells)\n");
                ship_marker = 'e';
                coord_boat(2, cmap, alphabet, ship_marker, map_size, 0);
                if (check_ship(cmap, 2, ship_marker, map_size) == false)
                    erase_ship(cmap, ship_marker, map_size, '~');
            }while (check_ship(cmap, 2, ship_marker, map_size) == false);
            print_map(alphabet, cmap, map_size);



// Creation of fire map
            myshoot_map = (char**) malloc(sizeof(char*)*map_size);
            for (int i = 0 ; i < map_size ; i++)
            {
                myshoot_map[i] = (char*) malloc(sizeof(char)*map_size);
            }
            create_map (myshoot_map, map_size);

            cshoot_map = (char**) malloc(sizeof(char*)*map_size);
            for (int i = 0 ; i < map_size ; i++)
            {
                cshoot_map[i] = (char*) malloc(sizeof(char)*map_size);
            }
            create_map (cshoot_map, map_size);

            while (end_game(mymap,map_size) == false || end_game(cmap, map_size) == false)
            {
                do
                {
                    replay = 0;
                    printf("\n\n YOUR TURN\n");
                    if (shoot(cmap, myshoot_map, alphabet, map_size) == true)
                        replay = 1;
                    gameboard(mymap, myshoot_map, alphabet, map_size, 1);
                }while (replay == 1);

                do
                {
                    replay = 0;
                    printf("\n\nHIS TURN\n");
                    if (ia (mymap, cshoot_map, map_size, 0) == true)
                        replay = 1;
                    gameboard(cmap, cshoot_map, alphabet, map_size, 0);
                } while (replay == 1);
            }
        }
/// MENU 2 ///
        if (main_access == 2)
        {
            printf("Actual size : %d\n",map_size);
            printf("Enter the size of your map (be resonable;) ) don't creates a too big map\n");
            do
            {
                printf("The size must be between 5 and 25\n");
                scanf("%d", &map_size);
            }while (map_size < 5 && map_size > 25);
        }
    }
    return 0;
}