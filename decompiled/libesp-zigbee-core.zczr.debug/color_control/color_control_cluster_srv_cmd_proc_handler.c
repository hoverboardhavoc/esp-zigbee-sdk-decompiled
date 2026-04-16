/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t color_control_cluster_srv_cmd_proc_handler(void *arg)

{
  byte bVar1;
  int iVar2;
  _Bool _Var3;
  ezb_zcl_status_t eVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined3 extraout_var_09;
  undefined3 extraout_var_10;
  undefined3 extraout_var_11;
  undefined3 extraout_var_12;
  undefined3 extraout_var_13;
  undefined3 extraout_var_14;
  undefined3 extraout_var_15;
  undefined3 extraout_var_16;
  undefined1 auStack_38 [4];
  zcl_packet_t rsp;
  
  auStack_38 = (undefined1  [4])0x0;
  rsp.header.src_addr._0_4_ = 0;
  rsp.header.src_addr.u._2_4_ = 0;
  rsp.header._8_4_ = 0;
  rsp.header.dst_addr.u._0_2_ = 0;
  rsp.header.dst_addr.u._2_2_ = 0;
  rsp.header.dst_addr.u._4_4_ = 0;
  rsp.header.src_ep = '\0';
  rsp.header.dst_ep = '\0';
  rsp.header.cluster_id = 0;
  rsp.header.profile_id = 0;
  rsp.header.fc = '\0';
  rsp.header._27_1_ = 0;
  rsp.header.manuf_code = 0;
  rsp.header.tsn = '\0';
  rsp.header.rssi = '\0';
  rsp.header.cmd_id = '\0';
  rsp.header._33_1_ = 0;
  rsp._34_2_ = 0;
  if (arg == (void *)0x0) {
    iVar2 = 1;
    goto _L0;
  }
  if ((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) {
    iVar2 = 1;
    goto _L0;
  }
  _Var3 = color_control_color_capacity_is_supported
                    (*(uint8_t *)((int)arg + 0x15),*(uint8_t *)((int)arg + 0x20));
  if (CONCAT31(extraout_var,_Var3) == 0) {
    iVar2 = 1;
    goto _L0;
  }
  iVar2 = zcl_packet_init(auStack_38,*(byte *)((int)arg + 0x1a) >> 2 & 1);
  if (iVar2 != 0) goto _L0;
  bVar1 = *(byte *)((int)arg + 0x20);
  if (bVar1 == 10) {
    eVar4 = color_control_move_to_color_temperature_cmd_handler
                      ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
    iVar2 = CONCAT31(extraout_var_11,eVar4);
  }
  else if (bVar1 < 0xb) {
    if (bVar1 == 6) {
      eVar4 = color_control_move_to_hue_and_saturation_cmd_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var_08,eVar4);
    }
    else if (bVar1 < 7) {
      if (bVar1 == 3) {
        eVar4 = color_control_move_to_saturation_cmd_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_07,eVar4);
      }
      else if (bVar1 < 4) {
        if (bVar1 == 1) {
_L0:
          eVar4 = color_control_move_hs_cmd_handler((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
          iVar2 = CONCAT31(extraout_var_06,eVar4);
        }
        else {
          if (bVar1 == 2) goto _L0;
          if (bVar1 != 0) goto _L0;
          eVar4 = color_control_move_to_hue_cmd_handler
                            ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
          iVar2 = CONCAT31(extraout_var_00,eVar4);
        }
      }
      else {
        if (bVar1 == 4) goto _L0;
        if (bVar1 != 5) goto _L0;
_L0:
        eVar4 = color_control_step_hs_cmd_handler((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_01,eVar4);
      }
    }
    else if (bVar1 == 8) {
      eVar4 = color_control_move_color_cmd_handler((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var_09,eVar4);
    }
    else if (bVar1 == 9) {
      eVar4 = color_control_step_color_cmd_handler((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var_10,eVar4);
    }
    else {
      if (bVar1 != 7) goto _L0;
      eVar4 = color_control_move_to_color_cmd_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var_02,eVar4);
    }
  }
  else if (bVar1 == 0x44) {
    eVar4 = color_control_color_loop_set_cmd_handler((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38)
    ;
    iVar2 = CONCAT31(extraout_var_16,eVar4);
  }
  else if (bVar1 < 0x45) {
    if (bVar1 == 0x42) {
      eVar4 = color_control_enhanced_step_hue_cmd_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var_15,eVar4);
    }
    else if (bVar1 < 0x43) {
      if (bVar1 == 0x40) {
        eVar4 = color_control_enhanced_move_to_hue_cmd_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_14,eVar4);
      }
      else {
        if (bVar1 != 0x41) goto _L0;
        eVar4 = color_control_enhanced_move_hue_cmd_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_03,eVar4);
      }
    }
    else if (bVar1 == 0x43) {
      eVar4 = color_control_enhanced_move_to_hue_and_saturation_cmd_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var_04,eVar4);
    }
    else {
_L0:
      iVar2 = zcl_packet_setup_default_response(auStack_38,arg,0x81);
    }
  }
  else if (bVar1 == 0x4b) {
    eVar4 = color_control_move_color_temperature_cmd_handler
                      ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
    iVar2 = CONCAT31(extraout_var_12,eVar4);
  }
  else if (bVar1 == 0x4c) {
    eVar4 = color_control_step_color_temperature_cmd_handler
                      ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
    iVar2 = CONCAT31(extraout_var_13,eVar4);
  }
  else {
    if (bVar1 != 0x47) goto _L0;
    eVar4 = color_control_stop_move_step_cmd_handler((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38)
    ;
    iVar2 = CONCAT31(extraout_var_05,eVar4);
  }
  if (iVar2 == 0) {
    zcl_packet_send(auStack_38,0);
  }
  else {
    zcl_packet_free(auStack_38);
  }
_L0:
  return (ezb_zcl_status_t)iVar2;
}

