/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> esp_zb_bdb_cancel_formation
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_bdb_cancel_formation(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC23,uVar2,"ESP_ZIGBEE_CORE","esp_zb_bdb_cancel_formation",
                  0x4bd);
    uVar2 = 0xffffffff;
  }
  else {
    bdb_cancel_formation();
    uVar2 = 0;
  }
  return uVar2;
}

