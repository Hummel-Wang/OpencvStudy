//ͼ��Աȶ������Ȳ���
//���ֳ��õĵ���̣��������ӣ������ó����Ե���г˷��ͼӷ�����:g(x) = ��f(x) + ��
//��2�ַ�ʽ�� 1.�����ؽ������Դ���  2. ʹ��Opencv�⺯��convertTo


#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <direct.h>

using namespace std;
using namespace cv;

double alpha;//���ƶԱȶ�
int beta;//��������
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

	

#pragma region ����һ�����������Դ���

	/*cout << " Enter the alpha value [1.0-3.0]:" << endl;
	cin >> alpha;
	cout << "Enter the beta value [0-100]:" << endl;
	cin >> beta;
	Mat new_image = Mat::zeros(srcImage.size(), srcImage.type());
	for (int i = 0; i < srcImage.rows; i++)
	{
		for (int j = 0; j < srcImage.cols; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				new_image.at<Vec3b>(i, j)[k] =
					saturate_cast<uchar>(alpha*(srcImage.at<Vec3b>(i, j)[k]) + beta);
			}
		}
	}
	imshow("���ĶԱȶ����Ⱥ�ͼ��", new_image);*/
#pragma endregion

#pragma region ��ʽ����Opencv convertTo����

	Mat imageConvert;
	srcImage.convertTo(imageConvert, srcImage.type(), 1, 100);
	imshow("���ĶԱȶ����Ⱥ�ͼ��", imageConvert);

#pragma endregion





	//waitKey�Ĳ�����λ��ms��6000������cmd�����6s�Զ��ر�; 0��������
	waitKey(0);
}



