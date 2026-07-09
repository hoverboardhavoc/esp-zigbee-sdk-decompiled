/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_ep_reporting_info_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int af_ep_reporting_info_init(undefined1 *param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined2 *puVar3;
  
  if (param_1 == (undefined1 *)0x0) {
    return 2;
  }
  zcl_reporting_restore_reporting_info(*param_1);
  puVar1 = *(undefined2 **)(param_1 + 4);
  do {
    if (puVar1 == (undefined2 *)0x0) {
      return 0;
    }
    for (puVar3 = *(undefined2 **)(puVar1 + 6); puVar3 != (undefined2 *)0x0;
        puVar3 = *(undefined2 **)(puVar3 + 6)) {
      if (((*(byte *)((int)puVar3 + 3) & 4) != 0) &&
         (iVar2 = zcl_reporting_info_find
                            (*param_1,*puVar1,*(undefined1 *)(puVar1 + 1),*puVar3,puVar3[2]),
         iVar2 == 0)) {
        zcl_reporting_info_create
                  (*param_1,*(undefined2 *)(param_1 + 2),0,*puVar1,*(undefined1 *)(puVar1 + 1),
                   *puVar3,puVar3[2]);
        iVar2 = zcl_reporting_info_add();
        if (iVar2 != 0) {
          return iVar2;
        }
      }
    }
    puVar1 = *(undefined2 **)(puVar1 + 8);
  } while( true );
}

