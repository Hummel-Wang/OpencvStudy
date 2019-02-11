//多个单通道图像合并为一个多通道图像
//多通道混合 - 红色分量部分


#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <direct.h>

using namespace std;
using namespace cv;

int main()
{
	Mat imageRedChannel;
	vector<Mat> channels;
	//获取当前执行目录地址
	string str = _getcwd(NULL, 0);
	int size = str.length();
	int index = str.rfind("\\");
	string imageRootPath = str.replace(index, size - index, "\\Images\\");
	//加载图像
	Mat srcImage = imread(imageRootPath + "xz001.jpg");
	Mat logoImage = imread(imageRootPath + "ls.png", 0);

	//图像分割
	split(srcImage, channels);
	imageRedChannel = channels.at(2);

	//加权操作 srcImage
	Mat imageROI = imageRedChannel(Rect(800, 650, logoImage.cols, logoImage.rows));

	addWeighted(imageROI, 1, logoImage, 1, 0., imageROI);

	//图像合并
	merge(channels, srcImage);

	//显示图像
	/*imshow("原始图像", srcImage);
	imshow("logo图像", logoImage);*/
	imshow("原始图像---logo图像", srcImage);

	//waitKey的参数单位是ms，6000即代表cmd框持续6s自动关闭; 0代表永久
	waitKey(0);
}



