/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> move_to_cvc_color_temperature
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 move_to_cvc_color_temperature(uint param_1,ushort *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  ushort uStack_34;
  ushort uStack_32;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (param_2 == (ushort *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x5d2
                  ,"move_to_cvc_color_temperature","payload");
  }
  else {
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_1c = 0;
    uStack_30 = param_1 & 0xff;
    uStack_24 = 1;
    uStack_20 = (uint)param_2[1];
    pcStack_18 = cvc_color_temperature_output_handler;
    uStack_14 = 7;
    uStack_32 = 0;
    uStack_34 = 0;
    iVar1 = color_control_srv_get_attr_desc();
    if (iVar1 != 0) {
      iVar2 = color_control_get_color_temperature_range(param_1,&uStack_32,&uStack_34);
      if (iVar2 != 0) {
        uStack_2c = (uint)**(ushort **)(iVar1 + 8);
        uStack_28 = (uint)uStack_32;
        if ((uint)uStack_32 < (uint)*param_2) {
          uStack_28 = (uint)*param_2;
        }
        if (uStack_34 < uStack_28) {
          uStack_28 = (uint)uStack_34;
        }
        uVar3 = schedule_cvc_color_line(param_1,&uStack_30);
        return uVar3;
      }
      return 0x86;
    }
  }
  return 0x86;
}

