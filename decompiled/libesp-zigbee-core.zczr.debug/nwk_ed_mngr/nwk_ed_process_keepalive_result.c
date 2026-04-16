/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_ed_process_keepalive_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_ed_process_keepalive_result(_Bool success)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined3 in_register_00002029;
  int iVar4;
  uint32_t uVar5;
  
  iVar4 = core_globals_get();
  milli_timer_stop(iVar4 + 0xae4);
  iVar4 = core_globals_get();
  uVar2 = *(uint *)(iVar4 + 0xaf8) >> 7 & 1;
  if (uVar2 == 0) {
    return;
  }
  iVar4 = core_globals_get();
  if ((*(byte *)(iVar4 + 0xa28) & 1) == 0) {
    iVar4 = core_globals_get();
    if ((*(byte *)(iVar4 + 0xa28) & 2) == 0) {
      iVar4 = core_globals_get();
      uVar2 = (uint)*(byte *)(iVar4 + 0x9ee);
      if (uVar2 != 0) {
        nwk_pim_stop_poll();
        uVar2 = 0;
      }
    }
    else {
      iVar4 = core_globals_get();
      bVar1 = *(byte *)(iVar4 + 0x9ee);
      if (bVar1 != 0) {
        nwk_pim_stop_poll();
        uVar2 = (uint)bVar1;
      }
    }
  }
  else {
    nwk_pim_start_poll();
    uVar2 = 0;
  }
  if (CONCAT31(in_register_00002029,success) == 0) {
    iVar4 = core_globals_get();
    if ((*(byte *)(iVar4 + 0xaf8) & 0x40) == 0) goto _L0;
    iVar4 = core_globals_get();
    uVar3 = *(uint *)(*(int *)(iVar4 + 0xac4) + 0x18);
    uVar5 = nwk_ed_get_keepalive_interval();
    if ((uVar3 & 0xfffff) <= uVar5 / 1000) {
      nwk_pim_stop_poll();
      nwk_raise_parent_link_failure();
      return;
    }
    uVar5 = nwk_ed_get_keepalive_interval();
    iVar4 = core_globals_get();
    uVar3 = *(uint *)(*(int *)(iVar4 + 0xac4) + 0x18);
    *(uint *)(*(int *)(iVar4 + 0xac4) + 0x18) =
         uVar3 & 0xfff00000 | (uVar3 & 0xfffff) - uVar5 / 1000 & 0xfffff;
  }
  else {
    iVar4 = core_globals_get();
    nwk_neighbor_zed_keepalive(*(undefined4 *)(iVar4 + 0xac4));
  }
  if (uVar2 == 0) {
    return;
  }
_L0:
  iVar4 = core_globals_get();
  *(byte *)(iVar4 + 0xaf8) = *(byte *)(iVar4 + 0xaf8) & 0xc0;
  iVar4 = core_globals_get();
  uVar5 = nwk_ed_get_keepalive_interval();
  milli_timer_start(iVar4 + 0xae4,uVar5);
  return;
}

