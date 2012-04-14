#ifndef IScriptEngine_h
#define IScriptEngine_h

#include <string>
#include "ADM_editor/include/IEditor.h"

class IScriptEngine
{
public:
	enum Capabilities
	{
		None
	};

	enum EventType
	{
		Information,
		Warning,
		Error
	};

	enum RunMode
	{
		Normal
	};

	struct EngineEvent
	{
		IScriptEngine *engine;
		EventType eventType;
		const char *fileName;
		int lineNo;
		const char *message;
	};

	typedef void (eventHandlerFunc)(EngineEvent *event);

	virtual ~IScriptEngine() {}
	virtual Capabilities capabilities() = 0;
	virtual IEditor* editor() = 0;
	virtual void initialise(IEditor *videoBody) = 0;
	virtual std::string name() = 0;
	virtual void registerEventHandler(eventHandlerFunc *func) = 0;
	virtual bool runScript(std::string script, RunMode mode) = 0;
	virtual bool runScriptFile(std::string name, RunMode mode) = 0;
	virtual void unregisterEventHandler(eventHandlerFunc *func) = 0;
};

#endif