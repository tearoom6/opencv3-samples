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
        if (src1.empty() || src2.empty() || src1.size != src2.size)
            throw ("failed to open file, or images are not same size.");

        src1.copyTo(dst);
        Rect roi = Rect(src1.cols / 4, src1.rows / 4, src1.cols / 2, src1.rows / 2);
        UMat src1Roi(src1, roi);
        UMat src2Roi(src2, roi);
        UMat dstRoi(dst, roi);

        add(src1Roi, src2Roi, dstRoi);

        imshow("src1", src1);
        imshow("src2", src2);
        imshow("dst", dst);
        imwrite("tmp/add_images_with_roi.jpg", dst.getMat(ACCESS_RW));

        waitKey(0);
    }
    catch (const char* str)
    {
        cerr << str << endl;
    }
    return 0;
}

