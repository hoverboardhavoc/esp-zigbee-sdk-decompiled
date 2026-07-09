/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> cvc_enhanced_step_hue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int cvc_enhanced_step_hue(undefined4 param_1,char *param_2,uint param_3)

{
  int iVar1;
  undefined1 local_30 [4];
  uint uStack_2c;
  int iStack_28;
  undefined2 uStack_24;
  uint uStack_20;
  undefined1 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (param_2 == (char *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x784
                  ,"cvc_enhanced_step_hue","payload");
  }
  else {
    local_30[0] = (undefined1)param_1;
    uStack_2c = 0;
    iStack_28 = 0;
    uStack_24 = 1;
    uStack_20 = (uint)*(ushort *)(param_2 + 4);
    uStack_1c = 0;
    pcStack_18 = cvc_enhanced_hue_output_handler;
    uStack_14 = 0x4000;
    iVar1 = color_control_srv_get_attr_desc();
    if (iVar1 == 0) {
      return 0x86;
    }
    param_3 = (uint)**(ushort **)(iVar1 + 8);
    uStack_2c = param_3;
    if (*param_2 != '\x01') {
      if (*param_2 == '\x03') {
        iStack_28 = param_3 - *(ushort *)(param_2 + 2);
        iVar1 = 0;
      }
      else {
        iVar1 = 0x85;
      }
      goto _L0;
    }
  }
  iStack_28 = param_3 + *(ushort *)(param_2 + 2);
  iVar1 = 0;
_L0:
  color_control_set_remaining_time(param_1,*(undefined2 *)(param_2 + 4));
  if (iVar1 == 0) {
    iVar1 = schedule_cvc_color_line(param_1,local_30);
  }
  return iVar1;
}

