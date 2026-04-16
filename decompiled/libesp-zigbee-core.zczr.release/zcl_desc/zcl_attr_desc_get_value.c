/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_desc.o -> zcl_attr_desc_get_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_attr_desc_get_value(zcl_attr_desc_t *attr_desc,void *value)

{
  int iVar1;
  
  if ((attr_desc != (zcl_attr_desc_t *)0x0) && (value != (void *)0x0)) {
    iVar1 = zcl_read_attr_value(value,attr_desc->data_p,attr_desc->type);
    return iVar1 + -1;
  }
  return 2;
}

