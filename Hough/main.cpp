//OpenCV支持三种不同的霍夫线变换，它们分别是：标准霍夫变换(Standard Hough Transform，SHT)
//多尺度霍夫变换（Multi-Scale Hough Transform，MSHT）
//累计概率霍夫变换(Progressive Probabilistic Hough Transform ，PPHT)。

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
	Mat srcImage = imread(imageRootPath + "lq.jpg");
	imshow("原始图像", srcImage);

#pragma region HoughLines

	/*HoughLines参数详解：
		第一个参数，InputArray类型的image，输入图像，即源图像，需为8位的单通道二进制图像，可以将任意的源图载入进来后由函数修改成此格式后，再填在这里。
		第二个参数，InputArray类型的lines，经过调用HoughLines函数后储存了霍夫线变换检测到线条的输出矢量。每一条线由具有两个元素的矢量表示，其中，是离坐标原点((0, 0)（也就是图像的左上角）的距离。 是弧度线条旋转角度（0~垂直线，π / 2~水平线）。
			第三个参数，double类型的rho，以像素为单位的距离精度。另一种形容方式是直线搜索时的进步尺寸的单位半径。PS : Latex中 / rho就表示 。
			第四个参数，double类型的theta，以弧度为单位的角度精度。另一种形容方式是直线搜索时的进步尺寸的单位角度。
			第五个参数，int类型的threshold，累加平面的阈值参数，即识别某部分为图中的一条直线时它在累加平面中必须达到的值。大于阈值threshold的线段才可以被检测通过并返回到结果中。
			第六个参数，double类型的srn，有默认值0。对于多尺度的霍夫变换，这是第三个参数进步尺寸rho的除数距离。粗略的累加器进步尺寸直接是第三个参数rho，而精确的累加器进步尺寸为rho / srn。
			第七个参数，double类型的stn，有默认值0，对于多尺度霍夫变换，srn表示第四个参数进步尺寸的单位角度theta的除数距离。且如果srn和stn同时为0，就表示使用经典的霍夫变换。否则，这两个参数应该都为正数。*/

	//Mat midImage, dstImage;//临时变量和目标图的定义

	////【2】进行边缘检测和转化为灰度图
	//Canny(srcImage, midImage, 50, 200, 3);//进行一次canny边缘检测
	//cvtColor(midImage, dstImage, CV_GRAY2BGR);//转化边缘检测后的图为灰度图

	////【3】进行霍夫线变换
	//vector<Vec2f> lines;//定义一个矢量结构lines用于存放得到的线段矢量集合
	//HoughLines(midImage, lines, 1, CV_PI / 180, 150, 0, 0);

	////【4】依次在图中绘制出每条线段
	//for (size_t i = 0; i < lines.size(); i++)
	//{
	//	float rho = lines[i][0], theta = lines[i][1];
	//	Point pt1, pt2;
	//	double a = cos(theta), b = sin(theta);
	//	double x0 = a * rho, y0 = b * rho;
	//	pt1.x = cvRound(x0 + 1000 * (-b));
	//	pt1.y = cvRound(y0 + 1000 * (a));
	//	pt2.x = cvRound(x0 - 1000 * (-b));
	//	pt2.y = cvRound(y0 - 1000 * (a));
	//	line(dstImage, pt1, pt2, Scalar(55, 100, 195), 1, CV_AA);
	//}

	////【6】边缘检测后的图 
	//imshow("【边缘检测后的图】", midImage);

	////【7】显示效果图  
	//imshow("【效果图】", dstImage);
#pragma endregion

#pragma region HoughLinesP

	/*HoughLinesP参数详解：
		第一个参数，InputArray类型的image，输入图像，即源图像，需为8位的单通道二进制图像，可以将任意的源图载入进来后由函数修改成此格式后，再填在这里。
		第二个参数，InputArray类型的lines，经过调用HoughLinesP函数后后存储了检测到的线条的输出矢量，每一条线由具有四个元素的矢量(x_1, y_1, x_2, y_2）  表示，其中，(x_1, y_1)和(x_2, y_2) 是是每个检测到的线段的结束点。
			第三个参数，double类型的rho，以像素为单位的距离精度。另一种形容方式是直线搜索时的进步尺寸的单位半径。
			第四个参数，double类型的theta，以弧度为单位的角度精度。另一种形容方式是直线搜索时的进步尺寸的单位角度。
			第五个参数，int类型的threshold，累加平面的阈值参数，即识别某部分为图中的一条直线时它在累加平面中必须达到的值。大于阈值threshold的线段才可以被检测通过并返回到结果中。
			第六个参数，double类型的minLineLength，有默认值0，表示最低线段的长度，比这个设定参数短的线段就不能被显现出来。
			第七个参数，double类型的maxLineGap，有默认值0，允许将同一行点与点之间连接起来的最大的距离。*/

	//Mat midImage, dstImage;//临时变量和目标图的定义

	////【2】进行边缘检测和转化为灰度图
	//Canny(srcImage, midImage, 50, 200, 3);//进行一此canny边缘检测
	//cvtColor(midImage, dstImage, CV_GRAY2BGR);//转化边缘检测后的图为灰度图

	////【3】进行霍夫线变换
	//vector<Vec4i> lines;//定义一个矢量结构lines用于存放得到的线段矢量集合
	//HoughLinesP(midImage, lines, 1, CV_PI / 180, 80, 50, 10);

	////【4】依次在图中绘制出每条线段
	//for (size_t i = 0; i < lines.size(); i++)
	//{
	//	Vec4i l = lines[i];
	//	line(dstImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(186, 88, 255), 1, CV_AA);
	//}

	////【6】边缘检测后的图 
	//imshow("【边缘检测后的图】", midImage);

	////【7】显示效果图  
	//imshow("【效果图】", dstImage);
#pragma endregion

#pragma region HoughCircles

	//HoughCircles参数详解：
	//	第一个参数，InputArray类型的image，输入图像，即源图像，需为8位的灰度单通道图像。
	//	第二个参数，InputArray类型的circles，经过调用HoughCircles函数后此参数存储了检测到的圆的输出矢量，每个矢量由包含了3个元素的浮点矢量(x, y, radius)表示。
	//	第三个参数，int类型的method，即使用的检测方法，目前OpenCV中就霍夫梯度法一种可以使用，它的标识符为CV_HOUGH_GRADIENT，在此参数处填这个标识符即可。
	//	第四个参数，double类型的dp，用来检测圆心的累加器图像的分辨率于输入图像之比的倒数，且此参数允许创建一个比输入图像分辨率低的累加器。上述文字不好理解的话，来看例子吧。例如，如果dp = 1时，累加器和输入图像具有相同的分辨率。如果dp = 2，累加器便有输入图像一半那么大的宽度和高度。
	//	第五个参数，double类型的minDist，为霍夫变换检测到的圆的圆心之间的最小距离，即让我们的算法能明显区分的两个不同圆之间的最小距离。这个参数如果太小的话，多个相邻的圆可能被错误地检测成了一个重合的圆。反之，这个参数设置太大的话，某些圆就不能被检测出来了。
	//	第六个参数，double类型的param1，有默认值100。它是第三个参数method设置的检测方法的对应的参数。对当前唯一的方法霍夫梯度法CV_HOUGH_GRADIENT，它表示传递给canny边缘检测算子的高阈值，而低阈值为高阈值的一半。
	//	第七个参数，double类型的param2，也有默认值100。它是第三个参数method设置的检测方法的对应的参数。对当前唯一的方法霍夫梯度法CV_HOUGH_GRADIENT，它表示在检测阶段圆心的累加器阈值。它越小的话，就可以检测到更多根本不存在的圆，而它越大的话，能通过检测的圆就更加接近完美的圆形了。
	//	第八个参数，int类型的minRadius, 有默认值0，表示圆半径的最小值。
	//	第九个参数，int类型的maxRadius, 也有默认值0，表示圆半径的最大值。

	Mat midImage, dstImage;//临时变量和目标图的定义

	//【3】转为灰度图，进行图像平滑
	cvtColor(srcImage, midImage, CV_BGR2GRAY);//转化边缘检测后的图为灰度图
	GaussianBlur(midImage, midImage, Size(9, 9), 2, 2);

	//【4】进行霍夫圆变换
	vector<Vec3f> circles;
	HoughCircles(midImage, circles, CV_HOUGH_GRADIENT, 1.5, 10, 200, 100, 0, 0);

	//【5】依次在图中绘制出圆
	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		//绘制圆心
		circle(srcImage, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		//绘制圆轮廓
		circle(srcImage, center, radius, Scalar(155, 50, 255), 3, 8, 0);
	}

	//【6】显示效果图  
	imshow("【效果图】", srcImage);

#pragma endregion





	//waitKey的参数单位是ms，6000即代表cmd框持续6s自动关闭; 0代表永久
	waitKey(0);
}



