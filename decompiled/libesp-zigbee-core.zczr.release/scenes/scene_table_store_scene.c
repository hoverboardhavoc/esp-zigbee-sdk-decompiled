/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scene_table_store_scene
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 scene_table_store_scene(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  
  uVar10 = 2;
  if (param_2 != 0) {
    uVar7 = 0;
    piVar9 = *(int **)(param_2 + 0x1c);
    for (piVar8 = piVar9; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
      uVar7 = uVar7 + 3 + (uint)*(byte *)((int)piVar8 + 6) & 0xffff;
    }
    uVar7 = uVar7 + 0x18 & 0xffff;
    puVar6 = (undefined1 *)calloc(1,uVar7);
    uVar10 = 1;
    if (puVar6 != (undefined1 *)0x0) {
      uVar3 = *(undefined2 *)(param_2 + 2);
      uVar1 = *(undefined1 *)(param_2 + 4);
      *puVar6 = (char)param_1;
      puVar6[2] = (char)((ushort)uVar3 >> 8);
      puVar6[1] = (char)uVar3;
      puVar6[3] = uVar1;
      strncpy(puVar6 + 4,(char *)(param_2 + 8),0x11);
      uVar4 = *(undefined2 *)(param_2 + 6);
      puVar6[0x15] = (char)uVar4;
      puVar6[0x16] = (char)((ushort)uVar4 >> 8);
      uVar5 = 0;
      puVar6[0x17] = *(undefined1 *)(param_2 + 0x19);
      for (; piVar9 != (int *)0x0; piVar9 = (int *)*piVar9) {
        puVar6[uVar5 + 0x18] = *(undefined1 *)(piVar9 + 1);
        (puVar6 + uVar5 + 0x18)[1] = *(undefined1 *)((int)piVar9 + 5);
        bVar2 = *(byte *)((int)piVar9 + 6);
        puVar6[(uVar5 + 2 & 0xffff) + 0x18] = bVar2;
        uVar5 = uVar5 + 3 & 0xffff;
        if (bVar2 != 0) {
          memcpy(puVar6 + uVar5 + 0x18,(void *)piVar9[2],(uint)bVar2);
          uVar5 = uVar5 + *(byte *)((int)piVar9 + 6) & 0xffff;
        }
      }
      scene_table_remove_stored_scene(param_1,uVar3,uVar1);
      uVar10 = ds_internal_add_entry(0xb,puVar6,uVar7);
      mm_free(puVar6);
    }
  }
  return uVar10;
}

