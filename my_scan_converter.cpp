#include "my_scan_converter.h"
#include <stdlib.h>
#include <iostream>

// TODO: negative slope, steep lines, clean code

int detectLine(int dx, int dy) {

  if (dy == 0) {
    cout << "The line is horizontal" << "\n";
    return 1;
  } else if (dx == 0) {
    cout << "The line is vertical" << "\n";
    return 2;
  } else if (dy > 0) {
    cout << "The line is diagonal w/ positive slope" << "\n";
    return 3;
  } else {
    cout << "The line is diagonal w/ negative slope" << "\n";
    return 4;
  }
}

void swapStartEnd(int &xbegin, int &ybegin, int &xend, int &yend) {

    if (xbegin > xend && ybegin ) {
      int temp = xbegin;
      xbegin = xend;
      xend = temp;
      temp = ybegin;
      ybegin = yend;
      yend = temp;
    }

}

void MyScanConverter::drawLine(ScreenBuffer *buf, int xbegin, int ybegin, int xend, int yend)
{

    // Swap points if necessary
    swapStartEnd(xbegin, ybegin, xend, yend);

    int dx = xend - xbegin;
    int dy = yend - ybegin;

    int lineType = detectLine(dx, dy);

    const bool isSteep = (abs(dy) > abs(dx));

    cout << "Steep :: " << isSteep << "\n";

    // If the line is steep, all we have to do is swap x and y...


    // energize the fist pixel
    buf -> energizePixel(xbegin, ybegin);

    if (lineType == 1) {
      for (int x = xbegin + 1; x < xend; x++) {
        buf -> energizePixel(x, ybegin);
      }
    } else if (lineType == 2) {
      for (int y = ybegin + 1; y < yend; y++) {
        buf -> energizePixel(xbegin, y);
      }
    } else if (lineType == 3) {

      // int d = 2 * dx - dy;
      // int y = ybegin;
      // for (int x = xbegin + 1; x < xend; x++) {
      //   buf -> energizePixel(x, y);
      //   d = d + (2 * dy);
      //   if (d > 0) {
      //     y++;
      //     d = d - (2 * dx);
      //   }
      // }

      if (isSteep) {

        int p = 2 * dx - dy;

        int x = xbegin;
        for (int y = ybegin + 1; y <= yend; y++) {
          if (p > 0) {
            x++;
            p = p + 2 * dx - 2 * dy;
          } else {
            p = p + 2 * dx;
          }
          buf -> energizePixel(x, y);
        }
      } else {
        int p = 2 * dx - dy;

        int y = ybegin;
        for (int x = xbegin + 1; x <= xend; x++) {
          if (p > 0) {
            y++;
            p = p + 2 * dy - 2 * dx;
          } else {
            p = p + 2 * dy;
          }
          buf -> energizePixel(x, y);
        }
      }

    } else {

      

    }
}
