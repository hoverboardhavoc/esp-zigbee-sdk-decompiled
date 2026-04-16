/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> identify.o -> zcl_message_set_identify_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t zcl_message_set_identify_attr_value(uint16_t ep_id,uint16_t identify_value)

{
  int iVar1;
  zcl_attr_desc_t *pzVar2;
  uint16_t attr_id;
  uint16_t auStack_12 [5];
  
  auStack_12[0] = identify_value;
  iVar1 = ezb_zcl_set_attr_value(ep_id & 0xff,3,1,0,0,auStack_12,0);
  if (iVar1 == 0) {
    pzVar2 = identify_srv_get_attr_desc((uint8_t)ep_id,attr_id);
    iVar1 = zcl_message_notify_attr_value(ep_id & 0xff,3,1,pzVar2);
  }
  return (ezb_zcl_status_t)iVar1;
}

