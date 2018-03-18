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

        Point p0 = Point(mat.cols / 8, mat.rows / 8);
        Point p1 = Point(mat.cols * 7 / 8, mat.rows * 7 / 8);

        rectangle(mat, p0, p1, Scalar(0, 255, 0), 5, 8);

        Point p2 = Point(mat.cols * 2 / 8, mat.rows * 2 / 8);
        Point p3 = Point(mat.cols * 6 / 8, mat.rows * 6 / 8);
        rectangle(mat, p2, p3, Scalar(0, 255, 255), 2, 4);

        imshow("mat", mat);
        imwrite("tmp/square.jpg", mat);

        waitKey(0);
    }
    catch (const char* str)
    {
        cerr << str << endl;
    }
    return 0;
}

