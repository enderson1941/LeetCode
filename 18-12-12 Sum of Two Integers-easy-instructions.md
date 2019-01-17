# 四则运算的基本实现

数据在计算机内存中是以二进制存储的。
几种常用的位运算：

```
与运算&:   对应位均为1时为1，其它为0。
或运算|:   对应位均为0时为0，其它为1。
异或运算^:  对应位不相同时为1，相同时为0.
按位取反~:  每一位取反
右移>>: 将二进制进行右移，低位丢掉，高位补零。
左移<<: 将二进制进行左移，低位补零，高位丢掉。
```

### 加法

以0111 + 0101为例，观察异或运算和与运算的结果
```c
0111 ^ 0101 = 0010; //结果的每一位等于对应位相加模二，刚好是不带进位的加法结果。
0111 & 0101 = 0101; //结果的1表示对应位相加为2，0表示对应位相加小于二，刚好是进位标识。12
```
又因为进位是向高位进位，也就是说如果第二位是1，则表示在计算过程中要向第三位进位，所以可以将与运算结果左移一位后和异或运算的结果做加法。

代码如下：
```c
int add(int a, int b)
{
  return (b == 0) ? a : add(a ^ b, (a & b) << 1);

  //if(b == 0)
  //  return a;
  //else
  //  return add(a ^ b, (a & b) << 1);
  //异或结果 + 与运算结果左移一位
}
```

### 减法

减法和加法相同，减去一个数相当于加上这个数的相反数，所以完全可以利用加法操作，唯一需要做的就是求出被减数的相反数。
求相反数的方法：每一位取反，末位加一。

代码如下：
```c
//求n的相反数
//~：按位取反
//add：加法操作，末位加一
int negtive(int n)
{
  return add(~n, 1);
}

int subtraction(int a, int b)
{
  //加上被减数的相反数
  return add(a, negtive(b));
}
```

### 乘法

平时在笔算乘法数据都是十进制的，而抛去思维定势，把数看成是二进制，也可以进行笔算乘法。
根据算式可以知道，对于**a * b**，每次只需要将a左移一位乘上b的对应位，然后同上一次的结果做加法即可。
也就意味着当b的对应位为1时，对a左移一位然后同上一次的结果做加法。
如果b的对应位为0，只对a左移一位。
当然，上述这些运算不包括符号位，所以两个操作数都需要先转换成正数，符号需要单独考虑。对于4个字节（32位整数）来说，获取符号位只需要取出第31位的值即可。

代码如下：
```c
//取出符号位
int getSign(int n)
{
  return n >> 31;
}

//求n的绝对值
int positive(int n)
{
  return (getSign(n) & 1) ? negtive(n) : n;
}

int multiply(int a, int b)
{
  //如果两个数符号位不相容，则结果为负
  bool isNegtive = false;
  if(getSign(a) ^ getSign(b))
    isNegtive = true;

  a = positive(a);
  b = positive(b);

  int res = 0;
  while(b | 0)
  {
    //当b的对应位是1时，才需要加a
    if(b & 1)
        res = add(res, a);
    a = a << 1; //a左移
    b = b >> 1; //b右移
  }
  return isNegtive == true ? negtive(res) : res;
}
```

### 除法

同乘法一样，除法也可以进行二进制笔算，以**a / b**为例，只有当**a >= b**时才可以上商，又因为是二进制，所以商每次只会多1，在每次上1之后a都要减去一次b。

代码如下：
```c
int divide(int a, int b)
{
  //被除数不能为0
  if(b == 0)
      throw std::runtime_error("Divided can't be zero...");

  bool isNegtive = false;
  if(getSign(a) ^ getSign(b))
      isNegtive = true;

  a = positive(a);
  b = positive(b);

  int res = 0;
  while(a >= b)
  {
    res = add(res, 1);
    a = subtraction(a, b);
  }
  return beNegtive == true ? negtive(res) : res;
}
```
