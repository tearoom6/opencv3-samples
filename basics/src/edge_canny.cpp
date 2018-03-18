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
            throw ("not enough parameters specified. Specify: <filename> [<threshold1>] [<threshold2>].");

        imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE).copyTo(src);

        double threshold1 = 40.0, threshold2 = 200.0;
        if (argc >= 3)
            threshold1 = atof(argv[2]);
        if (argc >= 4)
            threshold2 = atof(argv[3]);

        Canny(src, dst, threshold1, threshold2);

        imshow("src", src);
        imshow("dst", dst);
        imwrite("tmp/edge_canny.jpg", dst.getMat(ACCESS_RW));

        waitKey(0);
    }
    catch (const char* str)
    {
        cerr << str << endl;
    }
    return 0;
}

