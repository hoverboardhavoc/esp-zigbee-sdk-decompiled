/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_conflicts.o -> nwk_change_network_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_change_network_address(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 uStack_16;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  nwk_set_short_address();
  uVar2 = nwk_get_extended_address();
  uVar3 = nwk_get_short_address();
  iVar4 = nwk_address_update(uVar2,uVar3,&uStack_16);
  if (iVar4 != 0) {
    __assert_func(0,0,0,0);
  }
  iVar4 = nwk_neighbor_table_get_by_addr_ref(uStack_16);
  if (iVar4 != 0) {
    log_write(1,"nwk_conflicts.c",0x10000);
    nwk_neighbor_table_delete(iVar4);
  }
  uVar1 = nwk_get_short_address();
  uStack_13 = (undefined1)uVar1;
  uStack_12 = (undefined1)((ushort)uVar1 >> 8);
  uStack_11 = 0;
  uStack_14 = 0x10;
  nwk_handle_network_status_local(&uStack_14);
  return;
}

