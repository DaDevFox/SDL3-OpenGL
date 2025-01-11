#include "resource_manager.h"
#include "log.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>

// Instantiate static variables
std::map<std::string, Texture2D> ResourceManager::textures;
std::map<std::string, Shader> ResourceManager::shaders;

Shader ResourceManager::loadShader(const std::string& vShaderFile, const std::string& fShaderFile,
	const std::string& gShaderFile, const std::string& name)
{
	shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
	return shaders[name];
}

Shader ResourceManager::getShader(const std::string& name)
{
	return shaders[name];
}

Texture2D ResourceManager::loadTexture(const std::string& file, const std::string& name)
{
	textures[name] = loadTextureFromFile(file);
	return textures[name];
}

Texture2D ResourceManager::getTexture(const std::string& name)
{
	return textures[name];
}

void ResourceManager::clear()
{
	// (Properly) delete all shaders
	for (const auto& iter : shaders)
		glDeleteProgram(iter.second.id);
	// (Properly) delete all textures
	for (const auto& iter : textures)
		glDeleteTextures(1, &iter.second.id);
}

Shader ResourceManager::loadShaderFromFile(const std::string& vShaderFile, const std::string& fShaderFile,
	const std::string& gShaderFile)
{
	// 1. Retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmentCode;
	std::string geometryCode;
	try
	{
		// Open files
		std::ifstream vertexShaderFile(vShaderFile);
		std::ifstream fragmentShaderFile(fShaderFile);
		std::stringstream vShaderStream, fShaderStream;
		if (vertexShaderFile.fail())
			throw std::runtime_error("File " + vShaderFile + " could not be opened to read as vertex shader source");
		if (fragmentShaderFile.fail())
			throw std::runtime_error("File " + fShaderFile + " could not be opened to read as fragment shader source");

		// Read file's buffer contents into streams
		vShaderStream << vertexShaderFile.rdbuf();
		fShaderStream << fragmentShaderFile.rdbuf();
		// close file handlers
		vertexShaderFile.close();
		fragmentShaderFile.close();
		// Convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
		// If geometry shader path is present, also load a geometry shader
		if (!gShaderFile.empty())
		{
			std::ifstream geometryShaderFile(gShaderFile);
			std::stringstream gShaderStream;
			gShaderStream << geometryShaderFile.rdbuf();
			geometryShaderFile.close();
			geometryCode = gShaderStream.str();
		}
	}
	catch (std::exception e)
	{
		std::ostringstream loadError;
		std::string geomShaderFile;
		if (!gShaderFile.empty())
			geomShaderFile = gShaderFile;

		loadError << "ERROR::SHADER: Failed to read shader files " << vShaderFile << " " << fShaderFile << " "
			<< geomShaderFile << "\n"
			<< "\n -- --------------------------------------------------- -- "
			<< std::endl;
		LOG(Error) << loadError.str();
	}
	const GLchar* vShaderCode = vertexCode.c_str();
	const GLchar* fShaderCode = fragmentCode.c_str();
	const GLchar* gShaderCode = geometryCode.c_str();
	// 2. Now create shader object from source code
	Shader shader{};
	shader.compile(vShaderCode, fShaderCode, !gShaderFile.empty() ? gShaderCode : nullptr);
	return shader;
}

Texture2D ResourceManager::loadTextureFromFile(const std::string& file)
{
	// Create Texture object
	Texture2D texture;
	texture.load(file);

	// Now generate texture
	texture.generate();
	// And finally return texture
	return texture;
}