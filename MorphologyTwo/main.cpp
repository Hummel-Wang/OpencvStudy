//形态学图像处理：开运算，闭运算，形态学梯度，顶帽，黑帽


#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <direct.h>
#include <opencv2/imgproc/imgproc.hpp>

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
	imshow("原始图像", srcImage);

	/*morphologyEx参数详解：
	    第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可。图像位深应该为以下五种之一：CV_8U, CV_16U, CV_16S, CV_32F 或CV_64F。
		第二个参数，OutputArray类型的dst，即目标图像，函数的输出参数，需要和源图片有一样的尺寸和类型。
		第三个参数，int类型的op，表示形态学运算的类型，可以是如下之一的标识符：
		MORPH_OPEN – 开运算（Opening operation）
		MORPH_CLOSE – 闭运算（Closing operation）
		MORPH_GRADIENT - 形态学梯度（Morphological gradient）
		MORPH_TOPHAT - “顶帽”（“Top hat”）
		MORPH_BLACKHAT - “黑帽”（“Black hat“）*/

	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));

	//形态学之开运算
	//morphologyEx(srcImage, srcImage, MORPH_OPEN, element);
	//imshow("【效果图】开运算", srcImage);

	//形态学之闭运算
	/*morphologyEx(srcImage, srcImage, MORPH_CLOSE, element);
	imshow("【效果图】闭运算", srcImage);*/

	//形态学之梯度
	//morphologyEx(srcImage, srcImage, MORPH_GRADIENT, element);
	//imshow("【效果图】梯度", srcImage);


	//形态学之顶帽
	/*morphologyEx(srcImage, srcImage, MORPH_TOPHAT, element);
	imshow("【效果图】顶帽", srcImage);*/

	//形态学之黑帽
	morphologyEx(srcImage, srcImage, MORPH_BLACKHAT, element);
	imshow("【效果图】黑帽", srcImage);


	//waitKey的参数单位是ms，6000即代表cmd框持续6s自动关闭; 0代表永久
	waitKey(0);
}



