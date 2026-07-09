/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> cvc_move_color_xy
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 cvc_move_color_xy(undefined4 param_1,ushort *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_50 [4];
  uint uStack_4c;
  int iStack_48;
  undefined2 uStack_44;
  undefined4 uStack_40;
  undefined1 uStack_3c;
  code *pcStack_38;
  undefined4 uStack_34;
  undefined1 auStack_30 [4];
  uint uStack_2c;
  int iStack_28;
  undefined2 uStack_24;
  undefined4 uStack_20;
  undefined1 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (param_2 == (ushort *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x518
                  ,"cvc_move_color_xy","payload");
  }
  else {
    local_50[0] = (undefined1)param_1;
    uStack_2c = 0;
    iStack_28 = 0;
    param_3 = 1;
    uStack_24 = 1;
    uStack_20 = 0;
    uStack_1c = 1;
    pcStack_18 = cvc_color_xy_output_handler;
    uStack_14 = 3;
    uStack_4c = 0;
    iStack_48 = 0;
    uStack_44 = 1;
    uStack_40 = 0;
    uStack_3c = 1;
    pcStack_38 = cvc_color_xy_output_handler;
    uStack_34 = 4;
    auStack_30[0] = local_50[0];
    if ((*param_2 != 0) || (param_2[1] != 0)) {
      iVar1 = color_control_srv_get_attr_desc(param_1,3);
      iVar2 = color_control_srv_get_attr_desc(param_1,4);
      if (iVar1 == 0) {
        return 0x86;
      }
      if (iVar2 != 0) {
        uStack_2c = (uint)**(ushort **)(iVar1 + 8);
        uStack_4c = (uint)**(ushort **)(iVar2 + 8);
        iStack_28 = uStack_2c + *param_2;
        iStack_48 = uStack_4c + param_2[1];
        if (*param_2 == 0) {
          uStack_20 = 0;
        }
        else {
          uStack_20 = 10;
        }
        if (param_2[1] == 0) {
          uStack_40 = 0;
        }
        else {
          uStack_40 = 10;
        }
        uVar3 = schedule_cvc_color_space(param_1,auStack_30,local_50);
        return uVar3;
      }
      return 0x86;
    }
  }
  stop_cvc_color(param_3);
  return 0xfe;
}

