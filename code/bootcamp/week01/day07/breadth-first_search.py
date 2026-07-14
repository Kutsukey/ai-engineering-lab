def bfs(graph,key,target):
    key_list = []
    looked_list = []
    parent = {}
    path = []
    key_list.append(key)

    if key == target: return [key]

    while len(key_list) != 0:
        s = key_list.pop(0)
        looked_list.append(s)
        for e in graph[s]:
            parent[e] = s
            if e in looked_list:
                continue
            elif e == target:
                while parent[e] != key:
                    path.append(e)
                    e = parent[e]
                path.append(e)
                path.append(key)
                return path[::-1]
            key_list.append(e)
            looked_list.append(e)
    return False


# Örnek Grafik Bilgisi (Sözlük / Adjacency List)
my_graph = {
    "Mustafa": ["Ahmet", "Bilal", "Aybars"],
    "Ahmet": ["Saliha"],
    "Bilal": ["Çağrı", "Saliha"],
    "Aybars": ["Thom"],
    "Saliha": [],
    "Çağrı": [],
    "Thom": []
}

# --- TEST SENARYOLARI ---

# Senaryo 1: Grafın içinde olan ve yakın bir hedefi arama
# Beklenen süreç: Genişleyerek arayıp "Çağrı"yı bulması
print("Senaryo 1 (Çağrı aranıyor):", bfs(my_graph, "Mustafa", "Çağrı"))

# Senaryo 2: Grafta hiç var olmayan birini arama
# Beklenen süreç: Tüm grafı gezip bitirdikten sonra False dönmesi
print("Senaryo 2 (Mert aranıyor):", bfs(my_graph, "Mustafa", "Mert"))