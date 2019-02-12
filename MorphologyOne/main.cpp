//��̬ѧͼ�������ͣ�����

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
	//��ȡ��ǰִ��Ŀ¼��ַ
	string str = _getcwd(NULL, 0);
	int size = str.length();
	int index = str.rfind("\\");
	string imageRootPath = str.replace(index, size - index, "\\Images\\");
	//����ͼ��
	Mat srcImage = imread(imageRootPath + "Lenna.jpg");

	//dilate������⣺
	//	��һ��������InputArray���͵�src������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɡ�ͼ��ͨ������������������ģ���ͼ�����ӦΪCV_8U��CV_16U��CV_16S��CV_32F�� CV_64F����֮һ��
	//	�ڶ���������OutputArray���͵�dst����Ŀ��ͼ����Ҫ��ԴͼƬ��һ���ĳߴ�����͡�
	//	������������InputArray���͵�kernel�����Ͳ����ĺˡ���ΪNULLʱ����ʾ����ʹ�òο���λ������3x3�ĺˡ�
	//	����һ��ʹ�ú��� getStructuringElement������������ʹ�á�getStructuringElement�����᷵��ָ����״�ͳߴ�ĽṹԪ�أ��ں˾��󣩡�
	//	���У�getStructuringElement�����ĵ�һ��������ʾ�ں˵���״�����ǿ���ѡ������������״֮һ��
	//	���� : MORPH_RECT
	//	������ : MORPH_CROSS
	//	��Բ�� : MORPH_ELLIPSE

	//��ȡ�Զ����
	Mat element1 = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat outImage1;
	//�������Ͳ���
	dilate(srcImage, outImage1, element1);

	/*erode������⣺
		��һ��������InputArray���͵�src������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɡ�ͼ��ͨ������������������ģ���ͼ�����ӦΪCV_8U��CV_16U��CV_16S��CV_32F�� CV_64F����֮һ��
		�ڶ���������OutputArray���͵�dst����Ŀ��ͼ����Ҫ��ԴͼƬ��һ���ĳߴ�����͡�
		������������InputArray���͵�kernel����ʴ�������ںˡ���ΪNULLʱ����ʾ����ʹ�òο���λ������3x3�ĺˡ�����һ��ʹ�ú��� getStructuringElement������������ʹ�á�getStructuringElement�����᷵��ָ����״�ͳߴ�ĽṹԪ�أ��ں˾��󣩡������忴������ǳ������dilate�����ĵ������������ⲿ�֣�
		���ĸ�������Point���͵�anchor��ê��λ�ã�����Ĭ��ֵ�� - 1�� - 1������ʾêλ�ڵ�λ��element�������ģ�����һ�㲻�ù�����
		�����������int���͵�iterations������ʹ��erode���������Ĵ�����Ĭ��ֵΪ1��
		������������int���͵�borderType�������ƶ�ͼ���ⲿ���ص�ĳ�ֱ߽�ģʽ��ע������Ĭ��ֵBORDER_DEFAULT��
		���߸�������const Scalar&���͵�borderValue�����߽�Ϊ����ʱ�ı߽�ֵ����Ĭ��ֵmorphologyDefaultBorderValue()��һ�����ǲ���ȥ��������Ҫ�õ���ʱ�����Կ��ٷ��ĵ��е�createMorphologyFilter()�����õ�����ϸ�Ľ��͡�
		ͬ���ģ�ʹ��erode������һ������ֻ��Ҫ��ǰ�������������������ĸ���������Ĭ��ֵ�������������getStructuringElementһ��ʹ�á�*/
	Mat element2 = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat outImage2;
	//�������Ͳ���
	dilate(srcImage, outImage2, element2);


	imshow("ԭʼͼ��", srcImage);
	imshow("���Ͳ�����ͼ��", outImage1);
	imshow("��ʴ������ͼ��", outImage2);
	//waitKey�Ĳ�����λ��ms��6000������cmd�����6s�Զ��ر�; 0��������
	waitKey(0);
}



