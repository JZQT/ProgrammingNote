# 字典

## 概述

字典(dict)是Python的一种内置类型，它相当于**哈希表**这样的数据结构，使我们可以根据字典的`key`来获取对应的`value`，并且查找速度十分快。

**注意**：字典里面的`key-value`是无序的。

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
