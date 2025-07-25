/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> esp_zb_set_node_descriptor_transfer_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_set_node_descriptor_transfer_size(uint param_1,uint param_2)

{
  if ((param_1 < 0x64e) && (param_2 < 0x64e)) {
    _DAT_000112ce = (short)param_1;
    _DAT_000112d2 = (short)param_2;
    return 0;
  }
  return 0x102;
}

