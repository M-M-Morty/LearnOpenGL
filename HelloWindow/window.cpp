#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}


int main() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	/*使用glfwWindowHint函数来配置GLFW,
	第一个参数代表选项的名称，我们可以从很多以GLFW_开头的宏定义中选择,
	第二个参数接受一个整型，用来设置这个选项的值。*/


	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}//GLAD是用来管理OpenGL的函数指针的，所以在调用任何OpenGL的函数之前我们需要初始化GLAD

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);//OpenGL渲染窗口的尺寸大小

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	//当用户改变窗口的大小的时候，视口也应该被调整

	while (!glfwWindowShouldClose(window)) {
		processInput(window);//检测特定的键是否被按下，并在每一帧做出处理

		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);//状态设置函数
		glClear(GL_COLOR_BUFFER_BIT);//状态设置和应用函数

		glfwPollEvents();//glfwPollEvents函数检查有没有触发什么事件
		glfwSwapBuffers(window);//glfwSwapBuffers函数会交换颜色缓冲
	}
	glfwTerminate();


	return 0;
}




