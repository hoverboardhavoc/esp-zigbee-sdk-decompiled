/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> zcl_level_affect_on_off_action
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_level_affect_on_off_action(uint8_t ep_id,uint8_t level)

{
  undefined4 uVar1;
  undefined3 in_register_00002029;
  int iVar2;
  zcl_attr_desc_t *pzVar3;
  undefined3 in_register_0000202d;
  uint uVar4;
  undefined1 uStack_11;
  
  iVar2 = ezb_zcl_get_attr_desc(6,1,0,0);
  pzVar3 = level_srv_get_attr_desc(ep_id,2);
  if (iVar2 != 0) {
    uVar4 = 0;
    if (pzVar3 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
      uVar4 = (uint)*pzVar3->data_p;
    }
    if (uVar4 < CONCAT31(in_register_0000202d,level)) {
      uStack_11 = 1;
      if (**(char **)(iVar2 + 8) == '\0') {
_L105:
        iVar2 = zcl_set_attr_value(6,1,0,0,&uStack_11,0);
        if (iVar2 == 0) {
          uVar1 = ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),6,1,0,0);
          zcl_message_notify_attr_value(CONCAT31(in_register_00002029,ep_id),6,1,uVar1);
        }
        return;
      }
    }
    else if (**(char **)(iVar2 + 8) != '\0') {
      uStack_11 = 0;
      goto _L105;
    }
  }
  return;
}

