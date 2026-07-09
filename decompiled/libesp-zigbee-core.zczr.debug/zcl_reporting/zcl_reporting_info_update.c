/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_info_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_reporting_info_update(void *param_1)

{
  byte bVar1;
  char *__dest;
  undefined4 uVar2;
  
  __dest = (char *)zcl_reporting_info_find
                             (*(undefined1 *)((int)param_1 + 1),*(undefined2 *)((int)param_1 + 4),
                              *(undefined1 *)((int)param_1 + 8),*(undefined2 *)((int)param_1 + 6),
                              *(undefined2 *)((int)param_1 + 0x30));
  if (__dest == (char *)0x0) {
    uVar2 = 5;
  }
  else {
    if (*__dest == '\0') {
      memcpy(__dest,param_1,0x34);
      if (*(int *)((int)param_1 + 0x10) == 0xffff) {
        *(undefined2 *)(__dest + 0x10) = *(undefined2 *)(__dest + 0x28);
        *(undefined2 *)(__dest + 0x12) = *(undefined2 *)(__dest + 0x2a);
        __dest[0x18] = '\0';
        __dest[0x19] = '\0';
        __dest[0x1a] = '\0';
        __dest[0x1b] = '\0';
        __dest[0x1c] = '\0';
        __dest[0x1d] = '\0';
        __dest[0x1e] = '\0';
        __dest[0x1f] = '\0';
      }
      bVar1 = __dest[9];
      __dest[9] = (byte)((*(uint *)(__dest + 8) >> 0xc & 0xf | 4) << 4) | bVar1 & 0xf;
      if ((bVar1 & 0xf) != 4) {
        __dest[9] = __dest[9] & 0xf0U | 3;
      }
      process_attr_report(__dest);
    }
    else {
      *(undefined2 *)(__dest + 0x10) = *(undefined2 *)((int)param_1 + 0x10);
      process_attr_report();
    }
    uVar2 = zcl_reporting_store_reporting_info(__dest);
  }
  return uVar2;
}

