/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_disc_table.o -> nwk_disc_table_add_parent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_disc_table_add_parent(void *param_1)

{
  byte bVar1;
  void *__s;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  
  iVar2 = core_globals_get();
  uVar3 = 2;
  if (param_1 != (void *)0x0) {
    iVar4 = disc_table_find(iVar2 + 0xb2c,*(undefined1 *)((int)param_1 + 8),
                            *(uint *)((int)param_1 + 0x10) >> 0x1d & 1,param_1);
    if (iVar4 == 0) {
      uVar5 = bitmap_find_first_zero_bit(iVar2 + 0xba4,6);
      if (uVar5 < 6) {
        test_and_set_bitmap_isra_0(iVar2 + 0xba4);
        __s = (void *)(iVar2 + 0xb2c + uVar5 * 0x14);
        memset(__s,0,0x14);
      }
      else {
        bVar6 = *(byte *)((int)param_1 + 9);
        iVar2 = core_globals_get();
        uVar5 = 0;
        __s = (void *)0x0;
        while( true ) {
          uVar5 = bitmap_find_next_bit(iVar2 + 0xba4,6,uVar5);
          uVar5 = uVar5 & 0xff;
          if (5 < uVar5) break;
          bVar1 = *(byte *)(iVar2 + uVar5 * 0x14 + 0xb35);
          if (bVar1 < bVar6) {
            __s = (void *)(iVar2 + uVar5 * 0x14 + 0xb2c);
            bVar6 = bVar1;
          }
          uVar5 = uVar5 + 1 & 0xff;
        }
        if (__s == (void *)0x0) {
          return 1;
        }
      }
      memcpy(__s,param_1,0x14);
    }
    uVar3 = 0;
  }
  return uVar3;
}

