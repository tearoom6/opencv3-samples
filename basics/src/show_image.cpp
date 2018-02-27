//
// Original copyright:
// (c)Copyright Spacesoft corp., 2016 All rights reserved.
//                               Hiro KITAYAMA
//
#include <opencv2/opencv.hpp>
#pragma comment(lib,"opencv_world310.lib")

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "no parameter specified." << std::endl;
        return -1;
    }

    cv::Mat src = cv::imread(argv[1]);
    cv::imshow("Image", src);
    cv::waitKey(5000);
    // 0 means waiting infinitely.
    //cv::waitKey(0);

    return 0;
}

