// HistogramEqualization.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "imageinput.h"
#include "iostream"
#include "String"
#include "math.h"
#include <opencv2/opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include<opencv2/highgui/highgui.hpp> 
using namespace cv;
using namespace std;

void function1() {
	image im;
	Mat img;
	String filename = "E:\\VSexample\\2.png";
	img = im.Greyvalue(filename);
	int height = img.rows, width = img.cols;
	int a, b, grey[256], x; double grey2[256], grey3[256], grey4[256], y = 0;
	for (a = 0; a < 255; a++)
		grey[a] = 0;
	for (a = 0; a < height; a++) {
		for (b = 0; b < width; b++) {
			x = img.at<uchar>(a, b);
			grey[x]++;
		}
	}
	for (a = 0; a < 255; a++) {
		grey2[a] = 1.0*grey[a] / (width * height * 1.0);
		y = y + grey2[a];
		grey3[a] = y;
		//cout << grey3[a] << " ";
		grey4[a] = floor(grey3[a] * 255 + 0.5);
		//cout << grey4[a] << " ";
	}

	for (a = 0; a < height; a++) {
		for (b = 0; b < width; b++) {
			x = img.at<uchar>(a, b);
			img.at<uchar>(a, b) = grey4[x];
		}
	}
	imshow("直方图均衡化", img);
	//waitKey(0);
	//system("pause");
}

void function2() {
	image im;
	Mat img;
	String filename = "E:\\VSexample\\2.png";
	img = im.Greyvalue(filename);
	Mat img2;
	img2 = img.clone();
	int height = img.rows, width = img.cols; int  i = 0, j = 0; int sx, sy;double  gxy;
	for (i = 1; i < (height-1); i++) {
		for (j = 1; j < (width-1); j++) {
			sx = img.at<uchar>(i, j - 1)+ 2 * img.at<uchar>(i + 1, j) + img.at<uchar>(i + 1, j + 1) - img.at<uchar>(i - 1, j - 1) - 2 * img.at<uchar>(i - 1, j) - img.at<uchar>(i - 1, j + 1);
			sy = img.at<uchar>(i - 1, j + 1) + 2 * img.at<uchar>(i, j + 1) + img.at<uchar>(i + 1, j + 1) - img.at<uchar>(i - 1, j - 1) - 2 * img.at<uchar>(i,j-1) - img.at<uchar>(i + 1, j - 1);
			gxy = sqrt(sx*sx+sy*sy);
			img2.at<uchar>(i,j) = floor(gxy);		
		}
	}
	imshow("边缘检测算法", img2);
	waitKey(0);
	system("pause");
}

int main()
{
	function1();
	function2();
    return 0;
}

