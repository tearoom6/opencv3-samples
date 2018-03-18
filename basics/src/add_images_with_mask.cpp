//
// Original copyright:
// (c)Copyright Spacesoft corp., 2016 All rights reserved.
//                               Hiro KITAYAMA
//
#include <opencv2/opencv.hpp>
#pragma comment(lib,"opencv_world310.lib")

using namespace cv;
using namespace std;

static UMat makeMask(int width, int height)
{
    Size sz(width, height);
    UMat mask(sz, CV_8UC1, Scalar(0));
    Point p0 = Point(width / 4, height / 4);
    Point p1 = Point(width * 3 / 4, height * 3 / 4);
    rectangle(mask, p0, p1, Scalar(255), -1);

    return mask;
}

int main(int argc, char* argv[])
{
    try
    {
        UMat src1, src2, dst;

        if (argc < 3)
            throw ("not enough parameters specified. Specify: <filename1> <filename2>.");

        imread(argv[1]).copyTo(src1);
        imread(argv[2]).copyTo(src2);

        UMat mask = makeMask(src1.cols, src1.rows);
        add(src1, src2, dst, mask);

        imshow("src1", src1);
        imshow("src2", src2);
        imshow("dst", dst);
        imwrite("tmp/add_images_with_mask.jpg", dst.getMat(ACCESS_RW));

        waitKey(0);
    }
    catch (const char* str)
    {
        cerr << str << endl;
    }
    return 0;
}

