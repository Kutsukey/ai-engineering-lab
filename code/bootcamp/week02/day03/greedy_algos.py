# Radyo istasyonu problemi (set-covering)
# Kapsanması gereken eyaletlerin kümesi (Set)
states_needed = {"mt", "wa", "or", "id", "nv", "ut", "ca", "az"}

# İstasyonlar ve kapsadıkları eyaletler (Sözlük / Hash)
stations = {
    "kone": {"id", "nv", "ut"},
    "ktwo": {"wa", "id", "mt"},
    "kthree": {"or", "nv", "ca"},
    "kfour": {"nv", "ut"},
    "kfive": {"ca", "az"}
}

# Seçilen nihai istasyonları tutacak boş küme
final_stations = set()

while states_needed:
    best_station = None
    covered = set()
    for station, states in stations.items():
        covering = states_needed & states
        if len(covering) > len(covered):
            best_station = station
            covered = covering
        
    final_stations.add(best_station)
    states_needed -= covered

print(final_stations)

# Harita Boyama (Graph Coloring)
# Graf yapısı: Eyaletler ve komşuları
usa_subset_graph = {
    "WA": {"ID", "OR"},
    "OR": {"WA", "ID", "NV", "CA"},
    "CA": {"OR", "NV", "AZ"},
    "NV": {"OR", "CA", "ID", "UT", "AZ"},
    "ID": {"WA", "OR", "NV", "UT", "MT", "WY"},
    "UT": {"NV", "ID", "WY", "CO", "AZ"},
    "AZ": {"CA", "NV", "UT", "NM"},
    "MT": {"ID", "WY", "ND", "SD"},
    "WY": {"MT", "ID", "UT", "CO", "NE", "SD"},
    "CO": {"WY", "UT", "NM", "KS", "NE"},
    "NM": {"AZ", "CO", "OK", "TX"},
    "ND": {"MT", "SD"},
    "SD": {"ND", "MT", "WY", "NE"},
    "NE": {"SD", "WY", "CO", "KS"},
    "KS": {"NE", "CO", "OK"},
    "OK": {"KS", "NM", "TX"},
    "TX": {"NM", "OK"}
}

complex_graph = {
    "Node_0": {"Node_1", "Node_2", "Node_3", "Node_4", "Node_5"},
    "Node_1": {"Node_0", "Node_2", "Node_6", "Node_7"},
    "Node_2": {"Node_0", "Node_1", "Node_3", "Node_8"},
    "Node_3": {"Node_0", "Node_2", "Node_4", "Node_9"},
    "Node_4": {"Node_0", "Node_3", "Node_5", "Node_6"},
    "Node_5": {"Node_0", "Node_4", "Node_7", "Node_8", "Node_9"},
    "Node_6": {"Node_1", "Node_4", "Node_8", "Node_9"},
    "Node_7": {"Node_1", "Node_5", "Node_8"},
    "Node_8": {"Node_2", "Node_5", "Node_6", "Node_7", "Node_9"},
    "Node_9": {"Node_3", "Node_5", "Node_6", "Node_8"}
}

def graphColor(graph):
    color = {}
    for node, neighbors in graph.items():
        forbidden_colors = set()
        for n in neighbors:
            if n in color:
                forbidden_colors.add(color[n])
        i = 0
        while True:
            if i in forbidden_colors:
                i += 1
            else:
                color[node] = i
                break
    return color

print(graphColor(usa_subset_graph))
print(graphColor(complex_graph))

        

                