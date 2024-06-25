#include "chapter5.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void chapter5::SubMain()
{
	float w = 300, h = 320;
	string path = "Resources/insinge.jpg";
	Mat image = imread(path);
	
	Mat imagewarped;
	Point2f scr[4] = { {66,1153},{730,958}, {390,1832}, {1215,1505} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f}, {0.0f,h}, {w,h} };
	Mat matrix = getPerspectiveTransform(scr, dst);
	warpPerspective(image, imagewarped, matrix, Point(w,h));
	resize(image, image, Size(), 0.25, 0.25);
	imshow("afbeelding", image);
	imshow("afbeelding warped", imagewarped);
	waitKey(0);
}