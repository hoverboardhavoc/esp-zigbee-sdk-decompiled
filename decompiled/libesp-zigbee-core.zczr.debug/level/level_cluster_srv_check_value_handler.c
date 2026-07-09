/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> level_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 level_cluster_srv_check_value_handler(int param_1,undefined4 param_2,byte *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  
  if (param_1 == 0) {
    iVar2 = level_srv_get_attr_desc(param_2,2);
    iVar3 = level_srv_get_attr_desc(param_2,3);
    if (iVar2 == 0) {
      bVar5 = 0;
    }
    else {
      bVar5 = **(byte **)(iVar2 + 8);
    }
    if (iVar3 == 0) {
      bVar4 = 0xff;
    }
    else {
      bVar4 = **(byte **)(iVar3 + 8);
    }
    if (*param_3 < bVar5) {
      uVar1 = 0x87;
    }
    else if (bVar4 < *param_3) {
      uVar1 = 0x87;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

