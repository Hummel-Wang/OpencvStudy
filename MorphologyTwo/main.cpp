//��̬ѧͼ���������㣬�����㣬��̬ѧ�ݶȣ���ñ����ñ


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
	imshow("ԭʼͼ��", srcImage);

	/*morphologyEx������⣺
	    ��һ��������InputArray���͵�src������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɡ�ͼ��λ��Ӧ��Ϊ��������֮һ��CV_8U, CV_16U, CV_16S, CV_32F ��CV_64F��
		�ڶ���������OutputArray���͵�dst����Ŀ��ͼ�񣬺����������������Ҫ��ԴͼƬ��һ���ĳߴ�����͡�
		������������int���͵�op����ʾ��̬ѧ��������ͣ�����������֮һ�ı�ʶ����
		MORPH_OPEN �C �����㣨Opening operation��
		MORPH_CLOSE �C �����㣨Closing operation��
		MORPH_GRADIENT - ��̬ѧ�ݶȣ�Morphological gradient��
		MORPH_TOPHAT - ����ñ������Top hat����
		MORPH_BLACKHAT - ����ñ������Black hat����*/

	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));

	//��̬ѧ֮������
	//morphologyEx(srcImage, srcImage, MORPH_OPEN, element);
	//imshow("��Ч��ͼ��������", srcImage);

	//��̬ѧ֮������
	/*morphologyEx(srcImage, srcImage, MORPH_CLOSE, element);
	imshow("��Ч��ͼ��������", srcImage);*/

	//��̬ѧ֮�ݶ�
	//morphologyEx(srcImage, srcImage, MORPH_GRADIENT, element);
	//imshow("��Ч��ͼ���ݶ�", srcImage);


	//��̬ѧ֮��ñ
	/*morphologyEx(srcImage, srcImage, MORPH_TOPHAT, element);
	imshow("��Ч��ͼ����ñ", srcImage);*/

	//��̬ѧ֮��ñ
	morphologyEx(srcImage, srcImage, MORPH_BLACKHAT, element);
	imshow("��Ч��ͼ����ñ", srcImage);


	//waitKey�Ĳ�����λ��ms��6000������cmd�����6s�Զ��ر�; 0��������
	waitKey(0);
}



