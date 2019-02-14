//OpenCV  remap重映射， surf特征提取在opencv3.xx版本需研究使用，待定

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <direct.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>



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
	Mat srcImage1 = imread(imageRootPath + "jz001.jpg");
	Mat srcImage2 = imread(imageRootPath + "jz002.jpg");
	imshow("原始图像", srcImage1);
	imshow("原始图像", srcImage2);

#pragma region remap  重映射

	/*remap参数详解：
		第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可，且需为单通道8位或者浮点型图像。
第二个参数，OutputArray类型的dst，函数调用后的运算结果存在这里，即这个参数用于存放函数调用后的输出结果，需和源图片有一样的尺寸和类型。
第三个参数，InputArray类型的map1，它有两种可能的表示对象。
表示点（x，y）的第一个映射。
表示CV_16SC2 , CV_32FC1 或CV_32FC2类型的X值。
第四个参数，InputArray类型的map2，同样，它也有两种可能的表示对象，而且他是根据map1来确定表示那种对象。
若map1表示点（x，y）时。这个参数不代表任何值。
表示CV_16UC1 , CV_32FC1类型的Y值（第二个值）。
第五个参数，int类型的interpolation,插值方式，之前的resize( )函数中有讲到，需要注意，resize( )函数中提到的INTER_AREA插值方式在这里是不支持的，所以可选的插值方式如下：
INTER_NEAREST - 最近邻插值
INTER_LINEAR – 双线性插值（默认值）
INTER_CUBIC – 双三次样条插值（逾4×4像素邻域内的双三次插值）
INTER_LANCZOS4 -Lanczos插值（逾8×8像素邻域的Lanczos插值）
第六个参数，int类型的borderMode，边界模式，有默认值BORDER_CONSTANT，表示目标图像中“离群点（outliers）”的像素值不会被此函数修改。
第七个参数，const Scalar&类型的borderValue，当有常数边界时使用的值，其有默认值Scalar( )，即默认值为0。*/

		//进行Harris角点检测找出角点
	//Mat  dstImage;
	//Mat map_x, map_y;
	////【2】创建和原始图一样的效果图，x重映射图，y重映射图
	//dstImage.create(srcImage.size(), srcImage.type());
	//map_x.create(srcImage.size(), CV_32FC1);
	//map_y.create(srcImage.size(), CV_32FC1);

	////【3】双层循环，遍历每一个像素点，改变map_x & map_y的值
	//for (int j = 0; j < srcImage.rows; j++)
	//{
	//	for (int i = 0; i < srcImage.cols; i++)
	//	{
	//		//改变map_x & map_y的值. 
	//		map_x.at<float>(j, i) = static_cast<float>(i);
	//		map_y.at<float>(j, i) = static_cast<float>(srcImage.rows - j);
	//	}
	//}

	////【4】进行重映射操作
	//remap(srcImage, dstImage, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
	//imshow("【程序窗口】", dstImage);

#pragma endregion

#pragma region  surf特征提取
	/*使用 FeatureDetector 接口来发现感兴趣点。
	使用 SurfFeatureDetector 以及其函数 detect 来实现检测过程
	使用函数 drawKeypoints 绘制检测到的关键点。*/

	//【2】定义需要用到的变量和类
	//int minHessian = 400;//定义SURF中的hessian阈值特征点检测算子
	//SurfFeatureDetector detector(minHessian);//定义一个SurfFeatureDetector（SURF） 特征检测类对象
	//std::vector<KeyPoint> keypoints_1, keypoints_2;//vector模板类是能够存放任意类型的动态数组，能够增加和压缩数据

	////【3】调用detect函数检测出SURF特征关键点，保存在vector容器中
	//detector.detect(srcImage1, keypoints_1);
	//detector.detect(srcImage2, keypoints_2);

	////【4】绘制特征关键点
	//Mat img_keypoints_1; Mat img_keypoints_2;
	//drawKeypoints(srcImage1, keypoints_1, img_keypoints_1, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
	//drawKeypoints(srcImage2, keypoints_2, img_keypoints_2, Scalar::all(-1), DrawMatchesFlags::DEFAULT);

	////【5】显示效果图
	//imshow("特征点检测效果图1", img_keypoints_1);
	//imshow("特征点检测效果图2", img_keypoints_2);
#pragma endregion






	//waitKey的参数单位是ms，6000即代表cmd框持续6s自动关闭; 0代表永久
	waitKey(0);
}



