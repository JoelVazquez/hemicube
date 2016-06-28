#include "Game.h"

const int Height = 720;
const int Width = 1280;
const char *Name = "yo que se...";
GLFWwindow* windows = NULL;
Game* game;

void displayCallback()
{
	//draw
	glfwSwapInterval(1);
	glfwSwapBuffers(windows);
}


void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{

		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	else 

		game->handleKey(key, action);

}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	glfwGetCursorPos(window, &xpos, &ypos);
	game->handleCursorPos(xpos, ypos);
	glfwSetCursorPos(window, Width / 2, Height / 2);
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
	// Window and OpenGL context
	windows = glfwCreateWindow(Width, Height, Name, NULL/*glfwGetPrimaryMonitor()*/, NULL);
	if (windows == NULL){
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(windows);
	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
	}


	// Capture the escape key being pressed below
	glfwSetInputMode(windows, GLFW_STICKY_KEYS, GL_TRUE);
	glfwSetInputMode(windows, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(windows, Width / 2, Height / 2);
	// Callback
	glfwSetCursorPosCallback(windows, cursor_position_callback);
	glfwSetKeyCallback(windows, KeyboardCallback);

}

int main(int argc, char const *argv[])
{
	init();
	game = new Game();
	glfwSetTime(0);
	double previous = glfwGetTime();
	double lag = 0.0;
	do
	{
		//Process input
		double current = glfwGetTime();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;
		game->update(lag);
		game->render(elapsed);
		glfwPollEvents();
		// Swap buffers
		glfwSwapBuffers(windows);
	} while (!glfwWindowShouldClose(windows));
	glfwTerminate();
	return 0;
}

