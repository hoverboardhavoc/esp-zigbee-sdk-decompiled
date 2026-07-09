/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_create_attr_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 *
zcl_create_attr_desc
          (undefined2 param_1,undefined4 param_2,byte param_3,int param_4,undefined4 param_5)

{
  size_t __size;
  undefined2 *puVar1;
  void *pvVar2;
  
  __size = zcl_get_attr_value_size(param_2,param_5);
  if (__size == 0xffff) {
    puVar1 = (undefined2 *)0x0;
  }
  else {
    puVar1 = (undefined2 *)calloc(1,0x10);
    if (puVar1 != (undefined2 *)0x0) {
      *puVar1 = param_1;
      if (__size == 0) {
        pvVar2 = (void *)0x0;
      }
      else {
        pvVar2 = calloc(1,__size);
      }
      *(void **)(puVar1 + 4) = pvVar2;
      puVar1[2] = (short)param_4;
      *(char *)(puVar1 + 1) = (char)param_2;
      if (param_4 == 0) {
        param_3 = param_3 & 0xdf;
      }
      else {
        param_3 = param_3 | 0x20;
      }
      *(byte *)((int)puVar1 + 3) = param_3;
      *(undefined4 *)(puVar1 + 6) = 0;
      if ((__size == 0) || (pvVar2 != (void *)0x0)) {
        zcl_write_attr_value(pvVar2,param_5,param_2);
      }
      else {
        mm_free(puVar1);
        puVar1 = (undefined2 *)0x0;
      }
    }
  }
  return puVar1;
}

