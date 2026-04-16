/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> datasets.o -> ds_internal_add_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ds_internal_add_entry(ds_key_t key,void *value,uint16_t length)

{
  ezb_err_t error;
  undefined2 in_register_00002032;
  
  error = ezb_plat_datasets_add(CONCAT22(in_register_00002032,length));
  ds_log('\x04',error,key,value);
  return error;
}

