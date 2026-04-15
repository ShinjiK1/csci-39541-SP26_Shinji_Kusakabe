#include"pch.h"

#include"RendererOpenGL.h"
#include"glad/glad.h"

#include"Window.h"

namespace Hat
{
	RendererOpenGL::RendererOpenGL()
	{
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
	}

	void RendererOpenGL::Draw(Picture& pic, int xCoord, int yCoord, Shader& shader)
	{
		float data[] = {
			xCoord, yCoord, 0.0f, 0.0f,	//Bottom Left
			xCoord, yCoord + pic.GetDimensions().height, 0.0f, 1.0f,	//Top Left
			xCoord + pic.GetDimensions().width, yCoord + pic.GetDimensions().height, 1.0f, 1.0f,	//Top Right
			xCoord + pic.GetDimensions().width, yCoord, 1.0f, 0.0f,	//Bottom Right
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


		pic.Bind();
		shader.Bind();
		shader.SupplyIntUniform("screenRes", { Window::Get()->GetSize().width,Window::Get()->GetSize().height });
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


		glDeleteBuffers(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}

	void RendererOpenGL::ScreenClear()
	{
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}