#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>

// Configurable parameters
#define WIDTH 40
#define HEIGHT 20
#define CIRCLE_CHAR 'O'
#define FRAME_RATE 100

// Game state
int circle_x, circle_y;
bool is_running;

void setup() {
    srand(time(NULL));
    circle_x = rand() % WIDTH;
    circle_y = rand() % HEIGHT;
    is_running = true;
}

void render() {
    system("cls"); // Clear the console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == circle_y && j == circle_x) {
                printf("%c", CIRCLE_CHAR);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void update() {
    if (_kbhit()) {
        char ch = _getch();
        if (ch == 'q') is_running = false; // Quit if 'q' is pressed
    }
    // You can add more game logic to move the circle here.
}

int main() {
    setup();
    while (is_running) {
        render();
        update();
        _sleep(FRAME_RATE);
    }
    return 0;
}