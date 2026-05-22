/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zcl_desc.o -> zcl_attr_desc_get_type
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t zcl_attr_desc_get_type(zcl_attr_desc_t *attr_desc)

{
  if (attr_desc == (zcl_attr_desc_t *)0x0) {
    attr_desc = (zcl_attr_desc_t *)__assert_func(0,0,0);
  }
  return attr_desc->type;
}

