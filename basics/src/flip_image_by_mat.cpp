//
// Original copyright:
// (c)Copyright Spacesoft corp., 2016 All rights reserved.
//                               Hiro KITAYAMA
//
#include <opencv2/opencv.hpp>
#pragma comment(lib,"opencv_world310.lib")

using namespace cv;
using namespace std;

static void cvt(const Mat& src, Mat& dst)
{
    flip(src, dst, 1);
}

int main(int argc, char* argv[])
{
    Mat src, dst;

    if (argc < 2)
    {
        cerr << "no parameter specified." << endl;
        return -1;
    }

    src = imread(argv[1]);
    cvt(src, dst);

    imshow("src", src);
    imshow("dst", dst);

    waitKey(0);

    return 0;
}

