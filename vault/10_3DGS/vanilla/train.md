satır 50 GaussianModel oluşturuluyor.
- dataset.sh_degree alıyor. max'a atanıyor. ne bilmiyorum.

- optimizer_type alıyor.  "default" ya da "sparse_adam"


satır 51 Scene oluşturuluyor. dataset ve gaussians arg olarak alıyor. İçini anlamadım.

training_setup çağırılıyor.

iterasyonlar başlıyor.

torch record çağırılıyor. (89)

her 1k iter sonrası SH arttırılıyor.

Render alınıyor. (106-116)

l1_loss ile Loss hesaplanıyor. (119-126)

Depth regularization yapılıyor. (129-140)

loss.backward() çağırlıyor. (142)

146-190 torch.no_grad() ile bir şeyler.

...Logger ve main.