/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> test_utils.o -> ezb_nwk_set_neighbor_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_nwk_set_neighbor_info(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_28 [20];
  
  iVar1 = nwk_neighbor_table_get_by_short();
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  else {
    *(ushort *)(iVar1 + 0xe) =
         (ushort)((param_2 & 7) << 10) | (ushort)(param_1 << 2) | *(ushort *)(iVar1 + 0xe) & 0xe003;
    uVar2 = nwk_cost_2_lqa(param_3);
    nwk_neighbor_clear_lqa(iVar1);
    uVar3 = nwk_lqa_to_rssi(uVar2);
    nwk_neighbor_update_lqa(iVar1,uVar2,uVar3);
    nwk_neighbor_get_extaddr(iVar1,auStack_28);
    uVar2 = mac_filter_add_lqa(auStack_28,uVar2);
  }
  return uVar2;
}

