/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_api.o -> ezb_zcl_get_attr_value_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t ezb_zcl_get_attr_value_size(ezb_zcl_attr_type_t attr_type,void *attr_value)

{
  undefined1 in_register_00002029;
  uint16_t uVar1;
  
  uVar1 = zcl_get_attr_value_size(CONCAT11(in_register_00002029,attr_type));
  return uVar1;
}

