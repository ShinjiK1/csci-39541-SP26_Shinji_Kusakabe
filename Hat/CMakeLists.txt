set(SOURCE_FILES
	HatApplication.h
	HatApplication.cpp
	HatUtility.h
	EntryPoint.h
	Include/Hat.h
	Window.h
	Window.cpp
	WindowImplementation.h
	ThirdParty/GLFW/WindowGLFW.h
	ThirdParty/GLFW/WindowGLFW.cpp
)

add_library(Hat SHARED ${Source_Files})

target_precompiled_headers(Hat PRIVATE pch.h)

if(MSVC)
	target_compile_definitions(Hat PUBlIC HAT_MSVC)
endif()

target_compile_definitions(Hat
	PRIVATE
		HAT_LIB
		HAT_GLFW
	PUBLIC
		$<$<CONFIG:Debug>:HAT_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:HAT_DEBUG=1>
)

target_include_directories(Hat PUBLIC include)
target_include_directories(Hat PRIVATE ../Hat)

target_link_libraries(Hat glfw)