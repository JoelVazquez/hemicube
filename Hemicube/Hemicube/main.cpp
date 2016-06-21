#include <GLFW/glfw3.h>
#include <iostream>

const int windowsHeight = 720;
const int windowsWidth = 1280;
const char *windowsName = "yo que se...";
GLFWwindow* windows = NULL;


void displayCallback()
{
	//draw
	glfwSwapInterval(1);
	glfwSwapBuffers(windows);
}

void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)

		glfwSetWindowShouldClose(window, GLFW_TRUE);

}





void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	glfwGetCursorPos(window, &xpos, &ypos);

	glfwSetCursorPos(window, windowsWidth / 2, windowsHeight / 2);
}

void reshapeCallback(int width, int height)
{

}


void init()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW\n" << std::endl;
		return;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Window and OpenGL context glfwGetPrimaryMonitor()
	windows = glfwCreateWindow(windowsWidth, windowsHeight, windowsName, NULL, NULL);
	if (windows == NULL){
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(windows);

	glfwSetInputMode(windows, GLFW_STICKY_KEYS, GL_TRUE);
	//glfwSetInputMode(windows, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(windows, windowsWidth / 2, windowsHeight / 2);
	// Callback
	glfwSetCursorPosCallback(windows, cursor_position_callback);
	glfwSetKeyCallback(windows, KeyboardCallback);

}

void run()
{
	double delta_time, delta_time_drwa, last, current;
	glfwSetTime(0);
	current = 0;
	last = glfwGetTime();
	delta_time_drwa = 0;

	do{

		current = glfwGetTime();
		delta_time = current - last;
		delta_time_drwa += delta_time;
		last = current;

		if (delta_time_drwa > 1 / 60)
		{

			delta_time_drwa = 0;
			displayCallback();
		}

		glfwPollEvents();

	} while (glfwGetKey(windows, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(windows) == 0);
	glfwTerminate();
}





int main(void)
{
	init();
	run();
	return 0;
}

