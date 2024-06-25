#include "chapter1.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/// <summary>
/// Laad een afbeelding in en laat deze zien op het scherm.
/// </summary>

void chapter1::imageLoad()
{
	string path = "Resources/test.png";
	Mat image = imread(path);
	imshow("afbeelding", image);
	waitKey(0);
}

/// <summary>
/// Laad een video in en laat deze zien op het scherm
/// </summary>

void chapter1::videoLoad() {
	
	string path = "Resources/test_video.mp4";
	VideoCapture cap(path);
	Mat img;
	while (true) {
		cap.read(img);
		if (img.empty()) {
			return;
		}
		imshow("video", img);
		waitKey(1);
	}
	
}

/// <summary>
/// Laad het beeld van de webcam zien op het scherm
/// </summary>

void chapter1::webcamLoad() {
	VideoCapture cap(0);
	Mat img;
	while (true) {
		cap.read(img);
		imshow("webcam", img);
		waitKey(1);
	}
}

void chapter1::SubMain()
{
	webcamLoad();
	videoLoad();
	imageLoad();
}
