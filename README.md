# LNI神经网络索引结构与CityHash索引结构的对比实验

## Introduction

利用生成标识数据与2020年Blacklist数据集，对比基于神经网络的学习型索引LNI和基于CityHash的传统索引HT-Cityhash在1000万数组上的映射冲突率。实验结果表明，对于生成标识数据，学习型索引LNI的的映射冲突概率为0.85%，远低于HT-Cityhash。然而，由于标识分布的不同，LNI对于Blacklist数据集的映射冲突概率远超过HT-Cityhash。

## About this repo

- `Cityhah`：基于CithHash的传统索引HT－Cityhash
- `Neural network model`：基于神经网络的学习型索引LNI
- `Datasets`：生成标识数据和2020年Blacklist数据集
## Experimental results
![image](https://user-images.githubusercontent.com/72145333/159824704-a10e3afa-aa63-4b05-b843-56001aeee5b5.png)
