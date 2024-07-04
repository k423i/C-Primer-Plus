

```cpp
// 使用cin.getline() 和 cin.get() 的区别
char name[15];
// 读取15个(或少于)字符给name 遇到enter换行时, 将此换行符替换为'\0'加入字符串末尾
// 最多读取14个字符 还有一格空间存放'\0'
cin.getline(name, 15);

```

