/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short * nwk_neighbor_table_init(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  short *psVar4;
  uint uVar5;
  
  iVar1 = core_globals_get();
  iVar2 = nbt_is_inited((void *)(iVar1 + 0xb1c));
  if ((iVar2 == 0) && (param_1 != 0)) {
    memset((void *)(iVar1 + 0xb1c),0,0x10);
    *(short *)(iVar1 + 0xb24) = (short)param_1;
    uVar3 = mm_calloc(param_1,0x1c);
    *(undefined4 *)(iVar1 + 0xb20) = uVar3;
    psVar4 = (short *)mm_calloc(*(ushort *)(iVar1 + 0xb24) + 7 >> 3,1);
    *(short **)(iVar1 + 0xb1c) = psVar4;
    *(short *)(iVar1 + 0xb26) = (short)(param_1 >> 1);
    return psVar4;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x1ab,
                "nwk_neighbor_table_init",&_LC11);
  iVar1 = core_globals_get();
  iVar2 = nbt_is_inited(iVar1 + 0xb1c);
  if (iVar2 != 0) {
    mm_free(*(undefined4 *)(iVar1 + 0xb20));
    *(undefined4 *)(iVar1 + 0xb20) = 0;
    psVar4 = (short *)mm_free(*(undefined4 *)(iVar1 + 0xb1c));
    *(undefined4 *)(iVar1 + 0xb1c) = 0;
    return psVar4;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x1b9,
                        "nwk_neighbor_table_deinit",&_LC11);
  iVar2 = core_globals_get();
  psVar4 = (short *)nbt_get_new_nbr(iVar2 + 0xb1c,iVar1);
  if (iVar1 == 0) {
    if (psVar4 == (short *)0x0) {
      return (short *)0x0;
    }
  }
  else if (psVar4 == (short *)0x0) {
    psVar4 = (short *)nbt_get_stale_router(iVar2 + 0xb1c);
    if (psVar4 == (short *)0x0) {
      return (short *)0x0;
    }
    if (*psVar4 != -1) {
      nwk_address_unlock_ref();
    }
  }
  memset(psVar4,0,0x1c);
  *psVar4 = -1;
  uVar5 = *(uint *)(psVar4 + 6);
  *(uint *)(psVar4 + 6) = uVar5 | 3;
  uVar5 = uVar5 & 0xfffffc3f;
  *(uint *)(psVar4 + 6) = uVar5 | 0xc3;
  *(uint *)(psVar4 + 6) = uVar5 | 0x1c0000c3;
  nwk_neighbor_clear_lqa(psVar4);
  return psVar4;
}

