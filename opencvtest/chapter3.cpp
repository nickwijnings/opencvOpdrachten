
#include "chapter3.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void chapter3::SubMain()
{
	string path = "Resources/test.png";
	Mat image = imread(path);
	Mat imageResize, imageCrop;
	Rect cropSize = Rect(200, 200, 200, 200);
	Size imageSize = cropSize.size();
	resize(image, imageResize, imageSize);
	imageCrop = image(cropSize);
	imshow("afbeelding", image);
	imshow("afbeelding resize", imageResize);
	imshow("afbeelding crop", imageCrop);
	waitKey(0);
}
