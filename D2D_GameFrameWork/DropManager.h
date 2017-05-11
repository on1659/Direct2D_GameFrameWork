#pragma once

#include "stdafx.h"
#include "Shellapi.h"
#include "Util.h"
#include "RenderManager_2D.h"

#include <deque>
#include <atlimage.h>

enum class DropInfo_TYPE
{
	   DROP_IMAGE = 0
	 , DROP_OTHER
	 , DROP_PDF
	 , DROP_DOC
	,  DROP_AUDIO
};

struct DropInfo
{
	std::vector<std::wstring>  vPath;
	std::vector<std::wstring>  vFileName;
	std::vector<DropInfo_TYPE> vDropType;
	POINT					   pt;
}; 

class CDropManager : public CSingleTonBase<CDropManager>
{
	std::deque<DropInfo> m_qDropInfo;
	DropInfo m_info;
	HWND m_hWnd{ nullptr };
	bool m_bCall{ false };
public:
	CDropManager(HWND hWnd = nullptr, const std::string& name = "DropManager") : CSingleTonBase(name)
	{
		if (nullptr == hWnd) return;
		m_hWnd = hWnd;
		DragAcceptFiles(m_hWnd, false);

	}
	~CDropManager()
	{
		for(auto& data : m_qDropInfo)
			data.vPath.clear();
		DragAcceptFiles(m_hWnd, false);
	}

	void DropMode(const bool& mode = true, HWND hWnd = nullptr)
	{
		if (nullptr == m_hWnd)
		{
			if (nullptr == hWnd)
			{
				return;
			}
			m_hWnd = hWnd;
		}
		DragAcceptFiles(m_hWnd, mode);
	}
	
	virtual bool OnProcessingMouseMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, const bool& show_box = false)
	{
		switch (uMsg)
		{
			case WM_DROPFILES:
				PushDropPath(hWnd, wParam, show_box);
				return true;
				break;
		}
		return false;
	}

	void PushDropPath(HWND hWnd, WPARAM wParam, const bool& show_box = false)
	{
		DropInfo info;

		HDROP hDrop; POINT pt;
		hDrop = (HDROP)wParam;
		DragQueryPoint(hDrop, &pt);
		info.pt = pt;

		TCHAR file_path[256] = { 0 };
		int nDragFileCount = ::DragQueryFile(hDrop, 0xFFFFFFFF, file_path, 256);

		for (int i = 0; i < nDragFileCount; ++i)
		{
			memset(file_path, 0x00, 256);
			::DragQueryFile(hDrop, i, file_path, 256);
			info.vPath.push_back(file_path);

			std::wstring file;
			Radar::GetFileName(file, file_path);
			info.vFileName.push_back(file);
			
			if (Radar::isImage(file_path))
			{
				AddImage(file, file_path);
				info.vDropType.push_back(DropInfo_TYPE::DROP_IMAGE);
			}
			else
			{
				info.vDropType.push_back(DropInfo_TYPE::DROP_OTHER);
			}
		}

		if (show_box)
		{
			for (const auto& name : info.vPath)
			{
				MessageBox(hWnd, name.c_str(), TEXT("file name"), MB_OK);
			}
		}
		m_qDropInfo.push_back(info);

		::DragFinish(hDrop);

		m_bCall = true;
	}


	void PutFolder(DropInfo& info, const std::wstring& folder_path)
	{
		auto vPathRead = Radar::FilePathRead(folder_path.c_str());

		for (auto& path : vPathRead)
		{
			if (path.find(TEXT(".")) > path.size())
			{
				PutFolder(info, path);
			}
			info.vPath.push_back(path);

		}
		
		

	}

	void AddImage(const std::wstring& file_name, const std::wstring& path)
	{
		RENDERMGR_2D->AddImage(file_name, path);
	}

	bool empty() const { return m_qDropInfo.empty(); }

	DropInfo& pop()
	{
		m_bCall = false;
		m_info = m_qDropInfo.front();
		m_qDropInfo.pop_front();
		return m_info;
	}

};