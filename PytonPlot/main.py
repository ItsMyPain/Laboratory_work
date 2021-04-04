import numpy as np
import matplotlib.pyplot as plt
import math
import matplotlib.ticker as ticker

A, B, C, D, E, T, T2, T3, T4, T5 = np.array([]), np.array([]), np.array([]), np.array([]), np.array([]), np.array(
    []), np.array([]), np.array([]), np.array([]), np.array([])

with open("7V.txt") as f:
    for line in f:
        a, t = line.split()
        A = np.append(A, int(float(a)))
        T = np.append(T, int(float(t)))

f.close()

with open("7Fl.txt") as f:
    for line in f:
        b, t = line.split()
        B = np.append(B, int(float(b)))
        T2 = np.append(T2, int(float(t)))

f.close()

with open("7L.txt") as f:
    for line in f:
        c, t = line.split()
        C = np.append(C, int(float(c)))
        T3 = np.append(T3, int(float(t)))

f.close()

with open("7S.txt") as f:
    for line in f:
        d, t = line.split()
        D = np.append(D, int(float(d)))
        T4 = np.append(T4, int(float(t)))

f.close()

with open("7M.txt") as f:
    for line in f:
        e, t = line.split()
        E = np.append(E, int(float(e)))
        T5 = np.append(T5, int(float(t)))

f.close()

fig, ax = plt.subplots()

ax.plot(T, A,
        linewidth=1)
ax.plot(T2, B,
        linewidth=1)
ax.plot(T3, C,
        linewidth=1)
ax.plot(T4, D,
        linewidth=1)
ax.plot(T5, E,
        linewidth=1)

# ax.set_yscale('log')
# ax.set_xscale('log')
ax.grid(which='major',
        color='k')
ax.minorticks_on()
ax.grid(which='minor',
        color='gray',
        linestyle=':')
plt.title('Random access')
plt.xlabel('Size')
plt.ylabel('Time, mc')
plt.legend(['Vector', 'Forward_list', 'List', 'Set', 'Map'])
ax.get_xaxis().get_major_formatter().set_scientific(False)
fig.set_figwidth(12)
fig.set_figheight(8)
fig.savefig('7.png')
plt.show()
