/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_zdo_command.o -> bind_device_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bind_device_cb(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar2 = zb_buf_begin_func();
  pbVar3 = (byte *)zb_buf_begin_func(param_1);
  bVar1 = *pbVar3;
  if (*(code **)(bind_user_cb + (uint)bVar1 * 4) != (code *)0x0) {
    (**(code **)(bind_user_cb + (uint)bVar1 * 4))(*(undefined1 *)(iVar2 + 1));
    *(undefined4 *)(bind_user_cb + (uint)bVar1 * 4) = 0;
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

