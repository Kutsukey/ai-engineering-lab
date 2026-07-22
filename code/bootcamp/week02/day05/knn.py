def knn(points, query, k):
    distances = []
    for point,name in points:
        total = 0
        for i in range(len(point)):
            total += (query[i] - point[i])**2
        distance = total ** 0.5
        distances.append((distance,name))
    distances.sort()
    k_list = distances[:k]
    counts = {}
    for _,n in k_list:
        counts[n] = counts.get(n,0) + 1

    return max(counts, key=lambda x:counts[x])

def knn_regression(points, query, k):
    distances = []
    for point,name in points:
        total = 0
        for i in range(len(point)):
            total += (query[i] - point[i])**2
        distance = total ** 0.5
        distances.append((distance,name))
    distances.sort()
    k_list = distances[:k]
    counts = {}
    total_v = sum(target for _, target in k_list)
    return total_v/k


#örnekler
points = [
    ([1, 2], "A"),
    ([2, 3], "A"),
    ([8, 8], "B"),
]

query = [3, 2]
k = 3

print(knn(points,query,k))

# Veri seti: ( [x, y], Etiket )
points = [
    ([1, 2], "A"),
    ([2, 3], "A"),
    ([3, 1], "A"),
    ([8, 8], "B"),
    ([9, 7], "B"),
    ([7, 9], "B")
]

# Test 1: A kümesine yakın bir nokta
query_1 = [2, 2]
print("Sorgu [2, 2] Tahmini:", knn(points, query_1, k=3))  # Çıktı: A

# Test 2: B kümesine yakın bir nokta
query_2 = [8, 7]
print("Sorgu [8, 7] Tahmini:", knn(points, query_2, k=3))  # Çıktı: B

fruits = [
    ([140, 7], "Elma"),
    ([130, 8], "Elma"),
    ([150, 6], "Elma"),
    ([170, 2], "Portakal"),
    ([180, 3], "Portakal"),
    ([160, 1], "Portakal")
]

# Sorgu: 145 gram, Pürüzsüzlüğü 7 olan bir meyve
new_fruit = [145, 7]

pred = knn(fruits, new_fruit, k=3)
print(f"Meyve Tahmini: {pred}")  # Çıktı: Elma

customers = [
    ([18, 50, 120], "Ekonomik"),
    ([22, 60, 100], "Ekonomik"),
    ([45, 500, 30], "Premium"),
    ([50, 600, 20], "Premium"),
    ([35, 450, 40], "Premium")
]

# Sorgu: 20 yaşında, 55$ harcayan, 110 dk harcayan müşteri
new_user = [20, 55, 110]

segment = knn(customers, new_user, k=3)
print(f"Müşteri Segmenti: {segment}")  # Çıktı: Ekonomik


houses = [
    ([100, 3], 5000000),
    ([120, 3], 6000000),
    ([80, 2], 3800000),
    ([150, 4], 8500000)
]
query_house = [105, 3]
k_house = 2

house_pred = knn_regression(houses, query_house, k=k_house)

print("=== ÖRNEK 1: EV FİYATI ===")
print(f"Sorgu Noktası  : 105 m², 3 Oda")
print(f"k Değeri       : {k_house}")
print(f"Tahmini Fiyat  : {house_pred:,.2f} TL\n")


# --- ÖRNEK 2: İkinci El Araba Fiyatı Tahmini ---
# Veri: ([model_yılı, km_bin], fiyat_tl)
cars = [
    ([2020, 50], 750000),
    ([2019, 60], 700000),
    ([2022, 15], 950000),
    ([2018, 110], 550000)
]
query_car = [2020, 52]
k_car = 2

car_pred = knn_regression(cars, query_car, k=k_car)

print("=== ÖRNEK 2: ARABA FİYATI ===")
print(f"Sorgu Noktası  : 2020 Model, 52 Bin KM")
print(f"k Değeri       : {k_car}")
print(f"Tahmini Fiyat  : {car_pred:,.2f} TL\n")


# --- ÖRNEK 3: Öğrenci Sınav Notu Tahmini ---
# Veri: ([haftalık_çalışma_saati, devamsızlık_gün], sınav_notu)
students = [
    ([10, 2], 85),
    ([12, 1], 95),
    ([9, 3], 80),
    ([2, 8], 35)
]
query_student = [11, 2]
k_student = 3

student_pred = knn_regression(students, query_student, k=k_student)

print("=== ÖRNEK 3: SINAV NOTU ===")
print(f"Sorgu Noktası  : 11 Saat Çalışma, 2 Gün Devamsızlık")
print(f"k Değeri       : {k_student}")
print(f"Tahmini Not    : {student_pred:.2f}")