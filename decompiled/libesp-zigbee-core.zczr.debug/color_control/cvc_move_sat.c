/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> cvc_move_sat
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 cvc_move_sat(undefined4 param_1,char *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_30 [4];
  uint uStack_2c;
  undefined4 uStack_28;
  ushort uStack_24;
  uint uStack_20;
  undefined1 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (param_2 == (char *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x371
                  ,"cvc_move_sat","payload");
  }
  else {
    local_30[0] = (undefined1)param_1;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 1;
    uStack_20 = 0;
    uStack_1c = 0;
    pcStack_18 = cvc_sat_output_handler;
    uStack_14 = 1;
    iVar2 = color_control_srv_get_attr_desc();
    if (iVar2 == 0) {
      return 0x86;
    }
    param_3 = (uint)**(byte **)(iVar2 + 8);
    cVar1 = *param_2;
    uStack_2c = param_3;
    if (cVar1 != '\x01') {
      if (cVar1 != '\x03') {
        if (cVar1 == '\0') {
          stop_cvc_color(param_1,0);
          return 0;
        }
        return 0x85;
      }
      if (param_2[1] == '\0') {
        return 0x85;
      }
      uStack_28 = 0;
      uStack_20 = (((uint)uStack_24 * 0xa0000 >> 0x10) * param_3) / (uint)(byte)param_2[1];
      goto _L0;
    }
  }
  if (param_2[1] == '\0') {
    return 0x85;
  }
  uStack_28 = 0xfe;
  uStack_20 = (int)(((uint)uStack_24 * 0xa0000 >> 0x10) * (0xfe - param_3)) /
              (int)(uint)(byte)param_2[1];
_L0:
  uVar3 = schedule_cvc_color_line(param_1,local_30);
  return uVar3;
}

