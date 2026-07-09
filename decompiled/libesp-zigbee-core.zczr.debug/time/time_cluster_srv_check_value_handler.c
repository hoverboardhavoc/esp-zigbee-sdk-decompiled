/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> time_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte time_cluster_srv_check_value_handler(uint param_1,undefined4 param_2,byte *param_3)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = time_server_get_attr_desc(param_2,1);
  if ((iVar1 == 0) || (pbVar2 = *(byte **)(iVar1 + 8), pbVar2 == (byte *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/time.c",0xe7,
                  "time_cluster_srv_check_value_handler","attr_desc && attr_desc->data_p");
  }
  else {
    if (param_1 == 1) {
      if (((*param_3 ^ *pbVar2) & 5) == 0) {
        return (*param_3 ^ *pbVar2) & 5;
      }
      return 0x88;
    }
    if (1 < param_1) {
      if (3 < (param_1 - 2 & 0xffff)) {
        return 0;
      }
      if ((*pbVar2 & 4) == 0) {
        if (*(int *)param_3 != -1) {
          return *pbVar2 & 4;
        }
        return 0x87;
      }
      return 0x88;
    }
    if (param_1 == 0) {
      if ((*pbVar2 & 1) != 0) {
        return 0x88;
      }
      if (*(int *)param_3 != -1) {
        return *pbVar2 & 1;
      }
      return 0x87;
    }
  }
  return 0;
}

