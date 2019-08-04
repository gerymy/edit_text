#include<termios.h>
#include<sys/ioctl.h>
#include<signal.h>
#include<stdlib.h>
#include<curses.h>
#define MAX_LEN 15
#define RIGHT_PASSWORD "pass"
void sig_winch(int signo)
{
	struct winsize size;
	ioctl(fileno(stdout),TIOCGWINSZ, (char *) &size);
	resizeterm(size.ws_row, size.ws_col);
}

int main(int argc, char ** argv)
{
	WINDOW * wnd;
	WINDOW * subwnd;
	FILE *fd;
	fd=fopen("txt.txt","r");
	int x, y;
	int n,l,i, test;
	int line=0;
	char f;
	int ch;
	int buf;
	initscr();
	signal (SIGWINCH, sig_winch);
	delwin(wnd);
	curs_set(1);
	attroff(A_BOLD);//format texta
	keypad(stdscr, TRUE);
	while ((buf = getc(fd)) != EOF) {
            if (buf == '\n') line++;
            if (line > LINES - 2) break;
            addch(buf);
          }
    fclose (fd);
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
	getyx(stdscr, y, x);
fd = fopen ("txt.txt", "w");
          for ( l = 0; l < LINES - 1; l++) {
            //n = COLS;
            for ( i = 0; i < COLS; i++)
            {
            	
            	if(mvinch(l,i)== '@') 
            		{
            			refresh();
						endwin();
						exit(EXIT_SUCCESS);
            		}
            	putc (mvinch (l, i) & A_CHARTEXT, fd);
            }
            	test=mvinch(l,i);
            putc('\n', fd);
          }
          fclose(fd);
	refresh();
	endwin();
	exit(EXIT_SUCCESS);
}
