#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    initscr();

    srand(time(NULL));

    while(1) {
        move(rand()%21,rand()%71);
        printw("*");
        refresh();
        usleep(100*1000);
    }
    

    sleep(2);

    // getch();
    endwin();
    return 0;
}