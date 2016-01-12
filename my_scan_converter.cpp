#include "my_scan_converter.h"

#include <iostream>

int DetectLine(int xbegin, int ybegin, int xend, int yend) {

  if (ybegin == yend) {
    cout << "The line is horizontal" << "\n";
    return 1;
  } else if (xbegin == xend) {
    cout << "The line is vertical" << "\n";
    return 2;
  } else {
    cout << "The line is diagonal" << "\n";
    return 3;
  }
}

void MyScanConverter::drawLine(ScreenBuffer *buf, int xbegin, int ybegin, int xend, int yend)
{

    // Should "massage" the points passed into the drawLine function here...

    int lineType = DetectLine(xbegin, ybegin, xend, yend);

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
    } else {

      // Draw a diagonal line

      // A = dy

      // D = A + (1/2)B
      // If D evaluates to positive, then plot (xbegin + 1, ybegin + 1)
        // Else, plot (xbegin + 1, ybegin)


      int dx = xend - xbegin;
      int dy = yend - ybegin;

      int d = 2 * dx - dy;

      int y = ybegin;

      for (int x = xbegin + 1; x < xend; x++) {
        buf -> energizePixel(x, y);
        d = d + (2 * dy);
        if (d > 0) {
          y++;
          d = d - (2 * dx);
        }
      }
    }

}
