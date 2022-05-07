// FindWaldo.cpp
// Purpose: recognize and label Waldo in a given "Where's Waldo" image
// Functionality: given an image of "Where's Waldo," Waldo is located and boxed
// Assumptions: 
//	Using a "Where's Waldo" image as well as a template image for Waldo

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

// ------------------------------------ testCase --------------------------------------

// purpose: test a given case
// preconditions: test is using valid images
// postconditions: outputs the result of each test case, with Waldo being boxed
// This method was inspired by opencv's documentation on how to perform template matching:
//	https://docs.opencv.org/3.4/de/da9/tutorial_template_matching.html

// --------------------------------------------------------------------------------------
void testCase(string puzzleName, string templateName)
{
	Mat waldoPuzzle = imread(puzzleName);
	Mat waldoTemplate = imread(templateName);

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

// ------------------------------------ main --------------------------------------

// purpose: recognize and label Waldo in a given "Where's Waldo" image
// preconditions: Using an existing "Where's Waldo" image as well as a template image for Waldo
// postconditions: Waldo is located and boxed on a copy of the original image

// --------------------------------------------------------------------------------------
int main()
{
	vector<string> puzzles;
	vector<string> templates;

	// populate test vectors
	puzzles.push_back("waldo_puzzle_01.png");
	puzzles.push_back("waldo_puzzle_02.png");
	puzzles.push_back("waldo_puzzle_03.png");
	puzzles.push_back("waldo_puzzle_04.png");
	puzzles.push_back("waldo_puzzle_05.png");
	puzzles.push_back("waldo_puzzle_06.png");
	puzzles.push_back("waldo_puzzle_07.png");
	puzzles.push_back("waldo_puzzle_08.png");

	templates.push_back("waldo_template_01.png");
	templates.push_back("waldo_template_02.png");
	templates.push_back("waldo_template_03.png");
	templates.push_back("waldo_template_04.png");
	templates.push_back("waldo_template_05.png");
	templates.push_back("waldo_template_06.png");
	templates.push_back("waldo_template_07.png");
	templates.push_back("waldo_template_08.png");

	// run each test case
	for (int i = 0; i < puzzles.size(); i++)
	{
		testCase(puzzles[i], templates[i]);
	}
}
