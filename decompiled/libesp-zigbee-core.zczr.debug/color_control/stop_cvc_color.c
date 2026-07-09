/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> stop_cvc_color
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void stop_cvc_color(uint param_1,byte *param_2)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = (byte *)color_control_srv_get_attr_desc(0xeff0);
  iVar2 = color_control_srv_get_attr_desc(param_1,0x4001);
  if ((pbVar1 == (byte *)0x0) || (iVar2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x18e
                  ,"stop_cvc_color","cvc_ctx_attr_desc && color_mode_attr_desc");
  }
  else {
    if (((byte *)(uint)**(byte **)(iVar2 + 8) != param_2) && (param_2 != (byte *)0xff)) {
      return;
    }
    pbVar1 = *(byte **)(pbVar1 + 8);
    param_2 = pbVar1 + 0x40;
    if (*pbVar1 != param_1) goto _L0;
  }
  zcl_cvc_stop(pbVar1);
_L0:
  if (pbVar1[0x40] == param_1) {
    zcl_cvc_stop(param_2);
  }
  color_control_set_remaining_time(param_1,0);
  return;
}

