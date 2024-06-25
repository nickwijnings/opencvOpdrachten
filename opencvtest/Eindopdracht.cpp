#include "Eindopdracht.h"
#include "DocumentScanner.h"
double scale = 2.25;
Mat lineOut(Mat image)
{
	Mat imageGray, imageBlur, imageCanny, imageResize;
	resize(image, imageResize, Size(), scale, scale);
	cvtColor(imageResize, imageGray, COLOR_BGR2GRAY);
	Canny(imageGray, imageCanny, 15, 60);
	return imageCanny;
}
int countLetters(Mat document, Mat origional) {
	Mat imageDilate, imageErode, lettersMap;
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	int letterCount = 0;
	resize(origional, lettersMap, Size(), scale, scale);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 13));
	
	dilate(document, imageDilate, kernel);
	erode(imageDilate, imageErode, kernel);
	findContours(imageErode, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	vector<Rect> letterboxes(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		if (area > 75 && area < 7000) {
			letterboxes[i] = boundingRect(contours[i]);
			rectangle(lettersMap, letterboxes[i].tl(), letterboxes[i].br(), Scalar((i * 3) % 255, (i * 7)%255, (i * 13) % 255), 4);
			letterCount++;
		}
	}
	resize(lettersMap, lettersMap, Size(), 0.2, 0.2);
	imshow("Letters", lettersMap);
	return letterCount;
}

int countWords(Mat document, Mat origional) {
	Mat imageDilate, imageErode, wordMap;
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	int wordCount = 0;
	resize(origional, wordMap, Size(), scale, scale);
	Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(20, 13));

	dilate(document, imageDilate, kernel);
	erode(imageDilate, imageErode, kernel);
	findContours(imageErode, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	vector<Rect> letterboxes(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		if (area > 2000) {
			letterboxes[i] = boundingRect(contours[i]);
			rectangle(wordMap, letterboxes[i].tl(), letterboxes[i].br(), Scalar((i * 3) % 255, (i * 7) % 255, (i * 13) % 255), 4);
			wordCount++;
		}
	}
	resize(wordMap, wordMap, Size(), 0.2, 0.2);
	imshow("Words", wordMap);
	return wordCount;
}

void Eindopdracht::SubMain()
{
	string path = "Resources/papiertje.jpg";
	int min =40, max =200;
	Mat image = imread(path);
	Mat document = DocumentScanner::getDocumentFromImage(image);

		Mat documentPre = lineOut(document);
		int letters = countLetters(documentPre, document);
		int words = countWords(documentPre, document);
		cout << "amount of letters: " << letters << endl;
		cout << "amount of words: " << words << endl;
		resize(image, image, Size(), 0.2, 0.2);
		imshow("afbeelding", image);
		resize(document, document, Size(), 0.3, 0.3);
		imshow("document", document);
		resize(documentPre, documentPre, Size(), 0.2, 0.2);
		imshow("documentpre", documentPre);
		waitKey(0);


}
