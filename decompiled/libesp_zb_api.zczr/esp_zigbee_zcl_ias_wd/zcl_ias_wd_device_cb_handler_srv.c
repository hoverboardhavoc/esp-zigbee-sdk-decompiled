/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_ias_wd.o -> zcl_ias_wd_device_cb_handler_srv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ias_wd_device_cb_handler_srv(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *__ptr;
  undefined4 uVar3;
  
  piVar2 = (int *)zb_buf_get_tail_func(0x38);
  if (*piVar2 != 9) {
    if (*piVar2 == 10) {
      __ptr = (undefined4 *)malloc(0xc);
      *__ptr = 0;
      iVar1 = piVar2[1];
      __ptr[2] = piVar2 + 3;
      *(char *)(__ptr + 1) = (char)iVar1;
      *(undefined2 *)((int)__ptr + 6) = 0x502;
      uVar3 = 0x1e;
      goto _L0;
    }
    zb_assert(0x10000,0x4d);
  }
  __ptr = (undefined4 *)malloc(0xc);
  *__ptr = 0;
  iVar1 = piVar2[1];
  __ptr[2] = piVar2 + 3;
  *(char *)(__ptr + 1) = (char)iVar1;
  *(undefined2 *)((int)__ptr + 6) = 0x502;
  uVar3 = 0x1d;
_L0:
  esp_zb_core_action_handler_schedule(uVar3,__ptr);
  uVar3 = esp_err_to_zb_ret();
  free(__ptr);
  return uVar3;
}

