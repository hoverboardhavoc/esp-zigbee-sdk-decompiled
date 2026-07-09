/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_change_color_mode
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int color_control_change_color_mode(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint unaff_s2;
  uint unaff_s3;
  undefined1 uStack_29;
  undefined4 uStack_28;
  undefined2 auStack_24 [8];
  
  auStack_24[0] = 0;
  uStack_28 = param_2 & 0xff;
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x28e
                  ,"color_control_change_color_mode","packet");
  }
  else {
    unaff_s2 = (uint)*(byte *)(param_1 + 0x15);
    iVar1 = color_control_srv_get_attr_desc(unaff_s2,0x4001);
    unaff_s3 = (uint)**(byte **)(iVar1 + 8);
    iVar1 = zcl_message_color_mode_change(param_1,param_2,unaff_s3,&uStack_28);
    if (iVar1 != 0xfe) goto _L0;
  }
  iVar1 = color_control_update_default_color(unaff_s2,unaff_s3,&uStack_28);
_L0:
  if (iVar1 == 0) {
    uVar2 = uStack_28 & 0xff;
    if (uVar2 == 2) {
      iVar1 = color_control_srv_set_attr_value(unaff_s2,7,(int)&uStack_28 + 2);
    }
    else if (uVar2 < 3) {
      if (uVar2 == 0) {
        color_control_srv_set_attr_value(unaff_s2,0,(int)&uStack_28 + 2);
        iVar1 = color_control_srv_set_attr_value(unaff_s2,1,auStack_24);
      }
      else {
        if (uVar2 != 1) {
          return 0x87;
        }
        color_control_srv_set_attr_value(unaff_s2,3,(int)&uStack_28 + 2);
        iVar1 = color_control_srv_set_attr_value(unaff_s2,4,auStack_24);
      }
    }
    else {
      if (uVar2 != 3) {
        return 0x87;
      }
      iVar1 = color_control_srv_set_attr_value(unaff_s2,0x4000,(int)&uStack_28 + 2);
    }
    if (iVar1 == 0) {
      if (param_2 == 3) {
        uStack_29 = 0;
        iVar1 = color_control_srv_set_attr_value(unaff_s2,8,&uStack_29);
      }
      else {
        iVar1 = color_control_srv_set_attr_value(unaff_s2,8,&uStack_28);
      }
      if (iVar1 == 0) {
        iVar1 = color_control_srv_set_attr_value(unaff_s2,0x4001,&uStack_28);
      }
    }
  }
  return iVar1;
}

