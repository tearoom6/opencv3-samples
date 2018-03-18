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
        UMat src1, src2, dst;

        if (argc < 3)
            throw ("not enough parameters specified. Specify: <filename1> <filename2>.");

        imread(argv[1]).copyTo(src1);
        imread(argv[2]).copyTo(src2);

        bitwise_or(src1, src2, dst);

        imshow("src1", src1);
        imshow("src2", src2);
        imshow("dst", dst);
        imwrite("tmp/or_images.jpg", dst.getMat(ACCESS_RW));

        waitKey(0);
    }
    catch (const char* str)
    {
        cerr << str << endl;
    }
    return 0;
}

