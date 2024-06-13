https://mf234.blogspot.com/2024/06/research-analysis-of-arduino-radar.html#more

Perubahan 11 November 2024

Fitur Baru:
> Laser: Menyala ketika objek terdeteksi dalam jarak kurang dari 50 cm.

Perubahan pada Arduino:
> Ditambahkan pin untuk mengontrol laser dan dikonfigurasi sebagai output.
>  >
> Fungsi baru stopAndActivateLaser():
  >> Menyalakan laser selama 2 detik.
>  > 
  >> Menghentikan servo sementara.
>  > 
  >> Mematikan laser.
>  >
> Fungsi dipanggil di loop utama jika jarak < 50 cm.

Perubahan pada Aplikasi Qt:
> Variabel baru:
> >
  >> Status aktivasi laser.
> >
  >> Mode operasi otomatis.
> >
> Timer baru:
> >
  >> laserTimer: Mengaktifkan laser selama 2 detik.
> >
  >> resumeTimer: Melanjutkan operasi normal setelah 2 detik.
> >
> Fungsi baru:
> >
  >> handleLaserActivation(): Menangani aktivasi laser.
> >
  >> resumeOperation(): Melanjutkan operasi normal.
> >
  >> updateLaserStatus(): Memperbarui status laser di UI.
> >
> Logika readSerial() diperbarui:
> >
  >> Menangani aktivasi laser berdasarkan jarak.
> >
  >> Mengatur status laser dengan benar.
> >
> Fungsi updateDetectionPoint():
> >
  >> Tidak memperbarui titik deteksi saat laser aktif.
> >
>textEdit ditambahkan ke UI untuk menampilkan status laser ("Laser: On" atau "Laser: Off").

Hasil:
Aplikasi radar dapat mengaktifkan laser selama 2 detik jika objek terdeteksi dalam jarak 50 cm.
Servo berhenti saat laser aktif.
Status laser ditampilkan di UI.
Operasi normal dilanjutkan setelah 2 detik.

============================================================================================

## Perbaikan dan Perubahan Radar - 13 Juni 2024

Halo! Dalam iterasi pengembangan radar kali ini, saya fokus pada peningkatan realisme dan pengalaman pengguna. Berikut adalah perubahan yang saya lakukan:

**1. Pergerakan Servo Otomatis:**

* Servo sekarang berosilasi secara otomatis dari 0 hingga 180 derajat dan kembali lagi.
* Sebelumnya, pergerakan servo hanya bisa diatur secara manual.
* Perubahan ini menghasilkan simulasi yang lebih realistis dan alami.

**2. Kontrol Servo yang Ditingkatkan:**

* Variabel `servoIncreasing` ditambahkan untuk melacak arah pergerakan servo.
* Fungsi `loop()` di Arduino dimodifikasi dengan logika baru untuk mengontrol servo berdasarkan `servoIncreasing`.
* Fungsi `updateServoAuto()` di Qt juga diperbarui untuk mendukung osilasi servo.

**3. Mempertahankan Status Mode Otomatis dan Keadaan Slider:**

* Status mode otomatis dan keadaan slider sekarang disimpan sebelum aktivasi laser.
* Status dan keadaan ini dipulihkan setelah laser dimatikan.
* Hal ini mencegah perubahan yang tidak diinginkan pada pengaturan saat laser aktif.

**4. Peningkatan Lainnya:**

* Fungsi `setSliderEnabled()` ditambahkan untuk mengaktifkan/menonaktifkan slider.
* Fungsi `handleLaserActivation()` dimodifikasi untuk memulihkan status dan keadaan sebelumnya.
* Fungsi `readSerial()` diperbarui untuk menyimpan status dan keadaan sebelum aktivasi laser.
* Fungsi `on_button_auto_clicked()` dimodifikasi untuk menyimpan status mode otomatis.

**Hasil:**

* Simulasi radar yang lebih realistis dan menarik.
* Pengalaman pengguna yang lebih baik dengan kontrol yang intuitif.
* Pergerakan servo yang otomatis dan mulus.
* Status dan pengaturan yang terjaga saat laser aktif.

**Kesimpulan:**

Perubahan ini meningkatkan realisme dan kegunaan simulasi radar secara signifikan. Pengguna sekarang dapat menikmati pengalaman yang lebih imersif dan mudah dikendalikan.

**Catatan:**

* Pastikan untuk mengimplementasikan fungsi yang disebutkan dalam ringkasan (misalnya `setSliderEnabled()`, dll.) sesuai dengan logika aplikasi Anda.

