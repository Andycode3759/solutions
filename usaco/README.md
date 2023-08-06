# The USA Computing Olympaid

在 train.usaco.org 上交题的一些注意事项：

- **文件头需要用注释给出信息**（用户 ID、题目 ID、语言类型）：
  ```c++
  /*
  ID: your_id_here
  TASK: task_name_here
  LANG: C++14
  */
  ```
- **需要文件读写，记得开 `freopen`。** 官方推荐的做法是用文件读写流 （`#include <fstream>`）。
- **文件比较会严格检查空行和空格。按照要求以空行作为输出结尾，且行末不要留多余空格。**
- 时限默认都是 1s，部分题目会给出特别说明。在线评测时程序会运行在现代 CPU 上，但**运行时间会等比例换算为 Intel Pentium III @ 700 MHz 的运行时间以保证公平**。
- **内存限制默认 16 MB** （不包括系统库占用），所以请省着点用。
- 不能使用 `strrev`（字符串反转，请自己手写） 和 `itoa`（可以用 `sprintf` 替代） 函数。
- GCC 版本是~~极其先进的~~ `11.2.0`，CCF 竞赛规范中为 `9.3.0`。
- 没有 O2。
