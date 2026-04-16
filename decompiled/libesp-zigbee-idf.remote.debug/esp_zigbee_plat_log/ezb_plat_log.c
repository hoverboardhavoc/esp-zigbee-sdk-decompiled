/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_log.o -> ezb_plat_log
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_plat_log(ezb_log_level_t log_level,char *format,...)

{
  undefined4 uVar1;
  undefined4 in_a2;
  undefined4 in_a3;
  undefined4 in_a4;
  undefined4 in_a5;
  undefined4 in_a6;
  undefined4 in_a7;
  char *pcVar2;
  va_list args;
  char *prefix_format [4];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  prefix_format[0] = "\x1b[0;31mE(%lu) %s: ";
  prefix_format[1] = "\x1b[0;33mW(%lu) %s: ";
  prefix_format[2] = "\x1b[0;32mI(%lu) %s: ";
  if (log_level - 1U < 3) {
    pcVar2 = prefix_format[log_level + -1];
    uStack_18 = in_a2;
    uStack_14 = in_a3;
    uStack_10 = in_a4;
    uStack_c = in_a5;
    uStack_8 = in_a6;
    uStack_4 = in_a7;
    uVar1 = esp_log_timestamp();
    esp_log_write(log_level,"ESP-ZIGBEE",pcVar2,uVar1,"ESP-ZIGBEE");
    esp_log_writev(log_level,"ESP-ZIGBEE",format,&uStack_18);
    esp_log_write(log_level,"ESP-ZIGBEE",&_LC4);
  }
  return;
}

