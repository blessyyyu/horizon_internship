import getopt
import sys


def filter(idlistfile: str, infile='', f=1, exclude=False):
    # id_list store the all
    id_list = []
    # key: infile's f-th field, value: infile's line content
    infile_dict = {}
    key_line = f - 1
    to_write_list = []
    to_write_str = ''
    with open(idlistfile, 'r', encoding='UTF-8') as f_idlist:
        for line in f_idlist:
            line = line.strip('\n')
            id_list.append(line)
        line = f_idlist.readline()

    if in_file == '':
        to_write_str = ''.join(id_list)
    else:
        # read file infile
        infile_content_list = []
        with open(infile, 'r', encoding='UTF-8') as f_infile:
            for line in f_infile:
                line = line.strip('\n')
                infile_content_list.append(line)
                line_list = line.split(" ")
                dict_key = line_list[key_line]
                infile_dict.update({dict_key: line})
        # print(infile_dict)

        if exclude:
            for key, value in infile_dict.items():
                if key not in id_list:
                    to_write_list.append(value)
        else:
            # traversal the all id_list to find key
            for i in range(len(id_list)):
                if id_list[i] in infile_dict:
                    to_write_list.append(infile_dict[id_list[i]])

        to_write_str = '\n'.join(to_write_list)
        f_infile.close()

    print(to_write_str)

    f_idlist.close()


if __name__ == '__main__':
    # 先id_list 后 out.scp
    argv = sys.argv[1:]
    opts, args = getopt.getopt(argv, "-f:", ["exclude"])
    in_file = ''
    out_file = ''
    id_list = ''
    f_ = 1
    exclude_ = False
    assert len(args) == 1 or len(args) == 2
    if len(args) == 1:
        id_list = args[0]
    if len(args) == 2:
        id_list = args[0]
        in_file = args[1]

    for opt, arg in opts:
        if opt in ['-f']:
            f_ = int(arg)
        if opt in ['--exclude']:
            exclude_ = True
        # print("parameter: ", opt, "value: ", arg)
    # print('id_list = ', id_list, 'infile = ',
    #       in_file, 'f = ', f_, 'exclude = ', exclude_)
    filter(id_list, infile=in_file, f=f_, exclude=exclude_)
