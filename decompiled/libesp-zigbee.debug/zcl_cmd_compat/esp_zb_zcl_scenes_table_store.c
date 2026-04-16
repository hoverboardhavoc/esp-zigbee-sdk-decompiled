/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_scenes_table_store
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_zcl_scenes_table_store
                    (uint8_t endpoint,uint16_t group_id,uint8_t scene_id,uint16_t transition_time,
                    esp_zb_zcl_scenes_extension_field_t *field)

{
  undefined3 in_register_00002029;
  esp_err_t eVar1;
  
  ezb_zcl_scenes_table_store(CONCAT31(in_register_00002029,endpoint));
  eVar1 = esp_zigbee_err_to_esp();
  return eVar1;
}

