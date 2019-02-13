//图像金字塔：resize()、pyrUp( )、pyrDown( )


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
	Mat srcImage = imread(imageRootPath + "tou.jpg");
	imshow("原始图像", srcImage);

#pragma region resize

	/*resize参数详解：
		第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可。
		第二个参数，OutputArray类型的dst，输出图像，当其非零时，有着dsize（第三个参数）的尺寸，或者由src.size()计算出来。
		第三个参数，Size类型的dsize，输出图像的大小; 如果它等于零，由下式进行计算：


		其中，dsize，fx，fy都不能为0。

		第四个参数，double类型的fx，沿水平轴的缩放系数，有默认值0，且当其等于0时，由下式进行计算：


		第五个参数，double类型的fy，沿垂直轴的缩放系数，有默认值0，且当其等于0时，由下式进行计算：

		第六个参数，int类型的interpolation，用于指定插值方式，默认为INTER_LINEAR（线性插值）。*/

	//Mat tmpImage, dstImage1, dstImage2;//临时变量和目标图的定义
	//tmpImage = srcImage;//将原始图赋给临时变量

	////进行尺寸调整操作
	//resize(tmpImage, dstImage1, Size(tmpImage.cols / 2, tmpImage.rows / 2), (0, 0), (0, 0), 3);
	//resize(tmpImage, dstImage2, Size(tmpImage.cols * 2, tmpImage.rows * 2), (0, 0), (0, 0), 3);

	////显示效果图  
	//imshow("【效果图】之一", dstImage1);
	//imshow("【效果图】之二", dstImage2);
#pragma endregion

#pragma region pyrUp

	/*pyrUp参数详解：
		第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可。
		第二个参数，OutputArray类型的dst，输出图像，和源图片有一样的尺寸和类型。
		第三个参数，const Size&类型的dstsize，输出图像的大小; 有默认值Size()，即默认情况下，由Size（src.cols * 2，src.rows * 2）来进行计算，且一直需要满足下列条件：

		第四个参数，int类型的borderType，又来了，边界模式，一般我们不用去管它。*/

	//Mat tmpImage, dstImage;//临时变量和目标图的定义
	//tmpImage = srcImage;//将原始图赋给临时变量

	////进行向上取样操作
	//pyrUp(tmpImage, dstImage, Size(tmpImage.cols * 2, tmpImage.rows * 2));
	////显示效果图  
	//imshow("【效果图】", dstImage);

#pragma endregion

#pragma region pyrDown

/*pyrDown参数详解：
	第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可。
第二个参数，OutputArray类型的dst，输出图像，和源图片有一样的尺寸和类型。
第三个参数，const Size&类型的dstsize，输出图像的大小;有默认值Size()，即默认情况下，由Size Size((src.cols+1)/2, (src.rows+1)/2)来进行计算*/

	Mat tmpImage, dstImage;//临时变量和目标图的定义
	tmpImage = srcImage;//将原始图赋给临时变量

	//进行向上取样操作
	pyrDown(tmpImage, dstImage, Size(tmpImage.cols / 2, tmpImage.rows / 2));

	//显示效果图  
	imshow("【效果图】", dstImage);

#pragma endregion




	//waitKey的参数单位是ms，6000即代表cmd框持续6s自动关闭; 0代表永久
	waitKey(0);
}



