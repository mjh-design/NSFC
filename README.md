# 学习型索引LNI与传统索引HT-Cityhash映射冲突概率对比实验

## Introduction

利用生成标识数据与2020年Blacklist数据集，分别测试对比学习型索引LNI和传统索引HT-Cityhash的映射冲突率。其中，测试数据量为100万，映射位置总数为1000万。实验结果表明，对于生成标识数据，学习型索引LNI的的映射冲突概率为0.85%，远低于HT-Cityhash。然而，由于标识分布的不同，LNI对于Blacklist数据集的映射冲突概率远超过HT-Cityhash。

## About this repo
- `Cityhah`：基于CithHash的传统索引HT－Cityhash
- `LNI`：基于神经网络的学习型索引LNI
- `Datasets`：生成标识数据和2020年Blacklist数据集
- 实验测试代码运行方法见具体文件夹（Cityhash、LNI）中README。
## Experimental results
![image](https://user-images.githubusercontent.com/72145333/159824704-a10e3afa-aa63-4b05-b843-56001aeee5b5.png)
