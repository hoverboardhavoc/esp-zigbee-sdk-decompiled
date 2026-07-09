/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ezb_zcl_ias_ace_zone_table_remove_zone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_zcl_ias_ace_zone_table_remove_zone(int param_1,int param_2)

{
  void *__s;
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 2;
  }
  else if (param_2 == 0xff) {
    uVar1 = 2;
  }
  else {
    __s = (void *)ias_ace_zone_table_get_zone();
    if (__s == (void *)0x0) {
      uVar1 = 2;
    }
    else {
      zone_table_remove_stored_zone(*(undefined1 *)(param_1 + 5),param_2);
      memset(__s,0,0x1e);
      *(undefined1 *)((int)__s + 4) = 0xff;
      *(undefined1 *)((int)__s + 5) = 0xff;
      *(undefined1 *)((int)__s + 6) = 0xff;
      *(undefined1 *)((int)__s + 7) = 0xff;
      *(undefined1 *)((int)__s + 8) = 0xff;
      *(undefined1 *)((int)__s + 9) = 0xff;
      *(undefined1 *)((int)__s + 10) = 0xff;
      *(undefined1 *)((int)__s + 0xb) = 0xff;
      *(undefined2 *)((int)__s + 2) = 0xffff;
      uVar1 = 0;
    }
  }
  return uVar1;
}

