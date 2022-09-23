# Shutu
An automatic problem solving program for an intelligence game

有一个这样的益智游戏，每行和每列标注出连续的填充格子数，目标是还原出原始图像

题目例子：

<img src="QQ图片20220923212430.jpg" width="360" height="399">

解决完成：

<img src="QQ图片20220923212435.jpg" width="360" height="800"> <img src="QQ图片20220923212439.jpg" width="360" height="800">

当然，可以使用暴力的方法，不过通过观察得知，题目和另一个益智游戏数独类似，可能存在一些恒定状态的位置，通过这些已知状态的位置，可以有效减少未知位置的状态数，最终确定所有格子的状态。

为了展现代码解题过程，代码每扫描一遍会停留一小段时间。
