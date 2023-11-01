#pragma comment (lib, "libgsl.a")
/* From GSL */
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
/* From opencv*/
#include<opencv4/opencv2/imgproc/imgproc.hpp>
#include<opencv4/opencv2/highgui/highgui.hpp>
#include<opencv4/opencv2/core/core.hpp>

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

using namespace std;
using namespace cv;

int get_min_index(double *array, int length, double _value);
/*********************结构体************************/
// 粒子结构体
typedef struct particle {
	double x;			// 当前x坐标
	double y;			// 当前y坐标
	double scale;		// 窗口比例系数
	double xPre;			// x坐标预测位置
	double yPre;			// y坐标预测位置
	double scalePre;		// 窗口预测比例系数
	double xOri;			// 原始x坐标
	double yOri;			// 原始y坐标
	int width;			// 原始区域宽度
	int height;			// 原始区域高度
	//Rect rect;			// 原始区域大小
	MatND hist;			// 粒子区域的特征直方图
	double weight;		// 该粒子的权重
} PARTICLE;

/*************************全局变量*************************/
char* video_file_name = "soccer.avi";
#define NUM_PARTICLE 50 //粒子数
/************************鼠标回调部分*************************/
Rect roiRect;//选取矩形区
Point startPoint;//起点
Point endPoint;//终点
Mat current_frame;
Mat roiImage;
Mat hsv_roiImage;
bool downFlag = false;//按下标志位
bool upFlag = false;//弹起标志位
bool getTargetFlag = false;
//rect方法

Mat regionExtraction(int xRoi, int yRoi,
	int widthRoi, int heightRoi)
{
	//创建与原图像同大小的Mat
	Mat roiImage;// (srcImage.rows, srcImage.cols, CV_8UC3);
	//提取感兴趣区域
	roiImage = current_frame(Rect(xRoi, yRoi, widthRoi, heightRoi)).clone();
	imshow("set-roi", roiImage);
	return roiImage;
}

//鼠标事件回调方法
void MouseEvent(int event, int x, int y, int flags, void* win_name)
{
	//左键按下，取当前位置
	if (event == EVENT_LBUTTONDOWN){
		downFlag = true;
		getTargetFlag = false;
		startPoint.x = x;
		startPoint.y = y;
	}
	//弹起，取当前位置作为终点
	if (event == EVENT_LBUTTONUP) {
		upFlag = true;
		endPoint.x = x;
		endPoint.y = y;
		//终点最值限定
		if (endPoint.x > current_frame.cols)endPoint.x = current_frame.cols;
		if (endPoint.y > current_frame.cols)endPoint.y = current_frame.rows;
	}
	//显示区域？
	if (downFlag == true && upFlag == false){
		Point tempPoint;
		tempPoint.x = x;
		tempPoint.y = y;
		Mat tempImage = current_frame.clone();//取原图像复制
		//用矩形标记
		rectangle(tempImage, startPoint, tempPoint, Scalar(0, 0, 255), 2, 3, 0);
		//imshow((char*)data, tempImage);
		imshow((char*)win_name, tempImage);
	}
	//按下选取完并弹起后
	if (downFlag == true && upFlag == true){
		//起点和终点不相同时，才提取区域
		if (startPoint.x != endPoint.x&&startPoint.y != endPoint.y){
			startPoint.x = min(startPoint.x, endPoint.x);
			startPoint.y = min(startPoint.y, endPoint.y);
			roiRect = Rect(startPoint.x, startPoint.y, endPoint.x - startPoint.x, endPoint.y - startPoint.y);
			roiImage=regionExtraction(startPoint.x, startPoint.y,
				abs(startPoint.x - endPoint.x),
				abs(startPoint.y - endPoint.y));
		}
		downFlag = false;
		upFlag = false;
		getTargetFlag = true;
	}
}
/*************************粒子初始化******************************************/
void particle_init(particle* particles,int _num_particle,MatND hist)
{
	for (int i = 0; i<_num_particle; i++)
	{
		//所有粒子初始化到框中的目标中心
		particles[i].x = roiRect.x + 0.5 * roiRect.width;
		particles[i].y = roiRect.y + 0.5 * roiRect.height;
		particles[i].xPre = particles[i].x;
		particles[i].yPre = particles[i].y;
		particles[i].xOri = particles[i].x;
		particles[i].yOri = particles[i].y;
		//pParticles->rect = roiRect;
		particles[i].width = roiRect.width;
		particles[i].height = roiRect.height;
		particles[i].scale = 1.0;
		particles[i].scalePre = 1.0;
		particles[i].hist = hist;
		//权重全部为0？
		particles[i].weight = 0;
	}
}
/************************粒子状态转移（新位置生成预测）***********************/
//相关定义
/* standard deviations for gaussian sampling in transition model */
#define TRANS_X_STD 1.0
#define TRANS_Y_STD 0.5
#define TRANS_S_STD 0.001
/* autoregressive dynamics parameters for transition model */
#define A1  2.0//2.0
#define A2  -1.0//-1.0
#define B0  1.0000
particle transition(particle p, int w, int h, gsl_rng* rng)
{
	//double rng_nu_x = rng.uniform(0., 1.);
	//double rng_nu_y = rng.uniform(0., 0.5);
	float x, y, s;
	particle pn;

	/* sample new state using second-order autoregressive dynamics */
	x = A1 * (p.x - p.xOri) + A2 * (p.xPre - p.xOri) +
		B0 * gsl_ran_gaussian(rng, TRANS_X_STD)/*rng.gaussian(TRANS_X_STD)*/ + p.xOri;  //计算该粒子下一时刻的x
	pn.x = MAX(0.0, MIN((float)w - 1.0, x));
	y = A1 * (p.y - p.yOri) + A2 * (p.yPre - p.yOri) +
		B0 * gsl_ran_gaussian(rng, TRANS_Y_STD)/*rng.gaussian(TRANS_Y_STD)*/ + p.yOri;
	pn.y = MAX(0.0, MIN((float)h - 1.0, y));
	s = A1 * (p.scale - 1.0) + A2 * (p.scalePre - 1.0) +
		B0 * gsl_ran_gaussian(rng, TRANS_S_STD)/*rng.gaussian(TRANS_S_STD)*/ + 1.0;
	pn.scale = MAX(0.1, s);
	pn.xPre = p.x;
	pn.yPre = p.y;
	pn.scalePre = p.scale;
	pn.xOri = p.xOri;
	pn.yOri = p.yOri;
	pn.width = p.width;
	pn.height = p.height;
	//pn.hist = p.hist;
	pn.weight = 0;

	return pn;
}
/*************************粒子权重归一化****************************/
void normalize_weights(particle* particles, int n)
{
	float sum = 0;
	int i;

	for (i = 0; i < n; i++)
		sum += particles[i].weight;
	for (i = 0; i < n; i++)
		particles[i].weight /= sum;
}
/***********************直方图参数********************************/
// 直方图
int hbins = 10, sbins = 10, vbin = 20;  //180 256 10
int histSize[] = { hbins, sbins };//vbin
//h的范围
float hranges[] = { 0, 180 };
//s的范围
float sranges[] = { 0, 256 };
float vranges[] = { 0, 256 };
//一般只比较hsv的h和s两个通道就够了
const float* ranges[] = { hranges, sranges };
// we compute the histogram from the 0-th and 1-st channels
int channels[] = { 0, 1 };

/*************************粒子权重排序******************************/
int particle_cmp(const void* p1,const void* p2)
{
	//这个函数配合qsort，如果这个函数返回值: (1) <0时：p1排在p2前面   (2)  >0时：p1排在p2后面
	particle* _p1 = (particle*)p1;
	particle* _p2 = (particle*)p2;
	//这里就由大到小排序了
	return _p2->weight - _p1->weight;
}
/*************************粒子重采样********************************/
void resample(particle* particles,particle* new_particles,int num_particles)
{
	//计算每个粒子的概率累计和
	double sum[NUM_PARTICLE], temp_sum = 0;
	int k = 0;
	for (int j = num_particles - 1; j >= 0; j--){
		temp_sum += particles[j].weight;
		sum[j] = temp_sum;
	}
	//为每个粒子生成一个均匀分布【0，1】的随机数
	RNG sum_rng(time(NULL));
	double Ran[NUM_PARTICLE];
	for (int j = 0; j < num_particles; j++){
		sum_rng = sum_rng.next();
		Ran[j] = sum_rng.uniform(0., 1.);
	}
	//在粒子概率累积和数组中找到最小的大于给定随机数的索引，复制该索引的粒子一次到新的粒子数组中 【从权重高的粒子开始】
	for (int j = 0; j <num_particles; j++){
		int copy_index = get_min_index(sum, num_particles, Ran[j]);
		new_particles[k++] = particles[copy_index];
		if (k == num_particles)
			break;
	}
	//如果上面的操作完成，新粒子数组的数量仍少于原给定粒子数量，则复制权重最高的粒子，直到粒子数相等
	while (k < num_particles)
	{
		new_particles[k++] = particles[0]; //复制权值最高的粒子
	}
	//以新粒子数组覆盖久的粒子数组
	for (int i = 0; i<num_particles; i++)
	{
		particles[i] = new_particles[i];  //复制新粒子到particles
	}
}

/*****************************************************************/
int main()
{
	//cv::RNG rng; //新版OPENCV自带随机数生成器
	Mat frame, hsv_frame;
	Vector<Mat> frames;
	//目标的直方图
	MatND hist;
	VideoCapture capture(video_file_name);	// 视频文件video_file_name

	int num_particles = NUM_PARTICLE; //粒子数
	PARTICLE particles[NUM_PARTICLE];
	PARTICLE new_particles[NUM_PARTICLE];
	PARTICLE * pParticles;
	pParticles=particles;
	//particles = (particle*)malloc(num_particles * sizeof(particle));
	//PARTICLE *new_particles;
	//随机数生成器
	gsl_rng* rng;
	gsl_rng_env_setup();
	rng = gsl_rng_alloc(gsl_rng_mt19937);
	gsl_rng_set(rng, time(NULL));
	//cv::RNG rng(time(NULL));
	float s;
	int i, j, k, w, h, x, y;
	//判断视频是否打开
	if (!capture.isOpened())
	{
		cout << "some thing wrong" << endl;
		system("pause");
		return -1;
	}
	//读取一帧
	while (1){
		capture >> frame;
		if (frame.empty()){
			cout << "finish" << endl;
			break;
			//return -1;
		}
		//创建窗口
		namedWindow("frame", CV_WINDOW_NORMAL);
		//复制一个原始帧，给框定目标回调函数用
		current_frame = frame.clone();
		setMouseCallback("frame", MouseEvent,"frame");
		frames.push_back(frame.clone());
		imshow("frame", frame);
		cvWaitKey(40);

		if (getTargetFlag == true){
			//目标区域转换到hsv空间
			//cvtColor(frame, hsv_frame, COLOR_BGR2HSV);
			cvtColor(roiImage, hsv_roiImage, COLOR_BGR2HSV);
			//计算目标区域的直方图
			calcHist(&hsv_roiImage, 1, channels, Mat(), hist, 2, histSize, ranges);
			normalize(hist, hist,0,1,NORM_MINMAX,-1,Mat());	// 归一化L2
			//粒子初始化
			particle_init(particles, num_particles, hist);
			//pParticles = particles;
			//for (int i = 0; i<num_particles; i++)
			//{
			//	//所有粒子初始化到框中的目标中心
			//	pParticles->x = roiRect.x + 0.5 * roiRect.width;
			//	pParticles->y = roiRect.y + 0.5 * roiRect.height;
			//	pParticles->xPre = pParticles->x;
			//	pParticles->yPre = pParticles->y;
			//	pParticles->xOri = pParticles->x;
			//	pParticles->yOri = pParticles->y;
			//	//pParticles->rect = roiRect;
			//	pParticles->width = roiRect.width;
			//	pParticles->height = roiRect.height;
			//	pParticles->scale = 1.0;
			//	pParticles->scalePre = 1.0;
			//	pParticles->hist = hist;
			//	//权重全部为0？
			//	pParticles->weight = 0;
			//	pParticles++;
			//}
		}
		else{
			continue;
		}
		while (1){
			//初始化完成才能进入这里
			capture >> frame;
			if (frame.empty()){
				cout << "finish" << endl;
				break;
				//return -1;
			}
			current_frame = frame.clone();
			frames.push_back(frame.clone());

			//cv::RNG rng;
			//double rng_num = rng.uniform(0., 1.);

			//对每个粒子的操作：
			for (j = 0; j < num_particles; j++){
				//rng = rng.next();
				//这里利用高斯分布的随机数来生成每个粒子下一次的位置以及范围
				particles[j] = transition(particles[j], frame.cols, frame.rows, rng);
				s = particles[j].scale;

				//根据新生成的粒子信息截取对应frame上的区域
				Rect imgParticleRect = Rect(std::max(0, std::min(cvRound(particles[j].x - 0.5*particles[j].width), cvRound(frame.cols - particles[j].width*s))),
					std::max(0, std::min(cvRound(particles[j].y - 0.5*particles[j].height), cvRound(frame.rows - particles[j].height*s))),
					cvRound(particles[j].width*s),
					cvRound(particles[j].height*s));

				Mat imgParticle = current_frame(imgParticleRect).clone();
				//上述区域转换到hsv空间
				cvtColor(imgParticle, imgParticle, CV_BGR2HSV);
				//计算区域的直方图
				calcHist(&imgParticle, 1, channels, Mat(), particles[j].hist, 2, histSize, ranges);
				//直方图归一化到（0，1）
				normalize(particles[j].hist, particles[j].hist, 0, 1, NORM_MINMAX, -1, Mat());	// 归一化L2
				//画出蓝色的粒子框
				rectangle(frame, imgParticleRect, Scalar(255, 0, 0), 1, 8);
				imshow("particle", imgParticle);
				//比较目标的直方图和上述计算的区域直方图,更新particle权重
				particles[j].weight = exp(-100 * (compareHist(hist, particles[j].hist, CV_COMP_BHATTACHARYYA)));
                //CV_COMP_CORREL

				int jj = 0;
			}
			//归一化权重
			normalize_weights(particles, num_particles);

			//重采样
			//new_particles = resample(particles, num_particles);
			int np, k = 0;
			//将粒子按权重从高到低排序
			qsort(particles, num_particles, sizeof(particle), &particle_cmp);
			//重采样
			resample(particles, new_particles, num_particles);
			//double sum[NUM_PARTICLE],temp_sum=0;
			//for (int j = num_particles - 1; j >= 0; j--){
			//	temp_sum += particles[j].weight;
			//	sum[j] = temp_sum;
			//}
			//RNG sum_rng(time(NULL));
			//double Ran[NUM_PARTICLE];
			//for (int j = 0; j < num_particles; j++){
			//	sum_rng=sum_rng.next();
			//	Ran[j]=sum_rng.uniform(0., 1.);
			//}
			//for (int j = 0; j <num_particles; j++){
			//	int copy_index = get_min_index(sum, num_particles, Ran[j]);
			//	new_particles[k++] = particles[copy_index];
			//	if (k == num_particles)
			//		break;
			//}
			//while (k < num_particles)
			//{
			//	new_particles[k++] = particles[0]; //复制权值最高的粒子
			//}
			//for (int i = 0; i<num_particles; i++)
			//{
			//	particles[i] = new_particles[i];  //复制新粒子到particles
			//}


		//  //这里的重采样算法貌似不是标准的，而且还用goto，有待修正
		//	for (int i = 0; i<num_particles; i++)
		//	{
		//		np = cvRound(particles[i].weight*1.0 * num_particles);
		//		for (int j = 0; j<np; j++)
		//		{
		//			new_particles[k++] = particles[i];
		//			if (k == num_particles)
		//				goto EXITOUT;
		//		}
		//	}
		//	while (k < num_particles)
		//	{
		//		new_particles[k++] = particles[0]; //复制权值最高的粒子
		//	}
		//EXITOUT:
		//	for (int i = 0; i<num_particles; i++)
		//	{
		//		particles[i] = new_particles[i];  //复制新粒子到particles
		//	}

			//重排序
			qsort(particles, num_particles, sizeof(particle), &particle_cmp);
			// step 8: 计算粒子的期望，作为跟踪结果
			//Rect_<double> rectTrackingTemp(0.0, 0.0, 0.0, 0.0);
			//rectTrackingTemp.x = cvRound(particles[0].x-0.5*particles[0].scale*particles[0].width);
			//rectTrackingTemp.y = cvRound(particles[0].y - 0.5*particles[0].scale*particles[0].height);
			//rectTrackingTemp.width = cvRound(particles[0].width*particles[0].scale);
			//rectTrackingTemp.height = cvRound(particles[0].height*particles[0].scale);

			//这里直接取权重最高的作为目标了，标准做法应该是按加权平均来计算目标位置
			s = particles[0].scale;
			Rect rectTrackingTemp = Rect(std::max(0, std::min(cvRound(particles[0].x - 0.5*particles[0].width), cvRound(frame.cols - particles[0].width*s))),
				std::max(0, std::min(cvRound(particles[0].y - 0.5*particles[0].height), cvRound(frame.rows - particles[0].height*s))),
				cvRound(particles[0].width*s),
				cvRound(particles[0].height*s));
			//for (int i = 0; i < num_particles; i++){
			//	rectTrackingTemp.x += particles[i]
			//}
			rectangle(frame, rectTrackingTemp, Scalar(0, 0, 255), 1, 8, 0);
			imshow("frame", frame);
			cvWaitKey(40);
		}
	}
}

/*二分法求数组中大于给定值的最小值索引*/
int get_min_index(double *array, int length, double _value)
{
	int _index = (length - 1) / 2;
	int last_index = length - 1;
	int _index_up_limit = length - 1;
	int _index_down_limit = 0;
	//先判断极值
	if (array[0] <= _value){
		return 0;
	}
	if (array[length - 1] > _value){
		return length - 1;
	}
	for (; _index != last_index;){
		//cout << _index << endl;
		last_index = _index;
		if (array[_index] > _value){
			_index = (_index_up_limit + _index) / 2;
			_index_down_limit = last_index;
		}
		else if (array[_index] < _value){
			_index = (_index_down_limit + _index) / 2;
			_index_up_limit = last_index;
		}
		else if (array[_index] == _value){
			_index--;
			break;
		}
	}
	//cout << "final result:" << endl;
	//cout << _index << endl;
	return _index;
}
