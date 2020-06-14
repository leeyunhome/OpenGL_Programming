//// LearnOpenGL_HelloWindow.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <iostream>
//
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//const char* vertexShaderSource = "#version 330 core\n"
//	"layout (location = 0) in vec3 aPos;\n"
//	"layout (location = 1) in vec3 aColor;\n"
//	"out vec3 ourColor;\n"
//	"out vec4 vertexColor;\n"
//	"void main()\n"
//	"{\n"
//	"	gl_Position = vec4(aPos, 1.0);\n"
//	"	vertexColor = vec4(0.5, 0.0, 0.0, 1.0);\n"
//	"	ourColor = aColor;\n"
//	"}\0";
//
//const char* fragmentShaderSource = "#version 330 core\n"
//	"out vec4 FragColor;\n"
//	"in vec4 vertexColor;\n"
//	"in vec3 ourColor;\n"
//	//"uniform vec4 ourColor;\n"
//	"void main()\n"
//	"{\n"
//	//"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//	//"	FragColor = vertexColor;\n"
//	//"	FragColor = ourColor;\n"
//	"	FragColor = vec4(ourColor, 1.0);\n"
//	"}\0";
//
//void processInput(GLFWwindow* window);
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	int nrAttributes;
//	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
//	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
//	unsigned int vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//
//	int success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	unsigned int fragmentShader;
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//
//	unsigned int shaderProgram;
//	shaderProgram = glCreateProgram();
//
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//	}
//
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	// set up vertex data (and buffer(s)) and configure vertex attributes
//	// ------------------------------------------------------------------
//	//float vertices[] = {
//	//	-0.5f, -0.5f, 0.0f,
//	//	 0.5f, -0.5f, 0.0f,
//	//	 0.0f,  0.5f, 0.0f
//	//};
//
//	// More attributes
//	float vertices[] = {
//		// positions         // colors
//		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
//		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
//		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
//	};
//
//	// Element Buffer Objects
//	//float vertices[] = {
//	//	 0.5f,  0.5f, 0.0f,  // top right
//	//	 0.5f, -0.5f, 0.0f,  // bottom right
//	//	-0.5f, -0.5f, 0.0f,  // bottom left
//	//	-0.5f,  0.5f, 0.0f   // top left 
//	//};
//	//unsigned int indices[] = {  // note that we start from 0!
//	//	0, 1, 3,   // first triangle
//	//	1, 2, 3    // second triangle
//	//};
//
//	unsigned int VBO;
//	glGenBuffers(1, &VBO);
//
//	unsigned int VAO;
//	glGenVertexArrays(1, &VAO);
//
//	// create the element buffer object
//	unsigned int EBO;
//	glGenBuffers(1, &EBO);
//
//	// ..:: Initialization code :: ..
//	// 1. bind Vertex Array Object
//	glBindVertexArray(VAO);
//	// 2. copy our vertices array in a  vertex buffer for OpenGL to use
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	// 3. copy our index array in a element buffer for OpenGL to use
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	// 4. then set the vertex attributes pointers
//	// position attribute
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	// color attribute
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	// ..:: Drawing code (in render loop) :: ..
//	// 4. draw the object
//	glUseProgram(shaderProgram);
//
//	while (!glfwWindowShouldClose(window))
//	{
//		// input
//		processInput(window);
//
//		// rendering commands here
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		// update the uniform color
//		//float timeValue = glfwGetTime();
//		////std::cout << timeValue << std::endl;
//		//float redValue = (sin(timeValue) / 2.0f) + 0.5f;
//		//int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//		//glUniform4f(vertexColorLocation, redValue, 0.0f, 0.0f, 1.0f);
//
//		// now render the triangle
//		glBindVertexArray(VAO);
//		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		//glBindVertexArray(0);
//
//
//		// check and call events and swap the buffers
//		glfwPollEvents();
//		glfwSwapBuffers(window);
//	}
//
//	glfwTerminate();
//	return 0;
//}
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}