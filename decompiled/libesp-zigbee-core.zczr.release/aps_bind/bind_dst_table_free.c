/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> bind_dst_table_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bind_dst_table_free(short *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  short *psVar4;
  undefined4 uVar5;
  
  if ((char)param_1[2] != '\0') {
    param_1 = (short *)__assert_func(0,0,0,0);
  }
  if ((((ushort)param_1[2] >> 8 & 1) == 0) && (*param_1 != -1)) {
    nwk_address_unlock_ref();
  }
  iVar1 = core_globals_get();
  psVar4 = *(short **)(iVar1 + 0x974);
  iVar1 = core_globals_get();
  uVar5 = *(undefined4 *)(iVar1 + 0x978);
  iVar1 = core_globals_get();
  uVar2 = (uint)*(ushort *)(iVar1 + 0x97c);
  if (param_1 < psVar4) {
    uVar2 = mempool_free_ent_part_0();
  }
  uVar3 = ((int)param_1 - (int)psVar4) / 6 & 0xffff;
  if (uVar3 < uVar2) goto _L26;
  do {
    uVar3 = 0;
    uVar5 = __assert_func(0,0,0,0);
_L26:
    iVar1 = test_and_clr_bitmap(uVar3,uVar5);
  } while (iVar1 == 0);
  return;
}

