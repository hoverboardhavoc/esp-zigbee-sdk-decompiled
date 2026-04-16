/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> test_utils.o -> ezb_nwk_set_neighbor_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_nwk_set_neighbor_info
                    (uint16_t short_addr,uint8_t age,uint8_t outgoing_cost,uint8_t incoming_cost)

{
  undefined2 in_register_0000202a;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ezb_err_t eVar4;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002035;
  undefined1 auStack_28 [4];
  ezb_extaddr_t extaddr;
  
  iVar1 = nwk_neighbor_table_get_by_short(CONCAT22(in_register_0000202a,short_addr));
  if (iVar1 == 0) {
    eVar4 = 5;
  }
  else {
    *(ushort *)(iVar1 + 0xe) =
         (ushort)((outgoing_cost & 7) << 10) | (short)CONCAT31(in_register_0000202d,age) << 2 |
         *(ushort *)(iVar1 + 0xe) & 0xe003;
    uVar2 = nwk_cost_2_lqa(CONCAT31(in_register_00002035,incoming_cost));
    nwk_neighbor_clear_lqa(iVar1);
    uVar3 = nwk_lqa_to_rssi(uVar2);
    nwk_neighbor_update_lqa(iVar1,uVar2,uVar3);
    nwk_neighbor_get_extaddr(iVar1,auStack_28);
    eVar4 = mac_filter_add_lqa(auStack_28,uVar2);
  }
  return eVar4;
}

