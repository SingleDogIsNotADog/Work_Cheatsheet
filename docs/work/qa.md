# 各种奇怪的问题

### Q：怪物自动消失

A：可能是因为怪物配置了消失时间，见G-怪物.xls表的disappear_time字段。

### Q：副本被刷（可以无限进入）

A：一般是未能触发到副本的结束方法，导致未能成功结算。原因可能是判断是否结束的条件出了问题。比如在OnAllMonsterDie里面做判断，然而玩家自己可以召唤怪物，如果玩家提前退出副本，则触发不到OnAllMonsterDie了。

### Q：数据库中多了一条记录（初始化时提示：Init Duplicate）

A：可能由于数据库缓存丢失（RoleCacheManager），导致 DBCommand::Update 失败后继续 DBCommand::Save ，当没有缓存的时候，Save还会插入数据，因此会多出一条数据来。