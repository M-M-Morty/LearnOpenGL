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
	/*ʹ��glfwWindowHint����������GLFW,
	��һ����������ѡ������ƣ����ǿ��ԴӺܶ���GLFW_��ͷ�ĺ궨����ѡ��,
	�ڶ�����������һ�����ͣ������������ѡ���ֵ��*/


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
	}//GLAD����������OpenGL�ĺ���ָ��ģ������ڵ����κ�OpenGL�ĺ���֮ǰ������Ҫ��ʼ��GLAD

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);//OpenGL��Ⱦ���ڵĳߴ��С

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	//���û��ı䴰�ڵĴ�С��ʱ���ӿ�ҲӦ�ñ�����

	while (!glfwWindowShouldClose(window)) {
		processInput(window);//����ض��ļ��Ƿ񱻰��£�����ÿһ֡��������

		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);//״̬���ú���
		glClear(GL_COLOR_BUFFER_BIT);//״̬���ú�Ӧ�ú���

		glfwPollEvents();//glfwPollEvents���������û�д���ʲô�¼�
		glfwSwapBuffers(window);//glfwSwapBuffers�����ύ����ɫ����
	}
	glfwTerminate();


	return 0;
}




