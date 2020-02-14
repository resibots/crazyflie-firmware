import matplotlib
import matplotlib.pyplot as plt
import numpy as np

class Link:
    def __init__(self):
        self.times = []
        self.rssis = []

links = {}

def read_file():
    f = open("ping_log.txt", "r")
    for line in f:
        try:
            data = line[:-1].split(',')
            time = float(data[0])
            for i, r in enumerate(data[1:-1]):
                if i not in links.keys():
                    links[i] = Link()
                rssi = float(r)
                links[i].times.append(time)
                links[i].rssis.append(rssi)
                print(i, time, rssi)
        except:
            print("Ignored " + line[:-1])
            break
    f.close()

def plot_time_signal():
    colors = ['tab:blue', 'tab:orange', 'tab:green'][::-1]
    labels= []
    for i, k in enumerate(reversed(list(links.keys()))):
        plt.plot(links.get(k).times, links.get(k).rssis, 
                c=colors[i],
                linewidth=3,
                label="Link {}".format(str(k)))
        labels.append("Link {}".format(str(k)))

    # plt.title('Time based signal logging')
    plt.xlabel('Time (s)')
    plt.ylabel('RSSI')
    # plt.legend(loc='upper left', fontsize='small', ncol=5)
    plt.legend(reversed(plt.legend().legendHandles), reversed(labels), ncol=5, fontsize='small', loc='upper left')
    plt.ylim(bottom=30, top=75)
    plt.show()

def plot_time_dist():
    colors = ['tab:blue', 'tab:orange', 'tab:green', 'tab:red', 'tab:purple'][::-1]
    labels= []
    for i, k in enumerate(reversed(list(links.keys()))):
        plt.plot(links.get(k).steps, links.get(k).pos_y, 
                c=colors[i],
                linewidth=3,
                label="Link {}".format(str(k)))
        labels.append("Link {}".format(str(k)))

    # plt.title('Time based signal logging')
    plt.xlabel('Simulation step')
    plt.ylabel('Tunnel distance (m)')
    # plt.legend(loc='upper left', fontsize='small', ncol=5)
    plt.legend(reversed(plt.legend().legendHandles), reversed(labels), ncol=5, fontsize='small', loc='upper left')
    plt.ylim(top=max(links.get(0).pos_y) + 10)
    plt.show()

if __name__ == "__main__":
    matplotlib.rcParams.update({'font.size': 34})
    matplotlib.rcParams['mathtext.fontset'] = 'stix'
    matplotlib.rcParams['font.family'] = 'STIXGeneral'

    read_file()

    plot_time_signal()
    #plot_time_dist()
