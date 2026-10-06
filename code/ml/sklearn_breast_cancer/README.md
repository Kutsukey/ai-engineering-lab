# Breast Cancer Sınıflandırma (scikit-learn)

## Problem
scikit-learn'in içinde gelen breast cancer veri setini kullandım. 569 hasta örneği var ve her biri için 30 ölçüm var. Hedef tümörün iyi huylu mu kötü huylu mu olduğunu tahmin etmek. Örneklerin 357'si iyi huylu, 212'si kötü huylu.

Bu problemde kötü huylu bir tümöre iyi huylu demek, iyi huylu bir tümöre kötü huylu demekten çok daha tehlikeli. O yüzden sadece accuracy'ye bakmadım.

## Ne yaptım
Veriyi %80 eğitim, %20 test olarak böldüm. random_state=31 kullandım ki her çalıştırmada aynı bölme çıksın. stratify ile iki sınıfın oranı iki tarafta da aynı kaldı. Test setine en sona kadar dokunmadım, çünkü modeli test sonucuna bakarak seçseydim test sonucu olduğundan iyi görünürdü.

most_frequent kullanan dummy model ile baseline koydum. Doğruluğu 0.626 çıktı. Diğer modellerin bunun üstünde olması lazım, yoksa bir şey öğrenmemişler demek.

Sonra üç modeli eğitim setinde katmanlı cross validation ile karşılaştırdım: logistic regression, decision tree ve random forest. Logistic regression için StandardScaler kullandım.

## Sonuçlar
Cross validation (ortalama, std): logistic regression 0.985, 0.009. Random forest 0.960, 0.005. Decision tree 0.943, 0.019.

En iyisi logistic regression çıktı, onu test setinde bir kere denedim. 114 örneğin 110'unu doğru bildi (accuracy 0.965). İyi huylu 72 örneğin hepsini doğru buldu. Kötü huylu 42 örneğin 38'ini buldu, 4 tanesine iyi huylu dedi. Yani kötü huylu için recall 0.90.

Logistic regression'ın neden kazandığından tam emin değilim. Veri küçük olduğu için basit model yetmiş olabilir diye düşünüyorum ama bunu kontrol etmedim.

## Öğrendiklerim
Default cross validation eğitim setini 5 parçaya bölüyor, 4 parçayla eğitip 1 parçayla deniyor ve bunu 5 kez tekrar ediyor. Amaç modelleri test setine dokunmadan karşılaştırmak. Ortalama başarıyı, std de 5 sonucun birbirinden ne kadar farklı çıktığını gösteriyor.

Logistic regression gradient descent ile eğitildiği için büyük sayılı sütunlar öğrenmeyi bozabiliyor, ölçekleyince hepsi aynı büyüklüğe geliyor. Ağaçlar sadece büyüktür küçüktür diye sorup ayırdığı için ölçekten etkilenmiyor.

Recall gerçekte kötü huylu olan hastaların yüzde kaçını yakaladığımız demek (38/42).

## Denemediklerim
Karar eşiğini düşürmeyi denemedim. Model "kötü huylu olasılığı 0.5'in üstündeyse kötü huylu de" diyor, bu eşiği 0.3 gibi bir sayıya çekersem daha fazla kötü huylu yakalarım ama iyi huyluya yanlış alarm da artar. Sonra bakacağım.

## Nasıl çalıştırılır
pip install scikit-learn pandas
python main.py
