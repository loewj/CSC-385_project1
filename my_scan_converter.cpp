#include "my_scan_converter.h"

#include <iostream>

void MyScanConverter::drawLine(ScreenBuffer *buf, int xbegin, int ybegin, int xend, int yend)
{
    // if (xend < xbegin) {
    //     int lowx = xend;
    //     xend = xbegin;
    //     xbegin = lowx;
    // }
    // if (yend < ybegin) {
    //     int lowy = yend;
    //     yend = ybegin;
    //     ybegin = lowy;
    // }
    //
    // double dx = xend - xbegin;
    // double dy = yend - ybegin;
    //
    // if (dx == 0) {
    //     for (int y = ybegin; y <= yend; y++) {
    //         buf -> energizePixel(xbegin, y);
    //     }
    // } else {
    //     for (int x = xbegin; x <= xend; x++) {
    //         int y = ybegin + dy * (x - xbegin) / dx;
    //         buf -> energizePixel(x, y);
    //     }
    // }

    // ================================================

    // Starting point is at the origin (xbegin, ybegin)
    // Swap if xbegin > xend... makes algorithm more "universal"

    // Should the next point be at (ebegin + 1, ybegin)?
    // Or (ebegin + 1, ybegin + 1)

    int dx = xend - xbegin;
    int dy = yend - ybegin;

    int d = 2 * dx - dy;

    buf -> energizePixel(xbegin, ybegin);

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
