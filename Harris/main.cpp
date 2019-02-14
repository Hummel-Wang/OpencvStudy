//OpenCV  HHarris�ǵ��⣬���ĳһ�������ⷽ���һ��΢С�䶯��������ҶȺܴ�ı仯����ô���ǾͰ�����֮Ϊ�ǵ�
//ͼ���������Ϳ��Ա���Ϊ�������֣�
//<1>��Ե
//<2>�ǵ�(����Ȥ�ؼ���)
//< 3 > �ߵ�(Blobs)(����Ȥ����)
//�ڵ�ǰ��ͼ�������򣬽ǵ����㷨�ɹ���Ϊ���ࣺ
//<1>���ڻҶ�ͼ��Ľǵ���
//<2>���ڶ�ֵͼ��Ľǵ���
//<3>�����������ߵĽǵ���

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
	Mat srcImage = imread(imageRootPath + "jz001.jpg", 0);
	imshow("ԭʼͼ��", srcImage);

#pragma region cornerHarris

	/*cornerHarris������⣺
		��һ��������InputArray���͵�src������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɣ�����Ϊ��ͨ��8λ���߸�����ͼ��
		�ڶ���������OutputArray���͵�dst���������ú���������������������������ڴ��Harris�ǵ��������������ԴͼƬ��һ���ĳߴ�����͡�
		������������int���͵�blockSize����ʾ����Ĵ�С���������ϸ��Ϣ��cornerEigenValsAndVecs�������н�����
		���ĸ�������int���͵�ksize����ʾSobel()���ӵĿ׾���С��
		�����������double���͵�k��Harris������
		������������int���͵�borderType��ͼ�����صı߽�ģʽ��ע������Ĭ��ֵBORDER_DEFAULT������ϸ�Ľ��ͣ��ο�borderInterpolate()������
		Threshold������⣺
		��һ��������InputArray���͵�src���������飬�ͨ�� , 8��32λ�������͵�Mat���ɡ�
        �ڶ���������OutputArray���͵�dst���������ú���������������������������ڴ�����������Һ͵�һ�������е�Mat������һ���ĳߴ�����͡�
        ������������double���͵�thresh����ֵ�ľ���ֵ��
        ���ĸ�������double���͵�maxval���������������ֵ����typeȡ CV_THRESH_BINARY ��CV_THRESH_BINARY_INV ��ֵ����ʱ�����ֵ.
        �����������int���͵�type����ֵ����,��threshold( )����֧�ֵĶ�ͼ��ȡ��ֵ�ķ�������ȷ����*/

		//����Harris�ǵ����ҳ��ǵ�
	Mat cornerStrength;
	cornerHarris(srcImage, cornerStrength, 2, 3, 0.01);

	//�ԻҶ�ͼ������ֵ�������õ���ֵͼ����ʾ  
	Mat harrisCorner;
	threshold(cornerStrength, harrisCorner, 0.00001, 255, THRESH_BINARY);
	imshow("�ǵ����Ķ�ֵЧ��ͼ", harrisCorner);
#pragma endregion





//waitKey�Ĳ�����λ��ms��6000������cmd�����6s�Զ��ر�; 0��������
	waitKey(0);
}



