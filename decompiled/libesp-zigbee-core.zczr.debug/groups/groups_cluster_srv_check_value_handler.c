/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char groups_cluster_srv_check_value_handler(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  
  if (param_1 == 0) {
    cVar1 = *param_2;
    if (cVar1 != '\0') {
      iVar2 = groups_group_name_is_supported();
      if (iVar2 == 0) {
        cVar1 = -0x7a;
      }
      else {
        cVar1 = '\0';
      }
    }
  }
  else {
    cVar1 = '\0';
  }
  return cVar1;
}

