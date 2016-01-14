#include "glsupport.h"
#include "screen_buffer.h"
#include "my_scan_converter.h"
#include "math.h"
#include "stdio.h"

static void testScene(ScreenBuffer * buf) {
    MyScanConverter m;
    for (float angle = 0; angle < M_PI * 2; angle += M_PI/32) {
        float a_y = sin(angle) * 150;
        float a_x = cos(angle) * 150;
        m.drawLine(buf, 200, 200, 200 + (int) a_x, 200 + (int) a_y);
    }
}

static void initScene(ScreenBuffer * buf) {
    MyScanConverter msc;
    msc.drawLine(buf, 10, 10, 50, 10);
    msc.drawLine(buf, 10, 10, 50, 50);
    msc.drawLine(buf, 50, 50, 50, 10);
    cout << "diagonal" << "\n";
    msc.drawLine(buf, 10, 10, 50, 25);

    buf -> energizePixel(50, 25, 0.5);
    buf -> energizePixel(50, 50, 0.5);
    buf -> energizePixel(50, 10, 0.5);
}

int main(int argc, char **argv) {
    try {
        glutInit(&argc, argv);

        int pixel_width = 2;
        int pixel_height = 2;
        int buffer_width = 400;
        int buffer_height = 400;

        cout << "screen buffer being constructed" << "\n";

        ScreenBuffer * buf = new ScreenBuffer(buffer_width, buffer_height, pixel_width, pixel_height);

        cout << "screen buffer constructed" << "\n";

        glewInit();

        //initScene(buf);
        testScene(buf);

        glutMainLoop();
        return 0;
    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
        return -1;
    }
}
