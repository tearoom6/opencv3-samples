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
    if (argc < 2)
    {
        cerr << "no parameter specified." << endl;
        return -1;
    }

    // Mat to UMat - 1
    {
        Mat mat = imread(argv[1]);
        UMat umat;
        mat.copyTo(umat);
    }

    // Mat to UMat - 2
    {
        UMat umat;
        imread(argv[1]).copyTo(umat);
    }

    // Mat to UMat - 3
    {
        Mat mat = imread(argv[1]);
        UMat umat = mat.getUMat(ACCESS_RW);
    }

    // UMat to Mat
    {
        UMat umat;
        imread(argv[1]).copyTo(umat);
        Mat mat = umat.getMat(ACCESS_RW);
    }
    return 0;
}

