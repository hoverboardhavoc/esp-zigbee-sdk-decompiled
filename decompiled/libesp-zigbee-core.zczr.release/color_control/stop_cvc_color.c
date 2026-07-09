/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> stop_cvc_color
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void stop_cvc_color(uint param_1,uint param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = color_control_srv_get_attr_desc_part_0();
  iVar3 = color_control_srv_get_attr_desc(param_1,0x4001);
  if ((iVar2 == 0) || (iVar3 == 0)) {
    iVar3 = __assert_func(0,0,0,0);
  }
  if ((**(byte **)(iVar3 + 8) != param_2) && (param_2 != 0xff)) {
    return;
  }
  pbVar1 = *(byte **)(iVar2 + 8);
  if (*pbVar1 == param_1) {
    zcl_cvc_stop(pbVar1);
  }
  if (pbVar1[0x40] == param_1) {
    zcl_cvc_stop(pbVar1 + 0x40);
  }
  iVar2 = color_control_srv_get_attr_desc(param_1,2);
  if (iVar2 != 0) {
    **(undefined2 **)(iVar2 + 8) = 0;
  }
  return;
}

