
//��ͨ��ͼ�����Ϊ��ͨ��ͼ��

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <direct.h>

using namespace std;
using namespace cv;

int main()
{
	vector<Mat> channels;

	//��ȡ��ǰִ��Ŀ¼��ַ
	string str = _getcwd(NULL, 0);
	int size = str.length();
	int index = str.rfind("\\");
	string imageRootPath = str.replace(index, size - index, "\\Images\\");
	//����ͼ��
	Mat srcImage = imread(imageRootPath + "xz001.jpg");
	//��ʾԭͼ
	imshow("��ʾԭͼ", srcImage);

	split(srcImage, channels);
	Mat imageBlue = channels.at(0);
	Mat imageGreen = channels.at(1);
	Mat imageRed = channels.at(2);

	imshow("imageBlue", imageBlue);
	imshow("imageGreen", imageGreen);
	imshow("imageRed", imageRed);

	//waitKey�Ĳ�����λ��ms��6000������cmd�����6s�Զ��ر�; 0��������
	waitKey(0);
}

