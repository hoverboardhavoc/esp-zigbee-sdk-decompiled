/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> cvc_color_loop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 cvc_color_loop(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  int unaff_s2;
  int unaff_s3;
  int unaff_s4;
  int unaff_s6;
  undefined1 local_40 [4];
  uint uStack_3c;
  int iStack_38;
  undefined2 uStack_34;
  int iStack_30;
  undefined1 uStack_2c;
  code *pcStack_28;
  undefined4 uStack_24;
  
  if (param_2 == (byte *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x82b
                  ,"cvc_color_loop","payload");
  }
  else {
    local_40[0] = (undefined1)param_1;
    uStack_3c = 0;
    iStack_38 = 0;
    uStack_34 = 1;
    iStack_30 = 0;
    uStack_2c = 0;
    pcStack_28 = cvc_enhanced_hue_output_handler;
    uStack_24 = 0x4000;
    unaff_s2 = color_control_srv_get_attr_desc(0x4002);
    unaff_s3 = color_control_srv_get_attr_desc(param_1,0x4003);
    unaff_s4 = color_control_srv_get_attr_desc(param_1,0x4004);
    iVar2 = color_control_srv_get_attr_desc(param_1,0x4005);
    unaff_s6 = color_control_srv_get_attr_desc(param_1,0x4000);
    if (unaff_s2 == 0) {
      return 0x86;
    }
    if (unaff_s3 == 0) {
      return 0x86;
    }
    if (unaff_s4 == 0) {
      return 0x86;
    }
    if (iVar2 == 0) {
      return 0x86;
    }
    if (unaff_s6 == 0) {
      return 0x86;
    }
    if ((*param_2 & 2) != 0) {
      **(byte **)(unaff_s3 + 8) = param_2[2];
    }
    if ((*param_2 & 4) != 0) {
      **(undefined2 **)(unaff_s4 + 8) = *(undefined2 *)(param_2 + 4);
    }
    if ((*param_2 & 8) != 0) {
      **(undefined2 **)(iVar2 + 8) = *(undefined2 *)(param_2 + 6);
    }
    if ((*param_2 & 1) == 0) goto _L0;
    bVar1 = param_2[1];
    if (bVar1 != 1) {
      if (bVar1 == 2) {
        color_control_copy_attr_u16(param_1,0x4000,0x4006);
        **(undefined1 **)(unaff_s2 + 8) = 1;
      }
      else {
        if (bVar1 != 0) {
          return 0x87;
        }
        if (**(char **)(unaff_s2 + 8) == '\x01') {
          **(char **)(unaff_s2 + 8) = '\0';
          color_control_copy_attr_u16(param_1,0x4006);
        }
      }
      goto _L0;
    }
  }
  color_control_copy_attr_u16(param_1,0x4000,0x4005);
  **(undefined1 **)(unaff_s2 + 8) = 1;
_L0:
  if (**(char **)(unaff_s2 + 8) == '\0') {
    stop_cvc_color(param_1,3);
  }
  else {
    iStack_30 = (uint)**(ushort **)(unaff_s4 + 8) * 10;
    uStack_3c = (uint)**(ushort **)(unaff_s6 + 8);
    if (**(char **)(unaff_s3 + 8) == '\0') {
      iStack_38 = uStack_3c + 0x10000;
    }
    else {
      iStack_38 = uStack_3c - 0x10000;
    }
    schedule_cvc_color_line(param_1,local_40);
  }
  return 0;
}

