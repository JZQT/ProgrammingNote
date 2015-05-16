# 元组

## 概述

元组(tuple)是Python的一种内置类型，它与Python另外一种内置类型列表(list)十分相似，但是元组是**不可变**类型，而列表是**可变**类型。

## 示例

* 创建元组

    创建一个元组，可以通过使用`()`符号的方式
    ```python
    >>> score = ('jzqt', 60)
    >>> score
    ('jzqt', 60)
    ```
    **注意**：创建单个元素的元组需要在`()`内加`,`，如果不加的话会被认为是小括号运算
    ```python
    >>> name = ('jzqt')     # 创建了一个字符串而不是元组
    >>> name
    jzqt
    >>> name = ('jzqt',)    # 创建了一个元组
    >>> name
    ('jzqt',)
    >>> name = ()           # 创建了一个空元组
    ```

    也可以通过`tuple()`函数将列表等可迭代类型转换成元组
    ```python
    >>> tuple([1, 'jzqt', 2])
    (1, 'jzqt', 2')
    >>> tuple('jzqt')
    ('j', 'z', 'q', 't')
    ```

* 获取元组信息

    元组和列表一样通过索引取值，索引依旧从0开始
    ```python
    >>> score = ('jzqt', 60)
    >>> score[1]
    60
    >>> score[0]
    'jzqt'
    ```

    通过`len()`函数来获取元组的元素个数
    ```python
    >>> len(('jzqt', 60))
    2
    ```

    元组是不可表类型，因此元组自带的方法都是获取元组信息的

    |方法                           |功能                                                                                   |
    |:------------------------------|:------------------------------------------------------|
    |`count(value)`                 |返回`value`在元组中出现的次数                          |
    |`index(value, [start, [stop]])`|返回索引范围为`[start:stop]`的第一个值为`value`的索引  |

    示例：
    1. `count(value)`

        ```python
        >>> score = ('jzqt', 60, 60)
        >>> score.count(60)
        2
        ```

    2. `index(value, [start, [stop]])`

        ```python
        >>> score = ('jzqt', 60, 60)
        >>> score.index(60)
        1
        >>> score.index(60, 2)
        2
        ```

* 操作元组

    **元组是不可变类型**，因此**元组一旦确定后便无法添加或删除元素，也无法修改元组内的元素，除非是可变元素**
    ```python
    >>> score = ('jzqt', 60)
    >>> score[1] = 100          # 改变元组中的不可变元素会抛出异常
    Traceback (most recent call last):
      File "<stdin>", line 1, in <module>
    TypeError: 'tuple' object does not support item assignment
    >>> score = ('jzqt', 60, ['jzqt'])
    >>> score[2].append(60)
    >>> score
    ('jzqt', 60, ['jzqt', 60])
    ```
