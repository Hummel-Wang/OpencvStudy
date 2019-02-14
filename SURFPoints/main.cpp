//OpenCV  remap��ӳ�䣬 surf������ȡ��opencv3.xx�汾���о�ʹ�ã�����

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
	//��ȡ��ǰִ��Ŀ¼��ַ
	string str = _getcwd(NULL, 0);
	int size = str.length();
	int index = str.rfind("\\");
	string imageRootPath = str.replace(index, size - index, "\\Images\\");
	//����ͼ��
	Mat srcImage1 = imread(imageRootPath + "jz001.jpg");
	Mat srcImage2 = imread(imageRootPath + "jz002.jpg");
	imshow("ԭʼͼ��", srcImage1);
	imshow("ԭʼͼ��", srcImage2);

#pragma region remap  ��ӳ��

	/*remap������⣺
		��һ��������InputArray���͵�src������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɣ�����Ϊ��ͨ��8λ���߸�����ͼ��
�ڶ���������OutputArray���͵�dst���������ú���������������������������ڴ�ź������ú�������������ԴͼƬ��һ���ĳߴ�����͡�
������������InputArray���͵�map1���������ֿ��ܵı�ʾ����
��ʾ�㣨x��y���ĵ�һ��ӳ�䡣
��ʾCV_16SC2 , CV_32FC1 ��CV_32FC2���͵�Xֵ��
���ĸ�������InputArray���͵�map2��ͬ������Ҳ�����ֿ��ܵı�ʾ���󣬶������Ǹ���map1��ȷ����ʾ���ֶ���
��map1��ʾ�㣨x��y��ʱ����������������κ�ֵ��
��ʾCV_16UC1 , CV_32FC1���͵�Yֵ���ڶ���ֵ����
�����������int���͵�interpolation,��ֵ��ʽ��֮ǰ��resize( )�������н�������Ҫע�⣬resize( )�������ᵽ��INTER_AREA��ֵ��ʽ�������ǲ�֧�ֵģ����Կ�ѡ�Ĳ�ֵ��ʽ���£�
INTER_NEAREST - ����ڲ�ֵ
INTER_LINEAR �C ˫���Բ�ֵ��Ĭ��ֵ��
INTER_CUBIC �C ˫����������ֵ����4��4���������ڵ�˫���β�ֵ��
INTER_LANCZOS4 -Lanczos��ֵ����8��8���������Lanczos��ֵ��
������������int���͵�borderMode���߽�ģʽ����Ĭ��ֵBORDER_CONSTANT����ʾĿ��ͼ���С���Ⱥ�㣨outliers����������ֵ���ᱻ�˺����޸ġ�
���߸�������const Scalar&���͵�borderValue�����г����߽�ʱʹ�õ�ֵ������Ĭ��ֵScalar( )����Ĭ��ֵΪ0��*/

		//����Harris�ǵ����ҳ��ǵ�
	//Mat  dstImage;
	//Mat map_x, map_y;
	////��2��������ԭʼͼһ����Ч��ͼ��x��ӳ��ͼ��y��ӳ��ͼ
	//dstImage.create(srcImage.size(), srcImage.type());
	//map_x.create(srcImage.size(), CV_32FC1);
	//map_y.create(srcImage.size(), CV_32FC1);

	////��3��˫��ѭ��������ÿһ�����ص㣬�ı�map_x & map_y��ֵ
	//for (int j = 0; j < srcImage.rows; j++)
	//{
	//	for (int i = 0; i < srcImage.cols; i++)
	//	{
	//		//�ı�map_x & map_y��ֵ. 
	//		map_x.at<float>(j, i) = static_cast<float>(i);
	//		map_y.at<float>(j, i) = static_cast<float>(srcImage.rows - j);
	//	}
	//}

	////��4��������ӳ�����
	//remap(srcImage, dstImage, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
	//imshow("�����򴰿ڡ�", dstImage);

#pragma endregion

#pragma region  surf������ȡ
	/*ʹ�� FeatureDetector �ӿ������ָ���Ȥ�㡣
	ʹ�� SurfFeatureDetector �Լ��亯�� detect ��ʵ�ּ�����
	ʹ�ú��� drawKeypoints ���Ƽ�⵽�Ĺؼ��㡣*/

	//��2��������Ҫ�õ��ı�������
	//int minHessian = 400;//����SURF�е�hessian��ֵ������������
	//SurfFeatureDetector detector(minHessian);//����һ��SurfFeatureDetector��SURF�� ������������
	//std::vector<KeyPoint> keypoints_1, keypoints_2;//vectorģ�������ܹ�����������͵Ķ�̬���飬�ܹ����Ӻ�ѹ������

	////��3������detect��������SURF�����ؼ��㣬������vector������
	//detector.detect(srcImage1, keypoints_1);
	//detector.detect(srcImage2, keypoints_2);

	////��4�����������ؼ���
	//Mat img_keypoints_1; Mat img_keypoints_2;
	//drawKeypoints(srcImage1, keypoints_1, img_keypoints_1, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
	//drawKeypoints(srcImage2, keypoints_2, img_keypoints_2, Scalar::all(-1), DrawMatchesFlags::DEFAULT);

	////��5����ʾЧ��ͼ
	//imshow("��������Ч��ͼ1", img_keypoints_1);
	//imshow("��������Ч��ͼ2", img_keypoints_2);
#pragma endregion






	//waitKey�Ĳ�����λ��ms��6000������cmd�����6s�Զ��ر�; 0��������
	waitKey(0);
}



