#include <stdio.h>
#include <ncurses.h>
#include <locale.h>

int main()
{
    // 한글셋팅
    setlocale(LC_CTYPE, "ko_KR.utf8");
    initscr();

    keypad(stdscr, TRUE);
    while(1) {
        int ch = getch();

        if(ch == KEY_LEFT) {
            printw("←LEFT\n");
            refresh();
        }
        else if(ch == KEY_RIGHT) {
            printw("→RIGHT\n");
            refresh();
        }
        else if(ch == KEY_UP) {
            printw("↑UP\n");
            refresh();
        }
        else if(ch == KEY_DOWN) {
            printw("↓DOWN\n");
            refresh();
        }
    }

    getch();
    endwin();
    return 0;
}