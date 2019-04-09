#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void erase_ship(char **mymap, int ship)
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (mymap[i][j] == ship)
                mymap[i][j] = '~';


}
 bool check_ship(char **mymap, int lenght, int ship) {
    int sum = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (mymap[i][j] == ship)
                sum++;
    if (sum==lenght)
        return true;
    else
        return false;
}


void coord_boat( int lenght, int cpt, char **mymap, char *alphabet, char ship) {
    char Xtemp;
    int direction, posY;
    direction = 3;
    while (direction != 1 && direction != 2) {
        printf("Would you place your boat in a Vertical (enter 1) or Horizontal (enter 2) way?   ");
        scanf("%d", &direction);
    }

    printf("Now you will give me the coordinates of the boat's bow \n");
    printf("Give me the capital letter for the column, please : \n");
    do {
        scanf("%c", &Xtemp);
    } while (Xtemp != 'A' && Xtemp != 'B' && Xtemp != 'C' && Xtemp != 'D' && Xtemp != 'E' && Xtemp != 'F' && Xtemp != 'G' &&
             Xtemp != 'H' && Xtemp != 'I' && Xtemp != 'J');

    printf("Give me the number for the line, please : \n");
    scanf("%d", &posY);
    while (posY<1 || posY>10){
        printf("Give me the number for the line, please : \n");
        scanf("%d", &posY);
    }
    printf("%c,,,,%d \n", Xtemp, posY);
    int posX = 0;
    while (alphabet [posX] != Xtemp)
    {
        posX++;
    }
    posY--;
    while (mymap[posX][posY] == '~' && lenght != 0 && posX <= 10 && posY <= 10) {
        mymap[posX][posY] = ship;
        if (direction == 1)
            posX++;
        else
            posY++;
        lenght--;
        printf("%d is posx, %d is posy \n", posX, posY);
    }

}


void print_map (char *alphabet, char **mymap)
{
    int cpt = 1;
    printf("   ");
    for (int i = 0; i < 10; i++)
        printf("%c ", alphabet[i]);
    printf("\n");
    for (int i = 0; i < 10; i++)

    {   if (cpt!= 10)
            printf("%d  ", cpt);
        else
            printf("%d ", cpt);
        cpt++;
        for (int j = 0; j < 10; j++)
            printf("%c ", mymap[i][j]);
        printf("\n");
    }
}
//MAIN ALGORITHM
int main()
{

    char** mymap;
    mymap = (char**) malloc(sizeof(char*)*10);
    for (int i = 0 ; i < 10 ; i++)
    {
        mymap[i] = (char*) malloc(sizeof(char)*10);
    }
    char alphabet [27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int direction;
    int cpt = 1;
    int ship = 6;
    int cpt_ship = 1;
    int lenght;
    char ship_l = 'a';

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++){
            mymap[i][j] = '~';
        }
    }
    print_map(alphabet, mymap);

    do
    {
    printf("\nPlace your Aircraft Carrier (5 cells)\n");
    coord_boat(5, cpt_ship, mymap, alphabet, ship_l);
    if (check_ship(mymap, lenght, ship_l) == false)
        erase_ship(mymap, ship_l);
    }while (check_ship(mymap, lenght, ship_l) == false);
    print_map(alphabet, mymap);


    do
    {
    printf("Place your Battleship (4 cells)\n");
    ship_l = 'b';
    coord_boat(4, cpt_ship, mymap, alphabet, ship_l);
    if (check_ship(mymap, lenght, ship_l) == false)
        erase_ship(mymap, ship_l);
    }while (check_ship(mymap, lenght, ship_l) == false);
    print_map(alphabet, mymap);

    do
    {
    printf("Place your Cruiser (3 cells)\n");
    ship_l = 'c';
    coord_boat(3, cpt_ship, mymap, alphabet, ship_l);

    }while (check_ship(mymap, lenght, ship_l) == false);
    print_map(alphabet, mymap);

    do
    {
    printf("Place your Yellow Submarine (3 cells)\n");
    ship_l = 'd';
    coord_boat(3, cpt_ship, mymap, alphabet, ship_l);

    }while (check_ship(mymap, lenght, ship_l) == false);
    print_map(alphabet, mymap);

    do
    {
    printf("Place your Destroyer (2 cells)\n");
    ship_l = 'e';
    coord_boat(2, cpt_ship, mymap, alphabet, ship_l);

    }while (check_ship(mymap, lenght, ship_l) == false);
    print_map(alphabet, mymap);
}


