/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_ed_process_keepalive_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_ed_process_keepalive_result(_Bool success)

{
  undefined4 uVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined3 in_register_00002029;
  int iVar4;
  uint32_t uVar5;
  uint uVar6;
  undefined4 uStack_24;
  nwk_network_status_cmd_t cmd;
  
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
      if (*(char *)(iVar4 + 0x9ee) != '\0') {
        nwk_pim_stop_poll();
      }
      goto _L0;
    }
    iVar4 = core_globals_get();
    if (*(char *)(iVar4 + 0x9ee) != '\0') {
      nwk_pim_stop_poll();
    }
  }
  else {
    nwk_pim_start_poll();
_L0:
    uVar2 = 0;
  }
  if (CONCAT31(in_register_00002029,success) == 0) {
    iVar4 = core_globals_get();
    if ((*(byte *)(iVar4 + 0xaf8) & 0x40) == 0) goto _L0;
    iVar4 = core_globals_get();
    uVar6 = *(uint *)(*(int *)(iVar4 + 0xac4) + 0x14);
    uVar5 = nwk_ed_get_keepalive_interval();
    if ((uVar6 & 0xfffff) <= uVar5 / 1000) {
      nwk_pim_stop_poll();
      uStack_24 = 9;
      uVar3 = nwk_get_parent_shortaddr();
      uVar1 = uStack_24;
      uStack_24._3_1_ = SUB41(uVar1,3);
      uStack_24._0_3_ =
           CONCAT12((char)((ushort)uVar3 >> 8),CONCAT11((char)uVar3,(undefined1)uStack_24));
      nwk_handle_network_status_local(&uStack_24);
      return;
    }
    uVar5 = nwk_ed_get_keepalive_interval();
    iVar4 = core_globals_get();
    uVar6 = *(uint *)(*(int *)(iVar4 + 0xac4) + 0x14);
    *(uint *)(*(int *)(iVar4 + 0xac4) + 0x14) =
         uVar6 & 0xfff00000 | (uVar6 & 0xfffff) - uVar5 / 1000 & 0xfffff;
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

