
#define DLLExport __declspec(dllexport)

//硬件初始化函数,0__fail,1__success
extern "C" DLLExport int AZ216_Init(int delay_code,int Adcras_Flag);
//delay_code ---延时代码,Adcras_Flag---软件模块标志

//与上层数据处理软件的接口程序
extern "C" DLLExport int AZ216(int m_pca,int g_channels,short int *m_data1,int block_num,double sampfreq,
					int samp_mode,int trg_delay,int trg_level,int trg_mode,int trg_channel);


//m_pca---程控放大倍数,1,2,4,8,16;
//g_channels--通道数,1,2;
//m_data1--保存数据的;
//block_num--采样块数,1块为1024个样本点
//sampfreq--采样频率,HZ;
//samp_mode, trg_delay, trg_level, trg_mode, trg_channel---参数输入0值.