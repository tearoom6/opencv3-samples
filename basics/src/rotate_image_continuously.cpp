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

        if (argc<2)
            throw ("not enough parameters specified. Specify: <filename>.");

        imread(argv[1]).copyTo(src);

        if (src.empty())
            throw ("failed to open file.");

        Point2f center = Point2f(static_cast<float>(src.cols / 2),
            static_cast<float>(src.rows / 2));

        imshow("src", src);
        namedWindow("dst", CV_WINDOW_AUTOSIZE);
        for (float angle = 0.0; angle<360.0; angle += .5)
        {
            Mat affineTrans = getRotationMatrix2D(center, angle, 1.0);
            warpAffine(src, dst, affineTrans, src.size(), INTER_CUBIC);
            imshow("dst", dst);
            if (waitKey(1) >= 0) break;
        }
    }
    catch (const char* str)
    {
        cerr << str << endl;
    }
    return 0;
}

