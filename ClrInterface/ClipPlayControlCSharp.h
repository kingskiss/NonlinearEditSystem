#pragma once

#include "ClipPlayControlIO.h"
#include <vcclr.h>

#using "ClrDataTypeChange.dll"

using namespace System;
using namespace ClrDataTypeChange;

//#define _MAGICODE_CLIPPLAYCONTROL_

namespace ClrInterfaceDll
{
	/// <summary>
	/// 类说明：视频播放控件托管类
	/// 日期：2017-04-19
	/// 作者：szwb
	/// 修改：2017-05-19		添加注释
	/// </summary>
	public ref class ClipPlayControlCSharp
	{
	public:
		ClipPlayControlCSharp();

		//void Release();

		//加载播控素材
		//参数：
		//1、szClipFileName ---- 输入参数，素材文件全名（包括路径和文件名）
		//2、hWnd ---- 输入参数，素材预览窗口句柄
		//返回值：
		// S_OK ----- 加载成功；否则加载失败
		//注意：只能加载高清MP4或H264音视频素材
		//int SetClip(String^ strFileName, IntPtr hWnd);

		//int SetClip(String^ szClipFileName, ZimuMixInfoList^ ZimuList, IntPtr hWnd);


		/////////////////////////////////////////////////////
		//字幕编辑操作接口  --- begin

		//功能：添加一个字幕，即把字幕文件拖到轨道上
		//参数：
		//szZimuFile ---- 输入参数，添加的字幕文件全名称
		//返回值：
		// >=0 成功 ; <0 失败
		//说明：该接口需要打开字幕文件读取字幕帧数据，如果是第一次打开可能需要一段时间，调用者必须等待该函数返回才能进行下一步处理
		int AddZimuIO(String^ szZimuFile);

		//功能：删除一个字幕，即把轨道上的字幕删除
		//参数：
		//szZimuFile ---- 输入参数，待删除的字幕文件全名称
		//返回值：
		// >=0 成功 ; <0 失败
		int DeleteZimuIO(String^ szZimuFile);

		//功能：修改一个字幕，即把轨道上一个字幕的位置、播放时间等进行修改
		//参数：
		//szZimuFile ---- 输入参数，待修改的字幕文件全名称
		//返回值：
		// >=0 成功 ; <0 失败
		int ModifyZimuIO(String^ szZimuFile);

		//字幕编辑操作接口  --- end
		/////////////////////////////////////////////////////

		//加载多个音视频素材
		//参数：
		//1、AVClipList ---- 输入参数，音视频素材列表，列表中的音视频按前后顺序连续播放
		//2、ZimuList ---- 输入参数，需要叠加的字幕列表
		//3、hWnd ---- 输入参数，素材预览窗口句柄
		//返回值：
		// S_OK ----- 加载成功；否则加载失败
		//注意：
		//1、只能加载高清MP4或H264音视频素材
		//2、CClipPlayControlIO提供的其它所有接口都是在SetMultiClips成功返回后才有效的！
		int SetMultiClipsIO(AVClipInfoList^ AVClipList, ZimuMixInfoList^ ZimuList, IntPtr hWnd);
		//int SetClip(String^ szClipFileName, ZimuMixInfoList^ ZimuList, IntPtr hWnd);


		// 返回set的素材
		String^ GetClip();

		/////////////////////////////////////////////////////
		//素材播控接口
		//播放
		//返回值：S_OK = 成功；否则 失败
		int Play();

		//暂停
		//返回值：S_OK = 成功；否则 失败
		int Pause();

		//从暂停恢复播放
		//返回值：S_OK = 成功；否则 失败
		int Continue();

		//停止
		//返回值：S_OK = 成功；否则 失败
		int Stop();

		//拖动素材到指定位置
		//参数：
		//  rtPos ---- 输入参数，指定位置的时间，单位：100ns
		int SetGivenPosition(long long rtPos);
		/////////////////////////////////////////////////////

		//获取当前播放状态
		//返回值：
		//	0 = 正在运行；1=暂停；2=停止；3=关闭；
		// 返回-1时，表示出错了！
		int GetCurState();

		//获取素材时长
		//返回值：素材时长，单位：100ns;
		// 返回-1时，表示出错了！
		long long GetDuration();

		//获取当前播放位置
		//返回值：当前播放位置，单位：100ns
		// 返回-1时，表示出错了！
		long long GetPosition();

		//设置入点、出点或当前播出位置
		//参数：
		//  rtPos ---- 入点或当前播出位置，单位：100ns
		//  rtEndPos --- 出点，如果出点为素材末尾，则不用设置，直接使用缺省值0，单位：100ns
		//返回值：S_OK = 成功；否则 失败
		int SetPosition(long long rtPos, long long rtEndPos);


		//保存指定帧图像为BMP文件
		//参数：
		//1、szBmpFileName ---- 输入参数，Bmp图像文件全名（包括路径和文件名）
		//2、rtPos ---- 输入参数，待保存的帧图像所在时刻，单位：100ns
		//说明：保存的图片为24位1920*1080大小的BMP图
		void SaveGivenFrameToBmp(String^ szBmpFileName, long long rtPos);


		// 视频信息结构体转换
		AVClipInfo ConvertToAVClipInfoList(tagAVClipInfoCLR^ ctagAVClipInfoCLR);


		// 字幕信息结构体转换
		ZimuMixInfo ConvertToZimuPreviewInfo(tagZimuMixInfoCLR^ ctagZimuPreviewInfoCLR);


	private:
		CClipPlayControlIO* m_IClipPlayControl;

		String^ _strFileName;
	};
}