/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> on_off.o -> on_off_process_transition
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void on_off_process_transition(uint8_t ep_id,uint8_t cmd_id,uint8_t on_off,uint16_t x,uint16_t y)

{
  zcl_attr_desc_t *pzVar1;
  zcl_attr_desc_t *pzVar2;
  zcl_attr_desc_t *pzVar3;
  _Bool on_off_00;
  bool on_off_01;
  uint16_t attr_id;
  undefined3 in_register_0000202d;
  uint uVar4;
  undefined3 in_register_00002031;
  int iVar5;
  int iVar6;
  uint16_t *value;
  uint16_t uStack_24;
  uint16_t auStack_22 [5];
  
  iVar5 = CONCAT31(in_register_00002031,on_off);
  uVar4 = CONCAT31(in_register_0000202d,cmd_id);
  iVar6 = iVar5;
  uStack_24 = y;
  auStack_22[0] = x;
  if (uVar4 < 2) goto _L0;
  while( true ) {
    pzVar1 = on_off_srv_get_attr_desc(ep_id,0);
    pzVar2 = on_off_srv_get_attr_desc(ep_id,0x4001);
    pzVar3 = on_off_srv_get_attr_desc(ep_id,0x4002);
    if (pzVar1 != (zcl_attr_desc_t *)0x0) break;
    iVar6 = 0;
    __assert_func(0,0,0,0);
_L0:
    iVar6 = zcl_level_action_affect_by_on_off(iVar6 != 0);
    if (iVar6 != 0) {
      return;
    }
  }
  if ((pzVar2 == (zcl_attr_desc_t *)0x0) || (pzVar3 == (zcl_attr_desc_t *)0x0)) {
    on_off_00 = iVar5 != 0;
    goto _L0;
  }
                    /* WARNING: Load size is inaccurate */
  if (*pzVar1->data_p == '\x01') {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    if (*pzVar2->data_p == 0) {
      if (*pzVar3->data_p != 0) goto _L0;
      if (uVar4 != 0x40) {
        if (uVar4 == 0x42) goto _L0;
        if (uVar4 != 0) {
          return;
        }
      }
      on_off_00 = false;
_L0:
      zcl_message_on_off_set_attr_value(ep_id,on_off_00);
      return;
    }
    if (*pzVar3->data_p != 0) {
      if (uVar4 != 0x40) {
        if (uVar4 == 0x42) {
          if (auStack_22[0] != 0) goto _L0;
          uStack_24 = 0;
          on_off_01 = false;
          goto _L0;
        }
        if (uVar4 != 0) {
          return;
        }
      }
      auStack_22[0] = 0;
      zcl_message_on_off_set_attr_value(ep_id,false);
      value = auStack_22;
      attr_id = 0x4001;
      goto _L0;
    }
_L0:
    on_off_01 = iVar5 != 0;
_L0:
    zcl_message_on_off_set_attr_value(ep_id,on_off_01);
_L0:
    on_off_srv_set_attr_value(ep_id,0x4001,(uint8_t *)auStack_22);
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if ((*pzVar1->data_p != '\0') || (*pzVar2->data_p != 0)) goto _L0;
                    /* WARNING: Load size is inaccurate */
    if (*pzVar3->data_p == 0) {
      if (uVar4 != 0x41) {
        if (uVar4 == 0x42) goto _L0;
        if (uVar4 != 1) {
          return;
        }
      }
      on_off_00 = true;
      goto _L0;
    }
    if (uVar4 != 0x41) {
      if (uVar4 == 0x42) {
        auStack_22[0] = 0;
        goto _L0;
      }
      if (uVar4 != 1) {
        return;
      }
    }
    uStack_24 = 0;
    zcl_message_on_off_set_attr_value(ep_id,true);
  }
  value = &uStack_24;
  attr_id = 0x4002;
_L0:
  on_off_srv_set_attr_value(ep_id,attr_id,(uint8_t *)value);
  return;
}

