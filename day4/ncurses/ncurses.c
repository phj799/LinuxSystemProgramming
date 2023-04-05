#include <ncurses.h>

// 빌드 옵션 -lncursesw
int main()
{
  initscr();
  printw("hello world");
  refresh();

  getch();

  endwin();
  return 0;
}