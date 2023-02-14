#ifndef SEA_BATTLE_SB_GLOBDEF_H
#define SEA_BATTLE_SB_GLOBDEF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// no. of columns = colN => arr[row][col] = *(arr + ((row * colN) + col))
#define pos(arr, row, col, colN) (*(arr + ((row * colN) + col)))

#define SPACE 10

// erase to end of line
#define erase_line "\33[K"

// move cursor one line up
#define mv_cur_up "\33[A"

// f:forground - b:background
#define f_orange "\033[93m"
#define b_blue "\033[104m"
#define f_darkblue "\033[34m"
#define b_white "\033[107m"
#define f_black "\033[30m"
#define f_darkred "\033[31m"
#define b_darkyellow "\033[43m"
#define b_magenta "\033[37m"
#define f_grey "\033[37m"
#define b_black "\033[40m"
#define b_darkred "\033[41m"
#define color_reset "\033[0m"

#define num_to_char(num) (num + 48)

#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'
#define ENTER 'e'
#define EXIT 'q'
#define REPAIR_ATTACK 'r'
#define SAVE 'z'

#ifdef __linux__
#if __linux__
#define cls "clear"
#endif
#endif

#ifdef __linux__
#if __linux__
extern int getch(void);
#endif
#endif

#ifdef _WIN32
#if _WIN32

#define cls "cls"

#include <conio.h>

#endif
#endif


extern const char *logo;

struct player_info {
    char board[52][52];
    char name[20];
    int ship_number;
    int total_part;
    int bursting_ship_no;
    int repair_used;

    //max 9 ship with max 12 part and -1 instead \0 in int
    int ships_places[9][13][2];
};

extern int is_ended;

extern int board_size;
extern int repair_num;
extern int max_part;

// 0 and 1
extern int player;
extern int last_player;

extern int is_bot_on;
extern int is_online;

extern int player_number;

extern int file_version;

extern char board_cpy[2][52][52];

extern struct player_info p1;
extern struct player_info p2;

extern struct player_info *p[2];

#endif //SEA_BATTLE_SB_GLOBDEF_H
