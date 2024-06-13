https://mf234.blogspot.com/2024/06/research-analysis-of-arduino-radar.html#more

# Peningkatan Fungsionalitas dan Pengalaman Pengguna pada Simulasi Radar Arduino dengan Fitur Laser: Sebuah Studi Eksperimental

## Abstrak

Dalam penelitian ini, kami mengeksplorasi peningkatan lebih lanjut pada simulasi radar Arduino yang sebelumnya telah dikembangkan. Tujuan utama dari studi ini adalah untuk meningkatkan realisme dan pengalaman pengguna melalui penambahan fitur baru dan penyempurnaan kontrol. Perubahan yang dilakukan meliputi implementasi laser yang diaktifkan berdasarkan jarak objek, pergerakan servo yang otomatis dan lebih realistis, serta penyempurnaan kontrol dan penyimpanan status aplikasi selama aktivasi laser. Hasil eksperimen menunjukkan peningkatan yang signifikan dalam hal realisme dan kegunaan simulasi radar, memberikan pengalaman yang lebih imersif dan intuitif bagi pengguna.

## Pendahuluan

Simulasi radar Arduino telah terbukti menjadi alat yang berharga dalam memvisualisasikan dan memahami prinsip-prinsip dasar radar. Namun, untuk mencapai tingkat realisme dan pengalaman pengguna yang lebih tinggi, perlu dilakukan peningkatan lebih lanjut pada simulasi tersebut. Studi ini berfokus pada penambahan fitur laser yang diaktifkan berdasarkan jarak objek, serta peningkatan pergerakan servo dan kontrol aplikasi.

Penambahan fitur laser yang diaktifkan berdasarkan jarak objek bertujuan untuk memberikan visualisasi yang lebih realistis dan menarik. Dengan adanya laser yang menyala ketika objek terdeteksi dalam jarak tertentu, pengguna dapat memperoleh pengalaman yang lebih imersif dalam mengamati perilaku radar.

Selain itu, pergerakan servo yang sebelumnya statis diubah menjadi pergerakan yang otomatis dan mulus. Pergerakan ini dimodelkan untuk meniru osilasi yang terjadi pada radar sebenarnya, memberikan simulasi yang lebih realistis dan dinamis.

Terakhir, penyempurnaan kontrol dan penyimpanan status aplikasi selama aktivasi laser dilakukan untuk meningkatkan pengalaman pengguna dan menjaga konsistensi pengaturan. Dengan adanya penyimpanan status sebelum aktivasi laser dan pemulihan status setelahnya, perubahan yang tidak diinginkan pada pengaturan dapat dicegah, memberikan kontrol yang lebih intuitif dan pengalaman pengguna yang lebih baik.

## Metodologi

### Implementasi Fitur Laser

Fitur laser diimplementasikan dengan menambahkan pin baru pada Arduino untuk mengontrol laser dan mengonfigurasinya sebagai output. Sebuah fungsi baru, ditambahkan untuk menyalakan laser selama periode waktu tertentu (dalam kasus ini, 2 detik), menghentikan servo sementara, dan kemudian mematikan laser kembali. Fungsi ini dipanggil di dalam loop utama ketika jarak objek yang terdeteksi kurang dari batas tertentu (dalam kasus ini, 50 cm).

Pada aplikasi Qt, variabel baru ditambahkan untuk menyimpan status aktivasi laser dan mode operasi otomatis. Timer baru, `laserTimer` dan `resumeTimer`, juga ditambahkan untuk mengaktifkan laser selama periode waktu yang ditentukan dan melanjutkan operasi normal setelahnya. Fungsi `handleLaserActivation()`, `resumeOperation()`, dan `updateLaserStatus()` ditambahkan untuk menangani aktivasi laser, melanjutkan operasi normal, dan memperbarui status laser di antarmuka pengguna (UI). Logika `readSerial()` diperbarui untuk menangani aktivasi laser berdasarkan jarak dan mengatur status laser dengan benar. Terakhir, sebuah `textEdit` ditambahkan ke UI untuk menampilkan status laser secara real-time.

### Pergerakan Servo Otomatis

Untuk meningkatkan realisme simulasi, servo sekarang berosilasi secara otomatis dari 0 hingga 180 derajat dan kembali lagi ke 0 derajat. Sebuah variabel baru, `servoIncreasing`, ditambahkan untuk melacak arah pergerakan servo. Fungsi `loop()` di Arduino dimodifikasi dengan logika baru untuk mengontrol servo berdasarkan nilai `servoIncreasing`. Fungsi `updateServoAuto()` di Qt juga diperbarui untuk mendukung osilasi servo yang otomatis.

### Kontrol Servo yang Ditingkatkan dan Penyimpanan Status

Untuk meningkatkan pengalaman pengguna, status mode otomatis dan keadaan slider disimpan sebelum aktivasi laser, dan dipulihkan setelah laser dimatikan. Hal ini mencegah perubahan yang tidak diinginkan pada pengaturan saat laser aktif. Sebuah fungsi baru, `setSliderEnabled()`, ditambahkan untuk mengaktifkan atau menonaktifkan slider. Fungsi `handleLaserActivation()` dimodifikasi untuk memulihkan status dan keadaan sebelumnya setelah laser dimatikan. Fungsi `readSerial()` diperbarui untuk menyimpan status dan keadaan sebelum aktivasi laser. Fungsi `on_button_auto_clicked()` dimodifikasi untuk menyimpan status mode otomatis saat tombol ditekan.

## Hasil dan Diskusi

Perubahan yang dilakukan dalam penelitian ini meningkatkan realisme dan kegunaan simulasi radar secara signifikan. Pengguna sekarang dapat menikmati pengalaman yang lebih imersif dan mudah dikendalikan. Fitur laser yang diaktifkan berdasarkan jarak objek memberikan visualisasi yang lebih realistis dan menarik. Pengguna dapat mengamati perilaku laser secara real-time, memberikan pemahaman yang lebih baik tentang bagaimana radar bekerja dalam mendeteksi objek.

Pergerakan servo yang otomatis dan mulus juga meningkatkan realisme simulasi secara signifikan. Osilasi yang menyerupai pergerakan radar sebenarnya memberikan gambaran yang lebih akurat tentang bagaimana radar mengayunkan antenanya untuk memindai area yang lebih luas.

Kontrol yang ditingkatkan dan penyimpanan status aplikasi selama aktivasi laser memastikan pengalaman pengguna yang lebih baik dan konsisten. Dengan adanya penyimpanan status sebelum aktivasi laser dan pemulihan status setelahnya, pengguna dapat melanjutkan simulasi tanpa perlu mengatur ulang pengaturan yang telah mereka pilih sebelumnya. Hal ini memberikan kontrol yang lebih intuitif dan mengurangi friksi dalam penggunaan simulasi.

## Kesimpulan dan Pekerjaan Masa Depan

Penelitian ini berhasil meningkatkan fungsionalitas dan pengalaman pengguna pada simulasi radar Arduino dengan menambahkan fitur laser, pergerakan servo otomatis, dan penyempurnaan kontrol serta penyimpanan status aplikasi. Peningkatan ini memberikan simulasi yang lebih realistis dan menarik, serta meningkatkan kegunaan dan kemudahan penggunaan. Hasil eksperimen menunjukkan bahwa perubahan yang dilakukan mampu memberikan visualisasi yang lebih akurat dan pengalaman pengguna yang lebih baik dalam memahami prinsip-prinsip dasar radar.

Untuk penelitian masa depan, beberapa area yang dapat dijelajahi lebih lanjut meliputi:

1. Penambahan fitur-fitur tambahan untuk meningkatkan realisme simulasi, seperti pemodelan lingkungan yang lebih kompleks, penanganan objek bergerak, atau integrasi dengan data radar yang sebenarnya.
