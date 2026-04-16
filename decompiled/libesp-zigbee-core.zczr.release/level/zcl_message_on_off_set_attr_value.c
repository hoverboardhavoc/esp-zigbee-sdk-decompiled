/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> zcl_message_on_off_set_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t zcl_message_on_off_set_attr_value(uint8_t ep_id,_Bool on_off)

{
  undefined3 in_register_00002029;
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_11 [9];
  
  auStack_11[0] = on_off;
  iVar1 = zcl_set_attr_value(6,1,0,0,auStack_11,0);
  if (iVar1 == 0) {
    uVar2 = ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),6,1,0,0);
    iVar1 = zcl_message_notify_attr_value(CONCAT31(in_register_00002029,ep_id),6,1,uVar2);
  }
  return (ezb_zcl_status_t)iVar1;
}

