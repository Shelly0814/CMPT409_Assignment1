#########################################################################
#
#                           PokerHands
#
#########################################################################

Data_path = "/home/409/Code/"

datafile = ''.join([Data_path, 'PokerHands_in.txt'])

fin = open(datafile, 'r')


Save_path = "/home/409/Code/"

out_filename = ''.join([Save_path, "PokerHands_out.txt"])
fout = open(out_filename, 'w')


# read input file

num_lines = sum(1 for line in open(datafile))

data = [] * num_lines

for line in fin:
    value = line.split() # string
    value_int = [str(x) for x in value] # it contains cards in each line
    
    data.append(value_int) # the whole input data
    
fin.close()

# data[0]

# YOUR ALGORITHM

#   Writing the results

res = [-1, 1, 0, -1, -1, 0] # A variable indicating to the result of each line of input

for a in res:
    if (a == 0):
        fout.write(("Tie."+ '\n'))

    if (a == 1):
        fout.write(("White wins."+ '\n'))

    if (a == -1):
        fout.write(("Black wins."+ '\n'))

fout.close()

#########################################################################
#
#                           Check-the-Check(p10196)
#
#########################################################################

#           input
Data_path = "/home/409/Code/"
datafile = ''.join([Data_path, 'Check-the-Check_in.txt'])
fin = open(datafile, 'r')

#           output
Save_path = "/home/409/Code/"
out_filename = ''.join([Save_path, "Check-the-Check_out.txt"])
fout = open(out_filename, 'w')


# Read input file
num_lines = sum(1 for line in open(datafile))
num_chessboard = int((num_lines-8)/9)

data = [] * num_lines

for line in fin:
    value = line.split() # string
    value_int = [str(x) for x in value]
    data.append(value_int)

fin.close()


res = 0

for i in range(num_chessboard):
    
    board = data[(i*9):((i*9)+8)]
    
    # list(board[0][0])
    
    ## Your algorithm
    
    ## res is the result of your algorithm
    
    if res == 1:
        out = ''.join(['Game #', str(i+1),': white king is in check.'])
        fout.write((out+ '\n'))
    if res == -1:
        out = ''.join(['Game #', str(i+1),': black king is in check.'])
        fout.write((out+ '\n'))
    if res == 0:
        out = ''.join(['Game #', str(i+1),': no king is in check.'])
        fout.write((out+ '\n'))

fout.close()               


#########################################################################
#
#                           ErdosNumber
#
#########################################################################

#           input
Data_path = "/home/409/Code/"
datafile = ''.join([Data_path, 'ErdosNumber_in.txt'])
fin = open(datafile, 'r')

#           output
Save_path = "/home/409/Code/"
out_filename = ''.join([Save_path, "ErdosNumber_out.txt"])
fout = open(out_filename, 'w')


# Read input file
num_lines = sum(1 for line in open(datafile))

data = [] * num_lines

for line in fin:
    value = line.split() # string
    value_int = [str(x) for x in value]
    data.append(value_int)

fin.close()

length = [len(x) for x in data]
Scenario_lines = [i for i,x in enumerate(length) if x==1]  # index of lines that is a scenario number
                  
Scenario_num = len(Scenario_lines) # Number of scenarios


for i in range(Scenario_num):
    ind = Scenario_lines[i]
    paper_num = int(data[ind+1][0]) # number of papers for scenario i
    author_num = int(data[ind+1][1]) # number of authors for scenario i
    
    score = [0] * author_num
    papers = data[(ind+2):(ind+2+paper_num)]
    papers = [''.join(x) for x in papers]

    authors = data[(ind+paper_num+2):(ind+paper_num+2+author_num)]
    authors = [''.join(x) for x in authors]

    # Your Algorithm

    
    # write the result 
    fout.write((''.join(['Scenario ', str(i+1)]) +'\n'))
    for j in range(author_num):
        fout.write((authors[j] + ' '+ str(score[j]) +'\n'))
    

fout.close()

#########################################################################
#
#                           FleaCircus
#
#########################################################################

#           input
Data_path = "/home/409/Code/"
datafile = ''.join([Data_path, 'FleaCircus_in.txt'])
fin = open(datafile, 'r')

#           output
Save_path = "/home/409/Code/"
out_filename = ''.join([Save_path, "FleaCircus_out.txt"])
fout = open(out_filename, 'w')


# Read input file
num_lines = sum(1 for line in open(datafile))

data = [] * num_lines

for line in fin:
    value = line.split() # string
    value_int = [str(x) for x in value]
    data.append(value_int)

fin.close()

length = [len(x) for x in data]
SingleNumber_lines = [i for i,x in enumerate(length) if x==1]  # index of lines that is a scenario number

TestCase_num = int(len(SingleNumber_lines)/3) # number of test cases

n_lines = [0] * TestCase_num # it keeps index of lines that have 'n' numbers in test cases
l_lines = [0] * TestCase_num # it keeps index of lines that have 'l' numbers in test cases
zero_lines = [0] * TestCase_num # it keeps index of lines that have '0', end line of test cases

counter = 0
for i in (range(0, len(SingleNumber_lines), 3)):
    n_lines[counter] = SingleNumber_lines[i]
    counter = counter + 1

counter = 0
for i in (range(1, len(SingleNumber_lines), 3)):
    l_lines[counter] = SingleNumber_lines[i]
    counter = counter + 1

counter = 0
for i in (range(2, len(SingleNumber_lines), 3)):
    zero_lines[counter] = SingleNumber_lines[i]
    counter = counter + 1
    

for i in range(TestCase_num):
    Tree_branches = data[(n_lines[i]+1):(l_lines[i])]
    Jump_starts = data[(l_lines[i]+1):(zero_lines[i])]  
                       
    p = [0] * len(Jump_starts)
    r = [0] * len(Jump_starts)
    
    for j in range(len(Jump_starts)) :
        
        # Your Algorithm    
        
        ## Writing the results
        # based on your algorithm you should decide which line should be written in the output
        fout.write(('The fleas jump forever between '+ str(p[j])+' and ' + str(r[j]) +'.' +'\n'))
        fout.write(('The fleas meet at '+ str(p[j])+'.' +'\n'))
        
        
fout.close()