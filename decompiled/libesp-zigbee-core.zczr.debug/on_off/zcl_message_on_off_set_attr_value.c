/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> zcl_message_on_off_set_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t zcl_message_on_off_set_attr_value(uint8_t ep_id,_Bool on_off)

{
  ezb_zcl_status_t eVar1;
  undefined3 in_register_00002029;
  zcl_attr_desc_t *pzVar2;
  int iVar3;
  undefined3 extraout_var;
  uint8_t uStack_11;
  
  uStack_11 = on_off;
  pzVar2 = on_off_srv_get_attr_desc(ep_id,0);
  if ((pzVar2 == (zcl_attr_desc_t *)0x0) ||
     (iVar3 = zcl_attr_value_is_changed(&uStack_11), iVar3 == 0)) {
    iVar3 = 0x86;
  }
  else {
    eVar1 = on_off_srv_set_attr_value(ep_id,0,&uStack_11);
    iVar3 = CONCAT31(extraout_var,eVar1);
    if (iVar3 == 0) {
      zcl_message_notify_attr_value(CONCAT31(in_register_00002029,ep_id),6,1,pzVar2);
    }
  }
  return (ezb_zcl_status_t)iVar3;
}

