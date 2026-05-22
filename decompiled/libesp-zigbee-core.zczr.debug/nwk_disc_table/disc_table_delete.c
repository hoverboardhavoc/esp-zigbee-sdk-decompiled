/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> disc_table_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void disc_table_delete(nwk_disc_table_t *tbl,nwk_disc_table_ent_t *ent)

{
  _Bool _Var1;
  undefined3 extraout_var;
  void *__s1;
  uint extraout_a1;
  char *pcVar2;
  char *__s2;
  uint uVar3;
  
  uVar3 = ((int)ent - (int)tbl >> 2) * -0x33333333;
  if ((uVar3 & 0xffff) < 6) {
    _Var1 = test_and_clr_bitmap(uVar3 & 0xffff,tbl->ent_in_use);
    if (CONCAT31(extraout_var,_Var1) != 0) {
      return;
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
  if ((*(byte *)((int)__s1 + 8) == extraout_a1) &&
     ((char *)(*(uint *)((int)__s1 + 0x10) >> 0x1d & 1) == pcVar2)) {
    memcmp(__s1,__s2,8);
  }
  return;
}

