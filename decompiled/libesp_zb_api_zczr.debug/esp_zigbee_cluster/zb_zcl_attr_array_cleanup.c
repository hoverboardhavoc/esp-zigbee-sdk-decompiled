/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> zb_zcl_attr_array_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_attr_array_cleanup(ushort *param_1)

{
  int iVar1;
  
  if (param_1 != (ushort *)0x0) {
    for (iVar1 = 0; iVar1 < (int)(uint)*param_1; iVar1 = iVar1 + 1) {
      free(*(void **)(*(int *)(param_1 + 2) + iVar1 * 10 + 6));
    }
    free(*(void **)(param_1 + 2));
    return;
  }
  return;
}

