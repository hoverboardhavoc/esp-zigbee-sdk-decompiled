/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_store_scene
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 scene_table_store_scene(undefined4 param_1,int param_2)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  uint __size;
  
  if (param_2 == 0) {
    uVar7 = 2;
  }
  else {
    iVar5 = scene_entry_get_extended_field_length(param_2);
    __size = iVar5 + 0x18U & 0xffff;
    puVar6 = (undefined1 *)calloc(1,__size);
    if (puVar6 == (undefined1 *)0x0) {
      uVar7 = 1;
    }
    else {
      *puVar6 = (char)param_1;
      uVar2 = *(undefined2 *)(param_2 + 2);
      puVar6[1] = (char)uVar2;
      puVar6[2] = (char)((ushort)uVar2 >> 8);
      puVar6[3] = *(undefined1 *)(param_2 + 4);
      strncpy(puVar6 + 4,(char *)(param_2 + 8),0x11);
      uVar2 = *(undefined2 *)(param_2 + 6);
      puVar6[0x15] = (char)uVar2;
      puVar6[0x16] = (char)((ushort)uVar2 >> 8);
      puVar6[0x17] = *(undefined1 *)(param_2 + 0x19);
      uVar3 = 0;
      for (puVar4 = *(undefined4 **)(param_2 + 0x1c); puVar4 != (undefined4 *)0x0;
          puVar4 = (undefined4 *)*puVar4) {
        puVar6[uVar3 + 0x18] = *(undefined1 *)(puVar4 + 1);
        (puVar6 + uVar3 + 0x18)[1] = *(undefined1 *)((int)puVar4 + 5);
        bVar1 = *(byte *)((int)puVar4 + 6);
        puVar6[(uVar3 + 2 & 0xffff) + 0x18] = bVar1;
        uVar3 = uVar3 + 3 & 0xffff;
        if (bVar1 != 0) {
          memcpy(puVar6 + uVar3 + 0x18,(void *)puVar4[2],(uint)bVar1);
          uVar3 = *(byte *)((int)puVar4 + 6) + uVar3 & 0xffff;
        }
      }
      scene_table_remove_stored_scene
                (param_1,*(undefined2 *)(param_2 + 2),*(undefined1 *)(param_2 + 4));
      uVar7 = ds_internal_add_entry(0xb,puVar6,__size);
      mm_free(puVar6);
    }
  }
  return uVar7;
}

