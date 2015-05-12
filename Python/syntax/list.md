# 列表

## 概述

列表(list)是Python的一种内置类型，类似与C语言里面的数组(array)，但是Python的列表支持很多高级的操作比如**插入**，**添加**和**删除**等，或者说，把它比喻为**链表**这种数据结构更为恰当。

## 示例

* 创建列表

    假设我们需要创建一个列表，存储一些人的名字
    ```python
    name = ['Tony', 'Green', 'Alice', 'JZQT']
    ```

    如果需要创建一个空列表，有两种方式
    ```python
    emptylist = []      # 使用[]来创建空列表
    emptylist = list()  # 使用列表类来创建一个空列表
    ```

    由于Python是动态类型的语言，因此一个列表可以存储不同类型的元素，比如
    ```python
    mix = [1, 5.63, 'JZQT', [False, 3]]
    ```

    **注意**：列表里面的元素是有序的，所以`[1, 2]`和`[2, 1]`是两个不相等的列表。

* 获取列表信息

    列表是有**长度**的，我们可以使用`len()`函数获取列表的长度
    ```python
    >>> len(['Tony', 'Green', 'Alice', 'JZQT'])
    4
    >>> len([])
    0
    ```

    对于一个列表，我们要一一获得这个列表的元素并输出，可以这样做
    ```python
    >>> for i in ['Tony', 'Green', 'Alice', 'JZQT']:
    ...    print(i)
    ...
    Tony
    Green
    Alice
    JZQT
    ```
    因为列表是有序的，所以输出的结果是有序的。

    列表有**索引**（又称**下标**），我们可以按照索引来访问列表里面的元素，和C语言一样，索引是从0开始的
    ```python
    >>> name = ['Tony', 'Green', 'Alice', 'JZQT']
    >>> name[0]
    'Tony'
    >>> name[3]
    'JZQT'
    ```

    使用索引来遍历列表元素并输出索引及其元素值
    ```python
    >>> name = ['Tony', 'Green', 'Alice', 'JZQT']
    >>> for i in range(len(name)):
    ...    print(i, name[i])
    ...
    0 Tony
    1 Green
    2 Alice
    3 JZQT
    ```

* 使用列表自带方法

    列表自带的方法支持很多高级操作

    |方法                           |功能                                                                                   |
    |:------------------------------|:--------------------------------------------------------------------------------------|
    |`append(object)`               |把`object`添加到列表的尾部                                                             |
    |`clear()`                      |把列表清空成空列表                                                                     |
    |`copy()`                       |返回该列表的浅拷贝                                                                     |
    |`count(value)`                 |计算`value`在这个列表出现的次数                                                        |
    |`extend(iterable)`             |把可迭代对象`iterable`合并到列表的尾部                                                 |
    |`index(value, [start, [stop]])`|将索引范围为`[start:stop]`的第一个值为`value`的索引返回                                |
    |`insert(index, object)`        |将`object`插入到索引为`index`的元素的前面                                              |
    |`pop([index])`                 |删除并返回索引为`index`的元素，不提供参数则默认是最后一个元素                          |
    |`remove(value)`                |删除第一个值为`value`的元素                                                            |
    |`reverse()`                    |就地逆转列表的元素                                                                     |
    |`sort(key=None, reverse=False)`|就地稳定排序                                                                           |

    示例：
    1. `append(object)`

        ```python
        >>> name = ['Tony', 'Green', 'Alice', 'JZQT']
        >>> name.append('Hello World!')
        >>> name
        ['Tony', 'Green', 'Alice', 'JZQT', 'Hello World!']
        ```

    2. `clear()`

        ```python
        >>> name = ['Tony', 'Green', 'Alice', 'JZQT']
        >>> name.clear()
        >>> name
        []
        ```

    3. `copy()`

        ```python
        >>> name = ['Tony', 'Green', 'Alice', 'JZQT']
        >>> name.copy()
        ['Tony', 'Green', 'Alice', 'JZQT']
        ```

    4. `count(value)`

        ```python
        >>> name = ['Tony', 'Green', 'Alice', 'JZQT', 'JZQT']
        >>> name.count('JZQT')
        2
        ```

    5. `extend(iterable)`

        ```python
        >>> name = ['Tony', 'Green', 'Alice', 'JZQT']
        >>> name.extend([1, 2, 3])
        >>> name
        ['Tony', 'Green', 'Alice', 'JZQT', 1, 2, 3]
        ```

    6. `index(value, [start, [stop]])`

        ```python
        >>> name = ['Tony', 'Green', 'JZQT', 'Alice', 'JZQT']
        >>> name.index('JZQT')
        2
        >>> name.index('JZQT', 4)
        4
        >>> name.index('JZQT', 1, 5)
        2
        ```

    7. `insert(index, object)`

        ```python
        >>> name = ['Tony', 'Green', 'JZQT', 'Alice']
        >>> name.insert(1, 'Bob')
        >>> name
        ['Tony', 'Bob', 'Green', 'JZQT', 'Alice']
        >>> name.insert(100, 'God')
        >>> name
        ['Tony', 'Bob', 'Green', 'JZQT', 'Alice', 'God']
        >>> name.insert(-100, 'Oh')
        >>> name
        ['Oh', 'Tony', 'Bob', 'Green', 'JZQT', 'Alice', 'God']
        ```

    8. `pop([index])`

        ```python
        >>> name = ['Tony', 'Green', 'JZQT', 'Alice']
        >>> name.pop()
        'Alice'
        >>> name
        ['Tony', 'Green', 'JZQT']
        >>> name.pop(0)
        'Tony'
        >>> name
        ['Green', 'JZQT']
        ```

    9. `remove(value)`

        ```python
        >>> name = ['Tony', 'Green', 'JZQT', 'Alice', 'JZQT']
        >>> name.remove('JZQT')
        >>> name
        ['Tony', 'Green', 'Alice', 'JZQT']
        ```

    10. `reverse()`

        ```python
        >>> name = ['Tony', 'Green', 'JZQT', 'Alice']
        >>> name.reverse()
        >>> name
        ['Alice', 'JZQT', 'Green', 'Tony']
        ```

    11. `sort(key=None, reverse=False)`

        ```python
        >>> name = ['Tony', 'Green', 'JZQT', 'Alice']
        >>> name.sort()
        ['Alice', 'Green', 'JZQT', 'Tony']
        >>> name.sort(reverse=True)
        ['Tony', 'JZQT', 'Green', 'Alice']
        ```
