/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> simple_measurement.o -> rel_humidity_measurement_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
rel_humidity_measurement_cluster_srv_check_value_handler
          (uint16_t attr_id,uint8_t endpoint,void *value)

{
  ezb_zcl_status_t eVar1;
  
  eVar1 = check_value_simple_u16_measurement_server
                    (0x405,attr_id,endpoint,(uint8_t *)value,
                     &rel_humidity_measurement_cluster_srv_check_value_handler::
                      REL_HUMIDITY_measurement_ranges);
  return eVar1;
}

