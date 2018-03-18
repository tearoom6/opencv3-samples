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
            throw ("not enough parameters specified. Specify: <filename> [<ksize1>] [<ksize2>] [<sigma1>] [<sigma2>].");

        imread(argv[1]).copyTo(src);

        if (src.empty())
            throw ("Failed to open file.");

        int ksize1 = 11, ksize2 = 11;
        if (argc >= 3)
            ksize1 = atoi(argv[2]);
        if (argc >= 4)
            ksize2 = atoi(argv[3]);
        if ((ksize1 % 2) == 0 || ksize1 < 0 || (ksize2 % 2) == 0 || ksize2 < 0)
            throw ("both ksize must be positive and odd.");

        double sigma1 = 10.0, sigma2 = 10.0;
        if (argc >= 5)
            sigma1 = atof(argv[4]);
        if (argc >= 6)
            sigma2 = atof(argv[5]);

        GaussianBlur(src, dst, Size(ksize1, ksize2), sigma1, sigma2);

        imshow("src", src);
        imshow("dst", dst);
        imwrite("tmp/blur_gaussian.jpg", dst.getMat(ACCESS_RW));

        waitKey(0);
    }
    catch (const char* str)
    {
        cerr << str << endl;
    }
    return 0;
}

