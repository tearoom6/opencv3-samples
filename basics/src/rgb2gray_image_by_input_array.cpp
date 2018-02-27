//
// Original copyright:
// (c)Copyright Spacesoft corp., 2016 All rights reserved.
//                               Hiro KITAYAMA
//
#include <opencv2/opencv.hpp>
#pragma comment(lib,"opencv_world310.lib")

using namespace cv;
using namespace std;

static void cvt(InputArray inputSrc_)
{
    //Mat src = inputSrc_.getMat();
    //Mat dst;

    //cvtColor(src, dst, COLOR_RGB2GRAY);

    //imshow("src", src);
    //imshow("dst", dst);

    int type = inputSrc_.kind() & _InputArray::KIND_MASK;

    switch(type)
    {
        case _InputArray::MAT: // if (inputSrc_.isMat())
        {
            // Flip image.
            Mat src = inputSrc_.getMat();
            Mat dst;
            flip(src, dst, 1);

            imshow("src", src);
            imshow("dst", dst);
        }
        break;

        case _InputArray::UMAT: // if (inputSrc_.isUMat())
        {
            // rbg2gray image.
            UMat usrc = inputSrc_.getUMat();
            UMat udst;
            cvtColor(usrc, udst, COLOR_RGB2GRAY);

            imshow("usrc", usrc);
            imshow("udst", udst);
        }
        break;
    }
}

int main(int argc, char* argv[])
{
    Mat src;
    UMat usrc;

    if (argc < 2)
    {
        cerr << "no parameter specified." << endl;
        return -1;
    }

    src = imread(argv[1]);
    cvt(src);

    waitKey(0);
    destroyAllWindows();

    src.copyTo(usrc);
    cvt(usrc);

    waitKey(0);

    return 0;
}

