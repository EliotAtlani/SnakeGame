// NonBlockingInput.cpp
#include "NonBlockingInput.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    // Get current terminal attributes
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    // Disable canonical mode and echo
    newt.c_lflag &= ~(ICANON | ECHO);
    // Set new attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    // Set non-blocking read
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    // Try to read a character
    ch = getchar();

    // Restore old settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    // If a character was read, put it back into stdin
    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int getch(void)
{
    struct termios oldt, newt;
    int ch;

    // Get current terminal attributes
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    // Disable canonical mode and echo
    newt.c_lflag &= ~(ICANON | ECHO);
    // Set new attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Read a character
    ch = getchar();

    // Restore old settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}
