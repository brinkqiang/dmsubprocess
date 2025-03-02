# dmsubprocess

Copyright (c) 2013-2018 brinkqiang (brink.qiang@gmail.com)

[![dmsubprocess](https://img.shields.io/badge/brinkqiang-dmsubprocess-blue.svg?style=flat-square)](https://github.com/brinkqiang/dmsubprocess)
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://github.com/brinkqiang/dmsubprocess/blob/master/LICENSE)
[![blog](https://img.shields.io/badge/Author-Blog-7AD6FD.svg)](https://brinkqiang.github.io/)
[![Open Source Love](https://badges.frapsoft.com/os/v3/open-source.png)](https://github.com/brinkqiang)
[![GitHub stars](https://img.shields.io/github/stars/brinkqiang/dmsubprocess.svg?label=Stars)](https://github.com/brinkqiang/dmsubprocess) 
[![GitHub forks](https://img.shields.io/github/forks/brinkqiang/dmsubprocess.svg?label=Fork)](https://github.com/brinkqiang/dmsubprocess)

## Build status
| [Linux][lin-link] | [Mac][mac-link] | [Windows][win-link] |
| :---------------: | :----------------: | :-----------------: |
| ![lin-badge]      | ![mac-badge]       | ![win-badge]        |

[lin-badge]: https://github.com/brinkqiang/dmsubprocess/workflows/linux/badge.svg "linux build status"
[lin-link]:  https://github.com/brinkqiang/dmsubprocess/actions/workflows/linux.yml "linux build status"
[mac-badge]: https://github.com/brinkqiang/dmsubprocess/workflows/mac/badge.svg "mac build status"
[mac-link]:  https://github.com/brinkqiang/dmsubprocess/actions/workflows/mac.yml "mac build status"
[win-badge]: https://github.com/brinkqiang/dmsubprocess/workflows/win/badge.svg "win build status"
[win-link]:  https://github.com/brinkqiang/dmsubprocess/actions/workflows/win.yml "win build status"

## Intro
dmsubprocess 库提供的主要功能总结：

| 功能点                     | 描述                                                                 |
|---------------------------|--------------------------------------------------------------------|
| 执行外部命令并捕获输出       | 可运行指定命令并捕获其标准输出和标准错误输出内容。                             |
| 处理命令执行失败             | 当命令执行失败时返回错误状态（`ExitFailure`），并提供错误输出信息。            |
| 处理不存在的命令             | 当尝试执行不存在的命令时返回错误，并在Windows和Unix系统给出相应错误信息。       |
| 信号中断处理                | 支持处理子进程/父进程的中断信号（SIGINT/SIGTERM/SIGHUP），返回`ExitInterrupted`状态。 |
| 控制台终端交互支持           | 可通过`use_console`参数让子进程继承控制台终端（验证TTY设备）。                 |
| 单子进程管理                | 支持添加单个子进程并监控其执行状态，直到完成。                                |
| 多子进程并发管理             | 可同时管理多个子进程（如3个并行命令），通过事件循环监控所有进程状态。             |
| 大规模子进程处理             | 支持处理超过1024个子进程（使用`ppoll`避免文件描述符限制）。                    |
| 标准输入处理                | 子进程读取stdin时会检测到输入流已关闭（如`cat -`命令）。                       |
| 跨平台支持                  | 兼容Windows（`cmd`命令）和Unix-like系统（`ls`, `kill`等命令）。               |
| 状态查询接口                | 提供`Done()`方法检查子进程是否执行完成。                                    |
| 退出状态码获取              | 通过`Finish()`返回退出状态（`ExitSuccess`/`ExitFailure`/`ExitInterrupted`）。 |
| 异步事件驱动机制            | 通过`DoWork()`实现非阻塞的事件循环，监控子进程状态变化。                       |
| 资源限制处理                | 在Unix系统自动处理文件描述符限制（通过`setrlimit`调整）。                      |

**关键实现特性**：
- 使用`SubprocessSet`集中管理子进程集合
- 通过轮询（`DoWork`）实现异步执行监控
- 提供统一的输出捕获接口（`GetOutput()`）
- 支持子进程的中断信号传播和处理
- 针对大规模并发场景优化（超过1024个子进程）

## Contacts

## Thanks
