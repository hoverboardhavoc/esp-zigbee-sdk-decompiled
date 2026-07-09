/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_endpoint_add_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 af_endpoint_add_cluster_desc(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 2;
  }
  else if (param_2 == (undefined2 *)0x0) {
    uVar2 = 2;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 4);
    iVar1 = check_cluster_is_unique(uVar2,*param_2,*(undefined1 *)(param_2 + 1));
    if (iVar1 == 0) {
      uVar2 = 2;
    }
    else {
      *(undefined4 *)(param_2 + 8) = uVar2;
      *(undefined2 **)(param_1 + 4) = param_2;
      uVar2 = 0;
    }
  }
  return uVar2;
}

