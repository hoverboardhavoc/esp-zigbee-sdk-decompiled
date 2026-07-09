/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> ezb_zcl_scenes_table_store
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte ezb_zcl_scenes_table_store
               (undefined4 param_1,undefined2 param_2,undefined1 param_3,undefined2 param_4,
               int *param_5)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  void *__dest;
  uint __size;
  
  iVar2 = scene_table_find_entry();
  if (iVar2 == 0) {
    iVar2 = scene_table_get_unused_entry(param_1);
    if (iVar2 == 0) {
      return 1;
    }
  }
  else {
    scene_entry_free_scene_extension_field();
  }
  *(undefined2 *)(iVar2 + 2) = param_2;
  *(undefined1 *)(iVar2 + 4) = param_3;
  *(undefined1 *)(iVar2 + 8) = 0;
  *(undefined2 *)(iVar2 + 6) = param_4;
  *(undefined1 *)(iVar2 + 0x19) = 0;
  while( true ) {
    if (param_5 == (int *)0x0) {
      bVar1 = scene_table_add_entry(param_1,iVar2,1);
      return bVar1 ^ 1;
    }
    puVar3 = (undefined4 *)calloc(1,0xc);
    if (puVar3 == (undefined4 *)0x0) break;
    *(undefined2 *)(puVar3 + 1) = *(undefined2 *)(param_5 + 1);
    __size = (uint)*(byte *)((int)param_5 + 6);
    *(byte *)((int)puVar3 + 6) = *(byte *)((int)param_5 + 6);
    __dest = calloc(1,__size);
    puVar3[2] = __dest;
    if (__dest == (void *)0x0) {
      return 1;
    }
    if (__size != 0) {
      memcpy(__dest,(void *)param_5[2],__size);
    }
    *puVar3 = *(undefined4 *)(iVar2 + 0x1c);
    param_5 = (int *)*param_5;
    *(undefined4 **)(iVar2 + 0x1c) = puVar3;
  }
  return 1;
}

