#include "servermodule.h"
#include "inetworkmodule.h"

//---------------------------------------------------------------------------

class NetCallback : public IEngineNetCallback
{
public:
	NetCallback(INetworkModule *net_work) : m_net_work(net_work) {}
	virtual ~NetCallback() {}

	virtual void OnAccept(Port listen_port, NetID netid, IP ip, Port port)
	{
		std::cout << __FUNCTION__ << std::endl;
	}

	virtual void OnRecv(NetID netid, const char *data, int length)
	{
		std::cout << __FUNCTION__ << " " << data << std::endl;
		m_net_work->Send(netid, data, length);
	}

	virtual void OnDisconnect(NetID netid)
	{
		std::cout << __FUNCTION__ << std::endl;
	}

	virtual void OnConnect(bool result, int handle, NetID netid, IP ip, Port port)
	{
		std::cout << __FUNCTION__ << std::endl;
	}

private:
	INetworkModule *m_net_work;
};

//---------------------------------------------------------------------------

int ServerModule::Init()
{
	std::cout << m_name << " " << __FUNCTION__ << std::endl;
	return IModule::Succeed;
}

int ServerModule::Start()
{
	std::cout << m_name << " " << __FUNCTION__ << std::endl;

	DEPEND_ON_START(NETWORK_MODULE);
	m_network = dynamic_cast<INetworkModule*>(Interface()->QueryModule(NETWORK_MODULE));
	
	// ×¢²á»Øµ÷Æ÷
	static NetCallback net_callback(m_network);
	m_network->RegisterCallback(&net_callback);

	// ¿ªÆô¼àÌý
	m_network->Listen(SERVER_PORT, 64);

	return IModule::Succeed;
}

int ServerModule::Update()
{
	
	return IModule::Pending;
}

int ServerModule::Stop()
{
	std::cout << m_name << " " << __FUNCTION__ << std::endl;
	return IModule::Succeed;
}

int ServerModule::Release()
{
	std::cout << m_name << " " << __FUNCTION__ << std::endl;
	return IModule::Succeed;
}