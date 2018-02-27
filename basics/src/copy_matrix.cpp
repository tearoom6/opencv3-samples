//
// Original copyright:
// (c)Copyright Spacesoft corp., 2016 All rights reserved.
//                               Hiro KITAYAMA
//
#include <opencv2/opencv.hpp>
#pragma comment(lib,"opencv_world310.lib")

using namespace cv;
using namespace std;

void copy_shallow()
{
    Mat m1 = (Mat_<float>(2, 2) << 1, 2, 3, 4);

    cout << "Shallow Copy" << endl;

    Mat m1s = m1;
    cout << "m1=" << m1 << endl;

    m1.at<float>(0, 0) = 99;

    cout << "m1=" << m1 << endl;
    cout << "m1s=" << m1s << endl;
}

void copy_deep1()
{
    Mat m1 = (Mat_<float>(2, 2) << 1, 2, 3, 4);

    cout << endl << "Deep Copy 1" << endl;

    Mat m1d = m1.clone();
    cout << "m1=" << m1 << endl;

    m1.at<float>(0, 0) = 99;

    cout << "m1=" << m1 << endl;
    cout << "m1d=" << m1d << endl;

}

void copy_deep2()
{
    Mat m1 = (Mat_<float>(2, 2) << 1, 2, 3, 4);

    cout << endl << "Deep Copy 2" << endl;

    Mat m1d;
    m1.copyTo(m1d);
    cout << "m1=" << m1 << endl;

    m1.at<float>(0, 0) = 99;

    cout << "m1=" << m1 << endl;
    cout << "m1d=" << m1d << endl;
}

void copy_deep3()
{
    Mat m1 = (Mat_<float>(2, 2) << 1, 2, 3, 4);

    cout << endl << "Deep Copy 3" << endl;

    UMat m1d;
    m1.copyTo(m1d);
    cout << "m1=" << m1 << endl;

    m1.at<float>(0, 0) = 99;
    cout << "m1=" << m1 << endl;
    Mat m1dd;
    m1d.copyTo(m1dd);
    cout << "m1dd=" << m1dd << endl;
}

void copy_deep4()
{
    Mat m1 = (Mat_<float>(2, 2) << 1, 2, 3, 4);

    cout << endl << "Deep Copy 4" << endl;
    UMat umat = m1.getUMat(ACCESS_RW);
    cout << "m1=" << m1 << endl;

    m1.at<float>(0, 0) = 51;
    cout << "m1=" << m1 << endl;
    Mat m1dd;
    umat.copyTo(m1dd);
    cout << "m1dd=" << m1dd << endl;
}

int main(int argc, char* argv[])
{
    copy_shallow();
    copy_deep1();
    copy_deep2();
    copy_deep3();
    copy_deep4();

    return 0;
}

