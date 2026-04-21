#pragma once

#include"pch.h"

#ifdef TONKATSU_MSVC
	#ifdef TONKATSU_LIB
		#define TONKATSU_API __declspec(dllexport)
	#else
		#define TONKATSU_API __declspec(dllimport)
	#endif
#else
	#define TONKATSU_API
#endif

#ifdef TONKATSU_DEBUG==2
	#define TONKATSU_LOG(text) std::cout<<text<<std::endl;
	#define TONKATSU_ERROR(text) std::cout<<text<<std::endl;
#elif TONKATSU_DEBUG==1
	#define TONKATSU_LOG(text)
	#define TONKATSU_ERROR(text) std::cout<<text<<std::endl;
#else
	#define TONKATSU_LOG(text)
	#define TONKATSU_ERROR(text)
#endif