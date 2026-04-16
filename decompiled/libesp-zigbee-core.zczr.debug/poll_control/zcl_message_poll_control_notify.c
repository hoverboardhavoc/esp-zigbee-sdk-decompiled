/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> zcl_message_poll_control_notify
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t zcl_message_poll_control_notify(uint8_t ep_id,uint16_t attr_id,uint8_t *value)

{
  int iVar1;
  ezb_zcl_status_t eVar2;
  undefined3 in_register_00002029;
  zcl_attr_desc_t *pzVar3;
  undefined3 extraout_var;
  
  pzVar3 = poll_control_srv_get_attr_desc(ep_id,attr_id);
  if (pzVar3 == (zcl_attr_desc_t *)0x0) {
    iVar1 = 0x86;
  }
  else {
    eVar2 = poll_control_srv_set_attr_value(ep_id,attr_id,value);
    iVar1 = CONCAT31(extraout_var,eVar2);
    if (iVar1 == 0) {
      zcl_message_notify_attr_value(CONCAT31(in_register_00002029,ep_id),0x20,1,pzVar3);
    }
  }
  return (ezb_zcl_status_t)iVar1;
}

