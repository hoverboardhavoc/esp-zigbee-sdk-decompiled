/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> zb_zcl_endpoint_handler_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_endpoint_handler_register(uint param_1,undefined4 param_2)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  
  puVar1 = s_endpoint_handler_list;
  piVar4 = (int *)s_endpoint_handler_list;
  while( true ) {
    if ((ushort *)(piVar4 + -2) == (ushort *)0xfffffff8) {
      puVar2 = (undefined2 *)malloc(0xc);
      uVar3 = 0x101;
      if (puVar2 != (undefined2 *)0x0) {
        *puVar2 = (short)param_1;
        *(undefined2 **)(puVar2 + 4) = puVar1;
        *(undefined4 *)(puVar2 + 2) = param_2;
        s_endpoint_handler_list = puVar2 + 4;
        uVar3 = 0;
      }
      return uVar3;
    }
    if ((*(ushort *)(piVar4 + -2) == param_1) && (piVar4[-1] != 0)) break;
    piVar4 = (int *)*piVar4;
  }
  return 0x102;
}

