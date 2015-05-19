# 字典

## 概述

字典(dict)是Python的一种内置类型，它相当于**哈希表**这样的数据结构，使我们可以通过字典的键(`key`)来查找对应的值(`value`)，并且查找速度十分快。

## 示例

* 创建字典

    创建字典类型的元素，可以通过使用`{}`符号，`key`和`value`按照`key: value`这样的格式写在里面并用`,`隔开
    ```python
    >>> dic = {}    # 创建空字典
    >>> dic
    {}
    >>> dic = {'Alice': 78, 'JZQT': 60} # 创建一个非空字典
    >>> dic
    {'JZQT': 60, 'Alice': 78}
    ```

    或者，也可以使用`dict`来初始化字典
    ```python
    >>> dic = dict()  # 空字典
    >>> dic
    {}
    >>> dic = dict(Alice=78, JZQT=60)   # 使用关键字参数初始化字典
    >>> dic
    {'JZQT': 60, 'Alice': 78}
    >>> dic = dict([('Alice', 78), ('JZQT', 60)])   # 用可迭代对象初始化字典
    {'JZQT': 60, 'Alice': 78}
    ```

    **注意**：将可迭代对象转换成字典是通过这样的代码
    ```python
    d = {}
    for k, v in iterable:
        d[k] = v
    ```
    因此可迭代对象要类似这样的形式`[(k1, v1), (k2, v2), ...]`

* 操作字典

    字典的索引其实就是它的`key`，因此可以通过`[]`来根据`key`**获取**或**设置**对应的`value`
    ```python
    >>> dic = {'Alice': 89, 'JZQT': 60}
    >>> dic['Alice']
    89
    >>> dic['JZQT'] = 100
    >>> dic['JZQT']
    100
    >>> dic['Bob']
    Traceback (most recent call last):
      File "<stdin>", line 1, in <module>
    KeyError: 'Bob'
    ```
    上述例子可以看出使用`[]`来通过不存在的`key`获取`value`会抛出异常，如果使用字典自带的`get()`方法就可以避免这种情况

    也可以判断一个值是否是字典的`key`，使用`in`关键值
    ```python
    >>> dic = {'Alice': 89, 'JZQT': 60}
    >>> 'Alice' in dic
    True
    >>> 'Bob' in dic
    False
    ```

    给字典添加新的键值对可以直接使用`[]`来赋值
    ```python
    >>> dic = {'Alice': 89, 'JZQT': 60}
    >>> dic['Bob'] = 100
    >>> dic
    {'Alice': 89, 'JZQT': 60, 'Bob': 100}
    ```
    当然，添加新的键值对和改变已有键对应的值这两种行为看起来是一样的

    字典也是可迭代类型，使用`for`语句来迭代的话只能获取它的`key`，通过`key`获取`value`，不能直接获取`value`
    ```python
    >>> dic = {'Alice': 89, 'JZQT': 60}
    >>> for key in dic:
    ...     print(key, dic[key])
    ...
    Alice 89
    JZQT 60
    ```
    使用字典自带的方法`items()`或者`values()`可以直接获取字典的`value`


    上述操作字典的方式都未使用字典自带的方法，可完成的功能有限，而字典有许多自带的方法可实现许多高级操作，我们可以根据情况选择不同的方法

    |方法                               |功能                                                                                                               |
    |:----------------------------------|:------------------------------------------------------------------------------------------------------------------|
    |`clear()`                          |直接把字典所有键值对清空，即清空成空字典                                                                           |
    |`copy()`                           |返回字典的浅拷贝                                                                                                   |
    |`fromkeys(iterable, value=None, /)`|字典方法，构造并返回一个新字典，迭代对象`iterable`中的所有元素为`key`，`value`为参数`value`                        |
    |`get(k[, d])`                      |如果`k`是字典的`key`，返回对应的`value`，否则返回`d`，`d`默认为`None`                                              |
    |`items()`                          |返回一个类似集合的可迭代对象，包含字典的所有键值对                                                                 |
    |`keys()`                           |返回一个类似集合的可迭代对象，包含字典的所有键                                                                     |
    |`pop(k[, d])`                      |如果`k`是字典的`key`，那么返回对应的`value`并删除这个键值对，否则如果给了参数`d`则返回`d`，不然抛出异常`KeyError`  |
    |`popitem()`                        |以`(key, value)`形式返回并删除一个键值对，如果字典为空则抛出`KeyError`异常                                         |
    |`setdefault(k[, d])`               |调用方法`get(k, d)`，并且如果不存在`k`这样的`key`那么还会添加`key`为`k`，`value`为`d`这样的键值对，默认`d`为`None` |
    |`update([E, ]**F)`                 |根据字典对象或其他可迭代对象`E`以及关键字参数`F`来更新字典，具体更新方法后面介绍                                   |
    |`values()`                         |返回一个类似集合的可迭代对象，包含字典的所有值                                                                     |

    下面给出每个方法的示例程序

    * `clear()`
        
        ```python
        >>> dic = {'JZQT': 60, 'Alice': 89}
        >>> dic.clear()
        >>> dic
        {}
        ```

    * `copy()`

        ```python
        >>> {'JZQT': 60, 'Alice': 89}.copy()
        {'Alice': 89, 'JZQT': 60}
        ```

    * `fromkeys(iterable, value=None, /)`，这是字典的类方法，与具体的某个字典对象无关，都可以调用

        ```python
        >>> dict.fromkeys([1, 2, 3], 'JZQT')
        {1: 'JZQT', 2: 'JZQT', 3: 'JZQT'}
        ```

    * `get(k[, d])`

        ```python
        >>> dic = {'JZQT': 60}
        >>> dic.get('JZQT')
        60
        >>> dic.get('Alice', 89)
        89
        >>> None == dic.get('Bob')
        True
        ```

    * `items()`

        ```python
        >>> dic = {'JZQT': 60, 'Alice': 89}
        >>> for item in dic.items():
        ...     print(item)
        ...
        ('Alice', 89)
        ('JZQT', 60)
        ```

    * `keys()`

        ```python
        >>> dic = {'JZQT': 60, 'Alice': 89}
        >>> for k in dic.keys():
        ...     print(k)
        ...
        Alice
        JZQT
        ```

    * `pop(k[, d])`

        ```python
        >>> dic = {'JZQT': 60, 'Alice': 89}
        >>> dic.pop('JZQT')
        60
        >>> dic
        {'Alice': 89}
        >>> dic.pop('Bob', 'No the key!')
        'No the key!'
        ```
    * `popitem()`

        ```python
        >>> dic = {'JZQT': 60, 'Alice': 89}
        >>> dic.popitem()
        ('Alice', 89)
        >>> dic
        {'JZQT', 69}
        ```

    * `setdefault(k[, d])`

        ```python
        >>> dic = {'JZQT': 60}
        >>> dic.setdefault('Bob')
        >>> dic
        {'JZQT': 60, 'Bob': None}
        >>> dic.setdefault('JZQT', 100)
        60
        >>> dic
        {'JZQT': 60, 'Bob': None}
        ```

    * `update([E, ]**F)`

        如果给了参数`E`并且`E`有`keys()`方法，那么执行`for k in E: D[k] = E[k]`

        如果给了参数`E`但`E`没有`keys()`方法，那么执行`for k, v in E: D[k] = v`

        剩下的情况，执行`for k in F: D[k] = F[k]`

        ```python
        >>> dic = {'JZQT': 60, 'Alice': 89}
        >>> dic.update({'Bob': 100})
        >>> dic
        {'Alice': 89, 'JZQT': 60, 'Bob': 100}
        >>> dic.update([('hehe', 0)])
        >>> dic
        {'Alice': 89, 'JZQT': 60, 'Bob': 100, 'hehe': 0}
        >>> dic.update(JZQT=100)
        {'Alice': 89, 'JZQT': 100, 'Bob': 100, 'hehe': 0}
        ```

    * `values()`

        ```python
        >>> dic = {'JZQT': 60, 'Alice': 89}
        >>> for v in dic.values():
        ...     print(v)
        ...
        89
        60
        ```
