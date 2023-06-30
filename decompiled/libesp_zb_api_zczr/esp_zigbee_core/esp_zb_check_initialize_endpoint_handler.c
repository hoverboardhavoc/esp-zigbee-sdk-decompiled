/*
 * Last changed at upstream commit e81a64f4a72a1b96e84882b938e8d601ccb424df
 * https://github.com/espressif/esp-zigbee-sdk/commit/e81a64f4a72a1b96e84882b938e8d601ccb424df
 * Upstream date: 2023-06-30 20:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.7.0(8b8bde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_check_initialize_endpoint_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_check_initialize_endpoint_handler(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = zb_af_get_endpoint_desc();
  if (*(int *)(iVar1 + 3) == 0) {
    iVar1 = zb_af_get_endpoint_desc(param_1);
    *(undefined1 *)(iVar1 + 3) = 0xb0;
    *(undefined1 *)(iVar1 + 4) = 0x1b;
    *(undefined1 *)(iVar1 + 5) = 1;
    *(undefined1 *)(iVar1 + 6) = 0;
  }
  return;
}

