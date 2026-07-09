/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> mempool_free_ent.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mempool_free_ent_part_0(void)

{
  short *psVar1;
  short asStack_48 [17];
  short sStack_26;
  char cStack_24;
  
  psVar1 = (short *)__assert_func(0,0,0,0);
  sStack_26 = 0;
  cStack_24 = '\0';
  while( true ) {
    ds_group_info_itor_read(asStack_48);
    if (cStack_24 != '\0') {
      return;
    }
    if (asStack_48[0] == *psVar1) break;
    sStack_26 = sStack_26 + 1;
  }
  ds_internal_remove_entry(5,asStack_48);
  return;
}

