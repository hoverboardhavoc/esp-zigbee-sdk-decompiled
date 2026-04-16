/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_conflicts.o -> nwk_change_network_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_change_network_address(ezb_shortaddr_t new_addr)

{
  undefined2 uVar1;
  undefined2 in_register_0000202a;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 uStack_16;
  undefined1 uStack_14;
  undefined1 uStack_13;
  nwk_addr_ref_t addr_ref;
  nwk_network_status_cmd_t cmd;
  
  nwk_set_short_address(CONCAT22(in_register_0000202a,new_addr));
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
  addr_ref._0_1_ = (undefined1)((ushort)uVar1 >> 8);
  addr_ref._1_1_ = 0;
  uStack_14 = 0x10;
  nwk_handle_network_status_local(&uStack_14);
  return;
}

