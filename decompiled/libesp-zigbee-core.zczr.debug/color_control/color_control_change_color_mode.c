/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_change_color_mode
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t color_control_change_color_mode(zcl_packet_t *packet,uint8_t new_mode)

{
  uint8_t ep_id;
  ezb_zcl_status_t eVar1;
  byte bVar2;
  zcl_attr_desc_t *pzVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 in_register_0000202d;
  uint uVar4;
  ushort unaff_s2;
  uint8_t unaff_s3;
  uint8_t uStack_29;
  undefined1 auStack_28 [3];
  uint8_t mode;
  ezb_zcl_color_control_color_t new_color;
  
  new_color.mode = '\0';
  new_color._1_1_ = 0;
  _auStack_28 = (uint)new_mode;
  if (packet == (zcl_packet_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x28e
                  ,"color_control_change_color_mode","packet");
_L0:
    eVar1 = color_control_update_default_color
                      (unaff_s2,unaff_s3,(ezb_zcl_color_control_color_t *)auStack_28);
    uVar4 = CONCAT31(extraout_var_01,eVar1);
  }
  else {
    bVar2 = (packet->header).dst_ep;
    unaff_s2 = (ushort)bVar2;
    pzVar3 = color_control_srv_get_attr_desc(bVar2,0x4001);
                    /* WARNING: Load size is inaccurate */
    unaff_s3 = *pzVar3->data_p;
    eVar1 = zcl_message_color_mode_change
                      (packet,new_mode,unaff_s3,(ezb_zcl_color_control_color_t *)auStack_28);
    uVar4 = CONCAT31(extraout_var,eVar1);
    if (uVar4 == 0xfe) goto _L0;
  }
  if (uVar4 == 0) {
    uVar4 = _auStack_28 & 0xff;
    ep_id = (uint8_t)unaff_s2;
    if (uVar4 == 2) {
      eVar1 = color_control_srv_set_attr_value(ep_id,7,auStack_28 + 2);
      uVar4 = CONCAT31(extraout_var_05,eVar1);
    }
    else if (uVar4 < 3) {
      if (uVar4 == 0) {
        color_control_srv_set_attr_value(ep_id,0,auStack_28 + 2);
        eVar1 = color_control_srv_set_attr_value(ep_id,1,&new_color.mode);
        uVar4 = CONCAT31(extraout_var_04,eVar1);
      }
      else {
        if (uVar4 != 1) {
          uVar4 = 0x87;
          goto _L0;
        }
        color_control_srv_set_attr_value(ep_id,3,auStack_28 + 2);
        eVar1 = color_control_srv_set_attr_value(ep_id,4,&new_color.mode);
        uVar4 = CONCAT31(extraout_var_00,eVar1);
      }
    }
    else {
      if (uVar4 != 3) {
        uVar4 = 0x87;
        goto _L0;
      }
      eVar1 = color_control_srv_set_attr_value(ep_id,0x4000,auStack_28 + 2);
      uVar4 = CONCAT31(extraout_var_02,eVar1);
    }
    if (uVar4 == 0) {
      if (CONCAT31(in_register_0000202d,new_mode) == 3) {
        uStack_29 = '\0';
        eVar1 = color_control_srv_set_attr_value(ep_id,8,&uStack_29);
        uVar4 = CONCAT31(extraout_var_06,eVar1);
      }
      else {
        eVar1 = color_control_srv_set_attr_value(ep_id,8,auStack_28);
        uVar4 = CONCAT31(extraout_var_03,eVar1);
      }
      if (uVar4 == 0) {
        bVar2 = color_control_srv_set_attr_value(ep_id,0x4001,auStack_28);
        uVar4 = (uint)bVar2;
      }
    }
  }
_L0:
  return (ezb_zcl_status_t)uVar4;
}

