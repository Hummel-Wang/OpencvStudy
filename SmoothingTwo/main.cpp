//�����������˲�����ֵ�˲���˫���˲�


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
	Mat srcImage = imread(imageRootPath + "xz001.jpg");

	//�����˲�����
	   /*medianBlur����������£�
		��һ��������InputArray���͵�src�������������������1��3����4ͨ����Mat���͵�ͼ�񣻵�ksizeΪ3����5��ʱ��ͼ�������ΪCV_8U��CV_16U����CV_32F����֮һ�������ڽϴ�׾��ߴ��ͼƬ����ֻ����CV_8U��
		�ڶ���������OutputArray���͵�dst����Ŀ��ͼ�񣬺����������������Ҫ��ԴͼƬ��һ���ĳߴ�����͡����ǿ�����Mat::Clone����ԴͼƬΪģ�壬����ʼ���õ���ٰ�����Ŀ��ͼ��
		������������int���͵�ksize���׾������Գߴ磨aperture linear size����ע��������������Ǵ���1�����������磺3��5��7��9 ...*/

		/*bilateralFilter����������£�
	   ��һ��������InputArray���͵�src������ͼ�񣬼�Դͼ����ҪΪ8λ���߸����͵�ͨ������ͨ����ͼ��
		�ڶ���������OutputArray���͵�dst����Ŀ��ͼ����Ҫ��ԴͼƬ��һ���ĳߴ�����͡�
		������������int���͵�d����ʾ�ڹ��˹�����ÿ�����������ֱ����������ֵ��������Ϊ����������ôOpenCV��ӵ��������sigmaSpace�������������
		���ĸ�������double���͵�sigmaColor����ɫ�ռ��˲�����sigmaֵ�����������ֵԽ�󣬾ͱ����������������и�������ɫ�ᱻ��ϵ�һ�𣬲����ϴ�İ������ɫ����
		�����������double���͵�sigmaSpace����ռ����˲�����sigmaֵ������ռ�ı�ע���������ֵԽ����ζ��ԽԶ�����ػ��໥Ӱ�죬�Ӷ�ʹ����������㹻���Ƶ���ɫ��ȡ��ͬ����ɫ����d > 0��dָ���������С����sigmaSpace�޹ء�����d������sigmaSpace��
		������������int���͵�borderType�������ƶ�ͼ���ⲿ���ص�ĳ�ֱ߽�ģʽ��ע������Ĭ��ֵBORDER_DEFAULT��*/


	Mat outImage1;
	medianBlur(srcImage, outImage1, 3);

	Mat outImage2;
	bilateralFilter(srcImage, outImage2, 25, 25 * 2, 25 / 2);

	imshow("ԭʼͼ��", srcImage);
	imshow("��ֵ�˲�֮��ͼ��", outImage1);
	imshow("˫���˲�֮��ͼ��", outImage2);
	//waitKey�Ĳ�����λ��ms��6000������cmd�����6s�Զ��ر�; 0��������
	waitKey(0);
}



