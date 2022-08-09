/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_zdo_command.o -> device_leave_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_leave_cb(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)zb_buf_begin_func();
  bVar1 = *pbVar2;
  if (*(code **)(device_leave_user_cb + (uint)bVar1 * 4) != (code *)0x0) {
    (**(code **)(device_leave_user_cb + (uint)bVar1 * 4))(pbVar2[1]);
    *(undefined4 *)(device_leave_user_cb + (uint)bVar1 * 4) = 0;
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

