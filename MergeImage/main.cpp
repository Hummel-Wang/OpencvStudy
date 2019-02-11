//�����ͨ��ͼ��ϲ�Ϊһ����ͨ��ͼ��
//��ͨ����� - ��ɫ��������


#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <direct.h>

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
	Mat logoImage = imread(imageRootPath + "ls.png", 0);

	//ͼ��ָ�
	split(srcImage, channels);
	imageRedChannel = channels.at(2);

	//��Ȩ���� srcImage
	Mat imageROI = imageRedChannel(Rect(800, 650, logoImage.cols, logoImage.rows));

	addWeighted(imageROI, 1, logoImage, 1, 0., imageROI);

	//ͼ��ϲ�
	merge(channels, srcImage);

	//��ʾͼ��
	/*imshow("ԭʼͼ��", srcImage);
	imshow("logoͼ��", logoImage);*/
	imshow("ԭʼͼ��---logoͼ��", srcImage);

	//waitKey�Ĳ�����λ��ms��6000������cmd�����6s�Զ��ر�; 0��������
	waitKey(0);
}



