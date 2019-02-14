//OpenCV  HHarris角点检测，如果某一点在任意方向的一个微小变动都会引起灰度很大的变化，那么我们就把它称之为角点
//图像特征类型可以被分为如下三种：
//<1>边缘
//<2>角点(感兴趣关键点)
//< 3 > 斑点(Blobs)(感兴趣区域)
//在当前的图像处理领域，角点检测算法可归纳为三类：
//<1>基于灰度图像的角点检测
//<2>基于二值图像的角点检测
//<3>基于轮廓曲线的角点检测

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
	Mat srcImage = imread(imageRootPath + "jz001.jpg", 0);
	imshow("原始图像", srcImage);

#pragma region cornerHarris

	/*cornerHarris参数详解：
		第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可，且需为单通道8位或者浮点型图像。
		第二个参数，OutputArray类型的dst，函数调用后的运算结果存在这里，即这个参数用于存放Harris角点检测的输出结果，和源图片有一样的尺寸和类型。
		第三个参数，int类型的blockSize，表示邻域的大小，更多的详细信息在cornerEigenValsAndVecs（）中有讲到。
		第四个参数，int类型的ksize，表示Sobel()算子的孔径大小。
		第五个参数，double类型的k，Harris参数。
		第六个参数，int类型的borderType，图像像素的边界模式，注意它有默认值BORDER_DEFAULT。更详细的解释，参考borderInterpolate()函数。
		Threshold参数详解：
		第一个参数，InputArray类型的src，输入数组，填单通道 , 8或32位浮点类型的Mat即可。
        第二个参数，OutputArray类型的dst，函数调用后的运算结果存在这里，即这个参数用于存放输出结果，且和第一个参数中的Mat变量有一样的尺寸和类型。
        第三个参数，double类型的thresh，阈值的具体值。
        第四个参数，double类型的maxval，当第五个参数阈值类型type取 CV_THRESH_BINARY 或CV_THRESH_BINARY_INV 阈值类型时的最大值.
        第五个参数，int类型的type，阈值类型,。threshold( )函数支持的对图像取阈值的方法由其确定，*/

		//进行Harris角点检测找出角点
	Mat cornerStrength;
	cornerHarris(srcImage, cornerStrength, 2, 3, 0.01);

	//对灰度图进行阈值操作，得到二值图并显示  
	Mat harrisCorner;
	threshold(cornerStrength, harrisCorner, 0.00001, 255, THRESH_BINARY);
	imshow("角点检测后的二值效果图", harrisCorner);
#pragma endregion





//waitKey的参数单位是ms，6000即代表cmd框持续6s自动关闭; 0代表永久
	waitKey(0);
}



