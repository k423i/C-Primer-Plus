

```cpp
// 使用cin.getline() 和 cin.get() 的区别
char name[15];
// 读取15个(或少于)字符给name 遇到enter换行时, 将此换行符替换为'\0'加入字符串末尾
// 最多读取14个有意义的字符 还有一格空间存放'\0' 即strlen(name)最大等于14
cin.getline(name, 15);

// cin.get()也是最多读取14个有意义的字符 但遇到enter换行时只会中止 不会丢弃换行符
// 那么如果直接运行 cin.get(name, 15) 会留一个换行符在cin区无法进行下去
// 需要使用 cin.get() 读取掉这个换行 才能进行下面的正确读取 
cin.get(name, 15).get();
// 普通cin的输入和cin.get()同理 会留一个换行

// string对象可以赋值 但char[]不行
string s1;
string s2="copyTos1";
s1=s2; // valid
string s3=s1+s2; // copyTos1copyTos1

// string带有getline函数
string str;
getline(cin, str);
```

