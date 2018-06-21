#include "stdafx.h"
#include "imageinput.h"
#include "iostream"
#include "String"
#include <opencv2/opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include<opencv2/highgui/highgui.hpp> 
using namespace cv;
using namespace std;
Mat image::Greyvalue(String filename) {
	    //String filename = "E:\\VSexample\\12.jpg";
		Mat img = imread(filename, 0);//‘ÿ»ÎÕºœÒ
		return img;
}


