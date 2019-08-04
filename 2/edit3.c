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
	char password[MAX_LEN + 1];
	int x, y;
	char f;
	int ch;
	initscr();
	signal (SIGWINCH, sig_winch);
	curs_set(1);
	delwin(wnd);
	curs_set(1);
	//move(8,4);
	//wmove(stdscr,9, 0);
	attroff(A_BOLD);//format texta
	//attron(A_BLINK);
	keypad(stdscr, TRUE);
	//getyx(stdscr, y, x);
	//mvwaddch(win, y, x-1, '_');
	while ((ch = wgetch(stdscr)) != KEY_BACKSPACE) {
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
		//if (ch == KEY_BACKSPACE)
		  //  {
		//	if (i==0) continue;
		//	getyx(win, y, x);
		//	mvwaddch(win, y, x-1, ' ');
		//	wrefresh(win);
		//	wmove(win, y, x-1);
		//	i--;
		//	continue;
		}
		getyx(stdscr, y, x);
	//wscanw(stdscr,y,x,"%c", &f);
	//move(10, 10);
	//attroff(A_BLINK);
	//printw("hop hay:%c", f);
	printw("Press any key to continue...");
	//move(10, 4);
	//attroff(A_BLINK);
	//printw("hop hay");
	refresh();
	getch();
	endwin();
	exit(EXIT_SUCCESS);
}
