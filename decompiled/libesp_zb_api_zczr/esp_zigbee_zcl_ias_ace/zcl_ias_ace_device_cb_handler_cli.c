/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_ias_ace.o -> zcl_ias_ace_device_cb_handler_cli
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ias_ace_device_cb_handler_cli(void)

{
  uint *puVar1;
  undefined4 *__ptr;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  puVar1 = (uint *)zb_buf_get_tail_func(0x38);
  uVar4 = *puVar1;
  if (uVar4 != 0x17) {
    if (0x17 < uVar4) goto _L0;
    if (((uVar4 != 0x15) && (uVar4 != 0x16)) && (uVar4 != 0x13)) {
      uVar3 = 0x14;
      while (uVar4 != uVar3) {
        zb_assert(0x10000,0x9d);
_L0:
        if ((uVar4 == 0x1a) || (uVar4 < 0x1b)) break;
        uVar3 = 0x1b;
      }
    }
  }
  __ptr = (undefined4 *)malloc(0xc);
  uVar3 = puVar1[4];
  *__ptr = 0;
  __ptr[2] = uVar3;
  *(char *)(__ptr + 1) = (char)puVar1[1];
  *(undefined2 *)((int)__ptr + 6) = 0x501;
  esp_zb_core_action_handler_schedule(uVar4 + 0x15d,__ptr);
  uVar2 = esp_err_to_zb_ret();
  free(__ptr);
  return uVar2;
}

