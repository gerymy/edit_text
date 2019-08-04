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
/*void get_password(WINDOW * win, char * password, int max_len)
{
int i = 0;
int ch;
while (((ch = wgetch(win)) != 10) && (i < max_len-1)) {
if (ch == KEY_BACKSPACE) {int x, y;
if (i==0) continue;
getyx(win, y, x);
mvwaddch(win, y, x-1, ' ');
wrefresh(win);
wmove(win, y, x-1);
i--;
continue;
}
password[i++] = ch;
wechochar(win, '*');
}
password[i] = 0;
wechochar(win, '\n');}
*/
int main(int argc, char ** argv)
{
	WINDOW * wnd;
	WINDOW * subwnd;
	char password[MAX_LEN + 1];
	initscr();
	signal (SIGWINCH, sig_winch);
	//cbreak();
	//noecho();
	//curs_set(TRUE);
	//start_color();
	//refresh();
	//init_pair(1,COLOR_BLACK, COLOR_GREEN);
	//wattron(stdscr, A_BOLD);
	//init_pair(2, COLOR_BLUE, COLOR_WHITE);//устанавливаем цвет 1 фон 2 шрифт
	//init_pair(3,COLOR_RED, COLOR_WHITE);
	//init_pair(1,COLOR_BLACK, COLOR_RED);
	//wbkgd(stdscr,COLOR_PAIR(1));
	//refresh();
	//wnd = newwin(5,23,2, 2);
	//wattron(wnd, COLOR_PAIR(2));
	//box(wnd, '|', '-');
	//wprintw(wnd, "Enter your name ...\n");
	//subwnd = derwin(wnd, 4, 16, 1, 1);
	//wgetnstr(wnd, name, MAX_NAME_LEN);
	//name [MAX_NAME_LEN]=0;
	//wbkgd(subwnd, COLOR_PAIR(3));
	//wattron(subwnd, A_BOLD);
	//wbkgd(stdscr,COLOR_PAIR(1));
	//attron(A_BOLD);
	//wmove (stdscr,5, 15);
	//printw("Hello, brave new curses world! i nemnogo udlennim stroku ");
	//wprintw(subwnd, "Hello, brave new curses world!i nemnogo udlennim ");
	//wprintw(wnd, "Hello, %s", name);
	//keypad(wnd, TRUE);
	//wprintw(wnd, "Enter password...\n");
	curs_set(1);
	//get_password(wnd, password, MAX_LEN);
	//wattron(wnd, A_BLINK);
	//if (strcmp(password, RIGHT_PASSWORD) == 0) wprintw(wnd, "ACCESS GRANTED!");
	//else wprintw(wnd, "ACCESS DENIED!");	
	//wrefresh(wnd);
	//wrefresh(subwnd);
	//delwin(subwnd);
	delwin(wnd);
	curs_set(1);
	move(8,4);
	//wmove(stdscr,9, 0);
	attroff(A_BOLD);//format texta
	attron(A_BLINK);
	//wmove(stdscr,7, 16);//perremewenie curs
	printw("Press any key to continue...");
	move(8, 4);
	attroff(A_BLINK);
	printw("hop hay");
	refresh();
	getch();
	endwin();
	exit(EXIT_SUCCESS);
}
