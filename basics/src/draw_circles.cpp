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
        UMat img0(400, 400, CV_8UC3, Scalar(150, 150, 150));
        circle(img0, Point(200, 200), 50, Scalar(255, 0, 0));
        imwrite("tmp/circle0.jpg", img0.getMat(ACCESS_RW));

        UMat img1(400, 400, CV_8UC3, Scalar(150, 150, 150));
        circle(img1, Point(200, 200), 100, Scalar(0, 255, 0), 3);
        imwrite("tmp/circle1.jpg", img1.getMat(ACCESS_RW));

        UMat img2(400, 400, CV_8UC3, Scalar(150, 150, 150));
        circle(img2, Point(200, 200), 150, Scalar(0, 0, 255), -1);
        imwrite("tmp/circle2.jpg", img2.getMat(ACCESS_RW));
    }
    catch (const char* str)
    {
        cerr << str << endl;
    }
    return 0;
}

