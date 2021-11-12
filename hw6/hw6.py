import matplotlib.pyplot as plt
 

 

uniform_1 = []

uniform_2 = []

uniform_3 = []

uniform_4 = []

 

gaus_1 = []

gaus_2 = []

gaus_3 = []

gaus_4 = []

 

 

f = open('uniform_1.txt', 'r') 

while True:

    line = f.readline()

    if not line:

        break

    uniform_1.append(float(line.rstrip('\n')))

    

f = open('uniform_2.txt', 'r') 

while True:

    line = f.readline()

    if not line:

        break

    uniform_2.append(float(line.rstrip('\n')))

    

f = open('uniform_3.txt', 'r') 

while True:

    line = f.readline()

    if not line:

        break

    uniform_3.append(float(line.rstrip('\n')))

    

f = open('uniform_4.txt', 'r') 

while True:

    line = f.readline()

    if not line:

        break

    uniform_4.append(float(line.rstrip('\n')))

 

f = open('gaus_1.txt', 'r') 

while True:

    line = f.readline()

    if not line:

        break

    gaus_1.append(float(line.rstrip('\n')))

    

f = open('gaus_2.txt', 'r') 

while True:

    line = f.readline()

    if not line:

        break

    gaus_2.append(float(line.rstrip('\n')))

    

f = open('gaus_3.txt', 'r') 

while True:

    line = f.readline()

    if not line:

        break

    gaus_3.append(float(line.rstrip('\n')))

    

f = open('gaus_4.txt', 'r') 

while True:

    line = f.readline()

    if not line:

        break

    gaus_4.append(float(line.rstrip('\n')))

 
plt.subplot(4, 2, 1)
plt.hist(uniform_1, bins = 100, alpha = 0.7, label='uniform_100')

plt.subplot(4, 2, 2)
plt.hist(uniform_2, bins = 100, alpha = 0.5, label='uniform_1000')

plt. subplot(4, 2, 3)
plt.hist(uniform_3, bins = 100, alpha = 0.9 , label='uniform_10000')

plt.subplot(4, 2, 4)
plt.hist(uniform_4, bins = 100, alpha = 0.3, label='uniform_100000')

#plt.legend()

#plt.show
#plt.savefig('./uniform.png')

plt.subplot(4,2,5)
plt.hist(gaus_1, bins = 100, label='gaus_100')

plt.subplot(4,2,6)
plt.hist(gaus_2, bins = 100, label='gaus_1000')

plt.subplot(4,2, 7)
plt.hist(gaus_3, bins = 100, label='gaus_10000')

plt.subplot(4,2,8)
plt.hist(gaus_4, bins = 100, label='gaus_100000')

plt.legend()

plt.savefig('./result.png')


