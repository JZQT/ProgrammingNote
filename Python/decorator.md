# 装饰器

## 概述

装饰器是Python的一种高级语法。
我们对函数或者类进行装饰（加工）可以使用闭包和装饰器等多种方法，但是如果使用装饰器来做的话，语法简单且代码可读性高。

## 示例

### 无参数装饰器

比如要对一些函数进行装饰，使得调用函数前输出`start`，调用完毕后输出`end`，那么这个装饰器代码可以这么写

```python
def decorator(func):    # 定义这个装饰器函数
    def wrapper():
        print("start")
        func()
        print("end")
    return wrapper
```

接下来使用这个装饰器来装饰一个函数试试看

```python
@decorator              # 使用这个装饰器装饰fun函数
def fun():
    print("fun")

fun()       # 调用fun函数
```

使用`decorator`装饰器装饰`fun`函数需要在`fun`函数的定义处之前写上`@decorator`。
相当于执行了这么一个语句`fun = decorator(fun)`，这样的话新的`fun`就是以旧的`fun`作为`decorator`的参数的返回值了。
