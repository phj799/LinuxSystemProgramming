#include <ncurses.h>
#include <unistd.h>

// 빌드 옵션 -lncursesw
int main()
{
  initscr();
  int dir = 0;
  while(1) {
    if(dir==0) {
        for (int i = 0; i < 30; i++) {
            for(int j = 0; j < i; j++) {
                printw("#");
                refresh();
            }
            usleep(50*1000);
            clear();
        dir = 1;
        }
    }
    else if(dir==1) {
        for (int i = 29; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            printw("#");
            refresh();
        }
        usleep(50*1000);
        clear();
        dir = 0;
        }
    }
  }
  
  //getch();
  endwin();
  return 0;
}
