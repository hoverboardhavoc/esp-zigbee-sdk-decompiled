/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> zb_zcl_endpoint_handler_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_endpoint_handler_register(uint param_1,undefined4 param_2)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = s_endpoint_handler_list;
  while( true ) {
    if ((ushort *)(puVar3 + -2) == (ushort *)0xfffffff8) {
      puVar1 = (undefined2 *)malloc(0xc);
      if (puVar1 == (undefined2 *)0x0) {
        uVar2 = 0x101;
      }
      else {
        *puVar1 = (short)param_1;
        *(undefined4 *)(puVar1 + 2) = param_2;
        *(undefined4 **)(puVar1 + 4) = s_endpoint_handler_list;
        uVar2 = 0;
        s_endpoint_handler_list = (undefined4 *)(puVar1 + 4);
      }
      return uVar2;
    }
    if ((*(ushort *)(puVar3 + -2) == param_1) && (puVar3[-1] != 0)) break;
    puVar3 = (undefined4 *)*puVar3;
  }
  return 0x102;
}

