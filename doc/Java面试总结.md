# Java面试经验总结

## 1. Java内存模型
1. Java内存模型定义程序中各个变量的访问规则。即：在JVM中将变量存入内存和将变量从内存取出的底层细节。
站在编程人员角度来看，JMM规定了不同线程如何以及何时能够看到其它线程写入共享变量的值，以及如何同步对共享变量访问。

2. 线程的特性
原子性,有序性,可见性  
其中`synchronized`关键字能保证以上三种特性, `volatile`关键字只能保证 有序性和可见性, 原子性需要靠额外的加锁实现.

4. synchronized底层实现原理
搞清楚`synchronized`底层实现原理之前, 需要先明白Java对象的组成, 一个Java对象实例由三部分组成: ①对象头②实例数据③对齐填充. 其中在**对象头**的mark word字段中存储了锁的状态(无锁,偏向锁,轻量级锁,重量级锁). 每一个锁都对应一个monitor对象

5. Error和Exception区别及联系，可检查异常和不可检查异常
**答**：首先`Error`和`Exception`都是`Throwable`的子类，`Error`通常是JVM出现的错误，例如：OutofMemoryError, StackOverFlowError, ClassNotDefError等，Error错误级别比较严重，出现之后java程序一般就退出了，这些错误是不受检查异常，非代码性错误，因此应用程序也不应该去处理这些错误。
`Exception`是程序本身可以处理的异常，其又分为运行时异常和编译时异常。
