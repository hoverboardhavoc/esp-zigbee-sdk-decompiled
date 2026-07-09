/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte * scene_table_get(void)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  
  pbVar1 = (byte *)scenes_srv_get_attr_desc(0xeff1);
  if ((pbVar1 == (byte *)0x0) || (pbVar1 = *(byte **)(pbVar1 + 8), pbVar1 != (byte *)0x0)) {
    return pbVar1;
  }
  pcVar3 = "scene_table_get";
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x12e,
                        "scene_table");
  pbVar1 = (byte *)scene_table_get();
  if (pbVar1 != (byte *)0x0) {
    for (uVar4 = 0; uVar4 < *pbVar1; uVar4 = uVar4 + 1 & 0xff) {
      if (((pbVar1[uVar4 * 0x20 + 8] != 0) && (*(ushort *)(pbVar1 + uVar4 * 0x20 + 10) == uVar2)) &&
         ((char *)(uint)pbVar1[uVar4 * 0x20 + 0xc] == pcVar3)) {
        return pbVar1 + uVar4 * 0x20 + 8;
      }
    }
    pbVar1 = (byte *)0x0;
  }
  return pbVar1;
}

