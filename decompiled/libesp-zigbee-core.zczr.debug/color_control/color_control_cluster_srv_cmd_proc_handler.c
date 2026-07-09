/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int color_control_cluster_srv_cmd_proc_handler(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 1;
  }
  iVar2 = color_control_color_capacity_is_supported
                    (*(undefined1 *)(param_1 + 0x15),*(undefined1 *)(param_1 + 0x20));
  if (iVar2 == 0) {
    return 1;
  }
  iVar2 = zcl_packet_init(&uStack_38,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar2 != 0) {
    return iVar2;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  if (bVar1 == 10) {
    iVar2 = color_control_move_to_color_temperature_cmd_handler(param_1,&uStack_38);
    goto _L0;
  }
  if (bVar1 < 0xb) {
    if (bVar1 == 6) {
      iVar2 = color_control_move_to_hue_and_saturation_cmd_handler(param_1,&uStack_38);
      goto _L0;
    }
    if (bVar1 < 7) {
      if (bVar1 == 3) {
        iVar2 = color_control_move_to_saturation_cmd_handler(param_1,&uStack_38);
        goto _L0;
      }
      if (bVar1 < 4) {
        if (bVar1 == 1) {
_L0:
          iVar2 = color_control_move_hs_cmd_handler(param_1,&uStack_38);
          goto _L0;
        }
        if (bVar1 == 2) {
_L0:
          iVar2 = color_control_step_hs_cmd_handler(param_1,&uStack_38);
          goto _L0;
        }
        if (bVar1 == 0) {
          iVar2 = color_control_move_to_hue_cmd_handler(param_1,&uStack_38);
          goto _L0;
        }
      }
      else {
        if (bVar1 == 4) goto _L0;
        if (bVar1 == 5) goto _L0;
      }
    }
    else {
      if (bVar1 == 8) {
        iVar2 = color_control_move_color_cmd_handler(param_1,&uStack_38);
        goto _L0;
      }
      if (bVar1 == 9) {
        iVar2 = color_control_step_color_cmd_handler(param_1,&uStack_38);
        goto _L0;
      }
      if (bVar1 == 7) {
        iVar2 = color_control_move_to_color_cmd_handler(param_1,&uStack_38);
        goto _L0;
      }
    }
  }
  else {
    if (bVar1 == 0x44) {
      iVar2 = color_control_color_loop_set_cmd_handler(param_1,&uStack_38);
      goto _L0;
    }
    if (bVar1 < 0x45) {
      if (bVar1 == 0x42) {
        iVar2 = color_control_enhanced_step_hue_cmd_handler(param_1,&uStack_38);
        goto _L0;
      }
      if (bVar1 < 0x43) {
        if (bVar1 == 0x40) {
          iVar2 = color_control_enhanced_move_to_hue_cmd_handler(param_1,&uStack_38);
          goto _L0;
        }
        if (bVar1 == 0x41) {
          iVar2 = color_control_enhanced_move_hue_cmd_handler(param_1,&uStack_38);
          goto _L0;
        }
      }
      else if (bVar1 == 0x43) {
        iVar2 = color_control_enhanced_move_to_hue_and_saturation_cmd_handler(param_1,&uStack_38);
        goto _L0;
      }
    }
    else {
      if (bVar1 == 0x4b) {
        iVar2 = color_control_move_color_temperature_cmd_handler(param_1,&uStack_38);
        goto _L0;
      }
      if (bVar1 == 0x4c) {
        iVar2 = color_control_step_color_temperature_cmd_handler(param_1,&uStack_38);
        goto _L0;
      }
      if (bVar1 == 0x47) {
        iVar2 = color_control_stop_move_step_cmd_handler(param_1,&uStack_38);
        goto _L0;
      }
    }
  }
  iVar2 = zcl_packet_setup_default_response(&uStack_38,param_1,0x81);
_L0:
  if (iVar2 == 0) {
    zcl_packet_send(&uStack_38,0);
  }
  else {
    zcl_packet_free(&uStack_38);
  }
  return iVar2;
}

