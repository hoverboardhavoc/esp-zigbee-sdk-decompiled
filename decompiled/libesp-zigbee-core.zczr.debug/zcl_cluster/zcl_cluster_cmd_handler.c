/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_cluster.o -> zcl_cluster_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_cluster_cmd_handler(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    uVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_cluster.c",0x91,
                          "zcl_cluster_cmd_handler","packet");
  }
  else {
    uVar1 = (uint)*(ushort *)(param_1 + 0x16);
    if ((*(byte *)(param_1 + 0x1a) & 8) != 0) {
      uVar3 = 2;
      goto _L0;
    }
  }
  uVar3 = 1;
_L0:
  iVar2 = zcl_cluster_template_find(uVar1,uVar3);
  if (iVar2 == 0) {
    uVar3 = 0x81;
  }
  else if (*(short *)(param_1 + 0x16) < 0) {
    uVar3 = zcl_cluster_custom_cmd_handler(param_1,iVar2);
  }
  else if (*(code **)(iVar2 + 0x10) == (code *)0x0) {
    uVar3 = 0x81;
  }
  else {
    uVar3 = (**(code **)(iVar2 + 0x10))(param_1);
  }
  return uVar3;
}

