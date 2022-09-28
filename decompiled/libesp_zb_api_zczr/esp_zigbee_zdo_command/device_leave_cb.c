/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> device_leave_cb
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

