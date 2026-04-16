/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_attr_desc_get_value_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t zcl_attr_desc_get_value_size(zcl_attr_desc_t *attr_desc)

{
  uint16_t uVar1;
  
  if (attr_desc == (zcl_attr_desc_t *)0x0) {
    uVar1 = 0xffff;
  }
  else {
    uVar1 = zcl_get_attr_value_size(attr_desc->type,attr_desc->data_p);
  }
  return uVar1;
}

