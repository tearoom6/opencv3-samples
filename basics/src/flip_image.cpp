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
        if (argc<3)
            throw ("not enough parameters specified. Specify: <file name> <flip code>.");

        Mat src = imread(argv[1]);
        int flipCode = atoi(argv[2]);

        if (src.empty())
            throw ("failed to open file.");

        Mat dst;
        flip(src, dst, flipCode);

        imshow("src", src);
        imshow("dst", dst);

        waitKey(0);
    }
    catch (const char* str)
    {
        cerr << str << endl;
    }
    return 0;
}

