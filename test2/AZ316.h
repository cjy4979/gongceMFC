
#define DLLExport __declspec(dllexport)

//Ӳ����ʼ������,0__fail,1__success
extern "C" DLLExport int AZ216_Init(int delay_code,int Adcras_Flag);
//delay_code ---��ʱ����,Adcras_Flag---���ģ���־

//���ϲ����ݴ�������Ľӿڳ���
extern "C" DLLExport int AZ216(int m_pca,int g_channels,short int *m_data1,int block_num,double sampfreq,
					int samp_mode,int trg_delay,int trg_level,int trg_mode,int trg_channel);


//m_pca---�̿طŴ���,1,2,4,8,16;
//g_channels--ͨ����,1,2;
//m_data1--�������ݵ�;
//block_num--��������,1��Ϊ1024��������
//sampfreq--����Ƶ��,HZ;
//samp_mode, trg_delay, trg_level, trg_mode, trg_channel---��������0ֵ.