#include <stdio.h>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define N 7

char map[N][N+1] = {
    "#######",
    "#     #",
    "#^##  #",
    "#    a#",
    "#   ###",
    "#    Y#",
    "#######",
};

int nyM = 5;
int nxM = 1;
int ny = 1;
int nx = 1;
int gameSet = 0;
int hp = 100;
int fatal = 0;

bool isOut(int x, int y) {
    if(map[y][x]=='#') return true;
    return false;
}

void monster() {
    if(ny==nyM && nx==nxM) {
        usleep(500*1000);
        clear();
        mvprintw(10,20,"GAME OVER");
        refresh();
        sleep(1);
        gameSet = 1;
    }
}

void* moveM() {
    while(1)
    {
        if(gameSet==1) break;
        int dir = rand()%4;
        if(dir==0) { // 상
            if(map[nyM-1][nxM]==' ') nyM--;
        }
        else if(dir==1) { // 하
            if(map[nyM+1][nxM]==' ') nyM++;
        }
        else if(dir==2) { // 좌
            if(map[nyM][nxM-1]==' ') nxM--;
        }
        else if(dir==3) { // 우
            if(map[nyM][nxM+1]==' ') nxM++;
        }
        usleep(200*1000);
    }
}

void holyGrail() {
    if(map[ny][nx]=='Y') {
        usleep(500*1000);
        clear();
        mvprintw(10,24,"WIN (%d)", hp);
        refresh();
        sleep(1);
        gameSet = 1;
    }
}

void thorn() {
    if(map[ny][nx]=='^') {
        if(fatal == 0) {
            hp -= 10;
            fatal = 1;
        }
    }
    else fatal = 0;

    if(hp<=0) {
        usleep(500*1000);
        clear();
        mvprintw(10,20,"GAME OVER");
        refresh();
        sleep(1);
        gameSet = 1;
    }
}

void apple() {
    if(map[ny][nx]=='a') {
        hp += 10;
        map[ny][nx]=' ';
    }
}

void print()
{
    clear();
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {
            if ( y == ny && x == nx ) {
                printw("@");
            }
            else if ( y == nyM && x == nxM ) {
                printw("M");
            }
            else {
                printw("%c", map[y][x]);
            }
        }
        printw("\n");
    }
    printw("HP : %d\n", hp);
    refresh();
}

int main()
{
    // 한글셋팅
    setlocale(LC_CTYPE, "ko_KR.utf8");
    initscr();

    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    pthread_t tid;
    pthread_create(&tid, NULL, moveM, NULL);

    while(1) {
        print();
        monster();
        holyGrail();
        thorn();
        apple();

        int ch = getch();
        if(ch==ERR) ch = 0;

        if(ch == KEY_LEFT) {
            if(!isOut(nx-1, ny)) nx--;
        }
        else if(ch == KEY_RIGHT) {
            if(!isOut(nx+1, ny)) nx++;
        }
        else if(ch == KEY_UP) {
            if(!isOut(nx, ny-1)) ny--;
        }
        else if(ch == KEY_DOWN) {
            if(!isOut(nx, ny+1)) ny++;            
        }

        if(gameSet==1) break;
    }

    pthread_join(tid, NULL);
    getch();
    endwin();

    return 0;
}