/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_enhanced_step_hue_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void color_control_enhanced_step_hue_cmd_handler(int param_1,int param_2)

{
  int iVar1;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_12;
  
  uStack_12 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_1c);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_12,(int)&uStack_1c + 2);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_18);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,(int)&uStack_18 + 2);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,(int)&uStack_18 + 3);
    iVar1 = color_control_check_options_is_exec
                      (*(undefined1 *)(param_1 + 0x15),uStack_18 >> 0x10 & 0xff,uStack_18 >> 0x18);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = color_control_change_color_mode(param_1,3);
      if (iVar1 == 0) {
        iVar1 = cvc_enhanced_step_hue(*(undefined1 *)(param_1 + 0x15),&uStack_1c,0);
      }
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,iVar1);
  return;
}

