#include "clientmodule.h"
#include "gameserver/game.h"

//---------------------------------------------------------------------------

class NetCallback : public IEngineNetCallback
{
public:
	virtual ~NetCallback() {}

	virtual void OnAccept(Port listen_port, NetID netid, IP ip, Port port)
	{
		std::cout << __FUNCTION__ << std::endl;
	}

	virtual void OnRecv(NetID netid, const char *data, int length)
	{
		std::cout << __FUNCTION__ << " " << data << std::endl;
	}

	virtual void OnDisconnect(NetID netid)
	{
		std::cout << __FUNCTION__ << std::endl;
	}

	virtual void OnConnect(bool result, int handle, NetID netid, IP ip, Port port)
	{
		std::cout << __FUNCTION__ << std::endl;
	}
};

//---------------------------------------------------------------------------

int ClientModule::Init()
{
	std::cout << m_name << " " << __FUNCTION__ << std::endl;
	return IModule::Succeed;
}

int ClientModule::Start()
{
	std::cout << m_name << " " << __FUNCTION__ << std::endl;

	DEPEND_ON_START(NETWORK_MODULE);
	m_network = dynamic_cast<INetworkModule*>(Interface()->QueryModule(NETWORK_MODULE));
	
	static NetCallback net_callback;
	m_network->RegisterCallback(&net_callback);

	// 连接
	if (!m_network->Connect("127.0.0.1", ECHO_SERVER_PORT, &m_server_netid))
	{
		std::cout << "Connect fail" << std::endl;
		auto game = (Game*)Interface();
		game->Stop();
		return IModule::Fail;
	}

	return IModule::Succeed;
}

int ClientModule::Update()
{
	// 每隔一秒，发送一次hello
	static time_t next_send_timestamp = 0;
	time_t now = time(NULL);

	if (now >= next_send_timestamp)
	{
		next_send_timestamp = now + 1;
		static const char msg[] = "hello";
		m_network->Send(m_server_netid, msg, sizeof(msg));
	}

	return IModule::Pending;
}

int ClientModule::Stop()
{
	std::cout << m_name << " " << __FUNCTION__ << std::endl;
	return IModule::Succeed;
}

int ClientModule::Release()
{
	std::cout << m_name << " " << __FUNCTION__ << std::endl;
	return IModule::Succeed;
}
