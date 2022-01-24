import networkx as nx
import math
import numpy as np


# READ:
def get_seed(seed1, seed2, seed_pair):
    G1 = nx.read_edgelist(seed1)
    G2 = nx.read_edgelist(seed2)
    with open(seed_pair, 'r') as sp:
        lines = sp.readlines()
    return G1, G2, lines


# Get G1,G2 paired nodes and stored in Dictionary
def get_pair(lines):
    g1p = [ ]
    g1pdir = {}
    g2p = [ ]
    for line in lines:
        line = line.strip('\n')
        line = line.split(' ')
        g1p.append(line[ 0 ])
        g2p.append(line[ 1 ])
        g1pdir[ line[ 0 ] ] = line[ 1 ]
    return g1p, g2p, g1pdir


# Get G1, G2 unpaired nodes
def get_unpair(G1, G2, g1p, g2p):
    g1np = [ ]
    g2np = [ ]
    for i in G1.nodes:
        if i not in g1p:
            g1np.append(i)
    for j in G2.nodes:
        if j not in g2p:
            g2np.append(j)
    return g1np, g2np


# Get nodes' degrees
def get_degree(node_list, G):
    degree_dir = {}
    for i in node_list:
        degree_dir[ i ] = G.degree(i)
    return degree_dir


# get node's neighbors which are in the pair list
def check_in_pairs(node, G, pair_list):
    in_pair_list = [ ]
    for neighbor in G.neighbors(node):
        if neighbor in pair_list:
            in_pair_list.append(neighbor)
    return in_pair_list


# Count how many paired neighbors are in another Graph (G2).
def check_in_other_neighbor(neighbor_pair_list, other_G, pair_dir, other_node):
    other_pair_list = [ ]
    for i in neighbor_pair_list:
        other_pair_list.append(pair_dir[ i ])
    count = 0
    for j in other_pair_list:
        if j in other_G.neighbors(other_node):
            count += 1
    return count


# Calculate the score
def get_score(node1_degree, node2_degree, count):
    score = count / ((math.sqrt(node1_degree)) * (math.sqrt(node2_degree)))
    return score


# Calculate ECCE
def get_ECCE(score_list):
    std = np.std(score_list)
    max1 = max(score_list)
    score_list.remove(max1)
    max2 = max(score_list)
    if std == 0:
        result = 0
    else:
        result = (max1 - max2) / std
    return result


# Based on dictionary's value, get the key.
def get_key(dict, value):
    for k, v in dict.items():
        if v == value:
            a = k
    return a


# Calculate G1's one node and All G2 unpaired nodes  ECCE and find the Maximun score's G2 node.
def G1_node_compare_G2(node, G1, G1_pair, G2, G1_pair_dir, G1_unpair_degree_dir, G2_unpair_degree_dir, G2_unpair):
    node_pair_list = check_in_pairs(node, G1, G1_pair)
    G2_node_and_score = {}
    for j in G2_unpair:
        count = check_in_other_neighbor(node_pair_list, G2, G1_pair_dir, j)
        score = get_score(G1_unpair_degree_dir[ node ], G2_unpair_degree_dir[ j ], count)
        G2_node_and_score[ j ] = score

    score_list = list(G2_node_and_score.values())
    max_score_G2_node = get_key(G2_node_and_score, max(score_list))
    ECCE_score = get_ECCE(score_list)
    return ECCE_score, max_score_G2_node


# If ECCE larger than my setting value. Update G1 pair list, G2 pair list, G1 pair dictionary, and G1, & G2 unpaired list
def update_pair(ecce, node1, node2, v, G1_pair, G2_pair, G1_pair_dir, G1_unpair, G2_unpair):
    if ecce > v:
        G1_pair.append(node1)
        G2_pair.append(node2)
        G1_pair_dir[ node1 ] = node2
        G1_unpair.remove(node1)
        G2_unpair.remove(node2)

    return G1_pair, G2_pair, G1_pair_dir, G1_unpair, G2_unpair


# Read all G1's nodes to do the calculation and update the lists.
def get_result(v, G1, G2, G1_pair, G2_pair, G1_pair_dir, G1_unpair, G2_unpair, G1_unpair_degree_dir,
               G2_unpair_degree_dir):
    for node in G1_unpair:
        ecce, max_node = G1_node_compare_G2(node, G1, G1_pair, G2, G1_pair_dir, G1_unpair_degree_dir,
                                            G2_unpair_degree_dir, G2_unpair)
        G1_pair, G2_pair, G1_pair_dir, G1_unpair, G2_unpair = update_pair(ecce, node, max_node, v, G1_pair, G2_pair,
                                                                          G1_pair_dir, G1_unpair, G2_unpair)

    return G1_pair, G2_pair, G1_pair_dir, G1_unpair, G2_unpair


# Passing two seeds' location and pair list location to get two graph and get final result lists.
def running(seed1, seed2, seed_pair, v):
    G1, G2, node_pairs = get_seed(seed1, seed2, seed_pair)
    old_G1_pair, old_G2_pair, old_G1_pair_dir = get_pair(node_pairs)

    G1_pair = [ ]
    G2_pair = [ ]
    G1_pair_dir = {}
    for i in range(350, len(old_G1_pair)):
        G1_pair.append(old_G1_pair[ i ])
        G2_pair.append(old_G2_pair[ i ])
        G1_pair_dir[ old_G1_pair[ i ] ] = old_G2_pair[ i ]
    G1_unpair, G2_unpair = get_unpair(G1, G2, G1_pair, G2_pair)
    G1_unpair_degree_dir = get_degree(G1_unpair, G1)
    G2_unpair_degree_dir = get_degree(G2_unpair, G2)

    G1_pair, G2_pair, G1_pair_dir, G1_unpair, G2_unpair = get_result(v, G1, G2, G1_pair, G2_pair, G1_pair_dir,
                                                                     G1_unpair, G2_unpair, G1_unpair_degree_dir,
                                                                     G2_unpair_degree_dir)
    return G1_pair, G2_pair, G1_pair_dir, G1_unpair, G2_unpair, old_G1_pair, old_G2_pair, old_G1_pair_dir


# main method
if __name__ == "__main__":
    seed1 = 'seed_G1.edgelist'
    seed2 = 'seed_G2.edgelist'
    seed_pair = 'seed_node_pairs.txt'
    v = 0.5
    G1_pair, G2_pair, G1_pair_dir, G1_unpair, G2_unpair, old_G1_pair, old_G2_pair, old_G1_pair_dir = running(seed1,
                                                                                                             seed2,
                                                                                                             seed_pair,
                                                                                                             v)

count = 0
for i in range(500, len(old_G1_pair)):
    if old_G1_pair[ i ] in G1_pair and G1_pair_dir[ old_G1_pair[ i ] ] == old_G1_pair_dir[ old_G1_pair[ i ] ]:
        count += 1
accuracy = count /100

print('The accuracy is : ' + str(accuracy))

print(len(G1_pair))

print(len(G1_unpair))

with open('pairs.txt', 'w') as f:
    for i in G1_pair:
        s = i + ' ' + G1_pair_dir[ i ] + '\n'
        f.write(s)
