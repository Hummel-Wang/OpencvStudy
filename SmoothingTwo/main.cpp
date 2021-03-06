//非线性领域滤波：中值滤波，双边滤波


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

	//进行滤波操作
	   /*medianBlur参数详解如下：
		第一个参数，InputArray类型的src，函数的输入参数，填1、3或者4通道的Mat类型的图像；当ksize为3或者5的时候，图像深度需为CV_8U，CV_16U，或CV_32F其中之一，而对于较大孔径尺寸的图片，它只能是CV_8U。
		第二个参数，OutputArray类型的dst，即目标图像，函数的输出参数，需要和源图片有一样的尺寸和类型。我们可以用Mat::Clone，以源图片为模板，来初始化得到如假包换的目标图。
		第三个参数，int类型的ksize，孔径的线性尺寸（aperture linear size），注意这个参数必须是大于1的奇数，比如：3，5，7，9 ...*/

		/*bilateralFilter参数详解如下：
	   第一个参数，InputArray类型的src，输入图像，即源图像，需要为8位或者浮点型单通道、三通道的图像。
		第二个参数，OutputArray类型的dst，即目标图像，需要和源图片有一样的尺寸和类型。
		第三个参数，int类型的d，表示在过滤过程中每个像素邻域的直径。如果这个值我们设其为非正数，那么OpenCV会从第五个参数sigmaSpace来计算出它来。
		第四个参数，double类型的sigmaColor，颜色空间滤波器的sigma值。这个参数的值越大，就表明该像素邻域内有更宽广的颜色会被混合到一起，产生较大的半相等颜色区域。
		第五个参数，double类型的sigmaSpace坐标空间中滤波器的sigma值，坐标空间的标注方差。他的数值越大，意味着越远的像素会相互影响，从而使更大的区域足够相似的颜色获取相同的颜色。当d > 0，d指定了邻域大小且与sigmaSpace无关。否则，d正比于sigmaSpace。
		第六个参数，int类型的borderType，用于推断图像外部像素的某种边界模式。注意它有默认值BORDER_DEFAULT。*/


	Mat outImage1;
	medianBlur(srcImage, outImage1, 3);

	Mat outImage2;
	bilateralFilter(srcImage, outImage2, 25, 25 * 2, 25 / 2);

	imshow("原始图像", srcImage);
	imshow("中值滤波之后图像", outImage1);
	imshow("双边滤波之后图像", outImage2);
	//waitKey的参数单位是ms，6000即代表cmd框持续6s自动关闭; 0代表永久
	waitKey(0);
}



