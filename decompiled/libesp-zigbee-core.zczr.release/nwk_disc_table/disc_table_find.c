/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_disc_table.o -> disc_table_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * disc_table_find(int param_1,uint param_2,uint param_3,void *param_4)

{
  void *__s1;
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    uVar2 = bitmap_find_next_bit(param_1 + 0x78,6,uVar2);
    if (5 < uVar2) {
      return (void *)0x0;
    }
    __s1 = (void *)(uVar2 * 0x14 + param_1);
    if (((*(byte *)((int)__s1 + 8) == param_2) &&
        (param_3 == (*(uint *)((int)__s1 + 0x10) >> 0x1d & 1))) &&
       (iVar1 = memcmp(__s1,param_4,8), iVar1 == 0)) break;
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return __s1;
}

