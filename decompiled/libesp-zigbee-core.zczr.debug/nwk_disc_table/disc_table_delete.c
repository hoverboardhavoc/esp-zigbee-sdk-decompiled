/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> disc_table_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int disc_table_delete(int param_1,int param_2)

{
  int iVar1;
  void *__s1;
  uint extraout_a1;
  char *pcVar2;
  char *__s2;
  uint uVar3;
  
  uVar3 = (param_2 - param_1 >> 2) * -0x33333333;
  if ((uVar3 & 0xffff) < 6) {
    iVar1 = test_and_clr_bitmap(uVar3 & 0xffff,param_1 + 0x78);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_disc_table.c",0x56,
                  "disc_table_delete","idx < 6");
  }
  __s2 = "test_and_clr_bitmap(idx, tbl->ent_in_use)";
  pcVar2 = "disc_table_delete";
  __s1 = (void *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_disc_table.c",
                               0x57,"test_and_clr_bitmap(idx, tbl->ent_in_use)");
  if (*(byte *)((int)__s1 + 8) == extraout_a1) {
    if ((char *)(*(uint *)((int)__s1 + 0x10) >> 0x1d & 1) == pcVar2) {
      iVar1 = memcmp(__s1,__s2,8);
      if (iVar1 == 0) {
        iVar1 = 1;
      }
      else {
        iVar1 = 0;
      }
    }
    else {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

