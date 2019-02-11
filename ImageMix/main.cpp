
//ROI区域图像叠加，初级图像混合

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <direct.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//获取当前执行目录地址
	string str = _getcwd(NULL, 0);
	int size = str.length();
	int index = str.rfind("\\");
	string imageRootPath = str.replace(index, size - index, "\\Images\\");
	//加载背景图像
	Mat image = imread(imageRootPath + "xz001.jpg");
	//加载logo
	Mat logo = imread(imageRootPath + "ls.png");
	//显示图像
	imshow("背景图像", image);
	imshow("logo", logo);

	Mat imageROI = image(Rect(500, 300, logo.cols, logo.rows));
	//将logo加到背景图像上
	/*
	1、 第1个参数，输入图片1，
	2、第2个参数，图片1的融合比例
	3、第3个参数，输入图片2
	4、第4个参数，图片2的融合比例
	5、第5个参数，偏差
	6、第6个参数，输出图片*/
	addWeighted(imageROI, 1, logo, 1, 0., imageROI);

	imshow("合成图像", image);
	waitKey(0);
}
