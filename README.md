# vala2std

# 使用方法如下

# 1将vala代码编译为C语言输出
valac cuintstr.vala -C

javac ValaC2Std.java

# 2将为C语言输出的代码转换为std lib
java ValaC2Std cuintstr.c cuintstr-out.c

# 3编译执行
gcc cuintstr-out.c

实现了一个简单glib.h
string的处理 substr,indexof,lastindexof
list的处理基于双向链表
实现了g_utf8_strdown g_utf8_strup g_utf8_strreverse g_strdup_printf g_strconcat g_strrstr等函数
测试的vala代码是一个简单的kv map实现。
目前的问题是OOP定义只能用struct，有部分函数未实现。
