# IMsoftware

## 过程中出现的问题/解决方法
1. 刚开始创建了网络通信类和一些要使用到的界面类，在主函数先创建网络通信类，然后在网络通信类中定义界面类的对象组合。
A：这样虽然封装了类，但是类之间耦合度很高。所以改成了创建线程类（继承QThread类），使用线程类在后台做网络通信连接并实现虚函数run()，将线程类的对象实例写在main函数中，在main函数中连接主线程和工作线程的信号与槽
2. 工作线程要记得调用 start()函数 开启（调用start函数之后会自动调用run()函数）
3. 在run()函数最后要加上exec()，来开启事件循环
4. 在QThread内将QTcpSocket对象信号（connected、error、stateChangeed）与槽函数连接报数据类型未注册
>错误描述：QObject：：connect: Cannot queue arguments of type 'QAbstractSocket::SocketError' (Make sure ‘QAbstractSocket::SocketError' is registered using qRegisterMetaType(). )

A：因为connect函数的第五个参数默认是Qt::AutoConnection，该参数的意思是，如果信号的接收者的发送者位于同一个线程，则使用直接连接（Qt::DirectConnection），否则树用排队连接（Qt::QueuedConnection），连接的类型在信号发射时决定。因为错误描述中说`不能为QAbstractSocket::SocketError”类型的参数排队`，所以方法1：可以把第五个参数改为直接连接；方法2，用qRegisterMetaType()注册QAbstractSocket::SocketError   (未实现)

5. QTcpSocket对象的创建和使用要在同一个线程中，否则报错

6. 调用connectToHost建立连接后调用write发送数据失败
A：在信号stateChangeed的槽函数内判断当前QTcpSocket对象连接状态state()，如果是QAbstractSocket::ConnectedState则调用write()函数进行数据发送；

7. 服务端没开启和网线没连接错误不一样
A：服务端没开启错误为：QTcpSocket Connection Refused，网线没连接错误为：Network operation timed out

8. 对QTcpSocket.socketDescriptor做keepalive配置，在连接成功前配置无效
A：改为在在connected信号槽函数内配置，然后在disconnected信号槽函数内修改连接标志，这样可以监测到对端异常断开的情况。

9. 
