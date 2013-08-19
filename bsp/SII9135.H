/******************************************
* si9135
* ����ֲ�û�н��������ļĴ�����Ҫд;�����ļĴ���Ӧ��д�롰0��
* HDMI CTS:	  HDMI Compliance test specification
*      ACR:   Automatic audio clock regeneration
*	     AAC:   Auto Audio Control	     �Զ���Ƶ����
*	     SCDT:	sync detect	   �г����
*	     CKDT:  clock detect   ʱ�Ӽ��
*	   AVC: Auto Video Configuration �Զ���Ƶ����
*	   ACR: Audio Clock Recovery	
*	   BCH:	 
*	   ECC: 
*	   AEC: 
*  SVA/EVA:
*	   CSC: (Color Space Conversion	
*	  EDDC: Enhanced Display Data Channel Standard	
*
*******************************************/
#ifndef _SII9135I2C_H
#define _SII9135I2C_H

#include "typedef.h"

/***********************9135���߹�ϵ****************************/
//  DE---R93
//	 H---R95
//	 V---R96  ˳��ok
//PCLK---R97
// when 720p: DE-45K    H-45K    V-60HZ    CLK-74.2MHZ
// when	1080��DE-67.4K 	H-67.4K  59.9HZ    CLK-148MHZ
// when   
/************CI2CA Pin is pulled down****************/
#define HDCP_Device_Addr           0x74

#define FirstDeviceAddrWriteAddr   0x60	//ID,HDCP,Video,Interrupt,AEC,ECC
#define FirstDeviceAddrReadAddr    0x61

#define SecondDeviceAddrWriteAddr  0x68	//ACR,Audio Out,Power,Packets
#define SecondDeviceAddrReadAddr   0x69

/**********************************************************
*DDC-Accessible Registers(0x00~0xFF),mcu can not operation
***************��Щ�Ĵ������ÿ�����
**********************************************************/
//#define Device_Identification_Register 0XFB


/**********************************************************
*  sink-Accessible Register at Device Address: 0x60
*  MCU can operation
**********************************************************/
//#define id_register_VND_IDL  0x00 	  //0x01
//#define id_register_VND_IDH  0x01 	  //0x00
//#define id_register_DEV_IDL  0x02 	  //0x35
//#define id_register_DEV_IDH  0x03 	  //0x91
//#define id_register_DEV_REV  0x04 	  //0x03   ����

#define Software_Reset_Register     0x05    //0x00(default)   R/W    ??
#define System_Status_Register      0x06    //0x00(default)   Rֻ��
#define Software_Reset_Register_2   0x07	//0x00(default)   R/W	 deep-color and audio FIFO reset; ����
#define System_Control_Register_1   0x08    //0x04(default)   R/W    video bus mode:24-bit ??
#define Port_Switch_Register        0x09	//0x80(default:enable 300ns delay on SDA input line) 
                                            //0x91(enable port0 DDC and TMDS)
#define PCLK_CNT_MAX             0x0A       //0x34(defaul:disable auto stop)  R/W PCLK_Auto_Stop_Register
                                            //?? bit0:���Ϊ1,�����������塰0��
//#define HDCP_BKSV1               0X1A  //0x00(default) R
//#define HDCP_BKSV2               0X1B  //0x00(default) R
//#define HDCP_BKSV3               0X1C  //0x00(default) R
//#define HDCP_BKSV4               0X1D  //0x00(default) R
//#define HDCP_BKSV5               0X1E  //0x00(default) R  
                         //40bits��HDMI Receive��s KSV������receiver�Ƿ�HDCP capable��

//#define HDCP_RI1                0X1F   //0X00(default) R
//#define HDCP_RI2                0X20   //0X00(default) R  Link verification response
//
//#define HDCP_AKSV1              0X21   //0X00(default) R
//#define HDCP_AKSV2              0X22   //0X00(default) R
//#define HDCP_AKSV3              0X23   //0X00(default) R
//#define HDCP_AKSV4              0X24   //0X00(default) R
//#define HDCP_AKSV5              0X25   //0X00(default) R  40bits:HDMI Transmitter's KSV
//
//#define HDCP_AN1                0X26   //0X00(default) R
//#define HDCP_AN2                0X27   //0X00(default) R
//#define HDCP_AN3                0X28   //0X00(default) R
//#define HDCP_AN4                0X29   //0X00(default) R
//#define HDCP_AN5                0X2A   //0X00(default) R
//#define HDCP_AN6                0X2B   //0X00(default) R
//#define HDCP_AN7                0X2C   //0X00(default) R
//#define HDCP_AN8                0X2D   //0X00(default) R  Session random number

//#define BCAPS_SET  0x2E   //0x80(default) R/W	ע��д����Ĵ�����ʱ��
                          //BIT6:REPEATER(must set this bit to 1 after a hw reset,do not have to set to 1 after a sw reset!)
						  //BIT5:FIFO_RDY(�Ƽ���ÿ����⵽SYNC��ʧӲ����λʱ�塰0��)
//#define SHD_BSTAT1             0X2F//0X00(default) R/W   repeater tree�����HDCP�豸��������������������
//#define SHD_BSTAT2             0X30//0X00(default) r/w   HDMI_MODE,CASC_EXCEED,DEPTH
                                   //��2���Ĵ�������sourceͨ��DDCͨ����ȡ��  


/**********************************************************
*  vodeo input register@device addr:0x60H
*  ��ЩΪֻ���Ĵ���
**********************************************************/
#define H_RESL  0X3A    
#define H_RESH  0X3B    //0x00(default) r �зֱ���
#define V_RESL	0X3C
#define V_RESH	0X3D    //0x00(default) R ÿ��ͼ�������
#define DE_PIXL 0X4E
#define DE-PIXH 0X4F    //0x00(default)  R ����ͼ���width
#define DE_LINL 0X50
#define DE_LINH 0x51    //0x00(default) R ����ͼ���height

#define VID_VTAVL  0X52   //0x00(default) R vsync to active video lines
#define VID_VFP    0X53   //0x00(default) R VSYNC Front Porth

#define VID_STAT   0X55   //0x00(default) R �����źŸ��м��,VSYNC,HSYNC�ļ��Լ��
#define VID_HFP1   0X59
#define VID_HFP2   0X5A   //0x00(default) R Horizontal Front Porth Bits

#define VID_HSWIDL   0X5B
#define VID_HSWIDH   0X5C  //0x00(default) R width of the HSYNC pulse in units of unique pixels

#define VID_XPCNT1  0X6E	  //video pixel clock timing registor
#define VID_XPCNT2  0X6F    //0x00(default) Read only; the number of crystal clocks per 2048 video clock periods
							              //������59.94hz��60hz

/***********************************************
* video processing register@device address:0x60h
* �ص㿴
***********************************************/
#define VID_MODE    0X4A    //0x00(default) R/W   ��ʽת��
#define VID_MODE2   0X49    //0x00(default) R/W   ��ʽת��  bit[7:6]:dither_mode   
#define VID_BLANK1  0X4B	  //0x00(default) R/W   video blanking for channel 1(blue)
#define VID_BLANK2  0X4C	  //0x00(default) R/W   video blanking for channel 2(green)
#define VID_BLANK3  0X4D	  //0x00(default) R/W   video blanking for channel 3(red)
#define VID_CTRL    0X48    //0x00(default) R/W   video control register  ��ʽת�� 
#define VID_F2BPM   0X54    //0x01(default) R/W	  video filed2 back porth mode register
#define VID_CH_MAP  0X56    //0x00(default) R/W   video channel mapping	 RGB
#define VID_CTRL2   0X57    //0x01(default) R/W   ����HSYNC��jitter filter,Ĭ��enable
                            //����Silicon�Ƽ�disable ȥ����CEA-861��

#define DC_STAT     0X61    //0x00(default) Rֻ��  video pixel depth from deep-color packets
                            //0b00: 8 bits per pixel��	01-->10 bits��  10-->12 bits

#define VID_AOF     0X5F    //0x00(default) R/W  ָ��AVCģʽ�������Ƶ�ĸ�ʽ����
                            //0xC8: digital 10-bits 4:2:2 YCbCr output
							//����Ĵ���������deep-color video output format��Ҫ����0x60:0x61[1:0]
							//0x60:0x49[7:6],0x60:0x81[3:0]


#define INTR_STATE   0X70  //0x00(default) R    9135�ж�״̬;9135���ж����PIN��INT=1,9135���ж����
#define INTR1_UNMASK 0X75  //0x00(default) R/W  ��ӦINTR1; 1:not mask 0:mask
#define INTR2_UNMASK 0X76  //0x00(default) R/W  ��ӦINTR2; 1:not mask 0:mask
#define INTR3_UNMASK 0X77  //0x00(default) R/W  ��ӦINTR3; 1:not mask 0:mask
#define INTR4_UNMASK 0X78  //0x00(default) R/W  ��ӦINTR4; 1:not mask 0:mask
#define INTR5_UNMASK 0X7d  //0x00(default) R/W  ��ӦINTR5; 1:not mask 0:mask
#define INTR6_UNMASK 0X7e  //0x00(default) R/W  ��ӦINTR6; 1:not mask 0:mask
#define INTR7_UNMASK 0X92  //0x00(default) R/W  ��ӦINTR7; 1:not mask 0:mask

#define INT_CTRL     0X79  //0X06(default��INT��©���,assert low) R/W  ��PD#Ӱ��
                           //PD#�ı�INT���pin����Ϊ��
#define INTR1        0X71  //0X00(default) R/W  Interrupt Status #1 Register
#define INTR2        0X72  //0X00(default) R/W
#define INTR3        0X73  //0X00(default) R/W	
#define INTR4        0X74  //0X00(default) R/W  Interrupt status #4 register
#define IP_CTRL      0X7A  //0X00(default) R/W  Interrupt Packet Control register
#define INTR5        0X7b  //0X00(default) R/W
#define INTR6        0X7c  //0X00(default) R/W
#define INTR7        0X90  //0X00(default) R/W												

/**************TMDS Analog Core Register********************/
#define TMDS_CCTRL2   0X81  //0X20(default) R/W note:��������߹�������ƵԴ��,DC balance need disable!!
                            //bit[3:0]: control the deep-color clock from TMDS Core!!
							//�������0x61�Ĵ����������⼸��λ����
/**************TMDS Termination Control Register********************/
#define TEDS_TERMVTRL 0X82 //0X08(DEFAULT) R/W  �����ն˵��裬Ĭ��50ohm

/**************Auto Audio and Video Control 9135�Զ�����paths����********************/
#define  AEC_CTRL     0XB5 //0X00(default) R/W  Auto control register
#define  ECC_CTRL 	  0XBB //0X00(DEFAULT) R/W  ECC Control Register �Ƽ�0x01
#define  BCH_THRESH   0XBC //0X01(default) r/w  BCH Threshold register
#define  T4_THRES 	  0XBD //0X01(DEFAULT) R/W  ECC T4 Corrected threshold register
#define  T4_UNTHRES   0XBE //0X01(DEFAULT) R/W  ECC T4 Uncorrected threshold register

/***************ECC Error Threshold and count register@0x60 ********************/
//�˴���ȥһ�ѼĴ���

/**************AEC Exception Enable Register********************/
#define AEC_EN1 0XB6  //0X00(default) R/W
#define AEC_EN2 0XB7  //0X00(default) R/W
#define AEC_EN3 0XB8  //0X00(default) R/W

/**************AEC Video Configuration Mask Register********************/
#define AVC_EN1  0XB9   //0X00(default) R/W
#define AVC_EN2  0XBA     //0X00(default) R/W  provide enables for auto video configuration exception

/**************HDCP Repeater Registers@9x60h************************/
//#define DS_BSTAT1 0XD5
//#define DS_BSTAT2 0XD6  //Downstream BSTATUS Register


//�˴���ȥһ�ѼĴ���

/*******************************************************************
*
*  Sink_Accessible Registers at Device Address 0x68H ������ַ���ˣ�
*  
********************************************************************/
#define ACR_CTRL1  0X00  //0X00(default)          R/W  ACR Control Register #1
#define FREQ_SVAL  0x02  //0b0101 0010(default)   R/W  ACR Audio Frequency Register
/*********ACR N VALUE Registers*************/
#define N_SVAL1    0X03  //0X00(default) R/W
#define N_SVAL2    0X04	 //0X00(default) R/W
#define N_SVAL3    0X05	 //0X00(default) R/W
#define N_HVAL1    0X06	 //0X00(default) R
#define N_HVAL2    0X07	 //0X00(default) R
#define N_HVAL3    0X08  //0X00(default) R  N value for the audio clock regeneration method	
/***********ACR CTS Value Register**************/
#define CTS_SVAL1  0X09	 //0X00(default) R/W
#define CTS_SVAL2  0X0A	 //0X00(default) R/W
#define CTS_SVAL3  0X0B	 //0X00(default) R/W
#define CTS_HVAL1  0X0C	 //0X00(default) R
#define CTS_HVAL2  0X0D	 //0X00(default) R
#define CTS_HVAL3  0X0E  //0X00(default) R   The CTS value for the audio clock regeneration method	
/***********ACR PLL Lock Value Register**************/
#define LKWIN_SVAL 0X13 //
//........

#define TCLK_FS     0x17  //0b0001 0000  R  hardware extracted fs register
#define ACR_CTRL3   0X18  //0b0000 1100     ACR Control #3 Register

/************����2���Ĵ���@device addr��0x60h*************/
#define ACR_CFG1 0X88	//0x9a
#define ACR_CFG2 0x89   //0x36	  ACR Configration register

#define I2S_CTRL1 0X26  //0b0100 0000  R/W audio out i2s control reg #1
#define	I2S_CTRL2 0X27  //0b0000 0001  R/W audio out i2s control reg #2
#define I2S_MAP   0X28  //0b1110 0100  R/W audio out i2s map reg 
#define	AUD_CTRL  0X29  //0b0001 1000  R/W audio out control register

#define	 CHST1     0X2A    //0X00 R    AUDIO In channel status #1 reg
#define	 CHST2	   0x2b    //0x00 r    AUDIO In s/pdif channel status #2 reg
#define	 CHST3     0x2c    //0x00 r    AUDIO In s/pdif channel status #3 reg   
#define	 SW_OW     0X2E    //0X00 R/W  audio swap and overwrite reg
#define	 OW_CHST5  0X2F    //0X00 R/W  Audio CHST5 Overwrite reg
#define	 CHST4     0X30    //0X00 R    Audio In s/pdif channel status #4 reg
#define	 CHST5     0X31    //0X00 R    Audio In s/pdif channel status #45 reg
#define	 AUDO_MUTE 0X32    //0X00 R/W  AUDIO out channel mute reg
#define	 AUDP_STAT 0X34    //0X00 R    hdmi audio status reg
#define	 HDMI_MUTE 0X37    //0X00 R/W  HDMI MUTE Reg

#define	 AUDP_CRIT2    0X38    //0X0C    R/W  HDCP Enable Criteria
#define	 FIFO_PTRDIFF  0X39    //0X00    R/W  HDMI FIFO read/write pointer difference reg
#define	 PD_TOT        0X3C    //0X01    R/W  Power down total register
#define	 PD_SYS3       0X3D    //0X01    R/W  System power down #3 reg 
#define	 PD_SYS2       0X3e    //0x1100 0011  r/w  System power down #2 reg 
#define	 PD_SYS        0X3F    //0X1110 1101  R/W  System power down REG
/*************************************************
* AVI InfoFrame Registers  0X40~0X52   ֻ��
**************************************************/
#define	 AVI_TYPE  0X40  //
#define	 AVI_VERS  0X41 
#define	 AVI_LEN   0X42
#define	 AVI_CHSUM 0X43
//�˴�ʡ��һ��ѼĴ���

/*************************************************
* SPD InfoFrame Registers  0X60~0X7E  ֻ��
**************************************************/
//�˴�ʡ��һ��ѼĴ���

/*************************************************
*
* Audio InfoFrame Registers  0X80~0X8D  ֻ��
**************************************************/
//�˴�ʡ��һ��ѼĴ���

/*************************************************
*
* MPEG InfoFrame Registers  0XA0~0XBE  ֻ��
**************************************************/
//�˴�ʡ��һ��ѼĴ���

/*************************************************
*
* AUDIO control packet register 0xE0~0XFE ֻ��
**************************************************/
//�˴�ʡ��һ��ѼĴ���

/*************************************************
*
* Unrecongnized packet Registers  0XC0~0XDE  ֻ��
**************************************************/
//�˴�ʡ��һ��ѼĴ���

#define	 GCP_DBYTE1  0XDF  //0X00 R    General Control Packet register

/************************Packet Type Decode Registers*******************************/
#define	 MPEG_DEC    0XBF  //0X85 R/W  	
#define	 SPD_DEC     0X7F  //0X83 R/W
#define	 ACP_DEC     0XFF  //0X04 R/W


/**************************************************************/
void  sii9135_SomeNOP(uchar n);
void  sii9135_I2CWrite(uchar DeviceAdd,uchar PtrAdd,uchar Data);
uchar sii9135_I2CRead(uchar DeviceAdd,uchar PtrAdd);
void  sii9135_I2CReadp(uchar DeviceAdd,uchar PtrAdd,uchar *Data,unsigned int n);	//��ָ���IIC������
void  sii9135_I2CWritep(uchar DeviceAdd,uchar PtrAdd,uchar *Data,unsigned int n);//��ָ���IICд����
  unsigned char Video_Filed_Frequency_In9135(void);
  unsigned char PCLK_Detection(void);

//extern void  I2CStart1(void);
//extern void  I2CStop1(void);
//extern bit   WaitAck1(void);
//extern void  SendAck1(void);												   
//extern void  SendNotAck1(void);
//extern void  I2CSendByte1(unsigned char ch);
//extern uchar I2CRecevieByte1(void);

//void  I2CWrite1(uchar DeviceAdd,uchar PtrAdd,uchar Data);
//uchar I2CRead1(uchar DeviceAdd,uchar PtrAdd);
//extern void  I2CReadp1(uchar DeviceAdd,uchar PtrAdd,uchar *Data,unsigned int n); //��ָ���IIC������
//extern void  I2CWritep1(uchar DeviceAdd,uchar PtrAdd,uchar *Data,unsigned int n);//��ָ���IICд����
//extern data unsigned char SystemError;


#endif