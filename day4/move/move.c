#include <ncurses.h>
#include <unistd.h>

int main()
{
    initscr();

    move(10, 30);
    printw("GAME OVER\n");
    refresh();

    sleep(2);
    //getch();
    endwin();
    return 0;
}