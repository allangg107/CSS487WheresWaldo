#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat waldoPuzzle = imread("waldo_puzzle_02.png");
	Mat waldoTemplate = imread("waldo_template_02.png");

	Mat result = waldoPuzzle.clone();

	int resultCols = waldoPuzzle.cols;
	int resultRows = waldoPuzzle.rows;

	matchTemplate(waldoPuzzle, waldoTemplate, result, 0);
	normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

	double minVal; double maxVal; Point minLoc; Point maxLoc;
	Point matchLoc;
	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

	matchLoc = minLoc;

	result = waldoPuzzle.clone();

	rectangle(result, matchLoc, Point(matchLoc.x + waldoTemplate.cols, matchLoc.y + waldoTemplate.rows), Scalar::all(0), 2, 8, 0);
	namedWindow("result.png", WINDOW_NORMAL);
	resizeWindow("result.png", result.cols / 4, result.rows / 4);
	imshow("result.png", result);

	waitKey(0);
}