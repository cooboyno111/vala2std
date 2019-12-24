# vala2std

# 使用方法如下

# 1将vala代码编译为C语言输出
valac cuintstr.vala -C

javac ValaC2Std.java

# 2将为C语言输出的代码转换为std lib
java ValaC2Std cuintstr.c cuintstr-out.c

# 3编译执行
gcc cuintstr-out.c

# 实现了一个简单glib.h
# string的处理 substr,indexof,lastindexof
# list的处理基于双想链表
# g_utf8_strdown g_utf8_strup g_utf8_strreverse g_strdup_printf g_strconcat g_strrstr等函数
