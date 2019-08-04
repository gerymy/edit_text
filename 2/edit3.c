#include<termios.h>
#include<sys/ioctl.h>
#include<signal.h>
#include<stdlib.h>
#include<curses.h>
//#include"edit.h"
int x,y;
void sig_winch(int signo)
{
	struct winsize size;
	ioctl(fileno(stdout),TIOCGWINSZ, (char *) &size);
	resizeterm(size.ws_row, size.ws_col);
}
void vvod()
{
	FILE *fd;
	int buf;
	fd=fopen("txt.txt","r");
	while ((buf = getc(fd)) != EOF) 
	{
    	addch(buf);
    }
    fclose (fd);
}
void edit()
{
	int ch;
	while ((ch = wgetch(stdscr)) != CTRL('D')) {
		if(ch == KEY_UP)	
		{
		getyx(stdscr, y, x);
		wmove(stdscr, y-1, x);
		//mvwaddch(stdscr, y-1, x-1, '|');
		refresh();
		continue;
		}
		if(ch == KEY_DOWN)	
		{
		getyx(stdscr, y, x);
		wmove(stdscr, y+1, x);
		//mvwaddch(stdscr, y+1, x-1, '|');
		refresh();
		continue;
		}
		if(ch == KEY_LEFT)	
		{
		getyx(stdscr, y, x);
		//mvwaddch(stdscr, y, x-2, '-');
		wmove(stdscr, y, x-1);
		refresh();
		continue;
		}
		if(ch == KEY_RIGHT)	
		{
		getyx(stdscr, y, x);
		//mvwaddch(stdscr, y, x, '-');
		wmove(stdscr, y, x+1);
		refresh();
		continue;
		}
		}
}
void write1()
{	
	int lines,columns;
	FILE *fd;
	fd = fopen ("txt.txt", "w");
          for ( lines = 0; lines < LINES - 1; lines++) {
            for ( columns = 0; columns < COLS; columns++)
            {
            	if(mvinch(lines,columns)== '@') 
            		{
            			refresh();
						endwin();
						exit(EXIT_SUCCESS);
            		}
            	putc (mvinch (lines, columns) & A_CHARTEXT, fd);
            }
            putc('\n', fd);
          }
          fclose(fd);
}
int main(int argc, char ** argv)
{
	//WINDOW * wnd;
	//WINDOW * subwnd;
	FILE *fd;
	//int line=0;
	//int ch;
	//int buf;
	initscr();
	signal (SIGWINCH, sig_winch);
	//delwin(wnd);
	curs_set(1);
	attroff(A_BOLD);//format texta
	keypad(stdscr, TRUE);
	vvod();
	edit();
	getyx(stdscr, y, x);
	write1();
	refresh();
	endwin();
	exit(EXIT_SUCCESS);
}
