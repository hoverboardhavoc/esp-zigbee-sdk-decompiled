/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> zcl_message_on_off_set_attr_value
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
  int iVar2;
  zcl_attr_desc_t *pzVar3;
  undefined1 auStack_11 [5];
  
  auStack_11[0] = on_off;
  iVar2 = zcl_set_attr_value(6,1,0,0,auStack_11,0);
  if (iVar2 == 0) {
    pzVar3 = on_off_srv_get_attr_desc(ep_id,0);
    zcl_message_notify_attr_value(CONCAT31(in_register_00002029,ep_id),6,1,pzVar3);
    eVar1 = '\0';
  }
  else {
    eVar1 = 0x86;
  }
  return eVar1;
}

