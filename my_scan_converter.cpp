#include "my_scan_converter.h"
#include <stdlib.h>
#include <iostream>

void MyScanConverter::drawLine(ScreenBuffer *buf, int xbegin, int ybegin, int xend, int yend)
{

  // ====================

  // A line is "steep" if it is above a 45 degree angle
  const bool isSteep = (abs(yend - ybegin) > abs(xend - xbegin));

  // We swap x's and y's becuase it's the same line in a slightly different
  // direction, so we draw it as such
  if (isSteep) {
    std::swap(xbegin, ybegin);
    std::swap(xend, yend);
  }

  // If the line is in quadrant 2 or 3, then swap x's so we don't have to change
  // the loop's params
  if (xbegin > xend) {
    std::swap(xbegin, xend);
    std::swap(ybegin, yend);
  }

  int step;

  // Make the step negative if the line has negative slope
  if (ybegin > yend){
    step = -1;
  } else {
    step = 1;
  }

  // DX will always be >= 0 becuase of swapping, but DY won't
  int dx = xend - xbegin;
  int dy = abs(yend-ybegin);

  // ====================

  // Always energize the first pixel
  buf -> energizePixel(xbegin, ybegin);

  int y, p;

  p = 2 * dy - dx;

  y = ybegin;

  for (int x = xbegin + 1; x <= xend; x++) {
    if (p > 0) {
      p = p + 2 * dy - 2 * dx;
      y = y + step;
    } else {
      p = p + 2 * dy;
    }
    if (isSteep) {
      buf -> energizePixel(y, x);
    } else {
      buf -> energizePixel(x, y);
    }
  }
}

void drawTriangle(int a1, int a2, int b1, int b2, int c1, int c2) {
  
}
