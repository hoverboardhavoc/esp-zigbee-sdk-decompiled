/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_info_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_reporting_info_update(void *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  char *__dest;
  undefined4 uStack_2c;
  undefined2 uStack_28;
  char cStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 auStack_19 [13];
  
  __dest = (char *)zcl_reporting_info_find
                             (*(undefined1 *)((int)param_1 + 1),*(undefined2 *)((int)param_1 + 4),
                              *(undefined1 *)((int)param_1 + 8),*(undefined2 *)((int)param_1 + 6),
                              *(undefined2 *)((int)param_1 + 0x30));
  if (__dest == (char *)0x0) {
    return 5;
  }
  if (*__dest == '\0') {
    memcpy(__dest,param_1,0x34);
    if (*(int *)((int)param_1 + 0x10) == 0xffff) {
      *(undefined4 *)(__dest + 0x10) = *(undefined4 *)(__dest + 0x28);
      memset(__dest + 0x18,0,8);
    }
    bVar1 = __dest[9];
    __dest[9] = bVar1 | 0x40;
    if ((bVar1 & 0xf) != 4) {
      __dest[9] = bVar1 & 0xf0 | 0x43;
    }
  }
  else {
    *(undefined2 *)(__dest + 0x10) = *(undefined2 *)((int)param_1 + 0x10);
  }
  process_attr_report(__dest);
  memset(&uStack_2c,0,0x1b);
  zcl_reporting_remove_stored_reporting_info(__dest);
  uStack_28 = *(undefined2 *)(__dest + 4);
  uStack_2c = *(undefined4 *)__dest;
  cStack_26 = __dest[8];
  uStack_25 = (undefined1)*(undefined2 *)(__dest + 6);
  uStack_24 = (undefined1)((ushort)*(undefined2 *)(__dest + 6) >> 8);
  uStack_23 = (undefined1)*(undefined4 *)(__dest + 0x30);
  uStack_22 = (undefined1)((uint)*(undefined4 *)(__dest + 0x30) >> 8);
  uStack_21 = (undefined1)*(undefined2 *)(__dest + 0x10);
  uStack_20 = (undefined1)((ushort)*(undefined2 *)(__dest + 0x10) >> 8);
  if (*__dest == '\0') {
    uStack_1f = (undefined1)*(undefined2 *)(__dest + 0x12);
    uStack_1e = (undefined1)((ushort)*(undefined2 *)(__dest + 0x12) >> 8);
    uStack_1d = (undefined1)*(undefined4 *)(__dest + 0x28);
    uStack_1c = (undefined1)((uint)*(undefined4 *)(__dest + 0x28) >> 8);
    uStack_1b = (undefined1)*(undefined2 *)(__dest + 0x2a);
    uStack_1a = (undefined1)((ushort)*(undefined2 *)(__dest + 0x2a) >> 8);
    memcpy(auStack_19,__dest + 0x18,8);
  }
  uVar2 = ds_internal_add_entry(10,&uStack_2c,0x1b);
  return uVar2;
}

