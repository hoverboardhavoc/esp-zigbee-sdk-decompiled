/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_name_is_supported
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool scene_name_is_supported(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = scenes_srv_get_attr_desc(4);
  if (iVar2 == 0) {
    bVar1 = false;
  }
  else {
    bVar1 = **(char **)(iVar2 + 8) != '\0';
  }
  return bVar1;
}

