/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> datasets.o -> ds_internal_save_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ds_internal_save_entry(ds_key_t key,void *value,void *prev_value,uint16_t length)

{
  ds_action_t action;
  undefined2 in_register_0000202a;
  int iVar1;
  ezb_err_t error;
  undefined2 in_register_00002036;
  size_t __n;
  ushort auStack_22 [2];
  uint16_t read_length;
  
  __n = CONCAT22(in_register_00002036,length);
  auStack_22[0] = length;
  iVar1 = ezb_plat_datasets_get(0,auStack_22);
  if (((iVar1 == 0) && (auStack_22[0] == __n)) && (iVar1 = memcmp(value,prev_value,__n), iVar1 == 0)
     ) {
    action = '\x02';
    error = 0;
  }
  else {
    error = ezb_plat_datasets_set(CONCAT22(in_register_0000202a,key),value,__n);
    action = '\x01';
  }
  ds_log(action,error,key,value);
  return error;
}

