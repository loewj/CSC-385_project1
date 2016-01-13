#include "glsupport.h"
#include "screen_buffer.h"
#include "my_scan_converter.h"

static void initScene(ScreenBuffer * buf)
{
    MyScanConverter msc;

    // horizontal line forwards
    // msc.drawLine(buf, 30, 30, 50, 30);

    // horizontal line backwards
    // msc.drawLine(buf, 50, 30, 30, 30);

    // vertical line forwards
    //msc.drawLine(buf, 30, 20, 30, 60);

    // vertical line backwards
    // msc.drawLine(buf, 30, 60, 30, 20);

    // shallow positive slope
    // msc.drawLine(buf, 10, 10, 40, 30);

    // reversed shallow positive slope
    // msc.drawLine(buf, 40, 30, 10, 10);

    // deep positive slope
    // msc.drawLine(buf, 10, 10, 20, 40);

    // reversed deep positive slope
    // msc.drawLine(buf, 20, 40, 10, 10);

    // shallow negative slope
    // msc.drawLine(buf, 0, 30, 30, 10);

    // reversed shallow negative slope

    // origin to third quadrant

    // third quadrant to origin

    // origin to fourth quadrant

    // fourth quadrant to origin

    // msc.drawLine(buf, 50, 50, 50, 10);
    // msc.drawLine(buf, 10, 10, 50, 25);
    //
    // buf -> energizePixel(50, 25, 0.5);
    // buf -> energizePixel(50, 50, 0.5);
    // buf -> energizePixel(50, 10, 0.5);
}

int main(int argc, char **argv)
{
    try {
        glutInit(&argc, argv);

        int pixel_width = 8;
        int pixel_height = 8;
        int buffer_width = 64;
        int buffer_height = 64;

        cout << "screen buffer being constructed" << "\n";

        ScreenBuffer * buf = new ScreenBuffer(buffer_width, buffer_height, pixel_width, pixel_height);

        cout << "screen buffer constructed" << "\n";

        glewInit();

        initScene(buf);

        glutMainLoop();
        return 0;
    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
        return -1;
    }
}
