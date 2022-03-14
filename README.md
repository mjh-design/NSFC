# LNI神经网络索引结构与CityHash索引结构的对比实验

## Introduction

利用生成标识数据与Blacklist两个百万数据集，对比基于神经网络的索引结构和基于CityHash的索引结构在1000万数组上的映射冲突率。初步实验表明基于神经网络的索引结构在生成标识数据集上的冲突率为0.85%，显著低于CityHash索引结构的4.85%，显示了基于神经网络的索引结构相较于传统索引结构的优势。

## About this repo

- 'Cityhah'：基于CithHash索引结构实现的映射
- 'Neural network model'：基于LNI神经网络索引结构实现的映射
- 'Datasets'：生成标识数据和Blacklist数据集
