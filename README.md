https://mf234.blogspot.com/2024/06/research-analysis-of-arduino-radar.html#more

[6//11/2024]
Pada perubahan kali ini, saya telah menambahkan fitur laser yang menyala ketika objek terdeteksi dalam jarak kurang dari 50 cm. Fitur ini membuat simulasi radar terasa lebih realistis dan menarik.

Di sisi Arduino, saya menambahkan pin untuk mengontrol laser dan mengonfigurasi pin tersebut sebagai output. Saya juga membuat fungsi baru `stopAndActivateLaser()` yang bertanggung jawab untuk menyalakan laser selama 2 detik, menghentikan pergerakan servo sementara, lalu mematikan laser kembali. Fungsi ini dipanggil pada loop utama jika jarak kurang dari 50 cm.

Pada aplikasi Qt, saya menambahkan variabel baru untuk melacak status aktivasi laser dan mode operasi otomatis. Saya juga menambahkan dua timer baru - `laserTimer` untuk menangani aktivasi laser selama 2 detik, dan `resumeTimer` untuk melanjutkan operasi normal setelah aktivasi laser dan jeda 2 detik.

Saya membuat beberapa fungsi baru seperti `handleLaserActivation()` untuk menangani aktivasi laser, `resumeOperation()` untuk melanjutkan operasi normal, dan `updateLaserStatus()` untuk memperbarui status laser pada antarmuka pengguna.

Logika pada fungsi `readSerial()` juga saya perbaharui untuk menangani aktivasi laser berdasarkan jarak dan mengatur status laser dengan benar. Fungsi `updateDetectionPoint()` saya modifikasi agar tidak memperbarui titik deteksi jika laser sedang aktif.

Terakhir, saya menambahkan `textEdit` pada antarmuka pengguna untuk menampilkan status laser ("Laser: On" atau "Laser: Off").

Dengan peningkatan ini, aplikasi radar yang saya buat sekarang memiliki kemampuan untuk mengaktifkan laser selama 2 detik jika objek terdeteksi dalam jarak 50 cm. Selama aktivasi laser, servo akan berhenti berputar sementara, dan antarmuka pengguna akan menampilkan status laser yang sesuai. Setelah aktivasi laser dan jeda 2 detik, operasi normal akan dilanjutkan.

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
