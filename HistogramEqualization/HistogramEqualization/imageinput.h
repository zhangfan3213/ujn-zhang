#pragma once
#ifndef imageinput
#define imageinput
#include "stdafx.h"
#include "imageinput.h"
#include "iostream"
#include "String"
#include <opencv2/opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include<opencv2/highgui/highgui.hpp> 
using namespace std;
using namespace cv;
class image {
private:
public:
	Mat Greyvalue(String filename);
};

#endif // !imageinput


