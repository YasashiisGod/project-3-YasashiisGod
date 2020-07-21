/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);
  //

  int j;
  for (j= 50; j<70; j++){
    int row = j;
    for (int col = j; col <= screenWidth - j; col++)
      drawPixel(row, col+75,COLOR_WHITE);
  }

  for (j= 0; j<50; j++){
    int row =j;
    for (int col = j; col <= screenWidth - j; col++)
      drawPixel(row, col,COLOR_WHITE);
  }
  //
  drawString5x7(20,20, "hello", COLOR_GREEN, COLOR_RED);

  fillRectangle(30,30, 60, 60, COLOR_ORANGE);
  
}
