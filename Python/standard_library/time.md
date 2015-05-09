# time模块

## 概述

Python标准库的time模块提供了各种操作时间的东西。

## 类

* `struct_time(builtins.tuple)`

    `struct_time`类是一个由元组继承而来的表示时间值的类。

    它有以下成员

    |索引   |属性       |备注                                   |
    |:------|:----------|:--------------------------------------|
    |0      |`tm_year`  |年份，比如：1993                       |
    |1      |`tm_mon`   |月份，范围是[1, 12]                    |
    |2      |`tm_mday`  |本月的第几日，范围是[1, 31]            |
    |3      |`tm_hour`  |小时，范围是[0, 23]                    |
    |4      |`tm_min`   |分钟，范围是[0, 59]                    |
    |5      |`tm_sec`   |秒钟，范围是[0, 61]                    |
    |6      |`tm_wday`  |星期几，范围是[0, 6]，其中 0 表示星期一|
    |7      |`tm_yday`  |这一年的第几天，范围是[1, 366]         |
    |8      |`tm_isdst` |1 代表夏令时，0 代表不是， -1 表示未知 |


## 函数

* `time()`

    `time()`函数返回从**新纪元**到**调用这个函数**的以**秒**为单位的**浮点数**类型的**真实时间**值。
    这个新纪元是系统定义的，在Unix上，它是1970年1月1日。

    example:
    ```python
    import time
    print(time.time())
    ```

* `sleep(seconds)`
    `sleep()`函数的功能是**延迟执行**以**秒**为单位给定**浮点数**类型参数值的**真实时间**。

    example:
    ```python
    import time
    print("JZQT")
    time.sleep(1)   // 调用这个函数后下一个代码会延迟一秒运行
    print("JZQT")
    ```

* `clock()`

    `clock()`函数返回从**程序开始运行**到**调用这个函数**之间以**秒**为单位的**浮点数**类型的**CPU时间**值。
    注意是**CPU时间**，也就是CPU耗费在这个程序上的时间。
    使用`sleep()`函数延迟的时间以及**IO等待**的时间是没有花费在CPU上的。

    example:
    ```python
    import time
    print(time.clock())
    time.sleep(1)
    input()
    print(time.clock()) // 这次输出的时间与上次输出的时间几乎没有差别
    ```

