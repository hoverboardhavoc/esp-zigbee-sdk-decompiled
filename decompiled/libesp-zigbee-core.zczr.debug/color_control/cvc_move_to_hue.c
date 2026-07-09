/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> cvc_move_to_hue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 cvc_move_to_hue(uint param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_30;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (param_2 == (byte *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x2e8
                  ,"cvc_move_to_hue","payload");
_L0:
    uVar3 = 0x85;
  }
  else {
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_1c = 0;
    uStack_14 = 0;
    local_30 = param_1 & 0xff;
    uStack_24 = 1;
    uStack_20 = (uint)*(ushort *)(param_2 + 2);
    pcStack_18 = cvc_hue_output_handler;
    if (*param_2 == 0xff) {
      return 0x87;
    }
    iVar2 = color_control_srv_get_attr_desc(0);
    if (iVar2 == 0) {
      return 0x86;
    }
    uStack_2c = (uint)**(byte **)(iVar2 + 8);
    uStack_28 = (uint)*param_2;
    bVar1 = param_2[1];
    if (bVar1 == 2) {
      if (uStack_28 < uStack_2c) {
        uStack_28 = uStack_28 + 0xff;
      }
    }
    else if (bVar1 < 3) {
      if (bVar1 == 0) {
        if (uStack_28 < uStack_2c) {
          iVar2 = uStack_2c - uStack_28;
        }
        else {
          iVar2 = uStack_28 - uStack_2c;
        }
        if (uStack_2c < uStack_28 == 0x7f < iVar2) {
          if (uStack_2c < uStack_28) {
            uStack_28 = uStack_28 - 0xff;
          }
        }
        else if (uStack_28 < uStack_2c) {
          uStack_28 = uStack_28 + 0xff;
        }
      }
      else {
        if (bVar1 != 1) goto _L0;
        if (uStack_28 < uStack_2c) {
          iVar2 = uStack_2c - uStack_28;
        }
        else {
          iVar2 = uStack_28 - uStack_2c;
        }
        if (uStack_2c < uStack_28 == 0x7f < iVar2) {
          if (uStack_28 < uStack_2c) {
            uStack_28 = uStack_28 + 0xff;
          }
        }
        else if (uStack_2c < uStack_28) {
          uStack_28 = uStack_28 - 0xff;
        }
      }
    }
    else {
      if (bVar1 != 3) {
        return 0x85;
      }
      if (uStack_2c < uStack_28) {
        uStack_28 = uStack_28 - 0xff;
      }
    }
    uVar3 = schedule_cvc_color_line(param_1,&local_30);
  }
  return uVar3;
}

