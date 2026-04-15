#include"pch.h"
#include"HatApplication.h"
#include"Window.h"

#include"glad/glad.h"

#include"stbi.h"

#include"Picture.h"
#include"Shader.h"
#include"Renderer.h"

namespace Hat
{
	void HatApplication::Update()
	{

	}

	void HatApplication::Initialize()
	{

	}

	void HatApplication::Shutdown()
	{

	}

	void HatApplication::Run()
	{
		Window::Init();
		Window::Get()->Create({600,400}, "FallGame");

		Renderer::Init();

		Initialize();

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);

		/*
		float data[] = {
			0.0f, 0.0f, 0.0f, 0.0f,	//Bottom Left
			0.0f, 100.0f, 0.0f, 1.0f,	//Top Left
			100.0f, 100.0f,	1.0f, 1.0f,	//Top Right
			100.0f, 0.0f, 1.0f, 0.0f,	//Bottom Right
		};

		unsigned int indices[]{
			0, 1, 2, // first triangle
			0, 2, 3 // second triangle
		};

		unsigned int VAO{ 0 };
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		unsigned int VBO{ 0 };
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);

		unsigned int EBO{ 0 };
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		*/

		// Shaders

		/*

		const char* vertexSource = R"(
			#version 330 core

			layout(location=0) in vec2 coords;
			layout(location=1) in vec2 tcoords;

			out vec2 texCoords;
			uniform ivec2 screenRes;

			void main() 
			{
				texCoords = tcoords;
				gl_position = vec4(coords.x * 2.0/screenRes.x - 1, coords.y * 2.0/screenRes.y - 1, 0, 1);
			}
		)";

		unsigned int vertexShader{ 0 };
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		int sourceSize{ sizeof(vertexSource) };
		printf("%s", vertexSource);
		glShaderSource(vertexShader, 1, &vertexSource, &sourceSize);
		glCompileShader(vertexShader);

		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			HAT_ERROR("ERROR::SHADER::VERTEX::COMPILATION:FAILED\n" << infoLog << std::endl);
		}

		const char* fragSource = R"(
			#version 330 core

			in vec2 texCoords;
			out vec4 FragColor;

			uniform sampler2D picture;

			void main()
			{
				FragColor = texture(picture, texCoords);
			}
		)";

		unsigned int fragShader{ 0 };
		fragShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragShader, 1, &fragSource, NULL);
		glCompileShader(fragShader);

		glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
			HAT_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION:FAILED\n" << infoLog << std::endl);
		}

		unsigned int shaderProgram;
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragShader);
		glLinkProgram(shaderProgram);
		// check for linking errors
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			HAT_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl);
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragShader);

		*/



		// Textures
		/*
		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* pdata = stbi_load("../Hat/Assets/Images/Character.png", &width, &height, &nrChannels, 0);
		if (pdata)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pdata);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			HAT_ERROR("Failed to load texture" << std::endl);
		}
		stbi_image_free(pdata);
		*/

		Picture pic{ "../Hat/Assets/Images/Character.png" };
		//Shader shader{"../Hat/Assets/Shaders/defaultVertexShader.glsl", "../Hat/Assets/Shaders/defaultFragShader.glsl"};


		while (true) {
			Renderer::Get()->ScreenClear();

			Update();

			//glUseProgram(shaderProgram);
			//glBindVertexArray(VAO);
			//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			Renderer::Get()->Draw(pic, 200, 200);

			Window::Get()->SwapBuffers();
			Window::Get()->PollEvents();
		}

		Shutdown();
	}

	HatApplication::~HatApplication()
	{

	}
}