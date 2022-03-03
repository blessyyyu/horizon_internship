'''
Date: 2022-02-28 17:23:33
LastEditors: Cyan
LastEditTime: 2022-03-03 14:48:52
'''
import os
import sys
import getopt
import string


def main(file_name: str):
    """将file_name文件名中的单词统计它们的词频，
    输出到word_count.txt文件中

    :param file_name: 统计词频的文件名
    :return: None
    """
    dicts = {}
    # 修改路径
    os.chdir(r'C:\Users\shaoqing.yu\Documents\horizon_internship\basic_programming\python_basic_programming')
    if file_name == "":
        print('No file name')
        exit(1)
    content = []
    with open(file_name, 'r', encoding='UTF-8') as f:
        line = f.readline()
        while line:
            if line[-1] == '\n':
                line = line[:-1] + " "
            content.append(line)
            line = f.readline()
        content_str = "".join(content)
        words = content_str.split(" ")
        # 去除标点并统计词频
        for i in range(len(words)):
            if i == 43:
                print(i)
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
    """ 手动输入一个文件名
    """
    file_name = ""
    print('please input the file name of input text:')
    file_name = input()

    main(file_name)
