/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> poll_control_source_is_exist_in_bind_table
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool poll_control_source_is_exist_in_bind_table(uint8_t ep_id,uint16_t short_addr)

{
  bool bVar1;
  undefined3 in_register_00002029;
  int iVar2;
  undefined2 in_register_0000202e;
  undefined4 uStack_18;
  ezb_extaddr_t src_addr;
  
  uStack_18 = 0;
  src_addr.field_0.u64._0_4_ = 0;
  iVar2 = nwk_address_extended_by_short(CONCAT22(in_register_0000202e,short_addr),&uStack_18);
  if (iVar2 == 0) {
    iVar2 = aps_bind_table_find_src(&uStack_18,CONCAT31(in_register_00002029,ep_id),0x20);
    bVar1 = iVar2 != 0;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

