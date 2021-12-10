// FindWaldo.cpp
// Purpose: recognize and label Waldo in a given "Where's Waldo" image
// Functionality: given an image of "Where's Waldo," Waldo is located and boxed
// Assumptions: 
//	Using a "Where's Waldo" image as well as a template image for Waldo
// Authors: Allan Genari Gaarden, Tommy Ni, Joshua Medvinsky

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

// ------------------------------------ main --------------------------------------

// purpose: recognize and label Waldo in a given "Where's Waldo" image
// preconditions: Using a "Where's Waldo" image as well as a template image for Waldo
// postconditions: Waldo is located and boxed on a copy of the original image

// --------------------------------------------------------------------------------------
int main()
{
	Mat waldoPuzzle = imread("waldo_puzzle_06.png");
	Mat waldoTemplate = imread("waldo_template_06.png");

	Mat result = waldoPuzzle.clone();

	int resultCols = waldoPuzzle.cols;
	int resultRows = waldoPuzzle.rows;

	// match the template and store the result in result
	matchTemplate(waldoPuzzle, waldoTemplate, result, 0);
	normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

	// determine the coordinates for where the match for the template was found
	double minVal; double maxVal; Point minLoc; Point maxLoc;
	Point matchLoc;
	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

	matchLoc = minLoc;

	result = waldoPuzzle.clone();

	// draw the rectangle and output the result
	rectangle(result, matchLoc, Point(matchLoc.x + waldoTemplate.cols, matchLoc.y + waldoTemplate.rows), Scalar::all(0), 2, 8, 0);
	namedWindow("result.png", WINDOW_NORMAL);
	resizeWindow("result.png", result.cols / 4, result.rows / 4);
	imshow("result.png", result);

	waitKey(0);
}