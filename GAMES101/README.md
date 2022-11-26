## 介绍

该部分是[GAMES101: 现代计算机图形学入门](https://sites.cs.ucsb.edu/~lingqi/teaching/games101.html)作业的参考答案.

该课程全面而系统地介绍现代计算机图形学的四大组成部分:（1）光栅化成像, （2）几何表示, （3）光的传播理论, 以及（4）动画与模拟. 每个方面都会从基础原理出发讲解到实际应用, 并介绍前沿的理论研究. 通过该课程, 你可以学习到计算机图形学背后的数学和物理知识, 并锻炼实际的编程能力.

顾名思义, 作为入门, 该课程会尽可能的覆盖图形学的方方面面, 把每一部分的基本概念都尽可能说清楚, 让大家对计算机图形学有一个完整的、自上而下的全局把握. 全局的理解很重要, 学完该课程后, 你会了解到图形学不等于 OpenGL, 不等于光线追踪, 而是一套生成整个虚拟世界的方法. 从该课程的标题, 大家还可以看到“现代”二字, 也就是说, 这门课所要给大家介绍的都是现代化的知识, 也都是现代图形学工业界需要的图形学基础.

该课程与其它图形学教程还有一个重要的区别, 那就是该课程不会讲授 OpenGL, 甚至不会提及这个概念. 该课程所讲授的内容是图形学背后的原理, 而不是如何使用一个特定的图形学 API. 在学习完这门课的时候, 你一定有能力自己使用 OpenGL 写实时渲染的程序. 另外, 该课程并不涉及计算机视觉、图像视频处理、深度学习, 也不会介绍游戏引擎与三维建模软件的使用.

该课程主页: https://sites.cs.ucsb.edu/~lingqi/teaching/games101.html .

该课程录像: https://www.bilibili.com/video/av90798049 .

讲授教师主页: [闫令琪](https://sites.cs.ucsb.edu/~lingqi/index.html).

## 环境

操作系统:

```
$ hostnamectl
   Static hostname: lyfubuntu
         Icon name: computer-desktop
           Chassis: desktop
        Machine ID: 5035e8d52f2e4471805511e24788918c
           Boot ID: b20ae92003504b5d9bdee983093f9ea6
  Operating System: Ubuntu 20.04.5 LTS
            Kernel: Linux 5.15.0-53-generic
      Architecture: x86-64
```

安装 OpenCV 和 Eigen:

```
$ sudo apt install libopencv-dev
$ sudo apt install libeigen3-dev
```

g++, cmake 和 make:

```
$ g++ --version
g++ (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

$ cmake --version
cmake version 3.16.3

CMake suite maintained and supported by Kitware (kitware.com/cmake).
$ make --version
GNU Make 4.2.1
为 x86_64-pc-linux-gnu 编译
Copyright (C) 1988-2016 Free Software Foundation, Inc.
许可证：GPLv3+：GNU 通用公共许可证第 3 版或更新版本<http://gnu.org/licenses/gpl.html>。
本软件是自由软件：您可以自由修改和重新发布它。
在法律允许的范围内没有其他保证。
```

## Reference

[1] [GAMES101: 现代计算机图形学入门](https://sites.cs.ucsb.edu/~lingqi/teaching/games101.html).

[2] [kingiluob/Games101](https://github.com/kingiluob/Games101).

[3] [YANGTHEKING/GAMES101_AllHomework-Advanced-](https://github.com/YANGTHEKING/GAMES101_AllHomework-Advanced-).