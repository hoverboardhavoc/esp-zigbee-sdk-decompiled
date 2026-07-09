/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_move_hs_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void color_control_move_hs_cmd_handler(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uStack_18;
  ushort uStack_12;
  
  uStack_12 = 0;
  uStack_18 = 0;
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_18);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,(int)&uStack_18 + 1);
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar1 < uStack_12) {
      iVar2 = 0x80;
    }
    else {
      af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,(int)&uStack_18 + 2);
      af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,(int)&uStack_18 + 3);
      iVar2 = color_control_check_options_is_exec
                        (*(undefined1 *)(param_1 + 0x15),uStack_18 >> 0x10 & 0xff,uStack_18 >> 0x18)
      ;
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = color_control_change_color_mode(param_1,0);
        if (iVar2 == 0) {
          if (*(char *)(param_1 + 0x20) == '\x01') {
            iVar2 = cvc_move_hue(*(undefined1 *)(param_1 + 0x15),&uStack_18,0);
          }
          else {
            iVar2 = cvc_move_sat(*(undefined1 *)(param_1 + 0x15),&uStack_18);
          }
        }
      }
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,iVar2);
  return;
}

