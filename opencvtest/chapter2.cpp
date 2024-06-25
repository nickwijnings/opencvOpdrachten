#include "chapter2.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int tres1, tres2;
void chapter2::SubMain()
{
	string path = "Resources/beker.jpg";
	Mat image = imread(path);
	resize(image, image, Size(), 0.25, 0.25);
	Mat imageGray, imageBlur, imageCanny;
	cvtColor(image, imageGray, COLOR_BGR2GRAY);
	GaussianBlur(imageGray, imageBlur, Size(3, 3), 9, 0);
	namedWindow("Trackbars", (640, 200));
	createTrackbar("tres 1", "Trackbars", &tres1, 255);
	createTrackbar("tres 2", "Trackbars", &tres2, 255);
	while (true) {
		Canny(imageGray, imageCanny, tres1, tres2);
		imshow("afbeelding", image);
		imshow("afbeelding grijs", imageGray);
		imshow("afbeelding grijs", imageCanny);
		waitKey(1);
	}
}

void op2dot1() {
	string path = "Resources/balls.png";
	Mat image = imread(path);
	//resize(image, image, Size(), 0.25, 0.25);
	Mat imageGray, imageBlur, imageErode, imageDilate;
	cvtColor(image, imageGray, COLOR_BGR2GRAY);
	//GaussianBlur(imageGray, imageBlur, Size(3, 3), 9, 0);
	Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(21, 21));
	dilate(imageGray, imageDilate, kernel);
	erode(imageDilate, imageErode, kernel);
	imshow("afbeelding", image);
	imshow("afbeelding grijs", imageGray);
	imshow("afbeelding dilated", imageErode);
	waitKey(0);
}