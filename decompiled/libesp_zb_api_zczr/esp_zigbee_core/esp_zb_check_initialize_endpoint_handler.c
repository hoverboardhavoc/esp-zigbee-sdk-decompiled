/*
 * Last changed at upstream commit d04ab25a7353bae74042267d24c5fef5f02d0726
 * https://github.com/espressif/esp-zigbee-sdk/commit/d04ab25a7353bae74042267d24c5fef5f02d0726
 * Upstream date: 2023-08-08 16:02:31 +0800
 * Upstream subject: esp-zigbee-sdk: add touchlink example
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
    *(undefined1 *)(iVar1 + 3) = 2;
    *(undefined1 *)(iVar1 + 4) = 0x28;
    *(undefined1 *)(iVar1 + 5) = 1;
    *(undefined1 *)(iVar1 + 6) = 0;
  }
  return;
}

