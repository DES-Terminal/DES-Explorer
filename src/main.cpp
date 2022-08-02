#include "DES_Explorer.hpp"

#include <ncurses.h>

int main(int argc, char **argv)
{
  initscr();
  printw("Hello!\n");
  printw("ncurses sample!");
  getch();
  endwin();
  return 0;
}