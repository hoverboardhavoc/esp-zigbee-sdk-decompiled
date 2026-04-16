/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_process_transition
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void on_off_process_transition(uint8_t ep_id,uint8_t cmd_id,uint8_t on_off,uint16_t x,uint16_t y)

{
  char cVar1;
  zcl_attr_desc_t *pzVar2;
  zcl_attr_desc_t *pzVar3;
  zcl_attr_desc_t *pzVar4;
  int iVar5;
  undefined3 in_register_0000202d;
  uint uVar6;
  undefined3 in_register_00002031;
  int iVar7;
  uint16_t uStack_24;
  uint16_t auStack_22 [5];
  
  iVar7 = CONCAT31(in_register_00002031,on_off);
  uVar6 = CONCAT31(in_register_0000202d,cmd_id);
  uStack_24 = y;
  auStack_22[0] = x;
  if ((uVar6 < 2) && (iVar5 = zcl_level_action_affect_by_on_off(iVar7 != 0), iVar5 != 0)) {
    return;
  }
  pzVar2 = on_off_srv_get_attr_desc(ep_id,0);
  pzVar3 = on_off_srv_get_attr_desc(ep_id,0x4001);
  pzVar4 = on_off_srv_get_attr_desc(ep_id,0x4002);
  if (pzVar2 == (zcl_attr_desc_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0xd9,
                  "on_off_process_transition","on_off_attr_desc");
  }
  else if ((pzVar3 != (zcl_attr_desc_t *)0x0) && (pzVar4 != (zcl_attr_desc_t *)0x0)) {
                    /* WARNING: Load size is inaccurate */
    cVar1 = *pzVar2->data_p;
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    if ((cVar1 != '\x01') || ((*pzVar3->data_p == 0 || (*pzVar4->data_p == 0)))) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      if ((cVar1 != '\x01') || ((*pzVar3->data_p != 0 || (*pzVar4->data_p != 0)))) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        if ((cVar1 != '\0') || ((*pzVar3->data_p != 0 || (*pzVar4->data_p == 0)))) {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
          if ((cVar1 != '\0') || ((*pzVar3->data_p != 0 || (*pzVar4->data_p != 0)))) {
            zcl_message_on_off_set_attr_value(ep_id,iVar7 != 0);
            on_off_srv_set_attr_value(ep_id,0x4001,(uint8_t *)auStack_22);
            on_off_srv_set_attr_value(ep_id,0x4002,(uint8_t *)&uStack_24);
            return;
          }
          if (uVar6 != 0x41) {
            if (uVar6 == 0x42) {
              zcl_message_on_off_set_attr_value(ep_id,iVar7 != 0);
              on_off_srv_set_attr_value(ep_id,0x4001,(uint8_t *)auStack_22);
              on_off_srv_set_attr_value(ep_id,0x4002,(uint8_t *)&uStack_24);
              return;
            }
            if (uVar6 != 1) {
              return;
            }
          }
          zcl_message_on_off_set_attr_value(ep_id,true);
          return;
        }
        if (uVar6 != 0x41) {
          if (uVar6 == 0x42) {
            auStack_22[0] = 0;
            on_off_srv_set_attr_value(ep_id,0x4001,(uint8_t *)auStack_22);
            on_off_srv_set_attr_value(ep_id,0x4002,(uint8_t *)&uStack_24);
            return;
          }
          if (uVar6 != 1) {
            return;
          }
        }
        uStack_24 = 0;
        zcl_message_on_off_set_attr_value(ep_id,true);
        on_off_srv_set_attr_value(ep_id,0x4002,(uint8_t *)&uStack_24);
        return;
      }
      if (uVar6 != 0x40) {
        if (uVar6 == 0x42) {
          on_off_srv_set_attr_value(ep_id,0x4001,(uint8_t *)auStack_22);
          on_off_srv_set_attr_value(ep_id,0x4002,(uint8_t *)&uStack_24);
          return;
        }
        if (uVar6 != 0) {
          return;
        }
      }
      zcl_message_on_off_set_attr_value(ep_id,false);
      return;
    }
    if (uVar6 != 0x40) {
      if (uVar6 == 0x42) {
        if (auStack_22[0] == 0) {
          auStack_22[0] = 0;
          uStack_24 = 0;
          zcl_message_on_off_set_attr_value(ep_id,false);
          on_off_srv_set_attr_value(ep_id,0x4001,(uint8_t *)auStack_22);
          on_off_srv_set_attr_value(ep_id,0x4002,(uint8_t *)&uStack_24);
          return;
        }
        on_off_srv_set_attr_value(ep_id,0x4001,(uint8_t *)auStack_22);
        on_off_srv_set_attr_value(ep_id,0x4002,(uint8_t *)&uStack_24);
        return;
      }
      if (uVar6 != 0) {
        return;
      }
    }
    auStack_22[0] = 0;
    zcl_message_on_off_set_attr_value(ep_id,false);
    on_off_srv_set_attr_value(ep_id,0x4001,(uint8_t *)auStack_22);
    return;
  }
  zcl_message_on_off_set_attr_value(ep_id,iVar7 != 0);
  return;
}

