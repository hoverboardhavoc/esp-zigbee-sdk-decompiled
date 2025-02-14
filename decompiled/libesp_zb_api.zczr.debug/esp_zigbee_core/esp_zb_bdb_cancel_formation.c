/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> esp_zb_bdb_cancel_formation
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
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC22,uVar2,"ESP_ZIGBEE_CORE","esp_zb_bdb_cancel_formation",
                  0x4cb);
    uVar2 = 0xffffffff;
  }
  else {
    bdb_cancel_formation();
    uVar2 = 0;
  }
  return uVar2;
}

