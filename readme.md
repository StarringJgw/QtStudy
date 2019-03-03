## QT

### 简介

跨平台 GUI库

KDE Adobe...  ~~Battle.net~~

不同版本有较大差异

QtWidgets(C++) QtQuick(QML Js)

### 特性

#### 对象模型

![image-20190303171948226](/Users/jgw/Library/Application Support/typora-user-images/image-20190303171948226.png)

##### 对象树：（以QObject为例）

​	（堆／栈对象&影响（QDialog例））

​	实现：通过维护对象的parent&children列表来维护关系，通过对象之间父类（抽象类）与子类继承方法

​	作用：！保证删除堆或栈对象时过程的完整正确，比如删除父元素时删除所有子元素

#### 信号与槽（观察者模式）

用户操作--发出信号（抽象函数）--回调被连接的槽函数

QObject::connect(&button, &QPushButton::clicked, app &QApplication::quit);

（注意重载问题：取的函数如果有多种形式，则需要使用提前确定好的函数指针）

##### 参数传递

​	信号函数的**参数**传递到槽函数的**参数**，后者参数数目不得多于前者

​	find children...(类比getElementsBy...)

##### QAction

​	抽象的”动作“，添加至菜单栏／工具栏...

​	用户的操作（点击菜单栏／快捷键...）->触发动作->触发槽函数

#### 布局：

##### ui绘制（类比DreamWeaver）

##### BoxLayout（水平／垂直／格子／层叠）

​	将子元素加入layout->将layout应用至父元素

​	应用／撤销时自动完善对象树

​	layout也可作为元素放入另一个layout中（嵌套）

#### 简单流程：

​	完成&封装号要实现的功能

​	创建MainWindow&各布局

​	创建联系，写各动作的逻辑

#### 其他：

​	自带的QtCreator属实不好用

​	需要查功能时 善用代码提示+documentation

​	（官方documentation关注最向上的抽象类）

​	细节很多，阻塞与否／不能用外联写法...	

​	具体库具体学习