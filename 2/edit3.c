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
void vvod(char *path)
{
	FILE *fd;
	int buf;
	//fd=fopen("./txt.txt","r");
	fd=fopen(path,"r");
	while ((buf = getc(fd)) != EOF) 
	{
    	addch(buf);
    }
    fclose (fd);
}
void edit(char *path)
{
	int ch;
	while ((ch = wgetch(stdscr)) != KEY_F(9)) {
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
		if(ch == KEY_F(8))
		{
			save(path);
		}
		}
}
void exit6()
{
	endwin();
	exit(EXIT_SUCCESS);
}
void save(char *path)
{	
	int lines,columns;
	FILE *fd;
	fd = fopen (path, "w");
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
	int func;
	//int buf;
	//argv[1];
	initscr();
	signal (SIGWINCH, sig_winch);
	//delwin(wnd);
	curs_set(1);
	attron(A_BOLD);//format texta
	keypad(stdscr, TRUE);
	//move(LINES-3, 1);
	//printw("Wellcome to best text editor in the world , F6-open file, F7-close, F8-save\n");
	move(0,0);
	for (;;)
	{	
		func = wgetch(stdscr);
		getyx(stdscr,y,x);
		if(func == KEY_F(6))
		{
			vvod(argv[1]);
		}
		if(func == KEY_F(7))
		{
			edit(argv[1]);
		}
		if(func == KEY_F(8))
		{
			save(argv[1]);
		}
		if(func == KEY_F(9))
		{
			exit6();
		}
		refresh();
	}
	//vvod();
	//edit();
	//getyx(stdscr, y, x);
	//write1();
	//refresh();
	endwin();
	exit(EXIT_SUCCESS);
}
