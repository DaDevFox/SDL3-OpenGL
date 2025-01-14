#include <GL/glew.h>
#include <algorithm>
#include <map>
#include "log.h"

// Breakpoints that should ALWAYS trigger (EVEN IN RELEASE BUILDS) [x86]!
#ifdef _MSC_VER
#define eTB_CriticalBreakPoint() \
    if (IsDebuggerPresent())     \
        __debugbreak();
#else
#define eTB_CriticalBreakPoint() asm(" int $3");
#endif

const char* debugGlSourceToStr(GLenum source)
{
	static std::map<int, const char*> sources = {
			{ GL_DEBUG_SOURCE_API,             "API" },
			{ GL_DEBUG_SOURCE_WINDOW_SYSTEM,   "Window System" },
			{ GL_DEBUG_SOURCE_SHADER_COMPILER, "Shader Compiler" },
			{ GL_DEBUG_SOURCE_THIRD_PARTY,     "Third Party" },
			{ GL_DEBUG_SOURCE_APPLICATION,     "Application User" },
			{ GL_DEBUG_SOURCE_OTHER,           "Other" },
	};
	return sources.at(static_cast<int>(source));
}

const char* debugGlTypeToStr(GLenum type)
{
	static std::map<int, const char*> types = {
			{ GL_DEBUG_TYPE_ERROR,               "Error" },
			{ GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR, "Deprecated Behaviour" },
			{ GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR,  "Undefined Behaviour" },
			{ GL_DEBUG_TYPE_PORTABILITY,         "Portability" },
			{ GL_DEBUG_TYPE_PERFORMANCE,         "Performance" },
			{ GL_DEBUG_TYPE_MARKER,              "Marker" },
			{ GL_DEBUG_TYPE_PUSH_GROUP,          "Debug Push group" },
			{ GL_DEBUG_TYPE_POP_GROUP,           "Debug Pop Group" },
			{ GL_DEBUG_TYPE_OTHER,               "Other" }
	};
	return types.at(static_cast<int>(type));
}

const char* debugGlSeverityToStr(GLenum severity)
{
	static std::map<int, const char*> severities = {
			{ GL_DEBUG_SEVERITY_HIGH,         "High" },
			{ GL_DEBUG_SEVERITY_MEDIUM,       "Medium" },
			{ GL_DEBUG_SEVERITY_LOW,          "Low" },
			{ GL_DEBUG_SEVERITY_NOTIFICATION, "Notification" }
	};

	return severities.at(static_cast<int>(severity));
}

void debugGlErrorCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	GLvoid* userParam)
{
	std::string glLog(" --- OpenGL -------------------");
	glLog.append("\n                                ");
	glLog.append("message: ");
	glLog.append(message);
	glLog.append("\n                                ");
	glLog.append("type: ");
	glLog.append(debugGlTypeToStr(type));
	glLog.append("\n                                ");
	glLog.append("id: ");
	glLog.append(std::to_string(id));
	glLog.append("\n                                ");
	glLog.append("severity: ");
	glLog.append(debugGlSeverityToStr(severity));

	if (type == GL_DEBUG_TYPE_ERROR)
	{
		LOG(Error) << glLog;
	}
	else if (type == GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR || type == GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
		|| type == GL_DEBUG_TYPE_PORTABILITY || type == GL_DEBUG_TYPE_PERFORMANCE)
	{
		LOG(Warning) << glLog;
	}
	else
	{
		LOG(Debug) << glLog;
	}
}
