#include <ncurses.h>
#include <unistd.h>

// 빌드 옵션 -lncursesw
int main()
{
  initscr();
  for(char ch='A'; ch <= 'Z'; ch++) {
    printw("%c",ch);
    refresh();
    usleep(100*1000);
    clear();
  }

  for (int i = 0 ; i < 15; i++) {
    printw("=");
    refresh();
  }
  printw("\nGO GO GO GO GO\n");
  refresh();
  for (int i = 0 ; i < 15; i++) {
    printw("=");
    refresh();
  }

  sleep(2);
  //getch();
  endwin();
  return 0;
}
