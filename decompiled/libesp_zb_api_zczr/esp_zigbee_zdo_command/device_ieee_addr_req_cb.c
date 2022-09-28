/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> device_ieee_addr_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_ieee_addr_req_cb(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  pbVar2 = (byte *)zb_buf_begin_func();
  bVar1 = *pbVar2;
  iVar3 = zb_buf_begin_func(param_1);
  uStack_18 = ZDO_INVALID_IEEE_ADDR;
  uStack_14 = DAT_00012618;
  if (*(char *)(iVar3 + 1) == '\0') {
    zb_memcpy8(&uStack_18,iVar3 + 2);
  }
  if (*(code **)(ieee_user_cb + (uint)bVar1 * 4) != (code *)0x0) {
    (**(code **)(ieee_user_cb + (uint)bVar1 * 4))(*(undefined1 *)(iVar3 + 1),&uStack_18);
    *(undefined4 *)(ieee_user_cb + (uint)bVar1 * 4) = 0;
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

