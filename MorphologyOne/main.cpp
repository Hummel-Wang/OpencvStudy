//形态学图像处理：膨胀，服饰

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
	Mat srcImage = imread(imageRootPath + "Lenna.jpg");

	//dilate参数详解：
	//	第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可。图像通道的数量可以是任意的，但图像深度应为CV_8U，CV_16U，CV_16S，CV_32F或 CV_64F其中之一。
	//	第二个参数，OutputArray类型的dst，即目标图像，需要和源图片有一样的尺寸和类型。
	//	第三个参数，InputArray类型的kernel，膨胀操作的核。若为NULL时，表示的是使用参考点位于中心3x3的核。
	//	我们一般使用函数 getStructuringElement配合这个参数的使用。getStructuringElement函数会返回指定形状和尺寸的结构元素（内核矩阵）。
	//	其中，getStructuringElement函数的第一个参数表示内核的形状，我们可以选择如下三种形状之一：
	//	矩形 : MORPH_RECT
	//	交叉形 : MORPH_CROSS
	//	椭圆形 : MORPH_ELLIPSE

	//获取自定义核
	Mat element1 = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat outImage1;
	//进行膨胀操作
	dilate(srcImage, outImage1, element1);

	/*erode参数详解：
		第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可。图像通道的数量可以是任意的，但图像深度应为CV_8U，CV_16U，CV_16S，CV_32F或 CV_64F其中之一。
		第二个参数，OutputArray类型的dst，即目标图像，需要和源图片有一样的尺寸和类型。
		第三个参数，InputArray类型的kernel，腐蚀操作的内核。若为NULL时，表示的是使用参考点位于中心3x3的核。我们一般使用函数 getStructuringElement配合这个参数的使用。getStructuringElement函数会返回指定形状和尺寸的结构元素（内核矩阵）。（具体看上文中浅出部分dilate函数的第三个参数讲解部分）
		第四个参数，Point类型的anchor，锚的位置，其有默认值（ - 1， - 1），表示锚位于单位（element）的中心，我们一般不用管它。
		第五个参数，int类型的iterations，迭代使用erode（）函数的次数，默认值为1。
		第六个参数，int类型的borderType，用于推断图像外部像素的某种边界模式。注意它有默认值BORDER_DEFAULT。
		第七个参数，const Scalar&类型的borderValue，当边界为常数时的边界值，有默认值morphologyDefaultBorderValue()，一般我们不用去管他。需要用到它时，可以看官方文档中的createMorphologyFilter()函数得到更详细的解释。
		同样的，使用erode函数，一般我们只需要填前面的三个参数，后面的四个参数都有默认值。而且往往结合getStructuringElement一起使用。*/
	Mat element2 = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat outImage2;
	//进行膨胀操作
	dilate(srcImage, outImage2, element2);


	imshow("原始图像", srcImage);
	imshow("膨胀操作后图像", outImage1);
	imshow("腐蚀操作后图像", outImage2);
	//waitKey的参数单位是ms，6000即代表cmd框持续6s自动关闭; 0代表永久
	waitKey(0);
}



