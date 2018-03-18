//
// Original copyright:
// (c)Copyright Spacesoft corp., 2016 All rights reserved.
//                               Hiro KITAYAMA
//
#include <opencv2/opencv.hpp>
#pragma comment(lib,"opencv_world310.lib")

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    try
    {
        if (argc < 2)
            throw ("not enough parameters specified. Specify: <filename>.");

        Mat mat = imread(argv[1]);
        if (mat.empty())
            throw ("Failed to open file.");

        Point center = Point(mat.cols / 2, mat.rows / 2);
        Size sz = Size(mat.cols / 2, mat.rows / 2);

        ellipse(mat, center, sz, 0, 0, 360, Scalar(255,0,0), 3, 4);
        sz.width -= 20;
        sz.height -= 50;
        ellipse(mat, center, sz, 15, 10, 360, Scalar(255,255,0), 2, 4);

        imshow("mat", mat);
        imwrite("tmp/ellipse.jpg", mat);

        waitKey(0);
    }
    catch (const char* str)
    {
        cerr << str << endl;
    }
    return 0;
}

