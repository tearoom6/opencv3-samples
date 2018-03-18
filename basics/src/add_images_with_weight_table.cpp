//
// Original copyright:
// (c)Copyright Spacesoft corp., 2016 All rights reserved.
//                               Hiro KITAYAMA
//
#include <opencv2/opencv.hpp>
#pragma comment(lib,"opencv_world310.lib")

using namespace cv;
using namespace std;

// create cos k mat
Mat createCosMat(const int rows, const int cols)
{
    Mat mat(rows, cols, CV_8UC3, Scalar(0));
    Point center = Point(cols / 2, rows / 2);
    double radius = sqrt(pow(center.x, 2) + pow(center.y, 2));

    for (int y = 0; y < mat.rows; y++)
    {
        for (int x = 0; x < mat.cols; x++)
        {
            // distance from center
            double distance = sqrt(pow(center.x - x, 2) + pow(center.y - y, 2));
            // radius=π, current radian
            double radian = (distance / radius) * (double)CV_PI;
            // cosθ, normalize -1.0～1.0 to  0～1.0
            double Y = (cos(radian) + 1.0) / 2.0;
            // normalize (Y) 0～1.0 to 0.0～255.0
            mat.at<Vec3b>(y, x)[0] =
                mat.at<Vec3b>(y, x)[1] =
                mat.at<Vec3b>(y, x)[2] = (unsigned char)(Y * 255.0f);
        }
    }
    return mat;
}

Mat mulMat(const Mat mat, const Mat table)
{
    Mat dst, mat32f, table32f, dst32f;

    mat.convertTo(mat32f, CV_32FC3);
    table.convertTo(table32f, CV_32FC3);
    table32f /= 255.0f;
    multiply(mat32f, table32f, dst32f);
    dst32f.convertTo(dst, CV_8UC3);

    return dst;
}

int main(int argc, char* argv[])
{
    try
    {
        Mat src1, src2, intSrc1, intSrc2, dst;

        if (argc < 3)
            throw ("not enough parameters specified. Specify: <filename1> <filename2>.");

        imread(argv[1]).copyTo(src1);
        imread(argv[2]).copyTo(src2);

        Mat weightMat = createCosMat(src1.rows, src2.cols);
        Mat iWeightMat = Scalar(255, 255, 255) - weightMat;

        intSrc1 = mulMat(src1, weightMat);
        intSrc2 = mulMat(src2, iWeightMat);
        add(intSrc1, intSrc2, dst);

        imshow("src1", src1);
        imshow("src2", src2);
        imshow("dst", dst);
        imwrite("tmp/add_images_with_weight_table.jpg", dst);

        waitKey(0);
    }
    catch (const char* str)
    {
        cerr << str << endl;
    }
    return 0;
}

