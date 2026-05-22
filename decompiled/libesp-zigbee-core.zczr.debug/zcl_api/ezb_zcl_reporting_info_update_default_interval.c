/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_api.o -> ezb_zcl_reporting_info_update_default_interval
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_reporting_info_update_default_interval
                    (ezb_zcl_reporting_info_t info,uint16_t def_min_interval,
                    uint16_t def_max_interval)

{
  ezb_err_t eVar1;
  
  *(uint16_t *)((int)info + 0x28) = def_min_interval;
  *(uint16_t *)((int)info + 0x2a) = def_max_interval;
  eVar1 = zcl_reporting_info_update();
  return eVar1;
}

