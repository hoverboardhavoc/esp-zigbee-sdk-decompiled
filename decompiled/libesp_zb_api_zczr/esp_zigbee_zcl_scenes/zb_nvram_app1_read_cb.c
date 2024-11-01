/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_scenes.o -> zb_nvram_app1_read_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_nvram_app1_read_cb(uint param_1)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  void *pvVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  uint uVar11;
  undefined1 *__dest;
  undefined1 *puVar12;
  uint __size;
  undefined2 uStack_50;
  byte abStack_49 [5];
  undefined1 *local_44;
  
  iVar4 = -(param_1 + 0x10 & 0xfffffff0);
  if (param_1 < 2) {
    return;
  }
  iVar6 = zb_nvram_read_data((int)&uStack_50 + iVar4,param_1);
  uVar3 = *(ushort *)((int)&uStack_50 + iVar4);
  puVar12 = &esp_zb_zcl_scenes_table;
  __dest = &esp_zb_zcl_scenes_table;
  uVar5 = 2;
  do {
    uVar10 = uVar5 + 8;
    do {
      if (((uVar3 + 2 & 0xffff) < uVar10) || (__dest == (undefined1 *)0x11668)) {
        do {
          if (*(short *)(puVar12 + 2) != -1) {
            zb_zcl_scenes_set_scene_count(*puVar12,1);
          }
          puVar12 = puVar12 + 0xc;
        } while (puVar12 != (undefined1 *)0x11668);
        return;
      }
    } while (iVar6 != 0);
    pvVar7 = (void *)((int)&uStack_50 + uVar5 + iVar4);
    memcpy(__dest,pvVar7,8);
    uVar11 = (uint)*(byte *)((int)pvVar7 + 7);
    puVar8 = (undefined1 *)0x0;
    while (uVar5 = uVar10 & 0xffff, uVar11 != 0) {
      local_44 = puVar8;
      puVar8 = (undefined1 *)malloc(0xc);
      puVar9 = (undefined1 *)((int)&uStack_50 + uVar5 + iVar4);
      uVar1 = puVar9[1];
      *puVar8 = *puVar9;
      puVar8[1] = uVar1;
      bVar2 = *(byte *)((int)&uStack_50 + (uVar5 + 2 & 0xffff) + iVar4);
      __size = (uint)bVar2;
      puVar8[2] = bVar2;
      pvVar7 = malloc(__size);
      uVar10 = uVar5 + 3 & 0xffff;
      *(void **)(puVar8 + 4) = pvVar7;
      memcpy(pvVar7,(void *)((int)&uStack_50 + uVar10 + iVar4),__size);
      uVar10 = uVar10 + __size;
      *(undefined4 *)(puVar8 + 8) = 0;
      uVar11 = (uVar11 - 3 & 0xffff) - __size & 0xffff;
      if (local_44 == (undefined1 *)0x0) {
        *(undefined1 **)(__dest + 8) = puVar8;
      }
      else {
        *(undefined1 **)(local_44 + 8) = puVar8;
      }
    }
    __dest = __dest + 0xc;
  } while( true );
}

