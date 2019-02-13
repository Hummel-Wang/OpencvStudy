//ͼ���������resize()��pyrUp( )��pyrDown( )


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
	Mat srcImage = imread(imageRootPath + "tou.jpg");
	imshow("ԭʼͼ��", srcImage);

#pragma region resize

	/*resize������⣺
		��һ��������InputArray���͵�src������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɡ�
		�ڶ���������OutputArray���͵�dst�����ͼ�񣬵������ʱ������dsize���������������ĳߴ磬������src.size()���������
		������������Size���͵�dsize�����ͼ��Ĵ�С; ����������㣬����ʽ���м��㣺


		���У�dsize��fx��fy������Ϊ0��

		���ĸ�������double���͵�fx����ˮƽ�������ϵ������Ĭ��ֵ0���ҵ������0ʱ������ʽ���м��㣺


		�����������double���͵�fy���ش�ֱ�������ϵ������Ĭ��ֵ0���ҵ������0ʱ������ʽ���м��㣺

		������������int���͵�interpolation������ָ����ֵ��ʽ��Ĭ��ΪINTER_LINEAR�����Բ�ֵ����*/

	//Mat tmpImage, dstImage1, dstImage2;//��ʱ������Ŀ��ͼ�Ķ���
	//tmpImage = srcImage;//��ԭʼͼ������ʱ����

	////���гߴ��������
	//resize(tmpImage, dstImage1, Size(tmpImage.cols / 2, tmpImage.rows / 2), (0, 0), (0, 0), 3);
	//resize(tmpImage, dstImage2, Size(tmpImage.cols * 2, tmpImage.rows * 2), (0, 0), (0, 0), 3);

	////��ʾЧ��ͼ  
	//imshow("��Ч��ͼ��֮һ", dstImage1);
	//imshow("��Ч��ͼ��֮��", dstImage2);
#pragma endregion

#pragma region pyrUp

	/*pyrUp������⣺
		��һ��������InputArray���͵�src������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɡ�
		�ڶ���������OutputArray���͵�dst�����ͼ�񣬺�ԴͼƬ��һ���ĳߴ�����͡�
		������������const Size&���͵�dstsize�����ͼ��Ĵ�С; ��Ĭ��ֵSize()����Ĭ������£���Size��src.cols * 2��src.rows * 2�������м��㣬��һֱ��Ҫ��������������

		���ĸ�������int���͵�borderType�������ˣ��߽�ģʽ��һ�����ǲ���ȥ������*/

	//Mat tmpImage, dstImage;//��ʱ������Ŀ��ͼ�Ķ���
	//tmpImage = srcImage;//��ԭʼͼ������ʱ����

	////��������ȡ������
	//pyrUp(tmpImage, dstImage, Size(tmpImage.cols * 2, tmpImage.rows * 2));
	////��ʾЧ��ͼ  
	//imshow("��Ч��ͼ��", dstImage);

#pragma endregion

#pragma region pyrDown

/*pyrDown������⣺
	��һ��������InputArray���͵�src������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɡ�
�ڶ���������OutputArray���͵�dst�����ͼ�񣬺�ԴͼƬ��һ���ĳߴ�����͡�
������������const Size&���͵�dstsize�����ͼ��Ĵ�С;��Ĭ��ֵSize()����Ĭ������£���Size Size((src.cols+1)/2, (src.rows+1)/2)�����м���*/

	Mat tmpImage, dstImage;//��ʱ������Ŀ��ͼ�Ķ���
	tmpImage = srcImage;//��ԭʼͼ������ʱ����

	//��������ȡ������
	pyrDown(tmpImage, dstImage, Size(tmpImage.cols / 2, tmpImage.rows / 2));

	//��ʾЧ��ͼ  
	imshow("��Ч��ͼ��", dstImage);

#pragma endregion




	//waitKey�Ĳ�����λ��ms��6000������cmd�����6s�Զ��ر�; 0��������
	waitKey(0);
}



