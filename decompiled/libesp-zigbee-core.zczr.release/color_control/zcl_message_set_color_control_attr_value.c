/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> zcl_message_set_color_control_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
zcl_message_set_color_control_attr_value(uint8_t ep_id,uint16_t attr_id,void *value)

{
  ezb_zcl_status_t eVar1;
  undefined3 in_register_00002029;
  zcl_attr_desc_t *pzVar2;
  undefined3 extraout_var;
  zcl_attr_desc_t *pzVar3;
  zcl_attr_desc_t *attr_desc;
  
  pzVar2 = color_control_srv_get_attr_desc(ep_id,attr_id);
  pzVar3 = pzVar2;
  if (pzVar2 != (zcl_attr_desc_t *)0x0) {
    eVar1 = color_control_srv_set_attr_value(ep_id,attr_id,(uint8_t *)value);
    pzVar3 = (zcl_attr_desc_t *)CONCAT31(extraout_var,eVar1);
    if (pzVar3 == (zcl_attr_desc_t *)0x0) {
      eVar1 = zcl_message_notify_attr_value(CONCAT31(in_register_00002029,ep_id),0x300,1,pzVar2);
      return eVar1;
    }
  }
  return (ezb_zcl_status_t)pzVar3;
}

