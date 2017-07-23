#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <opencv2\highgui.hpp>
#include <opencv2\opencv.hpp>

int HW01_TestFunction();
int HW02_ReadAndShowData(int numberOfImgs);

using namespace cv;
using namespace std;
vector <Mat> Img;
vector <Mat> imgGray;
vector <Mat> Bin;

int main() {
	HW01_TestFunction();
	waitKey(0);
	destroyAllWindows();

	HW02_ReadAndShowData(8);

	waitKey(0);
	return 0;
}


int HW01_TestFunction() {

	Mat Img = imread("F:\AM021708\opencv-1and2-AM021708\testImage\lena.jpg", CV_LOAD_IMAGE_UNCHANGED);
	Mat imgGray = imread("F:\AM021708\opencv-1and2-AM021708\testImage\lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat Bin;
	cv::threshold(imgGray, Bin, 100.0, 255.0, THRESH_BINARY);

	namedWindow("Img", CV_WINDOW_AUTOSIZE);
	moveWindow("Img", 20, 20);
	imshow("Img",Img);
	namedWindow("imgGray", CV_WINDOW_AUTOSIZE);
	moveWindow("imgGray", 520, 20);
	imshow("imgGray", imgGray);
	namedWindow("Bin", CV_WINDOW_AUTOSIZE);
	moveWindow("Bin", 1020, 20);
	imshow("Bin", Bin);

	return 0;
}

int HW02_ReadAndShowData(int numberOfImgs) {
	
	for (int i = 1; i <= numberOfImgs; i++) {
		Img.push_back(imread("F:\AM021708\opencv-1and2-AM021708\testImage\capture" + to_string(i) + ".jpg",CV_LOAD_IMAGE_UNCHANGED));
		imgGray.push_back(imread("F:\AM021708\opencv-1and2-AM021708\testImage\capture" + to_string(i) + ".jpg", CV_LOAD_IMAGE_UNCHANGED));
		cv::threshold(imgGray[i], Bin, 100.0, 255.0, THRESH_BINARY);

		namedWindow("Img", CV_WINDOW_AUTOSIZE);
		moveWindow("Img", 20, 20);
		imshow("Img",Img[i]);
		namedWindow("imgGray", CV_WINDOW_AUTOSIZE);
		moveWindow("imgGray", 20, 20);
		imshow("imgGray", imgGray[i]);
		namedWindow("Bin", CV_WINDOW_AUTOSIZE);
		moveWindow("Bin", 20, 20);
		imshow("Bin", Bin[i]);

		const int ENTER = 13;
		while (true) {
			if (waitKey(0) == ENTER) {
				destroyAllWindows();
				break;
			}
		}
	}
	return 0;
}





