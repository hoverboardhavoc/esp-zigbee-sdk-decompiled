/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_cluster.o -> zcl_cluster_template_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_cluster_template_add(undefined2 *param_1)

{
  int iVar1;
  void *__dest;
  
  if (param_1 == (undefined2 *)0x0) {
    return 0x87;
  }
  iVar1 = zcl_cluster_template_find(*param_1,*(undefined1 *)(param_1 + 1));
  if (iVar1 == 0) {
    __dest = calloc(1,0x18);
    if (__dest == (void *)0x0) {
      return 0x89;
    }
    *(int *)((int)__dest + 0x14) = (int)__dest + 0x14;
    memcpy(__dest,param_1,0x14);
    iVar1 = core_globals_get();
    *(undefined4 *)((int)__dest + 0x14) = *(undefined4 *)(iVar1 + 0xd38);
    *(int *)(iVar1 + 0xd38) = (int)__dest + 0x14;
  }
  return 0;
}

