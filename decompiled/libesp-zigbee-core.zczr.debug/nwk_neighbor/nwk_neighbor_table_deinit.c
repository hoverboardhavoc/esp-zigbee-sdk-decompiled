/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short * nwk_neighbor_table_deinit(void)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  uint uVar4;
  
  iVar1 = core_globals_get();
  iVar2 = nbt_is_inited(iVar1 + 0xb1c);
  if (iVar2 != 0) {
    mm_free(*(undefined4 *)(iVar1 + 0xb20));
    *(undefined4 *)(iVar1 + 0xb20) = 0;
    psVar3 = (short *)mm_free(*(undefined4 *)(iVar1 + 0xb1c));
    *(undefined4 *)(iVar1 + 0xb1c) = 0;
    return psVar3;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x1c3,
                        "nwk_neighbor_table_deinit",&_LC11);
  iVar2 = core_globals_get();
  psVar3 = (short *)nbt_get_new_nbr(iVar2 + 0xb1c,iVar1);
  if (iVar1 == 0) {
    if (psVar3 == (short *)0x0) {
      return (short *)0x0;
    }
  }
  else if (psVar3 == (short *)0x0) {
    psVar3 = (short *)nbt_get_stale_router(iVar2 + 0xb1c);
    if (psVar3 == (short *)0x0) {
      return (short *)0x0;
    }
    if (*psVar3 != -1) {
      nwk_address_unlock_ref();
    }
  }
  memset(psVar3,0,0x1c);
  *psVar3 = -1;
  uVar4 = *(uint *)(psVar3 + 6);
  *(uint *)(psVar3 + 6) = uVar4 | 3;
  uVar4 = uVar4 & 0xfffffc3f;
  *(uint *)(psVar3 + 6) = uVar4 | 0xc3;
  *(uint *)(psVar3 + 6) = uVar4 | 0x1c0000c3;
  nwk_neighbor_clear_lqa(psVar3);
  return psVar3;
}

