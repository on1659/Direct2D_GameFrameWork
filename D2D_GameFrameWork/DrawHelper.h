#pragma once

#include "stdafx.h"

enum MyColorEnum
{
	AliceBlue = 0
	, AntiqueWhite
	, Aqua
	, Aquamarine
	, Azure
	, Beige
	, Bisque
	, Black
	, BlanchedAlmond
	, Blue
	, BlueViolet
	, Brown
	, BurlyWood
	, CadetBlue
	, Chartreuse
	, Chocolate
	, Coral
	, CornflowerBlue
	, Cornsilk
	, Crimson
	, Cyan
	, DarkBlue
	, DarkCyan
	, DarkGoldenrod
	, DarkGray
	, DarkGreen
	, DarkKhaki
	, DarkMagenta
	, DarkOliveGreen
	, DarkOrange
	, DarkOrchid
	, DarkRed
	, DarkSalmon
	, DarkSeaGreen
	, DarkSlateBlue
	, DarkSlateGray
	, DarkTurquoise
	, DarkViolet
	, DeepPink
	, DeepSkyBlue
	, DimGray
	, DodgerBlue
	, Firebrick
	, FloralWhite
	, ForestGreen
	, Fuchsia
	, Gainsboro
	, GhostWhite
	, Gold
	, Goldenrod
	, Gray
	, Green
	, GreenYellow
	, Honeydew
	, HotPink
	, IndianRed
	, Indigo
	, Ivory
	, Khaki
	, Lavender
	, LavenderBlush
	, LawnGreen
	, LemonChiffon
	, LightBlue
	, LightCoral
	, LightCyan
	, LightGoldenrodYellow
	, LightGreen
	, LightGray
	, LightPink
	, LightSalmon
	, LightSeaGreen
	, LightSkyBlue
	, LightSlateGray
	, LightSteelBlue
	, LightYellow
	, Lime
	, LimeGreen
	, Linen
	, Magenta
	, Maroon
	, MediumAquamarine
	, MediumBlue
	, MediumOrchid
	, MediumPurple
	, MediumSeaGreen
	, MediumSlateBlue
	, MediumSpringGreen
	, MediumTurquoise
	, MediumVioletRed
	, MidnightBlue
	, MintCream
	, MistyRose
	, Moccasin
	, NavajoWhite
	, Navy
	, OldLace
	, Olive
	, OliveDrab
	, Orange
	, OrangeRed
	, Orchid
	, PaleGoldenrod
	, PaleGreen
	, PaleTurquoise
	, PaleVioletRed
	, PapayaWhip
	, PeachPuff
	, Peru
	, Pink
	, Plum
	, PowderBlue
	, Purple
	, Red
	, RosyBrown
	, RoyalBlue
	, SaddleBrown
	, Salmon
	, SandyBrown
	, SeaGreen
	, SeaShell
	, Sienna
	, Silver
	, SkyBlue
	, SlateBlue
	, SlateGray
	, Snow
	, SpringGreen
	, SteelBlue
	, Tan
	, Teal
	, Thistle
	, Tomato
	, Turquoise
	, Violet
	, Wheat
	, White
	, WhiteSmoke
	, Yellow
	, YellowGreen
	, MyColorEnd
};

enum FONT_FORMAT
{
	  FONT_¿¾³¯¸ñ¿åÅÁ25
	, FONT_³ª´®¹Ù¸¥°íµñ
};

class MyColor : public CSingleTonBase<MyColor>
{
	std::map<std::string, ID2D1SolidColorBrush*> myBrushMap;

	std::vector<ID2D1SolidColorBrush*> vBrush;

public:

	MyColor() : CSingleTonBase("MyColor") {}

	ID2D1SolidColorBrush* GetColor(const MyColorEnum& color) {	return vBrush[static_cast<int>(color)]; }

	ID2D1SolidColorBrush* GetColor(const std::string& color) {	return nullptr; }

	bool Release()
	{
		CSingleTonBase::Release();

		for (auto& color : myBrushMap)
		{
			color.second->Release();
			color.second = nullptr;
		}
		myBrushMap.clear();

		for (auto& color : vBrush)
		{
			color->Release();
			color = nullptr;
		}
		vBrush.clear();

		return true;
	}

	void Load(ID2D1HwndRenderTarget *pd2dRenderTarget) { CreaetGobalBurshVector(pd2dRenderTarget); }

private:
	void CreaetGobalBurshVector(ID2D1HwndRenderTarget *pd2dRenderTarget)
	{							
		vBrush.reserve(static_cast<int>(MyColorEnum::MyColorEnd));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::AliceBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::AntiqueWhite			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Aqua					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Aquamarine			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Azure					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Beige					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Bisque				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Black					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::BlanchedAlmond		, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Blue					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::BlueViolet			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Brown					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::BurlyWood				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::CadetBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Chartreuse			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Chocolate				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Coral					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::CornflowerBlue		, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Cornsilk				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Crimson				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Cyan					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkCyan				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkGoldenrod			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkGray				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkGreen				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkKhaki				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkMagenta			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkOliveGreen		, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkOrange			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkOrchid			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkRed				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkSalmon			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkSeaGreen			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkSlateBlue			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkSlateGray			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkTurquoise			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DarkViolet			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DeepPink				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DeepSkyBlue			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DimGray				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::DodgerBlue			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Firebrick				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::FloralWhite			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::ForestGreen			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Fuchsia				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Gainsboro				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::GhostWhite			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Gold					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Goldenrod				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Gray					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Green					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::GreenYellow			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Honeydew				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::HotPink				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::IndianRed				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Indigo				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Ivory					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Khaki					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Lavender				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LavenderBlush			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LawnGreen				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LemonChiffon			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LightBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LightCoral			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LightCyan				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LightGoldenrodYellow	, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LightGreen			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LightGray				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LightPink				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LightSalmon			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LightSeaGreen			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LightSkyBlue			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LightSlateGray		, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LightSteelBlue		, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LightYellow			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Lime					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::LimeGreen				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Linen					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Magenta				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Maroon				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::MediumAquamarine		, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::MediumBlue			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::MediumOrchid			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::MediumPurple			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::MediumSeaGreen		, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::MediumSlateBlue		, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::MediumSpringGreen		, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::MediumTurquoise		, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::MediumVioletRed		, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::MidnightBlue			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::MintCream				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::MistyRose				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Moccasin				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::NavajoWhite			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Navy					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::OldLace				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Olive					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::OliveDrab				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Orange				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::OrangeRed				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Orchid				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::PaleGoldenrod			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::PaleGreen				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::PaleTurquoise			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::PaleVioletRed			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::PapayaWhip			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::PeachPuff				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Peru					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Pink					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Plum					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::PowderBlue			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Purple				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Red					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::RosyBrown				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::RoyalBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::SaddleBrown			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Salmon				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::SandyBrown			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::SeaGreen				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::SeaShell				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Sienna				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Silver				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::SkyBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::SlateBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::SlateGray				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Snow					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::SpringGreen			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::SteelBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Tan					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Teal					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Thistle				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Tomato				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Turquoise				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Violet				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Wheat					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::White					, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::WhiteSmoke			, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::Yellow				, 1.0f));
		AddBrush(pd2dRenderTarget, D2D1::ColorF(D2D1::ColorF::YellowGreen			, 1.0f));
	}				

	void CreaetGobalBurshMap(ID2D1HwndRenderTarget *pd2dRenderTarget)
	{
		//AddBrush(pd2dRenderTarget, "Red",    D2D1::ColorF(D2D1::ColorF::Red,	1.0f));
		//AddBrush(pd2dRenderTarget, "Green",  D2D1::ColorF(D2D1::ColorF::Green,  1.0f));
		//AddBrush(pd2dRenderTarget, "Blue",   D2D1::ColorF(D2D1::ColorF::Blue,	1.0f));
		//AddBrush(pd2dRenderTarget, "Yellow", D2D1::ColorF(D2D1::ColorF::Yellow, 1.0f));
		//AddBrush(pd2dRenderTarget, "Black",  D2D1::ColorF(D2D1::ColorF::Black,	1.0f));
		//AddBrush(pd2dRenderTarget, "White",  D2D1::ColorF(D2D1::ColorF::White,	1.0f));

		AddBrush(pd2dRenderTarget, "AliceBlue"				, D2D1::ColorF(D2D1::ColorF::AliceBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, "AntiqueWhite"			, D2D1::ColorF(D2D1::ColorF::AntiqueWhite			, 1.0f));
		AddBrush(pd2dRenderTarget, "Aqua"					, D2D1::ColorF(D2D1::ColorF::Aqua					, 1.0f));
		AddBrush(pd2dRenderTarget, "Aquamarine"				, D2D1::ColorF(D2D1::ColorF::Aquamarine				, 1.0f));
		AddBrush(pd2dRenderTarget, "Azure"					, D2D1::ColorF(D2D1::ColorF::Azure					, 1.0f));
		AddBrush(pd2dRenderTarget, "Beige"					, D2D1::ColorF(D2D1::ColorF::Beige					, 1.0f));
		AddBrush(pd2dRenderTarget, "Bisque"					, D2D1::ColorF(D2D1::ColorF::Bisque					, 1.0f));
		AddBrush(pd2dRenderTarget, "Black"					, D2D1::ColorF(D2D1::ColorF::Black					, 1.0f));
		AddBrush(pd2dRenderTarget, "BlanchedAlmond"			, D2D1::ColorF(D2D1::ColorF::BlanchedAlmond			, 1.0f));
		AddBrush(pd2dRenderTarget, "Blue"					, D2D1::ColorF(D2D1::ColorF::Blue					, 1.0f));
		AddBrush(pd2dRenderTarget, "BlueViolet"				, D2D1::ColorF(D2D1::ColorF::BlueViolet				, 1.0f));
		AddBrush(pd2dRenderTarget, "Brown"					, D2D1::ColorF(D2D1::ColorF::Brown					, 1.0f));
		AddBrush(pd2dRenderTarget, "BurlyWood"				, D2D1::ColorF(D2D1::ColorF::BurlyWood				, 1.0f));
		AddBrush(pd2dRenderTarget, "CadetBlue"				, D2D1::ColorF(D2D1::ColorF::CadetBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, "Chartreuse"				, D2D1::ColorF(D2D1::ColorF::Chartreuse				, 1.0f));
		AddBrush(pd2dRenderTarget, "Chocolate"				, D2D1::ColorF(D2D1::ColorF::Chocolate				, 1.0f));
		AddBrush(pd2dRenderTarget, "Coral"					, D2D1::ColorF(D2D1::ColorF::Coral					, 1.0f));
		AddBrush(pd2dRenderTarget, "CornflowerBlue"			, D2D1::ColorF(D2D1::ColorF::CornflowerBlue			, 1.0f));
		AddBrush(pd2dRenderTarget, "Cornsilk"				, D2D1::ColorF(D2D1::ColorF::Cornsilk				, 1.0f));
		AddBrush(pd2dRenderTarget, "Crimson"				, D2D1::ColorF(D2D1::ColorF::Crimson				, 1.0f));
		AddBrush(pd2dRenderTarget, "Cyan"					, D2D1::ColorF(D2D1::ColorF::Cyan					, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkBlue"				, D2D1::ColorF(D2D1::ColorF::DarkBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkCyan"				, D2D1::ColorF(D2D1::ColorF::DarkCyan				, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkGoldenrod"			, D2D1::ColorF(D2D1::ColorF::DarkGoldenrod			, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkGray"				, D2D1::ColorF(D2D1::ColorF::DarkGray				, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkGreen"				, D2D1::ColorF(D2D1::ColorF::DarkGreen				, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkKhaki"				, D2D1::ColorF(D2D1::ColorF::DarkKhaki				, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkMagenta"			, D2D1::ColorF(D2D1::ColorF::DarkMagenta			, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkOliveGreen"			, D2D1::ColorF(D2D1::ColorF::DarkOliveGreen			, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkOrange"				, D2D1::ColorF(D2D1::ColorF::DarkOrange				, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkOrchid"				, D2D1::ColorF(D2D1::ColorF::DarkOrchid				, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkRed"				, D2D1::ColorF(D2D1::ColorF::DarkRed				, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkSalmon"				, D2D1::ColorF(D2D1::ColorF::DarkSalmon				, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkSeaGreen"			, D2D1::ColorF(D2D1::ColorF::DarkSeaGreen			, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkSlateBlue"			, D2D1::ColorF(D2D1::ColorF::DarkSlateBlue			, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkSlateGray"			, D2D1::ColorF(D2D1::ColorF::DarkSlateGray			, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkTurquoise"			, D2D1::ColorF(D2D1::ColorF::DarkTurquoise			, 1.0f));
		AddBrush(pd2dRenderTarget, "DarkViolet"				, D2D1::ColorF(D2D1::ColorF::DarkViolet				, 1.0f));
		AddBrush(pd2dRenderTarget, "DeepPink"				, D2D1::ColorF(D2D1::ColorF::DeepPink				, 1.0f));
		AddBrush(pd2dRenderTarget, "DeepSkyBlue"			, D2D1::ColorF(D2D1::ColorF::DeepSkyBlue			, 1.0f));
		AddBrush(pd2dRenderTarget, "DimGray"				, D2D1::ColorF(D2D1::ColorF::DimGray				, 1.0f));
		AddBrush(pd2dRenderTarget, "DodgerBlue"				, D2D1::ColorF(D2D1::ColorF::DodgerBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, "Firebrick"				, D2D1::ColorF(D2D1::ColorF::Firebrick				, 1.0f));
		AddBrush(pd2dRenderTarget, "FloralWhite"			, D2D1::ColorF(D2D1::ColorF::FloralWhite			, 1.0f));
		AddBrush(pd2dRenderTarget, "ForestGreen"			, D2D1::ColorF(D2D1::ColorF::ForestGreen			, 1.0f));
		AddBrush(pd2dRenderTarget, "Fuchsia"				, D2D1::ColorF(D2D1::ColorF::Fuchsia				, 1.0f));
		AddBrush(pd2dRenderTarget, "Gainsboro"				, D2D1::ColorF(D2D1::ColorF::Gainsboro				, 1.0f));
		AddBrush(pd2dRenderTarget, "GhostWhite"				, D2D1::ColorF(D2D1::ColorF::GhostWhite				, 1.0f));
		AddBrush(pd2dRenderTarget, "Gold"					, D2D1::ColorF(D2D1::ColorF::Gold					, 1.0f));
		AddBrush(pd2dRenderTarget, "Goldenrod"				, D2D1::ColorF(D2D1::ColorF::Goldenrod				, 1.0f));
		AddBrush(pd2dRenderTarget, "Gray"					, D2D1::ColorF(D2D1::ColorF::Gray					, 1.0f));
		AddBrush(pd2dRenderTarget, "Green"					, D2D1::ColorF(D2D1::ColorF::Green					, 1.0f));
		AddBrush(pd2dRenderTarget, "GreenYellow"			, D2D1::ColorF(D2D1::ColorF::GreenYellow			, 1.0f));
		AddBrush(pd2dRenderTarget, "Honeydew"				, D2D1::ColorF(D2D1::ColorF::Honeydew				, 1.0f));
		AddBrush(pd2dRenderTarget, "HotPink"				, D2D1::ColorF(D2D1::ColorF::HotPink				, 1.0f));
		AddBrush(pd2dRenderTarget, "IndianRed"				, D2D1::ColorF(D2D1::ColorF::IndianRed				, 1.0f));
		AddBrush(pd2dRenderTarget, "Indigo"					, D2D1::ColorF(D2D1::ColorF::Indigo					, 1.0f));
		AddBrush(pd2dRenderTarget, "Ivory"					, D2D1::ColorF(D2D1::ColorF::Ivory					, 1.0f));
		AddBrush(pd2dRenderTarget, "Khaki"					, D2D1::ColorF(D2D1::ColorF::Khaki					, 1.0f));
		AddBrush(pd2dRenderTarget, "Lavender"				, D2D1::ColorF(D2D1::ColorF::Lavender				, 1.0f));
		AddBrush(pd2dRenderTarget, "LavenderBlush"			, D2D1::ColorF(D2D1::ColorF::LavenderBlush			, 1.0f));
		AddBrush(pd2dRenderTarget, "LawnGreen"				, D2D1::ColorF(D2D1::ColorF::LawnGreen				, 1.0f));
		AddBrush(pd2dRenderTarget, "LemonChiffon"			, D2D1::ColorF(D2D1::ColorF::LemonChiffon			, 1.0f));
		AddBrush(pd2dRenderTarget, "LightBlue"				, D2D1::ColorF(D2D1::ColorF::LightBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, "LightCoral"				, D2D1::ColorF(D2D1::ColorF::LightCoral				, 1.0f));
		AddBrush(pd2dRenderTarget, "LightCyan"				, D2D1::ColorF(D2D1::ColorF::LightCyan				, 1.0f));
		AddBrush(pd2dRenderTarget, "LightGoldenrodYellow"	, D2D1::ColorF(D2D1::ColorF::LightGoldenrodYellow	, 1.0f));
		AddBrush(pd2dRenderTarget, "LightGreen"				, D2D1::ColorF(D2D1::ColorF::LightGreen				, 1.0f));
		AddBrush(pd2dRenderTarget, "LightGray"				, D2D1::ColorF(D2D1::ColorF::LightGray				, 1.0f));
		AddBrush(pd2dRenderTarget, "LightPink"				, D2D1::ColorF(D2D1::ColorF::LightPink				, 1.0f));
		AddBrush(pd2dRenderTarget, "LightSalmon"			, D2D1::ColorF(D2D1::ColorF::LightSalmon			, 1.0f));
		AddBrush(pd2dRenderTarget, "LightSeaGreen"			, D2D1::ColorF(D2D1::ColorF::LightSeaGreen			, 1.0f));
		AddBrush(pd2dRenderTarget, "LightSkyBlue"			, D2D1::ColorF(D2D1::ColorF::LightSkyBlue			, 1.0f));
		AddBrush(pd2dRenderTarget, "LightSlateGray"			, D2D1::ColorF(D2D1::ColorF::LightSlateGray			, 1.0f));
		AddBrush(pd2dRenderTarget, "LightSteelBlue"			, D2D1::ColorF(D2D1::ColorF::LightSteelBlue			, 1.0f));
		AddBrush(pd2dRenderTarget, "LightYellow"			, D2D1::ColorF(D2D1::ColorF::LightYellow			, 1.0f));
		AddBrush(pd2dRenderTarget, "Lime"					, D2D1::ColorF(D2D1::ColorF::Lime					, 1.0f));
		AddBrush(pd2dRenderTarget, "LimeGreen"				, D2D1::ColorF(D2D1::ColorF::LimeGreen				, 1.0f));
		AddBrush(pd2dRenderTarget, "Linen"					, D2D1::ColorF(D2D1::ColorF::Linen					, 1.0f));
		AddBrush(pd2dRenderTarget, "Magenta"				, D2D1::ColorF(D2D1::ColorF::Magenta				, 1.0f));
		AddBrush(pd2dRenderTarget, "Maroon"					, D2D1::ColorF(D2D1::ColorF::Maroon					, 1.0f));
		AddBrush(pd2dRenderTarget, "MediumAquamarine"		, D2D1::ColorF(D2D1::ColorF::MediumAquamarine		, 1.0f));
		AddBrush(pd2dRenderTarget, "MediumBlue"				, D2D1::ColorF(D2D1::ColorF::MediumBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, "MediumOrchid"			, D2D1::ColorF(D2D1::ColorF::MediumOrchid			, 1.0f));
		AddBrush(pd2dRenderTarget, "MediumPurple"			, D2D1::ColorF(D2D1::ColorF::MediumPurple			, 1.0f));
		AddBrush(pd2dRenderTarget, "MediumSeaGreen"			, D2D1::ColorF(D2D1::ColorF::MediumSeaGreen			, 1.0f));
		AddBrush(pd2dRenderTarget, "MediumSlateBlue"		, D2D1::ColorF(D2D1::ColorF::MediumSlateBlue		, 1.0f));
		AddBrush(pd2dRenderTarget, "MediumSpringGreen"		, D2D1::ColorF(D2D1::ColorF::MediumSpringGreen		, 1.0f));
		AddBrush(pd2dRenderTarget, "MediumTurquoise"		, D2D1::ColorF(D2D1::ColorF::MediumTurquoise		, 1.0f));
		AddBrush(pd2dRenderTarget, "MediumVioletRed"		, D2D1::ColorF(D2D1::ColorF::MediumVioletRed		, 1.0f));
		AddBrush(pd2dRenderTarget, "MidnightBlue"			, D2D1::ColorF(D2D1::ColorF::MidnightBlue			, 1.0f));
		AddBrush(pd2dRenderTarget, "MintCream"				, D2D1::ColorF(D2D1::ColorF::MintCream				, 1.0f));
		AddBrush(pd2dRenderTarget, "MistyRose"				, D2D1::ColorF(D2D1::ColorF::MistyRose				, 1.0f));
		AddBrush(pd2dRenderTarget, "Moccasin"				, D2D1::ColorF(D2D1::ColorF::Moccasin				, 1.0f));
		AddBrush(pd2dRenderTarget, "NavajoWhite"			, D2D1::ColorF(D2D1::ColorF::NavajoWhite			, 1.0f));
		AddBrush(pd2dRenderTarget, "Navy"					, D2D1::ColorF(D2D1::ColorF::Navy					, 1.0f));
		AddBrush(pd2dRenderTarget, "OldLace"				, D2D1::ColorF(D2D1::ColorF::OldLace				, 1.0f));
		AddBrush(pd2dRenderTarget, "Olive"					, D2D1::ColorF(D2D1::ColorF::Olive					, 1.0f));
		AddBrush(pd2dRenderTarget, "OliveDrab"				, D2D1::ColorF(D2D1::ColorF::OliveDrab				, 1.0f));
		AddBrush(pd2dRenderTarget, "Orange"					, D2D1::ColorF(D2D1::ColorF::Orange					, 1.0f));
		AddBrush(pd2dRenderTarget, "OrangeRed"				, D2D1::ColorF(D2D1::ColorF::OrangeRed				, 1.0f));
		AddBrush(pd2dRenderTarget, "Orchid"					, D2D1::ColorF(D2D1::ColorF::Orchid					, 1.0f));
		AddBrush(pd2dRenderTarget, "PaleGoldenrod"			, D2D1::ColorF(D2D1::ColorF::PaleGoldenrod			, 1.0f));
		AddBrush(pd2dRenderTarget, "PaleGreen"				, D2D1::ColorF(D2D1::ColorF::PaleGreen				, 1.0f));
		AddBrush(pd2dRenderTarget, "PaleTurquoise"			, D2D1::ColorF(D2D1::ColorF::PaleTurquoise			, 1.0f));
		AddBrush(pd2dRenderTarget, "PaleVioletRed"			, D2D1::ColorF(D2D1::ColorF::PaleVioletRed			, 1.0f));
		AddBrush(pd2dRenderTarget, "PapayaWhip"				, D2D1::ColorF(D2D1::ColorF::PapayaWhip				, 1.0f));
		AddBrush(pd2dRenderTarget, "PeachPuff"				, D2D1::ColorF(D2D1::ColorF::PeachPuff				, 1.0f));
		AddBrush(pd2dRenderTarget, "Peru"					, D2D1::ColorF(D2D1::ColorF::Peru					, 1.0f));
		AddBrush(pd2dRenderTarget, "Pink"					, D2D1::ColorF(D2D1::ColorF::Pink					, 1.0f));
		AddBrush(pd2dRenderTarget, "Plum"					, D2D1::ColorF(D2D1::ColorF::Plum					, 1.0f));
		AddBrush(pd2dRenderTarget, "PowderBlue"				, D2D1::ColorF(D2D1::ColorF::PowderBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, "Purple"					, D2D1::ColorF(D2D1::ColorF::Purple					, 1.0f));
		AddBrush(pd2dRenderTarget, "Red"					, D2D1::ColorF(D2D1::ColorF::Red					, 1.0f));
		AddBrush(pd2dRenderTarget, "RosyBrown"				, D2D1::ColorF(D2D1::ColorF::RosyBrown				, 1.0f));
		AddBrush(pd2dRenderTarget, "RoyalBlue"				, D2D1::ColorF(D2D1::ColorF::RoyalBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, "SaddleBrown"			, D2D1::ColorF(D2D1::ColorF::SaddleBrown			, 1.0f));
		AddBrush(pd2dRenderTarget, "Salmon"					, D2D1::ColorF(D2D1::ColorF::Salmon					, 1.0f));
		AddBrush(pd2dRenderTarget, "SandyBrown"				, D2D1::ColorF(D2D1::ColorF::SandyBrown				, 1.0f));
		AddBrush(pd2dRenderTarget, "SeaGreen"				, D2D1::ColorF(D2D1::ColorF::SeaGreen				, 1.0f));
		AddBrush(pd2dRenderTarget, "SeaShell"				, D2D1::ColorF(D2D1::ColorF::SeaShell				, 1.0f));
		AddBrush(pd2dRenderTarget, "Sienna"					, D2D1::ColorF(D2D1::ColorF::Sienna					, 1.0f));
		AddBrush(pd2dRenderTarget, "Silver"					, D2D1::ColorF(D2D1::ColorF::Silver					, 1.0f));
		AddBrush(pd2dRenderTarget, "SkyBlue"				, D2D1::ColorF(D2D1::ColorF::SkyBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, "SlateBlue"				, D2D1::ColorF(D2D1::ColorF::SlateBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, "SlateGray"				, D2D1::ColorF(D2D1::ColorF::SlateGray				, 1.0f));
		AddBrush(pd2dRenderTarget, "Snow"					, D2D1::ColorF(D2D1::ColorF::Snow					, 1.0f));
		AddBrush(pd2dRenderTarget, "SpringGreen"			, D2D1::ColorF(D2D1::ColorF::SpringGreen			, 1.0f));
		AddBrush(pd2dRenderTarget, "SteelBlue"				, D2D1::ColorF(D2D1::ColorF::SteelBlue				, 1.0f));
		AddBrush(pd2dRenderTarget, "Tan"					, D2D1::ColorF(D2D1::ColorF::Tan					, 1.0f));
		AddBrush(pd2dRenderTarget, "Teal"					, D2D1::ColorF(D2D1::ColorF::Teal					, 1.0f));
		AddBrush(pd2dRenderTarget, "Thistle"				, D2D1::ColorF(D2D1::ColorF::Thistle				, 1.0f));
		AddBrush(pd2dRenderTarget, "Tomato"					, D2D1::ColorF(D2D1::ColorF::Tomato					, 1.0f));
		AddBrush(pd2dRenderTarget, "Turquoise"				, D2D1::ColorF(D2D1::ColorF::Turquoise				, 1.0f));
		AddBrush(pd2dRenderTarget, "Violet"					, D2D1::ColorF(D2D1::ColorF::Violet					, 1.0f));
		AddBrush(pd2dRenderTarget, "Wheat"					, D2D1::ColorF(D2D1::ColorF::Wheat					, 1.0f));
		AddBrush(pd2dRenderTarget, "White"					, D2D1::ColorF(D2D1::ColorF::White					, 1.0f));
		AddBrush(pd2dRenderTarget, "WhiteSmoke"				, D2D1::ColorF(D2D1::ColorF::WhiteSmoke				, 1.0f));
		AddBrush(pd2dRenderTarget, "Yellow"					, D2D1::ColorF(D2D1::ColorF::Yellow					, 1.0f));
		AddBrush(pd2dRenderTarget, "YellowGreen"			, D2D1::ColorF(D2D1::ColorF::YellowGreen			, 1.0f));
	}

	void AddBrush(ID2D1HwndRenderTarget	*pd2dRenderTarget, const std::string& name, D2D1::ColorF color)
	{
		ID2D1SolidColorBrush *brush;
		pd2dRenderTarget->CreateSolidColorBrush(color, &brush);
		myBrushMap.insert(std::make_pair(name, brush));
	}

	void AddBrush(ID2D1HwndRenderTarget	*pd2dRenderTarget, D2D1::ColorF color)
	{
		ID2D1SolidColorBrush *brush;
		pd2dRenderTarget->CreateSolidColorBrush(color, &brush);
		vBrush.push_back(brush);
	}

};

class MyFont : public CSingleTonBase<MyFont>
{
	std::vector<IDWriteTextFormat*> m_vTextFormat;
	IDWriteFactory*					m_pdwFactory;

public:

	void Load(IDWriteFactory *pdwFactory)
	{
		m_pdwFactory = pdwFactory;
		CreatFont(m_pdwFactory, TEXT("a¿¾³¯¸ñ¿åÅÁB"), 25, DWRITE_FONT_WEIGHT_BOLD);
		CreatFont(m_pdwFactory, TEXT("³ª´®¹Ù¸¥°íµñ"), 25, DWRITE_FONT_WEIGHT_BOLD);

	}


	void CreatFont
	(
		IDWriteFactory* pdwFactory
		, const WCHAR* fontFaimly
		, FLOAT fontSize = 25
		, DWRITE_FONT_WEIGHT fontWeight = DWRITE_FONT_WEIGHT_REGULAR
		, DWRITE_FONT_STYLE fontStyle = DWRITE_FONT_STYLE_NORMAL
		, DWRITE_FONT_STRETCH fontStretch = DWRITE_FONT_STRETCH_NORMAL
		, const WCHAR* localeName = TEXT("ko-kr")
	)
	{
		IDWriteTextFormat* format;
		pdwFactory->CreateTextFormat(fontFaimly, NULL, fontWeight, fontStyle, fontStretch, fontSize, localeName, &format);
		m_vTextFormat.push_back(format);
		//gvTextFormat.push_back(textFormat);
	}

	bool Release() override
	{
		for(auto& format : m_vTextFormat)
		{
			format->Release();
			format = nullptr;
		}
		m_vTextFormat.clear();

		return true;
	}

	IDWriteTextFormat* GetFont(const FONT_FORMAT& font) { return m_vTextFormat[static_cast<int>(font)]; }


};

/*
AliceBlue
AntiqueWhite
Aqua
Aquamarine
Azure
Beige
Bisque
Black
BlanchedAlmond
Blue
BlueViolet
Brown
BurlyWood
CadetBlue
Chartreuse
Chocolate
Coral
CornflowerBlue
Cornsilk
Crimson
Cyan
DarkBlue
DarkCyan
DarkGoldenrod
DarkGray
DarkGreen
DarkKhaki
DarkMagenta
DarkOliveGreen
DarkOrange
DarkOrchid
DarkRed
DarkSalmon
DarkSeaGreen
DarkSlateBlue
DarkSlateGray
DarkTurquoise
DarkViolet
DeepPink
DeepSkyBlue
DimGray
DodgerBlue
Firebrick
FloralWhite
ForestGreen
Fuchsia
Gainsboro
GhostWhite
Gold
Goldenrod
Gray
Green
GreenYellow
Honeydew
HotPink
IndianRed
Indigo
Ivory
Khaki
Lavender
LavenderBlush
LawnGreen
LemonChiffon
LightBlue
LightCoral
LightCyan
LightGoldenrodYellow
LightGreen
LightGray
LightPink
LightSalmon
LightSeaGreen
LightSkyBlue
LightSlateGray
LightSteelBlue
LightYellow
Lime
LimeGreen
Linen
Magenta
Maroon
MediumAquamarine
MediumBlue
MediumOrchid
MediumPurple
MediumSeaGreen
MediumSlateBlue
MediumSpringGreen
MediumTurquoise
MediumVioletRed
MidnightBlue
MintCream
MistyRose
Moccasin
NavajoWhite
Navy
OldLace
Olive
OliveDrab
Orange
OrangeRed
Orchid
PaleGoldenrod
PaleGreen
PaleTurquoise
PaleVioletRed
PapayaWhip
PeachPuff
Peru
Pink
Plum
PowderBlue
Purple
Red
RosyBrown
RoyalBlue
SaddleBrown
Salmon
SandyBrown
SeaGreen
SeaShell
Sienna
Silver
SkyBlue
SlateBlue
SlateGray
Snow
SpringGreen
SteelBlue
Tan
Teal
Thistle
Tomato
Turquoise
Violet
Wheat
White
WhiteSmoke
Yellow
YellowGreen
*/