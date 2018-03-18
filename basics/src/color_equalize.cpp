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

        imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE).copyTo(src);

        equalizeHist(src, dst);

        imshow("src", src);
        imshow("dst", dst);
        imwrite("tmp/equalize.jpg", dst.getMat(ACCESS_RW));

        waitKey(0);
    }
    catch (const char* str)
    {
        cerr << str << endl;
    }
    return 0;
}

