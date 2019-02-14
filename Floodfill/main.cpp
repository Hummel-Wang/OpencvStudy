//OpenCV  FloodFill  漫水填充算法

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
	Mat srcImage = imread(imageRootPath + "jz001.jpg");
	imshow("原始图像", srcImage);

#pragma region floodFill

	/*floodFill参数详解：
		第一个参数，InputOutputArray类型的image, 输入 / 输出1通道或3通道，8位或浮点图像，具体参数由之后的参数具体指明。
		第二个参数， InputOutputArray类型的mask，这是第二个版本的floodFill独享的参数，表示操作掩模, 。它应该为单通道、8位、长和宽上都比输入图像 image 大两个像素点的图像。第二个版本的floodFill需要使用以及更新掩膜，所以这个mask参数我们一定要将其准备好并填在此处。需要注意的是，漫水填充不会填充掩膜mask的非零像素区域。例如，一个边缘检测算子的输出可以用来作为掩膜，以防止填充到边缘。同样的，也可以在多次的函数调用中使用同一个掩膜，以保证填充的区域不会重叠。另外需要注意的是，掩膜mask会比需填充的图像大，所以 mask 中与输入图像(x, y)像素点相对应的点的坐标为(x + 1, y + 1)。
		第三个参数，Point类型的seedPoint，漫水填充算法的起始点。
		第四个参数，Scalar类型的newVal，像素点被染色的值，即在重绘区域像素的新值。
		第五个参数，Rect*类型的rect，有默认值0，一个可选的参数，用于设置floodFill函数将要重绘区域的最小边界矩形区域。
		第六个参数，Scalar类型的loDiff，有默认值Scalar()，表示当前观察像素值与其部件邻域像素值或者待加入该部件的种子像素之间的亮度或颜色之负差（lower brightness / color difference）的最大值。 
		第七个参数，Scalar类型的upDiff，有默认值Scalar()，表示当前观察像素值与其部件邻域像素值或者待加入该部件的种子像素之间的亮度或颜色之正差（lower brightness / color difference）的最大值。
		第八个参数，int类型的flags，操作标志符，此参数包含三个部分，比较复杂，我们一起详细看看。*/
		
	Rect ccomp;
	floodFill(srcImage, Point(50, 300), Scalar(155, 255, 55), &ccomp, Scalar(20, 20, 20), Scalar(20, 20, 20));
	imshow("【效果图】", srcImage);

#pragma endregion





	//waitKey的参数单位是ms，6000即代表cmd框持续6s自动关闭; 0代表永久
	waitKey(0);
}



