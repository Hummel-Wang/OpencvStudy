//���������˲��������˲�����ֵ�˲�����˹�˲�����ͨ�˲�����˫���˲�


#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <direct.h>
#include <opencv2/imgproc/imgproc.hpp>

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

	//�����˲�����
	/*boxFilter����������£�
		��һ��������InputArray���͵�src������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɡ��ú�����ͨ���Ƕ�������ģ��ҿ��Դ�������ͨ������ͼƬ������Ҫע�⣬�������ͼƬ���Ӧ��ΪCV_8U, CV_16U, CV_16S, CV_32F �Լ� CV_64F֮һ��
		�ڶ���������OutputArray���͵�dst����Ŀ��ͼ����Ҫ��ԴͼƬ��һ���ĳߴ�����͡�
		������������int���͵�ddepth�����ͼ�����ȣ� - 1����ʹ��ԭͼ��ȣ���src.depth()��
		���ĸ�������Size���͵�ksize���ں˵Ĵ�С��һ������дSize(w, h)����ʾ�ں˵Ĵ�С(���У�w Ϊ���ؿ�ȣ� hΪ���ظ߶�)��Size��3, 3���ͱ�ʾ3x3�ĺ˴�С��Size��5, 5���ͱ�ʾ5x5�ĺ˴�С
		�����������Point���͵�anchor����ʾê�㣨����ƽ�����Ǹ��㣩��ע������Ĭ��ֵPoint(-1, -1)���������������Ǹ�ֵ�Ļ����ͱ�ʾȡ�˵�����Ϊê�㣬����Ĭ��ֵPoint(-1, -1)��ʾ���ê���ں˵����ġ�
		������������bool���͵�normalize��Ĭ��ֵΪtrue��һ����ʶ������ʾ�ں��Ƿ��������һ����normalized���ˡ�
		���߸�������int���͵�borderType�������ƶ�ͼ���ⲿ���ص�ĳ�ֱ߽�ģʽ����Ĭ��ֵBORDER_DEFAULT������һ�㲻ȥ������*/

	/*blur����������£�
		��һ��������InputArray���͵�src������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɡ��ú�����ͨ���Ƕ�������ģ��ҿ��Դ�������ͨ������ͼƬ������Ҫע�⣬�������ͼƬ���Ӧ��ΪCV_8U, CV_16U, CV_16S, CV_32F �Լ� CV_64F֮һ��
		�ڶ���������OutputArray���͵�dst����Ŀ��ͼ����Ҫ��ԴͼƬ��һ���ĳߴ�����͡����������Mat::Clone����ԴͼƬΪģ�壬����ʼ���õ���ٰ�����Ŀ��ͼ��
		������������Size���ͣ���Size�����Ժ��н��⣩��ksize���ں˵Ĵ�С��һ������дSize(w, h)����ʾ�ں˵Ĵ�С(���У�w Ϊ���ؿ�ȣ� hΪ���ظ߶�)��Size��3, 3���ͱ�ʾ3x3�ĺ˴�С��Size��5, 5���ͱ�ʾ5x5�ĺ˴�С
		���ĸ�������Point���͵�anchor����ʾê�㣨����ƽ�����Ǹ��㣩��ע������Ĭ��ֵPoint(-1, -1)���������������Ǹ�ֵ�Ļ����ͱ�ʾȡ�˵�����Ϊê�㣬����Ĭ��ֵPoint(-1, -1)��ʾ���ê���ں˵����ġ�
		�����������int���͵�borderType�������ƶ�ͼ���ⲿ���ص�ĳ�ֱ߽�ģʽ����Ĭ��ֵBORDER_DEFAULT������һ�㲻ȥ������*/
	
	/*GaussianBlur����������£�
		��һ��������InputArray���͵�src������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɡ��������ǵ���������ͨ������ͼƬ������Ҫע�⣬ͼƬ���Ӧ��ΪCV_8U, CV_16U, CV_16S, CV_32F �Լ� CV_64F֮һ��
		�ڶ���������OutputArray���͵�dst����Ŀ��ͼ����Ҫ��ԴͼƬ��һ���ĳߴ�����͡����������Mat::Clone����ԴͼƬΪģ�壬����ʼ���õ���ٰ�����Ŀ��ͼ��
		������������Size���͵�ksize��˹�ں˵Ĵ�С������ksize.width��ksize.height���Բ�ͬ�������Ƕ�����Ϊ���������������ߣ����ǿ�������ģ����Ƕ�����sigma���������
		���ĸ�������double���͵�sigmaX����ʾ��˹�˺�����X����ĵı�׼ƫ�
		�����������double���͵�sigmaY����ʾ��˹�˺�����Y����ĵı�׼ƫ���sigmaYΪ�㣬�ͽ�����ΪsigmaX�����sigmaX��sigmaY����0����ô����ksize.width��ksize.height���������
		Ϊ�˽������ȷ�����룬����ǰѵ���������Size�����ĸ�����sigmaX�͵��������sigmaYȫ��ָ������
		������������int���͵�borderType�������ƶ�ͼ���ⲿ���ص�ĳ�ֱ߽�ģʽ��ע������Ĭ��ֵBORDER_DEFAULT��*/


	Mat outImage1;
	boxFilter(srcImage, outImage1, -1, Size(5, 5));

	Mat outImage2;
	blur(srcImage, outImage2, Size(5, 5));

	Mat outImage3;
	GaussianBlur(srcImage, outImage3, Size(5, 5), 0 , 0);

	imshow("ԭʼͼ��", srcImage);
	imshow("�����˲�֮��ͼ��", outImage1);
	imshow("��ֵ�˲�֮��ͼ��", outImage2);
	imshow("��˹�˲�֮��ͼ��", outImage3);
	//waitKey�Ĳ�����λ��ms��6000������cmd�����6s�Զ��ر�; 0��������
	waitKey(0);
}



