//线性领域滤波：方框滤波，均值滤波，高斯滤波【低通滤波】，双边滤波


#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <direct.h>
#include <opencv2/imgproc/imgproc.hpp>

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

	//进行滤波操作
	/*boxFilter参数详解如下：
		第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可。该函数对通道是独立处理的，且可以处理任意通道数的图片，但需要注意，待处理的图片深度应该为CV_8U, CV_16U, CV_16S, CV_32F 以及 CV_64F之一。
		第二个参数，OutputArray类型的dst，即目标图像，需要和源图片有一样的尺寸和类型。
		第三个参数，int类型的ddepth，输出图像的深度， - 1代表使用原图深度，即src.depth()。
		第四个参数，Size类型的ksize，内核的大小。一般这样写Size(w, h)来表示内核的大小(其中，w 为像素宽度， h为像素高度)。Size（3, 3）就表示3x3的核大小，Size（5, 5）就表示5x5的核大小
		第五个参数，Point类型的anchor，表示锚点（即被平滑的那个点），注意他有默认值Point(-1, -1)。如果这个点坐标是负值的话，就表示取核的中心为锚点，所以默认值Point(-1, -1)表示这个锚点在核的中心。
		第六个参数，bool类型的normalize，默认值为true，一个标识符，表示内核是否被其区域归一化（normalized）了。
		第七个参数，int类型的borderType，用于推断图像外部像素的某种边界模式。有默认值BORDER_DEFAULT，我们一般不去管它。*/

	/*blur参数详解如下：
		第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可。该函数对通道是独立处理的，且可以处理任意通道数的图片，但需要注意，待处理的图片深度应该为CV_8U, CV_16U, CV_16S, CV_32F 以及 CV_64F之一。
		第二个参数，OutputArray类型的dst，即目标图像，需要和源图片有一样的尺寸和类型。比如可以用Mat::Clone，以源图片为模板，来初始化得到如假包换的目标图。
		第三个参数，Size类型（对Size类型稍后有讲解）的ksize，内核的大小。一般这样写Size(w, h)来表示内核的大小(其中，w 为像素宽度， h为像素高度)。Size（3, 3）就表示3x3的核大小，Size（5, 5）就表示5x5的核大小
		第四个参数，Point类型的anchor，表示锚点（即被平滑的那个点），注意他有默认值Point(-1, -1)。如果这个点坐标是负值的话，就表示取核的中心为锚点，所以默认值Point(-1, -1)表示这个锚点在核的中心。
		第五个参数，int类型的borderType，用于推断图像外部像素的某种边界模式。有默认值BORDER_DEFAULT，我们一般不去管它。*/
	
	/*GaussianBlur参数详解如下：
		第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可。它可以是单独的任意通道数的图片，但需要注意，图片深度应该为CV_8U, CV_16U, CV_16S, CV_32F 以及 CV_64F之一。
		第二个参数，OutputArray类型的dst，即目标图像，需要和源图片有一样的尺寸和类型。比如可以用Mat::Clone，以源图片为模板，来初始化得到如假包换的目标图。
		第三个参数，Size类型的ksize高斯内核的大小。其中ksize.width和ksize.height可以不同，但他们都必须为正数和奇数。或者，它们可以是零的，它们都是由sigma计算而来。
		第四个参数，double类型的sigmaX，表示高斯核函数在X方向的的标准偏差。
		第五个参数，double类型的sigmaY，表示高斯核函数在Y方向的的标准偏差。若sigmaY为零，就将它设为sigmaX，如果sigmaX和sigmaY都是0，那么就由ksize.width和ksize.height计算出来。
		为了结果的正确性着想，最好是把第三个参数Size，第四个参数sigmaX和第五个参数sigmaY全部指定到。
		第六个参数，int类型的borderType，用于推断图像外部像素的某种边界模式。注意它有默认值BORDER_DEFAULT。*/


	Mat outImage1;
	boxFilter(srcImage, outImage1, -1, Size(5, 5));

	Mat outImage2;
	blur(srcImage, outImage2, Size(5, 5));

	Mat outImage3;
	GaussianBlur(srcImage, outImage3, Size(5, 5), 0 , 0);

	imshow("原始图像", srcImage);
	imshow("方框滤波之后图像", outImage1);
	imshow("均值滤波之后图像", outImage2);
	imshow("高斯滤波之后图像", outImage3);
	//waitKey的参数单位是ms，6000即代表cmd框持续6s自动关闭; 0代表永久
	waitKey(0);
}



