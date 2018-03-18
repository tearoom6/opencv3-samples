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
        UMat src, dst;

        if (argc < 2)
            throw ("not enough parameters specified. Specify: <filename>.");

        imread(argv[1]).copyTo(src);

        add(src, Scalar(128.0, 0.0, 0.0), dst);

        imshow("src", src);
        imshow("dst", dst);
        imwrite("tmp/add_scalar.jpg", dst.getMat(ACCESS_RW));

        waitKey(0);
    }
    catch (const char* str)
    {
        cerr << str << endl;
    }
    return 0;
}

