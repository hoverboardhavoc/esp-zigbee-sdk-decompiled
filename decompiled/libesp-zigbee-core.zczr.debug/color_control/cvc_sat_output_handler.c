/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> cvc_sat_output_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cvc_sat_output_handler(undefined4 param_1,int param_2,undefined2 param_3,undefined2 param_4)

{
  undefined4 uVar1;
  undefined4 extraout_a1;
  char *pcVar2;
  char *pcVar3;
  undefined2 uStack_32;
  undefined1 auStack_11 [5];
  
  if (-1 < param_2) {
    auStack_11[0] = (undefined1)param_2;
    zcl_message_set_color_control_attr_value(param_4,auStack_11);
    color_control_set_remaining_time(param_1,param_3);
    return;
  }
  pcVar3 = "output >= 0";
  pcVar2 = "cvc_sat_output_handler";
  uVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c"
                        ,0x2dd,"cvc_sat_output_handler","output >= 0");
  uStack_32 = math_mod(extraout_a1,0xff00);
  zcl_message_set_color_control_attr_value(uVar1,(uint)pcVar3 & 0xffff,&uStack_32);
  color_control_set_remaining_time(uVar1,(uint)pcVar2 & 0xffff);
  return;
}

