// constant definitions
enum {BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
#define bg(c) (c+10)            //macro defintion
// function declarations
void clearScreen(void);
void setColors(short fg, short bg);
void resetColors(void);
void barChart(int []);

