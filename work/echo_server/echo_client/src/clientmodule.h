#pragma once

#ifndef SERVER_MODULE_H
#define SERVER_MODULE_H

#include "imodule.h"
#include "inetworkmodule.h"
#include "servercommon.h"

static constexpr char CLIENT_MODULE[] = "ClientModule";

class INetworkModule;

class ClientModule : public IModule
{
public:
	ClientModule() : ClientModule(CLIENT_MODULE) {}
	ClientModule(const std::string &name) : m_name(name) {}

	virtual int Init();
	virtual int Start();
	virtual int Update();
	virtual int Stop();
	virtual int Release();
	virtual void Free() { delete this; }

protected:
	virtual ~ClientModule() {}
private:
	std::string m_name;
	NetID m_server_netid = (NetID)-1;
	INetworkModule *m_network = nullptr;
};

#endif