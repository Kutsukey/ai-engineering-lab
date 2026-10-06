# Sıfırdan Gradient Descent

## Problem
Veri noktaları: (x=1, y=3) ve (x=2, y=5). Modelim y = w*x + b. Loss olarak hatanın karesinin ortalamasını aldım. w ve b'yi sıfırdan başlatıp lr=0.1 ile güncelledim.

## Formüller
Hata = tahmin - y. Loss = hataların karesinin ortalaması. Zincir kuralı ile kağıtta türevleri çıkardım.
dL/dw = mean(2 * hata * x)
dL/db = mean(2 * hata)
Güncelleme: w = w - lr * dL/dw ve b = b - lr * dL/db.

## İki sürüm
manual_loop.py saf Python ile yazıldı, türevleri formülle elle hesaplıyor. torch_loop.py PyTorch ile yazıldı, türevleri loss.backward() hesaplıyor ve w.grad, b.grad içine koyuyor. İki sürüm aynı sayıları veriyor: 1. adımda w=1.3, b=0.8, loss=17. 2. adımda w=1.71, b=1.05, loss=1.685. 1000 adımda w 2'ye, b 1'e, loss sıfıra yaklaşıyor.

## Denemeler
zero_() satırlarını silince gradient'ler üst üste eklendi. 2. adımda gradient -4.1 olması gerekirken -17.1 çıktı ve w 1.71 yerine 3.01'e gitti, loss yükselmeye başladı.

no_grad bloğunu silince PyTorch "leaf variable in-place" hatası verdi.

w -= ... yerine w = w - ... yazınca w yeni bir tensör oldu, .grad kutusu boş kaldı ve backward çalışmadı.

lr=0.5 yapınca adım hedefi aşıp öbür tarafa atladı, her atlayış daha büyük oldu ve loss 1e+70'e çıktı.

Hız denemesi: 2 elemanla 10.000 adımda torch 1,81 sn, saf Python 0,054 sn sürdü. 1 milyon elemanla 100 adımda torch 0,17 sn, saf Python 37 sn sürdü.

## Öğrendiklerim
PyTorch'un her işlem için sabit bir yükü var. Veri çok küçükken bu yük hesaptan büyük oluyor ve saf Python hızlı çıkıyor. Veri büyüyünce tek bir tensör işlemi bir milyon elemanı birden işlediği için PyTorch çok hızlı oluyor. backward() ters yönde yolları çarpıp topluyor ve sonucu .grad içine ekliyor o yüzden her adımdan sonra sıfırlamak gerekiyor.

## Hâlâ kafamı karıştıran
Loss formülünün neden bu şekilde olduğu ve basit lineer regresyonun mantığı. Sonra tekrar bakacağım.

## Nasıl çalıştırılır
pip install torch
python manual_loop.py
python torch_loop.py
