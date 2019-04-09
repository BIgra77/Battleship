
#ifndef BATTLESHIP_FUNCTION_H
#define BATTLESHIP_FUNCTION_H

#endif //BATTLESHIP_FUNCTION_H

void erase_ship(char **mymap, int ship, int map_size, char eraser){
    for (int i = 0; i < map_size; i++)
        for (int j = 0; j < map_size; j++)
            if (mymap[i][j] == ship)
                mymap[i][j] = eraser;


}


bool check_ship(char **map, int lenght, int ship, int map_size) {
    int sum = 0;
    for (int i = 0; i < map_size; i++){
        for (int j = 0; j < map_size; j++){
            if (map[i][j] == ship){
                sum++;}}}
    if (sum == lenght)
        return true;
    else
        return false;
}


int randomly (int a, int b){

    return rand()%(b-a) + a;
}


void coord_boat( int lenght, char **mymap, char *alphabet, char ship, int map_size, int random) {
    char Xtemp;
    int direction = 3, posY, posX = 0;
    if (random == 0){
        direction = randomly(1,3);
        printf("\ndirection : %d\n",direction);
        posX = randomly(0, map_size-1);
        printf("\nposX : %d\n",posX);
        posY = randomly(0, map_size-1);
        printf("\nposY : %d\n",posY);

        while (lenght != 0 && mymap[posX][posY] == '~' && posX < map_size-1 && posY < map_size-1) {
            mymap[posX][posY] = ship;
            if (direction == 1)
                posX++;
            else
                posY++;
            lenght--;
            printf("posx is %d, posy is %d \n", posX, posY);
        }

    }
    else {
        while (direction != 1 && direction != 2) {
            printf("Would you place your boat in a Vertical (enter 1) or Horizontal (enter 2) way?   ");
            scanf("%d", &direction);
        }
        printf("Now you will give me the coordinates of the boat's bow \n");
        do {
            printf("So, give me the capital letter for the column, please : \n");
            scanf(" %c", &Xtemp);
        } while (Xtemp != 'A' && Xtemp != 'B' && Xtemp != 'C' && Xtemp != 'D' && Xtemp != 'E' && Xtemp != 'F' && Xtemp != 'G' &&
                 Xtemp != 'H' && Xtemp != 'I' && Xtemp != 'J' && Xtemp != 'K' && Xtemp != 'L' && Xtemp != 'M' && Xtemp != 'N'
                 && Xtemp != 'O' && Xtemp != 'P' && Xtemp != 'Q' && Xtemp != 'R' && Xtemp != 'S' && Xtemp != 'T' && Xtemp != 'U'
                 && Xtemp != 'V' && Xtemp != 'W' && Xtemp != 'X' && Xtemp != 'Y' && Xtemp != 'Z');

        do
        {
            printf("Give me the number for the line, please : \n");
            scanf("%d", &posY);
        }while (posY<1 || posY>map_size);

        printf("%c,,,,%d \n", Xtemp, posY);
        while (alphabet [posX] != Xtemp)
        {
            posX++;
        }
        posY--;
        // inverse coordinates //

        Xtemp = posX;
        posX = posY;
        posY = Xtemp;
        // to check there is no other possibilities

        while (lenght != 0 && mymap[posX][posY] == '~' && posX <= map_size && posY <= map_size) {
            mymap[posX][posY] = ship;
            if (direction == 1)
                posX++;
            else
                posY++;
            lenght--;
            printf("posx is %d, posy is %d \n", posX, posY);
        }}

}


void print_map (char *alphabet, char **mymap, int map_size){
    int cpt = 1;
    printf("   ");
    for (int i = 0; i < map_size; i++)
        printf("%c ", alphabet[i]);
    printf("\n");
    for (int i = 0; i < map_size; i++)

    {   if (cpt <= 9)
            printf("%d  ", cpt);
        else
            printf("%d ", cpt);
        cpt++;
        for (int j = 0; j < map_size; j++)
            printf("%c ", mymap[i][j]);
        printf("\n");
    }
}


void create_map (char** map, int map_size){
    for (int i = 0; i < map_size; i++){
        for (int j = 0; j < map_size; j++){
            map[i][j] = '~';
        }
    }
}


void gameboard (char** mymap, char** shootmap, char* alphabet, int map_size, int al){
    int cpt = 1;
    if (al == 1)
        printf("         MY MAP");
    else
        printf("         HIS MAP");
    for (int i = 0; i < map_size; i++)
        printf("   ");
    if (al == 1)
        printf("MY SHOOTS\n");
    else
        printf("HIS SHOOTS\n");
    printf("   ");
    for (int i = 0; i < map_size; i++)
        printf("%c ", alphabet[i]);
    printf("                    ");
    for (int i = 0; i < map_size; i++)
        printf("%c ", alphabet[i]);
    printf("\n");
    for (int i = 0; i < map_size; i++)
    {   if (cpt <= 9)
            printf("%d  ", cpt);
        else
            printf("%d ", cpt);
        for (int j = 0; j < map_size; j++)
            printf("%c ", mymap[i][j]);
        printf("                 ");
        if (cpt <= 9)
            printf("%d  ", cpt);
        else
            printf("%d ", cpt);
        for (int j = 0; j < map_size; j++)
            printf("%c ", shootmap[i][j]);
        printf("\n");
        cpt++;}
    printf("\n");
}


bool shoot (char** map, char** shootmap, char* alphabet, int map_size){
    char xtemp, shootx, marker;
    int shooty;

    do
    {
        do
        {
            printf("Enter the LETTER of your shoot : \n");
            scanf(" %c", &xtemp);
            int i = 0;
            while (xtemp != alphabet[i])
            {
                i++;
            }
            shootx = i;
        }while (shootx >= map_size);
        printf("%c -- %d\n", xtemp, shootx);

        do
        {
            printf("\n\nEnter the NUMBER of your shoot : \n");
            scanf("%d", &shooty);
        }while (shooty > map_size);
        shooty --;
        printf("\n%d\n",shooty);
    }while (shootmap[shootx][shooty] == 'X' || shootmap[shootx][shooty] == 'O');

    do
    {
        if (map[shooty][shootx] == 'a' || map[shooty][shootx] == 'b' || map[shooty][shootx] == 'c' || map[shooty][shootx] == 'd' ||
            map[shooty][shootx] == 'e')
        {
            marker = map[shooty][shootx];
            if (check_ship(map, 1, marker, map_size) == true)
            {
                printf("HIT AND SUNK\n");
                map[shooty][shootx] = 'X';
                shootmap[shooty][shootx] = 'X';
                return false;
            }
            else
            {
                printf("HIT\n");
                map[shooty][shootx] = 'X';
                shootmap[shooty][shootx] = 'X';
                return true;
            }

        }
        else
        {
            printf("MISSED\n");
            shootmap[shooty][shootx] = 'O';
            return false;
        }
    }while (shootmap[shootx][shooty] == 'X' && shootmap[shootx][shooty] == 'O');
}

bool end_game(char** map, int map_size)
{
    for(int i = 0; i < map_size; i ++)
    {
        for(int j = 0; j < map_size; j ++)
        {
            if (map[i][j] != '~' && map[i][j] != 'X' && map[i][j] != 'O')
                return false;
        }
    }
    return true;
}

bool ia (char** map, char** shootmap, int map_size, int dir_shoot_ia)
{
    int shootx, shooty;
    char marker;
    do
    {
        shootx = randomly(0,10);
        shooty = randomly(0,10);
    }while (shootmap[shootx][shooty] == 'O' || shootmap[shootx][shooty] == 'X');

    if (map[shooty][shootx] == 'a' || map[shooty][shootx] == 'b' ||map[shooty][shootx] == 'c' ||map[shooty][shootx] == 'd' ||
        map[shooty][shootx] == 'e') {
        marker = map[shooty][shootx];
        if (check_ship(map, 1, marker, map_size) == true) {
            printf("HIT & SUNK \n");
            map[shooty][shootx] = 'X';
            shootmap[shooty][shootx] = 'X';
            return false;
        } else {
            printf("HIT\n");
            map[shooty][shootx] = 'X';
            shootmap[shooty][shootx] = 'X';
            return true;
        }
    }
        if(map[shooty][shootx] = 'X', shootmap[shooty][shootx] = 'X')
        {
            dir_shoot_ia = randomly(1,5);       //1 = right, 2 = down, 3 = left, 4 = up
            if (dir_shoot_ia ==1)
                shootx++;
            else if  (dir_shoot_ia ==2)
                shooty--;
            else if (dir_shoot_ia ==3)
                shootx--;
            else if  (dir_shoot_ia ==4)
                shooty++;
        }

    else
    {
        printf("MISSED\n");
        shootmap[shooty][shootx] = 'O';
        return false;
    }
}

