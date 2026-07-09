/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_handle_device_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_device_leave(undefined2 *param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  iVar1 = nwk_neighbor_table_get_by_extended(param_1 + 1);
  uStack_18 = 0;
  uStack_14 = 0;
  _uStack_1c = CONCAT22(*param_1,2);
  nwk_mm_purge_tx_queue(0xff,&uStack_1c);
  nwk_fwd_purge_ex(*param_1,0,0);
  iVar2 = nwk_is_device_zed();
  if (iVar2 == 0) {
    nwk_route_table_remove_by_dst(*param_1);
    nwk_route_table_remove_by_next_hop(*param_1);
    nwk_route_record_table_remove_by_dst(*param_1);
    nwk_route_record_table_remove_by_next_hop(*param_1);
    if (iVar1 != 0) {
      nwk_neighbor_table_delete(iVar1);
    }
  }
  else if (((iVar1 != 0) && ((*(uint *)(iVar1 + 0xc) & 0x3c0) == 0)) &&
          ((*(byte *)(param_1 + 5) & 2) != 0)) {
    nwk_do_leave(2,0,(ushort)param_1[5] >> 1 & 1);
  }
  return;
}

