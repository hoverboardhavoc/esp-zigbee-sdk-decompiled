/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_pal_callback_ed_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_pal_callback_ed_done(int param_1)

{
  int iVar1;
  undefined1 uStack_14;
  byte bStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  iVar1 = s_devices;
  if ((*(code **)(s_devices + 0x38) != (code *)0x0) && (param_1 != 0x7f)) {
    uStack_14 = *(undefined1 *)(s_devices + 0x2c);
    uStack_11 = (undefined1)param_1;
    bStack_13 = (byte)((uint)*(undefined4 *)(s_devices + 0x34) >> 0x1b);
    uStack_12 = *(undefined1 *)(s_devices + 0x32);
    (**(code **)(s_devices + 0x38))(&uStack_14,*(undefined4 *)(s_devices + 0x3c));
  }
  mac_do_ed_scan(iVar1);
  return;
}

