#include "chapter4.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void chapter4::SubMain()
{
	Mat image(500,500,CV_8UC3, Scalar(255,0,0));
	circle(image, Point(100, 100), 200, Scalar(0, 255, 0), 40);
	rectangle(image, Rect(300, 300, 100, 200), Scalar(0, 0, 255), FILLED);
	line(image, Point(450, 0), Point(150, 450), Scalar(255, 255, 255), 30);
	putText(image, "Nick", Point(10, 250), 2, 5, Scalar(0, 0, 0), 10);
	imshow("afbeelding", image);
	waitKey(0);
}
