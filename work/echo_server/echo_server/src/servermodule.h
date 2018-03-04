#pragma once

#ifndef SERVER_MODULE_H
#define SERVER_MODULE_H

#include "imodule.h"
#include "servercommon.h"

static constexpr char SERVER_MODULE[] = "ServerModule";

class INetworkModule;

class ServerModule : public IModule
{
public:
	ServerModule() : ServerModule(SERVER_MODULE) {}
	ServerModule(const std::string &name) : m_name(name) {}

	virtual int Init();
	virtual int Start();
	virtual int Update();
	virtual int Stop();
	virtual int Release();
	virtual void Free() { delete this; }

protected:
	virtual ~ServerModule() {}
private:
	std::string m_name;
	INetworkModule *m_network = nullptr;
};

#endif