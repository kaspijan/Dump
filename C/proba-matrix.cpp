#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<unistd.h>
#include<winuser.h>

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

int main(){
	system("COLOR A");
	//system("mode 60");
	system("COLOR 1 | COLOR 2");
	//SetConsoleDisplayMode(hStdOut, CONSOLE_FULLSCREEN_MODE,0);
	system("mode con COLS=700");
	//ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
	//SendMessage(GetConsoleWindow(),WM_SYSKEYDOWN,VK_RETURN,0x20000000);
	
	
	
	// retrieve screen buffer info
    CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
    GetConsoleScreenBufferInfo(hStdOut, &scrBufferInfo);

    // current window size
    short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
    short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

    // current screen buffer size
    short scrBufferWidth = scrBufferInfo.dwSize.X;
    short scrBufferHeight = scrBufferInfo.dwSize.Y;        

    // to remove the scrollbar, make sure the window height matches the screen buffer height
    COORD newSize;
    newSize.X = scrBufferWidth;
    newSize.Y = winHeight;

    // set the new screen buffer dimensions
    int Status = SetConsoleScreenBufferSize(hStdOut, newSize);
    if (Status == 0)
    {
        printf("Neki fail.\n");
        exit(Status);
    }
	
	//ShowScrollBar(GetConsoleWindow(), SB_BOTH, 0);
	SetConsoleDisplayMode(hStdOut, CONSOLE_FULLSCREEN_MODE,0);
	ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	
	//SetConsoleTextAttribute(hStdOut, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY));
	
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int windowLen = csbi.srWindow.Right-csbi.srWindow.Left;
	
	int tracker = 0;
	for(int i = 0; i < 1e5; i++){
		printf("%c      ", rand()%135 + 40);
		tracker += 7;
		if(tracker > windowLen - 5){
			printf("\n");
			tracker = 0;
			}
		sleep(0.05);	
	}
	
	return 0;
}
