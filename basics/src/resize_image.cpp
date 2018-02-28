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

        if (argc<3)
            throw ("not enough parameters specified. Specify: <filename> <scale W> [<scale H>].");

        float scaleW = static_cast<float>(atof(argv[2]));
        float scaleH = scaleW;
        if (argc == 4)
            scaleH = static_cast<float>(atof(argv[3]));

        imread(argv[1]).copyTo(src);
        if (src.empty())
            throw ("failed to open file.");

        int width = static_cast<int>(src.cols*scaleW);
        int height = static_cast<int>(src.rows*scaleH);
        resize(src, dst, Size(width, height));

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

