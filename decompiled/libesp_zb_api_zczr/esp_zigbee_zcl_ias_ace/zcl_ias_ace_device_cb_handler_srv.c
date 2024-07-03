/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_ias_ace.o -> zcl_ias_ace_device_cb_handler_srv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ias_ace_device_cb_handler_srv(void)

{
  uint *puVar1;
  undefined4 *__ptr;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  puVar1 = (uint *)zb_buf_get_tail_func(0x38);
  uVar4 = *puVar1;
  if (uVar4 == 0x10) {
_L0:
    __ptr = (undefined4 *)malloc(0xc);
    __ptr[2] = puVar1[5];
  }
  else {
    if (0x10 < uVar4) goto _L0;
    if (uVar4 != 0xc) {
      if (0xc < uVar4) {
        __ptr = (undefined4 *)malloc(0x20);
        goto _L0;
      }
      uVar3 = 0xb;
      while (uVar4 != uVar3) {
        zb_assert(0x10000,0x5e);
_L0:
        if (uVar4 == 0x11) goto _L0;
        uVar3 = 0x12;
      }
    }
    __ptr = (undefined4 *)malloc(0x10);
    __ptr[2] = puVar1[4];
    __ptr[3] = puVar1[5];
  }
_L0:
  *__ptr = 0;
  *(char *)(__ptr + 1) = (char)puVar1[1];
  *(undefined2 *)((int)__ptr + 6) = 0x501;
  esp_zb_core_action_handler_schedule(uVar4 + 0x14,__ptr);
  uVar2 = esp_err_to_zb_ret();
  free(__ptr);
  return uVar2;
}

