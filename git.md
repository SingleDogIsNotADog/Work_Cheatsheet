**创建SSH KEY**

```shell
$ ssh-keygen -t rsa -C "youremail@example.com"
```

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
