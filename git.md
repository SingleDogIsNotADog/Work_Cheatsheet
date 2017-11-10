**创建SSH KEY**

```shell
$ ssh-keygen -t rsa -C "youremail@example.com"
```
在GitHub账号里创建一个SSH key，将`~/.ssh/id_rsa.pub`中的内容加入其中。

**创建版本库**

STEP1: 在Github中创建一个空的远程仓库

STEP2: 克隆一份到本地：

```shell
$ git clone git@github.com:githubname/repos.git
```

**提交版本**

```
$ git add *
$ git commit -m "commit log"
$ git push origin master
```

**拉取版本**

```
$ git pull origin master
```

**请求帮助**

```
$ git help
$ git help add
```
