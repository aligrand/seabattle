#include "sb_globdef.h"

#define randnum(min, max) \
          ((rand() % (int)(((max) + 1) - (min))) + (min))

#define Rpart (max_part - p2.total_part)

extern void board_creator(char[][52]);

extern int is_another_ship_available(int[][2], int);

extern void selector_to_ships_places(int[][2], int);

extern void copy_2Dchar_array(int, int, char *, char *);

extern void put_ship(int[][2], int);

void brain_selector_creator(int selector[][2], int n_i, int n_j, int i, int j) {
    int k = 0;

    for (int i_temp = i; i_temp < i + n_i; ++i_temp) {
        for (int j_temp = j; j_temp < j + n_j; ++j_temp) {
            selector[k][0] = i_temp;
            selector[k][1] = j_temp;

            ++k;
        }
    }
}

void call_Rbrain() {
    int n_i, n_j, i, j;
    int selector[12][2];

    sprintf(p2.name, "BOT");

    board_creator(p2.board);

    while (p2.total_part < max_part) {
        n_i = 10000;
        n_j = 10000;
        while (n_i * n_j > Rpart) {
            n_i = randnum(0, 11 % board_size) + 1;
            n_j = randnum(1, (12 / n_i) % board_size) + 1;
        }
        i = randnum(0, board_size - n_i);
        j = randnum(0, board_size - n_j);

        brain_selector_creator(selector, n_i, n_j, i, j);

        if (is_another_ship_available(selector, n_i * n_j)) {
            continue;
        }

        put_ship(selector, n_i * n_j);
        selector_to_ships_places(selector, n_i * n_j);

        p2.total_part += n_i * n_j;
    }

    copy_2Dchar_array(n_i, n_j, p[1], p2.board);
}
