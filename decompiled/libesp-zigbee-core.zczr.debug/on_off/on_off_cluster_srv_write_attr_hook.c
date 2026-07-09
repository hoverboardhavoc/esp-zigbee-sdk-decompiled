/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void on_off_cluster_srv_write_attr_hook(int param_1,char *param_2)

{
  int iVar1;
  
  if ((((param_1 == 0) && (iVar1 = on_off_srv_get_attr_desc(0x4000), iVar1 != 0)) &&
      (**(char **)(iVar1 + 8) == '\0')) && ((param_2 != (char *)0x0 && (*param_2 != '\0')))) {
    **(char **)(iVar1 + 8) = '\x01';
  }
  return;
}

