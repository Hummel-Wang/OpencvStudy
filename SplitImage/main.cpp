
//多通道图像分离为单通道图像

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <direct.h>

using namespace std;
using namespace cv;

int main()
{
	vector<Mat> channels;

	//获取当前执行目录地址
	string str = _getcwd(NULL, 0);
	int size = str.length();
	int index = str.rfind("\\");
	string imageRootPath = str.replace(index, size - index, "\\Images\\");
	//加载图像
	Mat srcImage = imread(imageRootPath + "xz001.jpg");
	//显示原图
	imshow("显示原图", srcImage);

	split(srcImage, channels);
	Mat imageBlue = channels.at(0);
	Mat imageGreen = channels.at(1);
	Mat imageRed = channels.at(2);

	imshow("imageBlue", imageBlue);
	imshow("imageGreen", imageGreen);
	imshow("imageRed", imageRed);

	//waitKey的参数单位是ms，6000即代表cmd框持续6s自动关闭; 0代表永久
	waitKey(0);
}

