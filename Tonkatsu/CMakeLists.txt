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
	Picture.h
	Picture.cpp
	PictureImplementation.h
	ThirdParty/OpenGL/PictureOpenGL.h
	ThirdParty/OpenGL/PictureOpenGL.cpp
	Shader.h
	Shader.cpp
	ShaderImplementation.h
	ThirdParty/OpenGL/ShaderOpenGL.h
	ThirdParty/OpenGL/ShaderOpenGL.cpp
	Renderer.h
	Renderer.cpp
	RendererImplementation.h
	ThirdParty/OpenGL/RendererOpenGL.h
	ThirdParty/OpenGL/RendererOpenGL.cpp
	KeyCodes.h
	TonkatsuEvents.h
	TonkatsuEvents.cpp
	Unit.h
	Unit.cpp
)

add_library(Tonkatsu SHARED ${Source_Files})

target_precompile_headers(Tonkatsu PRIVATE pch.h)

if(MSVC)
	target_compile_definitions(Tonkatsu PUBlIC TONKATSU_MSVC)
endif()

target_compile_definitions(Tonkatsu
	PRIVATE
		TONKATSU_LIB
		TONKATSU_OPENGL
	PUBLIC
		$<$<CONFIG:Debug>:TONKATSU_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:TONKATSU_DEBUG=1>
		TONKATSU_GLFW
)

target_include_directories(Tonkatsu PUBLIC include)
target_include_directories(Tonkatsu PRIVATE ../Tonkatsu)
target_include_directories(Tonkatsu PRIVATE ../glad/include)
target_include_directories(Tonkatsu PRIVATE ../stbi)

target_link_libraries(Tonkatsu glfw glad stbi)

file(COPY Assets Destination ${CMAKE_BINARY_DIR}/Tonkatsu)