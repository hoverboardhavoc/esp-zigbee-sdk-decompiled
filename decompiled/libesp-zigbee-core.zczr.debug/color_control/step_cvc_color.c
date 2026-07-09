/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> step_cvc_color
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 step_cvc_color(undefined4 param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_60 [4];
  uint uStack_5c;
  int iStack_58;
  undefined2 uStack_54;
  uint uStack_50;
  undefined1 uStack_4c;
  code *pcStack_48;
  undefined4 uStack_44;
  undefined1 auStack_40 [4];
  uint uStack_3c;
  int iStack_38;
  undefined2 uStack_34;
  uint uStack_30;
  undefined1 uStack_2c;
  code *pcStack_28;
  undefined4 uStack_24;
  
  if (param_2 == (byte *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x567
                  ,"step_cvc_color","payload");
  }
  else {
    local_60[0] = (undefined1)param_1;
    uStack_3c = 0;
    iStack_38 = 0;
    uStack_34 = 1;
    uStack_50 = (uint)*(ushort *)(param_2 + 2);
    uStack_2c = 0;
    pcStack_28 = cvc_color_xy_output_handler;
    uStack_24 = 3;
    uStack_5c = 0;
    iStack_58 = 0;
    uStack_54 = 1;
    uStack_4c = 0;
    pcStack_48 = cvc_color_xy_output_handler;
    uStack_44 = 4;
    auStack_40[0] = local_60[0];
    uStack_30 = uStack_50;
    iVar1 = color_control_srv_get_attr_desc();
    iVar2 = color_control_srv_get_attr_desc(param_1,4);
    if (iVar1 != 0) {
      if (iVar2 != 0) {
        uStack_3c = (uint)**(ushort **)(iVar1 + 8);
        uStack_5c = (uint)**(ushort **)(iVar2 + 8);
        iStack_38 = uStack_3c + *param_2;
        iStack_58 = uStack_5c + param_2[1];
        color_control_set_remaining_time(param_1,*(undefined2 *)(param_2 + 2));
        uVar3 = schedule_cvc_color_space(param_1,auStack_40,local_60);
        return uVar3;
      }
      return 0x86;
    }
  }
  return 0x86;
}

