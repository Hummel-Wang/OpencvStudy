//OpenCV��Ե��⣺Canny����, Sobel����, Laplace����, Scharr�˲����ϼ�


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
	Mat srcImage = imread(imageRootPath + "sg003.jpg");
	imshow("ԭʼͼ��", srcImage);

#pragma region Canny
	//Canny������⣺
//	��һ��������InputArray���͵�image������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɣ�����Ϊ��ͨ��8λͼ�񡣡�����Ϊ�Ҷ�ͼ��
//	�ڶ���������OutputArray���͵�edges������ı�Եͼ����Ҫ��ԴͼƬ��һ���ĳߴ�����͡�
//	������������double���͵�threshold1����һ���ͺ�����ֵ��
//	���ĸ�������double���͵�threshold2���ڶ����ͺ�����ֵ��
//	�����������int���͵�apertureSize����ʾӦ��Sobel���ӵĿ׾���С������Ĭ��ֵ3��
//	������������bool���͵�L2gradient��һ������ͼ���ݶȷ�ֵ�ı�ʶ����Ĭ��ֵfalse��

	//Mat srcClone = srcImage.clone();
	//Mat DstPic, edge, grayImage;
////������srcͬ���ͺ�ͬ��С�ľ���
	//DstPic.create(srcImage.size(), srcImage.type());

	////��ԭʼͼת��Ϊ�Ҷ�ͼ
	//cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

	////��ʹ��3*3�ں�������
	//blur(grayImage, edge, Size(3, 3));

	////����canny����
	//Canny(edge, edge, 3, 9, 3);

	////ͼƬ��ʾ
	//imshow("Canny֮��Ч��һ", edge);

	//DstPic = Scalar::all(0);
	//srcClone.copyTo(DstPic, edge);
	//imshow("Canny֮��Ч����", DstPic);
#pragma endregion

#pragma region Sobel 

	/*Sobel������⣺
		��һ��������InputArray ���͵�src��Ϊ����ͼ����Mat���ͼ��ɡ�
		�ڶ���������OutputArray���͵�dst����Ŀ��ͼ�񣬺����������������Ҫ��ԴͼƬ��һ���ĳߴ�����͡�
		������������int���͵�ddepth�����ͼ�����ȣ�֧������src.depth()��ddepth����ϣ�
		��src.depth() = CV_8U, ȡddepth = -1 / CV_16S / CV_32F / CV_64F
		��src.depth() = CV_16U / CV_16S, ȡddepth = -1 / CV_32F / CV_64F
		��src.depth() = CV_32F, ȡddepth = -1 / CV_32F / CV_64F
		��src.depth() = CV_64F, ȡddepth = -1 / CV_64F
		���ĸ�������int����dx��x �����ϵĲ�ֽ�����
		�����������int����dy��y�����ϵĲ�ֽ�����
		������������int����ksize����Ĭ��ֵ3����ʾSobel�˵Ĵ�С; ����ȡ1��3��5��7��
		���߸�������double���͵�scale�����㵼��ֵʱ��ѡ���������ӣ�Ĭ��ֵ��1����ʾĬ���������û��Ӧ�����ŵġ����ǿ������ĵ��в���getDerivKernels����ؽ��ܣ����õ���������ĸ�����Ϣ��
		�ڰ˸�������double���͵�delta����ʾ�ڽ������Ŀ��ͼ���ڶ�������dst��֮ǰ��ѡ��deltaֵ����Ĭ��ֵ0��
		�ھŸ������� int���͵�borderType�����ǵ��������ˣ����������һ�����������߽�ģʽ��Ĭ��ֵΪBORDER_DEFAULT��������������ڹٷ��ĵ���borderInterpolate���õ�����ϸ����Ϣ��
*/

//Mat grad_x, grad_y;
//Mat abs_grad_x, abs_grad_y, dst;

////��3���� X�����ݶ�
//Sobel(srcImage, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
//convertScaleAbs(grad_x, abs_grad_x);
//imshow("��Ч��ͼ�� X����Sobel", abs_grad_x);

////��4����Y�����ݶ�
//Sobel(srcImage, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
//convertScaleAbs(grad_y, abs_grad_y);
//imshow("��Ч��ͼ��Y����Sobel", abs_grad_y);

////��5���ϲ��ݶ�(����)
//addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
//imshow("��Ч��ͼ�����巽��Sobel", dst);

#pragma endregion

#pragma region Laplace

	/*Laplace������⣺
		��һ��������InputArray���͵�image������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɣ�����Ϊ��ͨ��8λͼ��
		�ڶ���������OutputArray���͵�edges������ı�Եͼ����Ҫ��ԴͼƬ��һ���ĳߴ��ͨ������
		������������int���͵�ddept��Ŀ��ͼ�����ȡ�
		���ĸ�������int���͵�ksize�����ڼ�����׵������˲����Ŀ׾��ߴ磬��С����Ϊ������������Ĭ��ֵ1��
		�����������double���͵�scale������������˹ֵ��ʱ���ѡ�ı������ӣ���Ĭ��ֵ1��
		������������double���͵�delta����ʾ�ڽ������Ŀ��ͼ���ڶ�������dst��֮ǰ��ѡ��deltaֵ����Ĭ��ֵ0��
		���߸������� int���͵�borderType���߽�ģʽ��Ĭ��ֵΪBORDER_DEFAULT��������������ڹٷ��ĵ���borderInterpolate()���õ�����ϸ����Ϣ��*/

		//Mat  src_gray, dst, abs_dst;

		////��3��ʹ�ø�˹�˲���������
		//GaussianBlur(srcImage, srcImage, Size(3, 3), 0, 0, BORDER_DEFAULT);

		////��4��ת��Ϊ�Ҷ�ͼ
		//cvtColor(srcImage, src_gray, CV_RGB2GRAY);

		////��5��ʹ��Laplace����
		//Laplacian(src_gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);

		////��6���������ֵ���������ת����8λ
		//convertScaleAbs(dst, abs_dst);

		////��7����ʾЧ��ͼ
		//imshow("��Ч��ͼ��ͼ��Laplace�任", abs_dst);

#pragma endregion

#pragma region scharr

//scharr������⣺
//��һ��������InputArray ���͵�src��Ϊ����ͼ����Mat���ͼ��ɡ�
//�ڶ���������OutputArray���͵�dst����Ŀ��ͼ�񣬺����������������Ҫ��ԴͼƬ��һ���ĳߴ�����͡�
//������������int���͵�ddepth�����ͼ�����ȣ�֧������src.depth()��ddepth����ϣ�
//��src.depth() = CV_8U, ȡddepth = -1 / CV_16S / CV_32F / CV_64F
//��src.depth() = CV_16U / CV_16S, ȡddepth = -1 / CV_32F / CV_64F
//��src.depth() = CV_32F, ȡddepth = -1 / CV_32F / CV_64F
//��src.depth() = CV_64F, ȡddepth = -1 / CV_64F
//���ĸ�������int����dx��x�����ϵĲ�ֽ�����
//�����������int����dy��y�����ϵĲ�ֽ�����
//������������double���͵�scale�����㵼��ֵʱ��ѡ���������ӣ�Ĭ��ֵ��1����ʾĬ���������û��Ӧ�����ŵġ����ǿ������ĵ��в���getDerivKernels����ؽ��ܣ����õ���������ĸ�����Ϣ��
//���߸�������double���͵�delta����ʾ�ڽ������Ŀ��ͼ���ڶ�������dst��֮ǰ��ѡ��deltaֵ����Ĭ��ֵ0��
//�ڰ˸������� int���͵�borderType�����ǵ��������ˣ����������һ�����������߽�ģʽ��Ĭ��ֵΪBORDER_DEFAULT��������������ڹٷ��ĵ���borderInterpolate���õ�����ϸ����Ϣ��

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y, dst;

	//��3���� X�����ݶ�
	Scharr(srcImage, grad_x, CV_16S, 1, 0, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);
	imshow("��Ч��ͼ�� X����Scharr", abs_grad_x);

	//��4����Y�����ݶ�
	Scharr(srcImage, grad_y, CV_16S, 0, 1, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);
	imshow("��Ч��ͼ��Y����Scharr", abs_grad_y);

	//��5���ϲ��ݶ�(����)
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);

	//��6����ʾЧ��ͼ
	imshow("��Ч��ͼ���ϲ��ݶȺ�Scharr", dst);


#pragma endregion


	//waitKey�Ĳ�����λ��ms��6000������cmd�����6s�Զ��ر�; 0��������
	waitKey(0);
}



