/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_ep_reporting_info_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int af_ep_reporting_info_init(undefined1 *param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == (undefined1 *)0x0) {
    iVar4 = 2;
  }
  else {
    zcl_reporting_restore_reporting_info(*param_1);
    iVar4 = 0;
    for (puVar2 = *(undefined2 **)(param_1 + 4); puVar2 != (undefined2 *)0x0;
        puVar2 = *(undefined2 **)(puVar2 + 8)) {
      for (puVar1 = *(undefined2 **)(puVar2 + 6); puVar1 != (undefined2 *)0x0;
          puVar1 = *(undefined2 **)(puVar1 + 6)) {
        if (((*(byte *)((int)puVar1 + 3) & 4) != 0) &&
           (iVar3 = zcl_reporting_info_find
                              (*param_1,*puVar2,*(undefined1 *)(puVar2 + 1),*puVar1,puVar1[2]),
           iVar3 == 0)) {
          zcl_reporting_info_create
                    (*param_1,*(undefined2 *)(param_1 + 2),0,*puVar2,*(undefined1 *)(puVar2 + 1),
                     *puVar1,puVar1[2]);
          iVar4 = zcl_reporting_info_add();
          if (iVar4 != 0) {
            return iVar4;
          }
        }
      }
    }
  }
  return iVar4;
}

