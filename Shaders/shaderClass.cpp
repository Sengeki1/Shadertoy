#include "shaderClass.h"

std::string get_file_contents(const char* filename) {
	std::ifstream in(filename, std::ios::binary); // read file ifstream 
	if (in) { // if file 
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return contents;
	}
	throw (errno);
}

void Shader::hotReloadGLSL(const char* vertexFile, const char* fragmentFile) {
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	const char* vertexSource = vertexCode.c_str(); // explanation of c_str: https://stackoverflow.com/questions/60896478/string-to-const-char-conversion-using-c-str-or-tochararray
	const char* fragmentSource = fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); // GLuint is an unsigned integer (aka a positive integer) in a openGL way - reference value
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader); // compile it into machine code

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	// Check for compilation errors
	GLint compileStatus;
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus != GL_TRUE) {
		// Retrieve the error log
		GLint logLength;
		glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> log(logLength);
		glGetShaderInfoLog(fragmentShader, logLength, nullptr, log.data());

		// Print the error log
		std::cerr << "Shader compilation failed:\n" << log.data() << std::endl;

		// Cleanup and return 0 to indicate failure
		glDeleteShader(fragmentShader);
	}

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus != GL_TRUE) {
		// Retrieve the error log
		GLint logLength;
		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> log(logLength);
		glGetShaderInfoLog(vertexShader, logLength, nullptr, log.data());

		// Print the error log
		std::cerr << "Shader compilation failed:\n" << log.data() << std::endl;

		// Cleanup and return 0 to indicate failure
		glDeleteShader(vertexShader);
	}

	ID = glCreateProgram(); // to use both shaders we have to warp them up into a shader program

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

	glDeleteShader(vertexShader); // we delete both because the program is already using them so there is no need 
	glDeleteShader(fragmentShader);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile) {
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	const char* vertexSource = vertexCode.c_str(); // explanation of c_str: https://stackoverflow.com/questions/60896478/string-to-const-char-conversion-using-c-str-or-tochararray
	const char* fragmentSource = fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); // GLuint is an unsigned integer (aka a positive integer) in a openGL way - reference value
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader); // compile it into machine code

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	// Check for compilation errors
	GLint compileStatus;
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus != GL_TRUE) {
		// Retrieve the error log
		GLint logLength;
		glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> log(logLength);
		glGetShaderInfoLog(fragmentShader, logLength, nullptr, log.data());

		// Print the error log
		std::cerr << "Shader compilation failed:\n" << log.data() << std::endl;

		// Cleanup and return 0 to indicate failure
		glDeleteShader(fragmentShader);
	}

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus != GL_TRUE) {
		// Retrieve the error log
		GLint logLength;
		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> log(logLength);
		glGetShaderInfoLog(vertexShader, logLength, nullptr, log.data());

		// Print the error log
		std::cerr << "Shader compilation failed:\n" << log.data() << std::endl;

		// Cleanup and return 0 to indicate failure
		glDeleteShader(vertexShader);
	}

	ID = glCreateProgram(); // to use both shaders we have to warp them up into a shader program

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

	glDeleteShader(vertexShader); // we delete both because the program is already using them so there is no need 
	glDeleteShader(fragmentShader);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile, const char* tesControlFile, const char* tesEvalFile) {
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);
	std::string tesControlCode = get_file_contents(tesControlFile);
	std::string tesEvalCode = get_file_contents(tesEvalFile);

	const char* vertexSource = vertexCode.c_str(); // explanation of c_str: https://stackoverflow.com/questions/60896478/string-to-const-char-conversion-using-c-str-or-tochararray
	const char* fragmentSource = fragmentCode.c_str();
	const char* tesControlSource = tesControlCode.c_str();
	const char* tesEvalSource = tesEvalCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); // GLuint is an unsigned integer (aka a positive integer) in a openGL way - reference value
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader); // compile it into machine code

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	GLuint tesControlShader = glCreateShader(GL_TESS_CONTROL_SHADER);
	glShaderSource(tesControlShader, 1, &tesControlSource, NULL);
	glCompileShader(tesControlShader);

	GLuint tesEvalShader = glCreateShader(GL_TESS_EVALUATION_SHADER);
	glShaderSource(tesEvalShader, 1, &tesEvalSource, NULL);
	glCompileShader(tesEvalShader);

	// Check for compilation errors
	GLint compileStatus;
	glGetShaderiv(tesEvalShader, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus != GL_TRUE) {
		// Retrieve the error log
		GLint logLength;
		glGetShaderiv(tesEvalShader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> log(logLength);
		glGetShaderInfoLog(tesEvalShader, logLength, nullptr, log.data());

		// Print the error log
		std::cerr << "Shader compilation failed:\n" << log.data() << std::endl;

		// Cleanup and return 0 to indicate failure
		glDeleteShader(tesEvalShader);
	}

	ID = glCreateProgram(); // to use both shaders we have to warp them up into a shader program

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, tesControlShader);
	glAttachShader(ID, tesEvalShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

	glDeleteShader(vertexShader); // we delete both because the program is already using them so there is no need 
	glDeleteShader(tesControlShader);
	glDeleteShader(tesEvalShader);
	glDeleteShader(fragmentShader);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile, const char* tesControlFile, const char* tesEvalFile, const char* geometryFile) {
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);
	std::string tesControlCode = get_file_contents(tesControlFile);
	std::string tesEvalCode = get_file_contents(tesEvalFile);
	std::string geometryCode = get_file_contents(geometryFile);

	const char* vertexSource = vertexCode.c_str(); // explanation of c_str: https://stackoverflow.com/questions/60896478/string-to-const-char-conversion-using-c-str-or-tochararray
	const char* fragmentSource = fragmentCode.c_str();
	const char* tesControlSource = tesControlCode.c_str();
	const char* tesEvalSource = tesEvalCode.c_str();
	const char* geometrySource = geometryCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); // GLuint is an unsigned integer (aka a positive integer) in a openGL way - reference value
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader); // compile it into machine code

	GLuint tesControlShader = glCreateShader(GL_TESS_CONTROL_SHADER);
	glShaderSource(tesControlShader, 1, &tesControlSource, NULL);
	glCompileShader(tesControlShader);

	GLuint tesEvalShader = glCreateShader(GL_TESS_EVALUATION_SHADER);
	glShaderSource(tesEvalShader, 1, &tesEvalSource, NULL);
	glCompileShader(tesEvalShader);

	GLuint geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
	glShaderSource(geometryShader, 1, &geometrySource, NULL);
	glCompileShader(geometryShader);

	// Check for compilation errors
	GLint compileStatus;
	glGetShaderiv(geometryShader, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus != GL_TRUE) {
		// Retrieve the error log
		GLint logLength;
		glGetShaderiv(geometryShader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> log(logLength);
		glGetShaderInfoLog(geometryShader, logLength, nullptr, log.data());

		// Print the error log
		std::cerr << "Shader compilation failed:\n" << log.data() << std::endl;

		// Cleanup and return 0 to indicate failure
		glDeleteShader(geometryShader);
	}

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	ID = glCreateProgram(); // to use both shaders we have to warp them up into a shader program

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, tesControlShader);
	glAttachShader(ID, tesEvalShader);
	glAttachShader(ID, geometryShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

	glDeleteShader(vertexShader); // we delete both because the program is already using them so there is no need 
	glDeleteShader(tesControlShader);
	glDeleteShader(tesEvalShader);
	glDeleteShader(geometryShader);
	glDeleteShader(fragmentShader);
}

void Shader::Activate() {
	glUseProgram(ID);
}

void Shader::Delete() {
	glDeleteProgram(ID);
}