#pragma once

#ifdef HAT_MSVC
	#ifdef HAT_LIB
		#define HAT_API __declspec(dllexport)
	#else
		#define HAT_API __declspec(dllimport)
	#endif
#else
	#define HAT_API
#endif

#ifdef HAT_DEBUG==2
	#define HAT_LOG(text) std::cout<<text<<std::endl;
	#define HAT_ERROR(text) std::cout<<text<<std::endl;
#elif HAT_DEBUG==1
	#define HAT_LOG(text)
	#define HAT_ERROR(text) std::cout<<text<<std::endl;
#else
	#define HAT_LOG(text)
	#define HAT_ERROR(text)
#endif