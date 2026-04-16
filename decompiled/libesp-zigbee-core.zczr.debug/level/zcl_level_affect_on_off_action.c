/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> zcl_level_affect_on_off_action
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_level_affect_on_off_action(uint8_t ep_id,uint8_t level)

{
  zcl_attr_desc_t *pzVar1;
  zcl_attr_desc_t *pzVar2;
  undefined3 in_register_0000202d;
  uint uVar3;
  
  pzVar1 = on_off_srv_get_attr_desc(ep_id,0);
  pzVar2 = level_srv_get_attr_desc(ep_id,2);
  if (pzVar1 != (zcl_attr_desc_t *)0x0) {
    if (pzVar2 == (zcl_attr_desc_t *)0x0) {
      uVar3 = 0;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar3 = (uint)*pzVar2->data_p;
    }
    if (uVar3 < CONCAT31(in_register_0000202d,level)) {
                    /* WARNING: Load size is inaccurate */
      if (*pzVar1->data_p == '\0') {
        zcl_message_on_off_set_attr_value(ep_id,true);
      }
    }
    else {
                    /* WARNING: Load size is inaccurate */
      if (*pzVar1->data_p != '\0') {
        zcl_message_on_off_set_attr_value(ep_id,false);
      }
    }
  }
  return;
}

