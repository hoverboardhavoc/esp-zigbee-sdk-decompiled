/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> zcl_message_level_set_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t zcl_message_level_set_attr_value(uint8_t ep_id,uint8_t level)

{
  ezb_zcl_status_t eVar1;
  undefined3 in_register_00002029;
  undefined3 extraout_var;
  zcl_attr_desc_t *pzVar2;
  int iVar3;
  uint8_t *in_a2;
  uint8_t auStack_11 [9];
  
  auStack_11[0] = level;
  eVar1 = level_srv_set_attr_value(ep_id,(uint16_t)auStack_11,in_a2);
  iVar3 = CONCAT31(extraout_var,eVar1);
  if (iVar3 == 0) {
    pzVar2 = level_srv_get_attr_desc(ep_id,0);
    iVar3 = zcl_message_notify_attr_value(CONCAT31(in_register_00002029,ep_id),8,1,pzVar2);
  }
  return (ezb_zcl_status_t)iVar3;
}

