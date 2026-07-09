/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> level_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 level_cluster_srv_check_value_handler(int param_1,undefined4 param_2,byte *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  byte bVar5;
  
  if (param_1 != 0) {
    return 0;
  }
  iVar1 = level_srv_get_attr_desc(param_2,2);
  iVar2 = level_srv_get_attr_desc(param_2,3);
  bVar4 = 0;
  if (iVar1 != 0) {
    bVar4 = **(byte **)(iVar1 + 8);
  }
  bVar5 = 0xff;
  if (iVar2 != 0) {
    bVar5 = **(byte **)(iVar2 + 8);
  }
  uVar3 = 0x87;
  if ((bVar4 <= *param_3) && (*param_3 <= bVar5)) {
    uVar3 = 0;
  }
  return uVar3;
}

