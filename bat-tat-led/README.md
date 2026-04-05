# STM32 LED Control (Register Level)

##  Giới thiệu
Chương trình điều khiển bật/tắt LED trên vi điều khiển STM32 bằng cách thao tác trực tiếp với thanh ghi.

##  Kiến thức sử dụng
- Lập trình thanh ghi (Register-level programming)
- GPIO trên STM32
- Sử dụng thanh ghi:
  - **BSRR (Bit Set Reset Register)**: bật LED
  - **BRR (Bit Reset Register)**: tắt LED

##  Chức năng
- Bật LED bằng BSRR
- Tắt LED bằng BRR

## 🛠️ Phần cứng
- STM32 (ví dụ: STM32F4xx)
- LED + điện trở

## Cấu trúc
- `main.c`: chương trình chính

## Cách chạy
1. Nạp code vào STM32
2. Quan sát LED thay đổi trạng thái

##  Ghi chú
- BSRR giúp set/reset bit nhanh, tránh read-modify-write
- BRR dùng để reset bit (tắt LED)
