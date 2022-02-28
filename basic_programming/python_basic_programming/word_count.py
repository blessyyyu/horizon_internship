# Author: Cyan
# Time : 2022/2/24 16:22
# Description:
# -*-coding:utf-8-*-
import os
import sys
import getopt
import string


# TODO(shaoqing.yu): 大小写问题
def main(file_name: str):
    """将file_name文件名中的单词统计它们的词频，
    输出到word_count.txt文件中

    :param file_name: 统计词频的文件名
    :return: None
    """
    dicts = {}
    if file_name == "":
        print('No file name')
    with open(file_name, 'r', encoding='UTF-8') as f:
        content = f.readline()
        words = content.split(" ")
        # 去除标点并统计词频
        for i in range(len(words)):
            if words[i][-1] in string.punctuation:
                words[i] = words[i][:-1]
            if words[i] in dicts:
                dicts[words[i]] += 1
            else:
                dicts.update({words[i]: 1})
    to_write_str = ""
    word_count_list = []
    for key in dicts:
        word_count_list.append('%s %d\n' % (key, dicts[key]))
    to_write_str = ''.join(word_count_list)
    print(to_write_str)
    with open("word_count.txt", 'w', encoding='UTF-8') as write_file:
        write_file.write(to_write_str)

    write_file.close()
    f.close()


if __name__ == '__main__':
    """ 接受一个-n file_name 的命令行参数
    """
    argv = sys.argv[1:]
    opts, args = getopt.getopt(argv, "n:", ["name="])
    file_name = ""
    for opt, arg in opts:
        if opt in ['-n', '--name']:
            file_name = arg

    main(file_name)
