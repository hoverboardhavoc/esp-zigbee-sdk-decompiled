/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> ezb_zcl_scenes_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_scenes_cluster_server_init(uint param_1)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  void *pvVar8;
  undefined4 *puVar9;
  size_t __size;
  byte *pbVar10;
  undefined4 local_5c;
  undefined4 uStack_58;
  byte *pbStack_54;
  undefined1 auStack_50 [2];
  short sStack_4e;
  char cStack_4c;
  byte *pbStack_48;
  undefined1 auStack_44 [32];
  
  memcpy(auStack_44,&_LANCHOR0,0x14);
  pbVar5 = (byte *)scenes_srv_get_attr_desc_part_0(param_1,0xeff0);
  pbVar6 = (byte *)scenes_srv_get_attr_desc(param_1,0);
  iVar7 = scenes_srv_get_attr_desc_part_0(param_1,0xeff1);
  if (((iVar7 != 0) && (pbVar5 != (byte *)0x0)) && (pbVar6 != (byte *)0x0)) goto _L0;
  do {
    do {
      iVar7 = __assert_func(0,0,0,0);
_L0:
      bVar1 = **(byte **)(pbVar5 + 8);
      pbVar5 = (byte *)(uint)bVar1;
      __size = (int)pbVar5 * 0x20 + 8;
      pvVar8 = calloc(1,__size);
      *(void **)(iVar7 + 8) = pvVar8;
    } while (pvVar8 == (void *)0x0);
    memset(pvVar8,0,__size);
    pbVar10 = *(byte **)(iVar7 + 8);
    *pbVar10 = bVar1;
    *(undefined4 *)(pbVar10 + 4) = *(undefined4 *)(pbVar6 + 8);
    local_5c = 0;
    uStack_58 = 0;
    pbStack_54 = (byte *)0x0;
    ds_zcl_scene_info_iterator_init(&local_5c);
_L0:
    pbVar10 = pbStack_54;
    if ((char)uStack_58 == '\0') {
      if ((pbStack_54 == (byte *)0x0) || (*pbStack_54 != param_1)) goto _L0;
      iVar7 = scene_table_get_unused_entry(param_1);
      if (iVar7 != 0) break;
_L0:
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (pbStack_54 != (byte *)0x0) {
      mm_free();
    }
    local_5c = 0;
    uStack_58 = 0;
    pbStack_54 = (byte *)0x0;
    if (bVar2) {
      ds_zcl_scene_info_iterator_init(auStack_50);
      while (cStack_4c == '\0') {
        if (*pbStack_48 == param_1) {
          ds_internal_remove_entry(0xb);
        }
        else {
          sStack_4e = sStack_4e + 1;
        }
        ds_zcl_scene_info_read(auStack_50);
      }
      pbVar6 = (byte *)scene_table_get(param_1);
      for (uVar4 = 0; uVar4 < *pbVar6; uVar4 = uVar4 + 1 & 0xff) {
        if (pbVar6[uVar4 * 0x20 + 8] != 0) {
          scene_table_store_scene(param_1,pbVar6 + uVar4 * 0x20 + 8);
        }
      }
    }
    iVar7 = zcl_cluster_template_add(auStack_44);
    if (iVar7 == 0) {
      return;
    }
  } while( true );
  *(undefined2 *)(iVar7 + 2) = *(undefined2 *)(pbVar10 + 1);
  *(byte *)(iVar7 + 4) = pbVar10[3];
  pbVar5 = (byte *)0x0;
  *(undefined2 *)(iVar7 + 6) = *(undefined2 *)(pbVar10 + 0x15);
  pbVar3 = pbVar10 + 0x18;
  *(byte *)(iVar7 + 0x19) = pbVar10[0x17];
  strncpy((char *)(iVar7 + 8),(char *)(pbVar10 + 4),0x11);
  pbVar6 = (byte *)((local_5c & 0xffff) - 0x18 & 0xffff);
  while (pbVar5 < pbVar6) {
    puVar9 = (undefined4 *)calloc(1,0xc);
    if (puVar9 == (undefined4 *)0x0) goto _L0;
    *(byte *)(puVar9 + 1) = pbVar3[(int)pbVar5];
    pbVar6 = (byte *)((uint)(pbVar6 + -3) & 0xffff);
    *(byte *)((int)puVar9 + 5) = (pbVar3 + (int)pbVar5)[1];
    uVar4 = (uint)pbVar3[(uint)(pbVar5 + 2) & 0xffff];
    *(byte *)((int)puVar9 + 6) = pbVar3[(uint)(pbVar5 + 2) & 0xffff];
    pbVar5 = (byte *)((uint)(pbVar5 + 3) & 0xffff);
    if (uVar4 != 0) {
      pvVar8 = calloc(1,uVar4);
      puVar9[2] = pvVar8;
      if (pvVar8 == (void *)0x0) goto _L0;
      memcpy(pvVar8,pbVar3 + (int)pbVar5,uVar4);
      pbVar5 = (byte *)((uint)(pbVar5 + uVar4) & 0xffff);
      pbVar6 = (byte *)((int)pbVar6 - uVar4 & 0xffff);
    }
    *puVar9 = *(undefined4 *)(iVar7 + 0x1c);
    *(undefined4 **)(iVar7 + 0x1c) = puVar9;
  }
  scene_table_add_entry(param_1,iVar7,0);
  if ((char)uStack_58 == '\0') {
_L0:
    local_5c = CONCAT22((short)(local_5c >> 0x10) + 1,(undefined2)local_5c);
    ds_zcl_scene_info_read(&local_5c);
  }
  goto _L0;
}

