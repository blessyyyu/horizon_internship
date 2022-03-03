'''
Date: 2022-03-03 14:49:36
LastEditors: Cyan
LastEditTime: 2022-03-03 19:08:29
Description: rewrite the kaldi style filter_scp.pl
'''
import getopt
import sys


def filter(idlistfile: str, infile='', outfile='', f=1, exclude=False):
    id_list = []
    infile_dict = {}
    with open(idlistfile, 'r', encoding='UTF-8') as f_idlist:
        line = f_idlist.readline()
        while line:
            id_list.append(line)
            line = f_idlist.readline()
    if in_file == '':
        to_write_str = ''.join(id_list)
    else:
        # read file infile
        with open(infile, 'r', encoding='UTF-8') as f_infile:
            line = f_infile.readline()
            line_list = line.split()

    with open(out_file, 'w', encoding='UTF-8') as f_outfile:
        f_outfile.write(to_write_str)

    f_idlist.close()
    f_outfile.close()


if __name__ == '__main__':
    # 先id_list 后 out.scp
    argv = sys.argv[1:]
    opts, args = getopt.getopt(argv, "-f:", ["exclude"])
    in_file = ''
    out_file = ''
    id_list = ''
    f = 1
    exclude = False
    assert len(args) == 2 or len(args) == 3
    if len(args) == 2:
        id_list = args[0]
        out_file = args[1]
    if len(args) == 3:
        id_list = args[0]
        in_file = args[1]
        out_file = args[2]

    for opt, arg in opts:
        if opt in ['-f']:
            f = arg
        if opt in ['--exclude']:
            exclude = True
        # print("parameter: ", opt, "value: ", arg)
    filter(id_list, outfile=out_file, f=f, exclude=exclude)
