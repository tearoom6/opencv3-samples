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

        Point p = Point(50, mat.rows / 2 - 50);
        putText(mat, "Hello OpenCV", p, FONT_HERSHEY_TRIPLEX,
            0.8, Scalar(250, 200, 200), 2, CV_AA);

        imshow("mat", mat);
        imwrite("tmp/text.jpg", mat);

        waitKey(0);
    }
    catch (const char* str)
    {
        cerr << str << endl;
    }
    return 0;
}

