/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> bind_src_table_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bind_src_table_free(short *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short *psVar5;
  undefined4 uVar6;
  
  iVar1 = bind_src_is_empty();
  if (iVar1 == 0) {
    __assert_func(0,0,0);
  }
  if (*param_1 != -1) {
    nwk_address_unlock_ref();
  }
  iVar1 = core_globals_get();
  psVar5 = *(short **)(iVar1 + 0x968);
  iVar1 = core_globals_get();
  uVar6 = *(undefined4 *)(iVar1 + 0x96c);
  iVar1 = bind_src_size();
  iVar2 = core_globals_get();
  uVar3 = (uint)*(ushort *)(iVar2 + 0x970);
  if (param_1 < psVar5) {
    uVar3 = mempool_free_ent_part_0();
  }
  uVar4 = ((int)param_1 - (int)psVar5) / iVar1 & 0xffff;
  if (uVar4 < uVar3) goto _L26;
  do {
    uVar4 = 0;
    uVar6 = __assert_func(0,0,0,0);
_L26:
    iVar1 = test_and_clr_bitmap(uVar4,uVar6);
  } while (iVar1 == 0);
  return;
}

