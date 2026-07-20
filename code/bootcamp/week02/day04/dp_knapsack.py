# Knapsack Problem

example_items = {
    "Laptop": {"weight": 2, "value": 3000},
    "Telefon": {"weight": 1, "value": 1500},
    "Saat": {"weight": 1, "value": 2000},
    "Gitar": {"weight": 4, "value": 4000},
    "Tablo": {"weight": 3, "value": 3500}
}

def knapsack(items, cap):
    rows = list(items.keys())
    min_weight = min(items.values(), key=lambda x: x["weight"])["weight"]
    cols = round(cap / min_weight)

    table = [[0 for _ in range(cols + 1)] for _ in range(len(rows) + 1)]
    
    i, j = 1, 0
    while i < len(table):
        weight = items[rows[i-1]]["weight"]
        value = items[rows[i-1]]["value"]
        while j < len(table[0]):
            if weight <= j * min_weight:
                rem_index = int(j - weight/min_weight)
                table[i][j] = max(table[i-1][j], value + table[i-1][rem_index])
            else:
                 table[i][j] = table[i-1][j]
            j += 1
        i += 1
        j = 0
    
    j = len(table[0]) - 1
    i = len(table) - 1
    selected = []
    while i > 0:
        current_item = rows[i-1]
        weight = items[current_item]["weight"]
        if table[i][j] == table[i-1][j]:
            i -= 1
        else:
            selected.append(current_item)
            j = int(j - weight/min_weight)
            i -= 1

    return table, selected

table,selected = knapsack(example_items,4)

print(table[-1][-1])
print(selected)
