//图像对比度与亮度操作
//两种常用的点过程（即点算子），是用常数对点进行乘法和加法运算:g(x) = αf(x) + β
//有2种方式： 1.逐像素进行线性处理  2. 使用Opencv库函数convertTo


#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <direct.h>

using namespace std;
using namespace cv;

double alpha;//控制对比度
int beta;//控制亮度
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

	

#pragma region 方法一：逐像素线性处理

	/*cout << " Enter the alpha value [1.0-3.0]:" << endl;
	cin >> alpha;
	cout << "Enter the beta value [0-100]:" << endl;
	cin >> beta;
	Mat new_image = Mat::zeros(srcImage.size(), srcImage.type());
	for (int i = 0; i < srcImage.rows; i++)
	{
		for (int j = 0; j < srcImage.cols; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				new_image.at<Vec3b>(i, j)[k] =
					saturate_cast<uchar>(alpha*(srcImage.at<Vec3b>(i, j)[k]) + beta);
			}
		}
	}
	imshow("更改对比度亮度后图像", new_image);*/
#pragma endregion

#pragma region 方式二：Opencv convertTo函数

	Mat imageConvert;
	srcImage.convertTo(imageConvert, srcImage.type(), 1, 100);
	imshow("更改对比度亮度后图像", imageConvert);

#pragma endregion





	//waitKey的参数单位是ms，6000即代表cmd框持续6s自动关闭; 0代表永久
	waitKey(0);
}



