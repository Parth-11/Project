#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include <GL\glew.h>

class Shader {
private:
	unsigned int shaderID, uniformProjection, uniformModel,uniformView;
	unsigned int uniformAmbientIntenstiy, uniformAmbientColour;
	unsigned int uniformDiffuseIntensity, uniformDirection;
public:
	Shader();
	~Shader();

	void CreateFromString(const std::string& vertexCode, const std::string& fragmentCode);

	void CreateFromFiles(const std::string vertexLocation, const std::string fragmentLocation);

	std::string ReadFile(const std::string fileLocation);

	unsigned int GetProjectionLocation() const;
	unsigned int GetModelLocation() const;
	unsigned int GetViewLocation() const;
	unsigned int GetAmbientIntensityLocation() const;
	unsigned int GetAmbientColourLocation() const;
	unsigned int GetDiffuseIntensityLocation() const;
	unsigned int GetDirectionLocation() const;

	void UseShader();
	void ClearShader();

private:
	void CompileShader(const std::string& vertexCode,const std::string& fragmentCode);
	void AddShader(const char* shaderCode, GLenum shaderType);
};