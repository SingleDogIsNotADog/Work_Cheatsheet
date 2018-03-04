# 所需工具

vs2015，服务端引擎库。

# 类关系

InterfaceMgr -> Game

IModule -> 子类实现

Game使用了一个容器，管理所有的IModule的运行状态、生命周期。

# 创建和初始化

Game执行流程：注册IModule -> Run

IModule执行流程：Init -> Start -> Update -> Stop -> Release

如果IModule的这些方法之一执行失败，那么就不再继续执行后续方法，除了Release，Release方法将在Game Stop的时候被执行。

如果函数返回IModule::Succeed，那么就准备执行下一个函数。

如果函数返回IMdoule::Pending，那么下一次循环继续执行此函数。

**生命周期**

当所有的IMudule的Init、Start、Update、Stop、Release都正确执行后，Run方法结束，当Game对象析构的时候，执行IModule::Free方法，让其自己释放。

或者进程收到了SIGINT信号，那么IModule的Init、Start、Update方法都不再被执行，而是执行其Stop方法、Release方法。

# 网络功能

NetworkModule提供了网络的功能，可以作为服务器监听客户端，可以发起连接，收发信息。

NetworkModule为每一个连接分配了一个NetID。

处理信息的功能是通过回调器（IEngineNetCallback）完成的，需要自己实现一个子类。

通过INetworkModule::RegisterCallback注册回调器。

INetworkModule不负责管理回调器的生命周期。

# 网络模块的相关方法

作为服务器，使用Listen方法开始监听，等待客户端的连接，当连接成功后，执行IEngineNetCallback::OnAccept方法。

当收到信息的时候，执行IEngineNetCallback::OnRecv方法。

当有一个连接断开的时候，执行IEngineNetCallback::OnDisconnect方法。

执行INetworkModule::Connet方法向另一个进程发起一个连接。

执行INetworkModule::Send方法给另一个进程发送信息。

执行INetworkModule::Disconnect方法断开一个连接。