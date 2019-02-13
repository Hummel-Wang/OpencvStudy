//OpenCV边缘检测：Canny算子, Sobel算子, Laplace算子, Scharr滤波器合辑


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
	Mat srcImage = imread(imageRootPath + "sg003.jpg");
	imshow("原始图像", srcImage);

#pragma region Canny
	//Canny参数详解：
//	第一个参数，InputArray类型的image，输入图像，即源图像，填Mat类的对象即可，且需为单通道8位图像。【必须为灰度图】
//	第二个参数，OutputArray类型的edges，输出的边缘图，需要和源图片有一样的尺寸和类型。
//	第三个参数，double类型的threshold1，第一个滞后性阈值。
//	第四个参数，double类型的threshold2，第二个滞后性阈值。
//	第五个参数，int类型的apertureSize，表示应用Sobel算子的孔径大小，其有默认值3。
//	第六个参数，bool类型的L2gradient，一个计算图像梯度幅值的标识，有默认值false。

	//Mat srcClone = srcImage.clone();
	//Mat DstPic, edge, grayImage;
////创建与src同类型和同大小的矩阵
	//DstPic.create(srcImage.size(), srcImage.type());

	////将原始图转化为灰度图
	//cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

	////先使用3*3内核来降噪
	//blur(grayImage, edge, Size(3, 3));

	////运行canny算子
	//Canny(edge, edge, 3, 9, 3);

	////图片显示
	//imshow("Canny之后效果一", edge);

	//DstPic = Scalar::all(0);
	//srcClone.copyTo(DstPic, edge);
	//imshow("Canny之后效果二", DstPic);
#pragma endregion

#pragma region Sobel 

	/*Sobel参数详解：
		第一个参数，InputArray 类型的src，为输入图像，填Mat类型即可。
		第二个参数，OutputArray类型的dst，即目标图像，函数的输出参数，需要和源图片有一样的尺寸和类型。
		第三个参数，int类型的ddepth，输出图像的深度，支持如下src.depth()和ddepth的组合：
		若src.depth() = CV_8U, 取ddepth = -1 / CV_16S / CV_32F / CV_64F
		若src.depth() = CV_16U / CV_16S, 取ddepth = -1 / CV_32F / CV_64F
		若src.depth() = CV_32F, 取ddepth = -1 / CV_32F / CV_64F
		若src.depth() = CV_64F, 取ddepth = -1 / CV_64F
		第四个参数，int类型dx，x 方向上的差分阶数。
		第五个参数，int类型dy，y方向上的差分阶数。
		第六个参数，int类型ksize，有默认值3，表示Sobel核的大小; 必须取1，3，5或7。
		第七个参数，double类型的scale，计算导数值时可选的缩放因子，默认值是1，表示默认情况下是没有应用缩放的。我们可以在文档中查阅getDerivKernels的相关介绍，来得到这个参数的更多信息。
		第八个参数，double类型的delta，表示在结果存入目标图（第二个参数dst）之前可选的delta值，有默认值0。
		第九个参数， int类型的borderType，我们的老朋友了（万年是最后一个参数），边界模式，默认值为BORDER_DEFAULT。这个参数可以在官方文档中borderInterpolate处得到更详细的信息。
*/

//Mat grad_x, grad_y;
//Mat abs_grad_x, abs_grad_y, dst;

////【3】求 X方向梯度
//Sobel(srcImage, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
//convertScaleAbs(grad_x, abs_grad_x);
//imshow("【效果图】 X方向Sobel", abs_grad_x);

////【4】求Y方向梯度
//Sobel(srcImage, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
//convertScaleAbs(grad_y, abs_grad_y);
//imshow("【效果图】Y方向Sobel", abs_grad_y);

////【5】合并梯度(近似)
//addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
//imshow("【效果图】整体方向Sobel", dst);

#pragma endregion

#pragma region Laplace

	/*Laplace参数详解：
		第一个参数，InputArray类型的image，输入图像，即源图像，填Mat类的对象即可，且需为单通道8位图像。
		第二个参数，OutputArray类型的edges，输出的边缘图，需要和源图片有一样的尺寸和通道数。
		第三个参数，int类型的ddept，目标图像的深度。
		第四个参数，int类型的ksize，用于计算二阶导数的滤波器的孔径尺寸，大小必须为正奇数，且有默认值1。
		第五个参数，double类型的scale，计算拉普拉斯值的时候可选的比例因子，有默认值1。
		第六个参数，double类型的delta，表示在结果存入目标图（第二个参数dst）之前可选的delta值，有默认值0。
		第七个参数， int类型的borderType，边界模式，默认值为BORDER_DEFAULT。这个参数可以在官方文档中borderInterpolate()处得到更详细的信息。*/

		//Mat  src_gray, dst, abs_dst;

		////【3】使用高斯滤波消除噪声
		//GaussianBlur(srcImage, srcImage, Size(3, 3), 0, 0, BORDER_DEFAULT);

		////【4】转换为灰度图
		//cvtColor(srcImage, src_gray, CV_RGB2GRAY);

		////【5】使用Laplace函数
		//Laplacian(src_gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);

		////【6】计算绝对值，并将结果转换成8位
		//convertScaleAbs(dst, abs_dst);

		////【7】显示效果图
		//imshow("【效果图】图像Laplace变换", abs_dst);

#pragma endregion

#pragma region scharr

//scharr参数详解：
//第一个参数，InputArray 类型的src，为输入图像，填Mat类型即可。
//第二个参数，OutputArray类型的dst，即目标图像，函数的输出参数，需要和源图片有一样的尺寸和类型。
//第三个参数，int类型的ddepth，输出图像的深度，支持如下src.depth()和ddepth的组合：
//若src.depth() = CV_8U, 取ddepth = -1 / CV_16S / CV_32F / CV_64F
//若src.depth() = CV_16U / CV_16S, 取ddepth = -1 / CV_32F / CV_64F
//若src.depth() = CV_32F, 取ddepth = -1 / CV_32F / CV_64F
//若src.depth() = CV_64F, 取ddepth = -1 / CV_64F
//第四个参数，int类型dx，x方向上的差分阶数。
//第五个参数，int类型dy，y方向上的差分阶数。
//第六个参数，double类型的scale，计算导数值时可选的缩放因子，默认值是1，表示默认情况下是没有应用缩放的。我们可以在文档中查阅getDerivKernels的相关介绍，来得到这个参数的更多信息。
//第七个参数，double类型的delta，表示在结果存入目标图（第二个参数dst）之前可选的delta值，有默认值0。
//第八个参数， int类型的borderType，我们的老朋友了（万年是最后一个参数），边界模式，默认值为BORDER_DEFAULT。这个参数可以在官方文档中borderInterpolate处得到更详细的信息。

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y, dst;

	//【3】求 X方向梯度
	Scharr(srcImage, grad_x, CV_16S, 1, 0, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);
	imshow("【效果图】 X方向Scharr", abs_grad_x);

	//【4】求Y方向梯度
	Scharr(srcImage, grad_y, CV_16S, 0, 1, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);
	imshow("【效果图】Y方向Scharr", abs_grad_y);

	//【5】合并梯度(近似)
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);

	//【6】显示效果图
	imshow("【效果图】合并梯度后Scharr", dst);


#pragma endregion


	//waitKey的参数单位是ms，6000即代表cmd框持续6s自动关闭; 0代表永久
	waitKey(0);
}



