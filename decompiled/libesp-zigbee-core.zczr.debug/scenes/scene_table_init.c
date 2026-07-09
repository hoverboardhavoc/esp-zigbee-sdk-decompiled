/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 scene_table_init(undefined4 param_1)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  size_t __size;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  void *__s;
  undefined4 uVar8;
  undefined1 *puVar9;
  int extraout_a1;
  byte *pbVar10;
  uint __size_00;
  
  iVar5 = scenes_srv_get_attr_desc(0xeff0);
  iVar6 = scenes_srv_get_attr_desc(param_1,0);
  iVar7 = scenes_srv_get_attr_desc(param_1,0xeff1);
  if (((iVar7 == 0) || (iVar5 == 0)) || (iVar6 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x117,
                  "scene_table_init",
                  "scene_table_attr_desc && scene_total_attr_desc && scene_count_attr_desc");
  }
  else {
    bVar1 = **(byte **)(iVar5 + 8);
    __size = (uint)bVar1 * 0x20 + 8;
    __s = calloc(1,__size);
    *(void **)(iVar7 + 8) = __s;
    if (__s != (void *)0x0) {
      memset(__s,0,__size);
      pbVar10 = *(byte **)(iVar7 + 8);
      *pbVar10 = bVar1;
      *(undefined4 *)(pbVar10 + 4) = *(undefined4 *)(iVar6 + 8);
      return 0;
    }
  }
  uVar8 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x11c,
                        "scene_table_init","scene_table_attr_desc->data_p");
  if (extraout_a1 == 0) {
    uVar8 = 2;
  }
  else {
    iVar5 = scene_entry_get_extended_field_length(extraout_a1);
    __size_00 = iVar5 + 0x18U & 0xffff;
    puVar9 = (undefined1 *)calloc(1,__size_00);
    if (puVar9 == (undefined1 *)0x0) {
      uVar8 = 1;
    }
    else {
      *puVar9 = (char)uVar8;
      uVar2 = *(undefined2 *)(extraout_a1 + 2);
      puVar9[1] = (char)uVar2;
      puVar9[2] = (char)((ushort)uVar2 >> 8);
      puVar9[3] = *(undefined1 *)(extraout_a1 + 4);
      strncpy(puVar9 + 4,(char *)(extraout_a1 + 8),0x11);
      uVar2 = *(undefined2 *)(extraout_a1 + 6);
      puVar9[0x15] = (char)uVar2;
      puVar9[0x16] = (char)((ushort)uVar2 >> 8);
      puVar9[0x17] = *(undefined1 *)(extraout_a1 + 0x19);
      uVar3 = 0;
      for (puVar4 = *(undefined4 **)(extraout_a1 + 0x1c); puVar4 != (undefined4 *)0x0;
          puVar4 = (undefined4 *)*puVar4) {
        puVar9[uVar3 + 0x18] = *(undefined1 *)(puVar4 + 1);
        (puVar9 + uVar3 + 0x18)[1] = *(undefined1 *)((int)puVar4 + 5);
        bVar1 = *(byte *)((int)puVar4 + 6);
        puVar9[(uVar3 + 2 & 0xffff) + 0x18] = bVar1;
        uVar3 = uVar3 + 3 & 0xffff;
        if (bVar1 != 0) {
          memcpy(puVar9 + uVar3 + 0x18,(void *)puVar4[2],(uint)bVar1);
          uVar3 = *(byte *)((int)puVar4 + 6) + uVar3 & 0xffff;
        }
      }
      scene_table_remove_stored_scene
                (uVar8,*(undefined2 *)(extraout_a1 + 2),*(undefined1 *)(extraout_a1 + 4));
      uVar8 = ds_internal_add_entry(0xb,puVar9,__size_00);
      mm_free(puVar9);
    }
  }
  return uVar8;
}

