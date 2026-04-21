set(SOURCE_FILES
	TonkatsuApplication.h
	TonkatsuApplication.cpp
	TonkatsuUtility.h
	EntryPoint.h
	Include/Tonkatsu.h
	Window.h
	Window.cpp
	WindowImplementation.h
	ThirdParty/GLFW/WindowGLFW.h
	ThirdParty/GLFW/WindowGLFW.cpp
)

add_library(Tonkatsu SHARED ${Source_Files})

target_precompiled_headers(Tonkatsu PRIVATE pch.h)

if(MSVC)
	target_compile_definitions(Tonkatsu PUBlIC TONKATSU_MSVC)
endif()

target_compile_definitions(Tonkatsu
	PRIVATE
		TONKATSU_LIB
		TONKATSU_GLFW
	PUBLIC
		$<$<CONFIG:Debug>:TONKATSU_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:TONKATSU_DEBUG=1>
)

target_include_directories(Tonkatsu PUBLIC include)
target_include_directories(Tonkatsu PRIVATE ../Tonkatsu)

target_link_libraries(Tonkatsu glfw)