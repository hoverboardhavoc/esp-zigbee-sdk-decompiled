/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_ed_process_keepalive_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_ed_process_keepalive_result(int param_1)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uStack_24;
  
  iVar3 = core_globals_get();
  milli_timer_stop(iVar3 + 0xae4);
  iVar3 = core_globals_get();
  uVar1 = *(uint *)(iVar3 + 0xaf8) >> 7 & 1;
  if (uVar1 == 0) {
    return;
  }
  iVar3 = core_globals_get();
  if ((*(byte *)(iVar3 + 0xa28) & 1) == 0) {
    iVar3 = core_globals_get();
    if ((*(byte *)(iVar3 + 0xa28) & 2) == 0) {
      iVar3 = core_globals_get();
      if (*(char *)(iVar3 + 0x9ee) != '\0') {
        nwk_pim_stop_poll();
      }
      goto _L0;
    }
    iVar3 = core_globals_get();
    if (*(char *)(iVar3 + 0x9ee) != '\0') {
      nwk_pim_stop_poll();
    }
  }
  else {
    nwk_pim_start_poll();
_L0:
    uVar1 = 0;
  }
  if (param_1 == 0) {
    iVar3 = core_globals_get();
    if ((*(byte *)(iVar3 + 0xaf8) & 0x40) == 0) goto _L0;
    iVar3 = core_globals_get();
    uVar6 = *(uint *)(*(int *)(iVar3 + 0xac4) + 0x14);
    uVar5 = nwk_ed_get_keepalive_interval();
    if ((uVar6 & 0xfffff) <= uVar5 / 1000) {
      nwk_pim_stop_poll();
      uStack_24 = 9;
      uVar2 = nwk_get_parent_shortaddr();
      uVar4 = uStack_24;
      uStack_24._3_1_ = SUB41(uVar4,3);
      uStack_24._0_3_ =
           CONCAT12((char)((ushort)uVar2 >> 8),CONCAT11((char)uVar2,(undefined1)uStack_24));
      nwk_handle_network_status_local(&uStack_24);
      return;
    }
    uVar5 = nwk_ed_get_keepalive_interval();
    iVar3 = core_globals_get();
    uVar6 = *(uint *)(*(int *)(iVar3 + 0xac4) + 0x14);
    *(uint *)(*(int *)(iVar3 + 0xac4) + 0x14) =
         uVar6 & 0xfff00000 | (uVar6 & 0xfffff) - uVar5 / 1000 & 0xfffff;
  }
  else {
    iVar3 = core_globals_get();
    nwk_neighbor_zed_keepalive(*(undefined4 *)(iVar3 + 0xac4));
  }
  if (uVar1 == 0) {
    return;
  }
_L0:
  iVar3 = core_globals_get();
  *(byte *)(iVar3 + 0xaf8) = *(byte *)(iVar3 + 0xaf8) & 0xc0;
  iVar3 = core_globals_get();
  uVar4 = nwk_ed_get_keepalive_interval();
  milli_timer_start(iVar3 + 0xae4,uVar4);
  return;
}

