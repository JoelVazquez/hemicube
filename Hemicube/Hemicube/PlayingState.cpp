#include "PlayingState.h"


PlayingState::PlayingState(Game* pGame)
{
	this->m_pGame = pGame;
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);


	glGenVertexArrays(1, &m_VertexArrayID);
	glBindVertexArray(m_VertexArrayID);

	// Create and compile our GLSL program from the shaders
	m_ProgramID = LoadShaders("../TransformVertexShader.vertexshader", "../ColorFragmentShader.fragmentshader");

	// Get a handle for our "MVP" uniform
	m_MatrixID = glGetUniformLocation(m_ProgramID, "MVP");

	// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	glm::mat4 view = glm::lookAt(
		glm::vec3(4, 3, -3), // Camera is at (4,3,-3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
		);

	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 model = glm::mat4(1.0f);
	// Our ModelViewProjection : multiplication of our 3 matrices
	m_MVP = projection * view * model; // Remember, matrix multiplication is the other way around

	// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	// A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices


	glGenBuffers(1, &m_VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_VertexBufferData), g_VertexBufferData, GL_STATIC_DRAW);
	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
		);

	glGenBuffers(1, &m_ColorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_ColorBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_ColorBufferData), g_ColorBufferData, GL_STATIC_DRAW);
	// 2nd attribute buffer : colors
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(
		1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
		);
}


void PlayingState::Update()
{
}

void PlayingState::Render()
{
	// Use our shader
	glUseProgram(m_ProgramID);
	glUniformMatrix4fv(m_MatrixID, 1, GL_FALSE, &m_MVP[0][0]);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Draw the triangle !
	glBindVertexArray(m_VertexArrayID);
	glDrawArrays(GL_TRIANGLES, 0, 12 * 3); // 12*3 indices starting at 0 -> 12 triangles
}


PlayingState::~PlayingState()
{
}