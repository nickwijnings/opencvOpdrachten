#include "chapter6.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;


void chapter6::SubMain()
{
	string path = "Resources/kerstballen.bmp";
	Mat image = imread(path);
	Mat imageHSV, mask;
	cvtColor(image, imageHSV, COLOR_BGR2HSV);
	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);


	while (true) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imageHSV, lower, upper, mask);
		
		imshow("afbeelding", image);
		imshow("afbeelding mask", mask);
		waitKey(1);
	}
}