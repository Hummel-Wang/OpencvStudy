
//ROI����ͼ����ӣ�����ͼ����

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <direct.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//��ȡ��ǰִ��Ŀ¼��ַ
	string str = _getcwd(NULL, 0);
	int size = str.length();
	int index = str.rfind("\\");
	string imageRootPath = str.replace(index, size - index, "\\Images\\");
	//���ر���ͼ��
	Mat image = imread(imageRootPath + "xz001.jpg");
	//����logo
	Mat logo = imread(imageRootPath + "ls.png");
	//��ʾͼ��
	imshow("����ͼ��", image);
	imshow("logo", logo);

	Mat imageROI = image(Rect(500, 300, logo.cols, logo.rows));
	//��logo�ӵ�����ͼ����
	/*
	1�� ��1������������ͼƬ1��
	2����2��������ͼƬ1���ںϱ���
	3����3������������ͼƬ2
	4����4��������ͼƬ2���ںϱ���
	5����5��������ƫ��
	6����6�����������ͼƬ*/
	addWeighted(imageROI, 1, logo, 1, 0., imageROI);

	imshow("�ϳ�ͼ��", image);
	waitKey(0);
}
