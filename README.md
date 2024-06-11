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

Kode Tambahan:
<<
dialog.ui:
</widget>
  <widget class="QTextEdit" name="textEdit">
   <property name="geometry">
    <rect>
     <x>10</x>
     <y>510</y>
     <width>61</width>
     <height>31</height>
    </rect>
   </property>
   <property name="font">
    <font>
     <family>Times New Roman</family>
    </font>
   </property>
  </widget>
>>
