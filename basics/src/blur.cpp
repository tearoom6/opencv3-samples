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
            throw ("not enough parameters specified. Specify: <filename> [<ksize>].");

        int ksize = 11;
        if (argc >= 3)
            ksize = atoi(argv[2]);

        imread(argv[1]).copyTo(src);

        blur(src, dst, Size(ksize, ksize));

        imshow("src", src);
        imshow("dst", dst);
        imwrite("tmp/blur.jpg", dst.getMat(ACCESS_RW));

        waitKey(0);
    }
    catch (const char* str)
    {
        cerr << str << endl;
    }
    return 0;
}

